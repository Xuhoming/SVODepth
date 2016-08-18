// This file is part of SVO - Semi-direct Visual Odometry.
//
// Copyright (C) 2014 Christian Forster <forster at ifi dot uzh dot ch>
// (Robotics and Perception Group, University of Zurich, Switzerland).
//
// SVO is free software: you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the Free Software
// Foundation, either version 3 of the License, or any later version.
//
// SVO is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <svo/config.h>
#include <svo/frame_handler_mono.h>
#include <svo/map.h>
#include <svo/frame.h>
#include <vector>
#include <string>
#include <vikit/math_utils.h>
#include <vikit/vision.h>
#include <vikit/abstract_camera.h>
#include <vikit/atan_camera.h>
#include <vikit/pinhole_camera.h>
#include <opencv2/opencv.hpp>
#include <sophus/se3.h>
#include <iostream>
#include "test_utils.h"
#include <list>
#include <boost/bind.hpp>
#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>
#include <vikit/file_reader.h>
#include <vikit/blender_utils.h>
#include <vikit/timer.h>
#include <svo/feature_detection.h>
#include <svo/depth_filter.h>
#include <svo/frame.h>
#include <svo/feature.h>
#include <svo/point.h>

namespace svo {

struct ConvergedSeed {
  int x_, y_;
  double depth_, error_;
  ConvergedSeed(int x, int y, double depth, double error) :
    x_(x), y_(y), depth_(depth), error_(error)
  {}
};

class BenchmarkNode
{
  vk::AbstractCamera* cam_;
  svo::FrameHandlerMono* vo_;
  double timestamp = 0;
  std::list<ConvergedSeed> results_;
  std::vector<double> errors_;
  size_t n_converged_seeds_;
  svo::DepthFilter* depth_filter_;
  svo::FramePtr frame_ref_;
  svo::FramePtr frame_cur_;
  cv::Mat depth_ref_;

public:
  BenchmarkNode();
  virtual ~BenchmarkNode();
  void runFromFolder();
  void depthFilterCb(svo::Point* point, double depth_sigma2);
  void testReconstruction(std::string dataset_dir, std::string experiment_name);
};

BenchmarkNode::BenchmarkNode()
{
  n_converged_seeds_= 0;
  depth_filter_ = NULL;
  errors_.reserve(1000);
  cam_ = new vk::PinholeCamera(752, 480, 315.5, 315.5, 376.0, 240.0);
  vo_ = new svo::FrameHandlerMono(cam_);
  vo_->start();
}

BenchmarkNode::~BenchmarkNode()
{
  delete vo_;
  delete cam_;
}

// void BenchmarkNode::runFromFolder()
// {
//   for(int img_id = 2; img_id < 188; ++img_id)
//   {
//     // load image
//     std::stringstream ss;
//     ss << svo::test_utils::getDatasetDir() << "/sin2_tex2_h1_v8_d/img/frame_"
//        << std::setw( 6 ) << std::setfill( '0' ) << img_id << "_0.png";
//     if(img_id == 2)
//       std::cout << "reading image " << ss.str() << std::endl;
//     cv::Mat img(cv::imread(ss.str().c_str(), 0));
//     assert(!img.empty());

//     // process frame
//     vo_->addImage(img, 0.01*img_id);

    

//     // display tracking quality
//     if(vo_->lastFrame() != NULL)
//     {
//       timestamp += vo_->lastProcessingTime();
//       Eigen::Quaterniond pose_q;
//       pose_q = vo_->lastFrame()->T_f_w_.inverse().rotation_matrix();
//       //pose_q.normalize();
      
//     	std::cout << "Frame-Id: " << vo_->lastFrame()->id_ << " \t"
//                   << "#Features: " << vo_->lastNumObservations() << " \t"
//                   << "Proc. Time: " << vo_->lastProcessingTime()*1000 << "ms \n"
//                   << "Pose: " << vo_->lastFrame()->timestamp_<<vo_->lastFrame()->T_f_w_.inverse() << pose_q.x() << " \t"
//                   << pose_q.y()  << " \t" << pose_q.z() << " \t" << pose_q.w() <<"\n";

//     	// access the pose of the camera via vo_->lastFrame()->T_f_w_.
//     }
//   }
// }


void BenchmarkNode::depthFilterCb(svo::Point* point, double depth_sigma2)
{
  double depth = (frame_ref_->pos() - point->pos_).norm();
  double depth_pt = depth_ref_.at<float>(point->obs_.front()->px[1],
                                                   point->obs_.front()->px[0]);
  double error = fabs(depth - depth_ref_.at<float>(point->obs_.front()->px[1],
                                                   point->obs_.front()->px[0]));
  //printf("svo depth:%f  ref depth:%f\n", depth, depth_pt);
  results_.push_back(ConvergedSeed(
      point->obs_.front()->px[0], point->obs_.front()->px[1], depth, error));
  errors_.push_back(error);
  delete point->obs_.front();
  delete point;
  ++n_converged_seeds_;
}

void BenchmarkNode::testReconstruction(
    std::string dataset_dir,
    std::string experiment_name)
{
  // vk::FileReader<vk::blender_utils::file_format::ImageNameAndPose> sequence_file_reader(dataset_dir+"/trajectory.txt");
  // std::vector<vk::blender_utils::file_format::ImageNameAndPose> sequence;
  // sequence_file_reader.skipComments();
  // if(!sequence_file_reader.next())
  //   std::runtime_error("Failed to open sequence file");
  // sequence_file_reader.readAllEntries(sequence);
  // std::cout << "RUN EXPERIMENT: read " << sequence.size() << " dataset entries." << std::endl;
  // std::vector<vk::blender_utils::file_format::ImageNameAndPose>::iterator it = sequence.begin();
  vk::Timer t;
  std::list<size_t> n_converged_per_iteration;

  svo::feature_detection::DetectorPtr feature_detector(
      new svo::feature_detection::FastDetector(
          cam_->width(), cam_->height(), svo::Config::gridSize(), svo::Config::nPyrLevels()));
  svo::DepthFilter::callback_t depth_filter_cb = boost::bind(&BenchmarkNode::depthFilterCb, this, _1, _2);
  depth_filter_ = new svo::DepthFilter(feature_detector, depth_filter_cb);
  depth_filter_->options_.verbose = true;


  for(int img_id = 2; img_id < 22; ++img_id)
  {
    // load image
    std::stringstream ss;
    ss << svo::test_utils::getDatasetDir() << "/sin2_tex2_h1_v8_d/img/frame_"
       << std::setw( 6 ) << std::setfill( '0' ) << img_id << "_0.png";
    printf("reading image: '%s'\n", ss.str().c_str());
    cv::Mat img(cv::imread(ss.str().c_str(), 0));
    assert(!img.empty());

    // process frame
    vo_->addImage(img, depth_ref_, 0.01*img_id);

    if(vo_->lastFrame() != NULL){
      std::cout << "Position: " << vo_->lastFrame()->T_f_w_.inverse().translation() << " \t";


      if(img_id == 2)
      {
        // create reference frame and load ground truth depthmap
                // load image
        std::stringstream image_name;
        image_name << std::setw( 6 ) << std::setfill( '0' ) << img_id;
        vk::blender_utils::loadBlenderDepthmap(dataset_dir+"/depth/frame_" + image_name.str().c_str() + "_0.depth", *cam_, depth_ref_);
        printf("current id is %s",image_name.str().c_str());
        frame_ref_ = boost::make_shared<svo::Frame>(cam_, img, depth_ref_, 0.0);
        frame_ref_->T_f_w_ = vo_->lastFrame()->T_f_w_.inverse();
        depth_filter_->addKeyframe(frame_ref_, 2, 0.5);

        
        continue;
      }

      n_converged_seeds_ = 0;
      frame_cur_ = boost::make_shared<svo::Frame>(cam_, img, depth_ref_, 0.0);
      frame_cur_->T_f_w_ = vo_->lastFrame()->T_f_w_.inverse();
      depth_filter_->addFrame(frame_cur_);
      n_converged_per_iteration.push_back(n_converged_seeds_);

    }

  }

  printf("Experiment '%s' took %f ms\n", experiment_name.c_str(), t.stop()*1000);

  // compute mean, median and variance of error in converged area
  {
    printf("# converged:  \t %zu (ref: 287)\n", errors_.size());
    double sum_error = 0;
    std::for_each(errors_.begin(), errors_.end(), [&](double& e){sum_error+=e;});
    printf("mean error:   \t %f cm (ref: 0.080357)\n", sum_error*100/errors_.size());
    std::vector<double>::iterator it = errors_.begin()+0.5*errors_.size();
    std::nth_element(errors_.begin(), it, errors_.end());
    printf("50-percentile: \t %f cm (ref: 0.062042)\n", *it*100);
    it = errors_.begin()+0.8*errors_.size();
    std::nth_element(errors_.begin(), it, errors_.end());
    printf("80-percentile: \t %f cm (ref: 0.124526)\n", *it*100);
    it = errors_.begin()+0.95*errors_.size();
    std::nth_element(errors_.begin(), it, errors_.end());
    printf("95-percentile: \t %f cm (ref: 0.200417)\n", *it*100);
  }

  // trace error
  std::string trace_dir(svo::test_utils::getTraceDir());
  std::string trace_name(trace_dir + "/depth_filter_" + experiment_name + ".txt");
  std::ofstream ofs(trace_name.c_str());
  for(std::list<ConvergedSeed>::iterator i=results_.begin(); i!=results_.end(); ++i)
    ofs << i->x_ << ", " << i->y_ << ", " << fabs(i->error_) << std::endl;
  ofs.close();
  
  // trace convergence rate
  trace_name = trace_dir + "/depth_filter_" + experiment_name + "_convergence.txt";
  ofs.open(trace_name.c_str());
  for(std::list<size_t>::iterator it=n_converged_per_iteration.begin();
      it!=n_converged_per_iteration.end(); ++it)
    ofs << *it << std::endl;
  ofs.close();

  // write ply file for pointcloud visualization in Meshlab
  trace_name = trace_dir + "/depth_filter_" + experiment_name + ".ply";
  ofs.open(trace_name.c_str());
  ofs << "ply" << std::endl
      << "format ascii 1.0" << std::endl
    << "element vertex " << results_.size() << std::endl
    << "property float x" << std::endl
    << "property float y" << std::endl
    << "property float z" << std::endl
    << "property uchar blue" << std::endl
    << "property uchar green" << std::endl
    << "property uchar red" << std::endl
    << "end_header" << std::endl;

  for(std::list<ConvergedSeed>::iterator i=results_.begin(); i!=results_.end(); ++i)
  {
  cv::Vec3b c = frame_ref_->img_pyr_[0].at<cv::Vec3b>(i->y_, i->x_);
  Eigen::Vector3d p = cam_->cam2world(i->x_, i->y_)*i->depth_;
  ofs << p[0] << " " << p[1] << " " << p[2] << " "
      << (int) c[0] << " " << (int) c[1] << " " << (int) c[2] << std::endl;
  }
}

} // namespace svo

int main(int argc, char** argv)
{
  {
    svo::BenchmarkNode benchmark;
    std::string dataset_dir(svo::test_utils::getDatasetDir() + "/sin2_tex2_h1_v8_d");
    std::string experiment_name("sin2_tex2_h1_v8_d");
    benchmark.testReconstruction(dataset_dir, experiment_name);
    return 0;
  }
  printf("BenchmarkNode finished.\n");
  return 0;
}

