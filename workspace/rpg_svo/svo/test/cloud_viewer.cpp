// #include <pcl/visualization/cloud_viewer.h>
// #include <iostream>
// #include <pcl/io/io.h>
// #include <pcl/io/pcd_io.h>
// #include <vtkCameraActor.h>
    
// int user_data;
    
// void 
// viewerOneOff (pcl::visualization::PCLVisualizer& vie wer)
// {
//     viewer.setBackgroundColor (1.0, 0.5, 1.0);
//     pcl::PointXYZ o;
//     o.x = 1.0;
//     o.y = 0;
//     o.z = 0;
//     viewer.addSphere (o, 0.25, "sphere", 0);
//     std::cout << "i only run once" << std::endl;
    
// }
    
// void 
// viewerPsycho (pcl::visualization::PCLVisualizer& viewer)
// {
//     static unsigned count = 0;
//     std::stringstream ss;
//     ss << "Once per viewer loop: " << count++;
//     viewer.removeShape ("text", 0);
//     viewer.addText (ss.str(), 200, 300, "text", 0);
    
//     //FIXME: possible race condition here:
//     user_data++;
// }

// void ShowFrustum(pcl::visualization::PCLVisualizer& viewer,
//                  const cv::Scalar& color,
//                  const std::string& name,
//                  const Rigid3D<float>& pose,
//                  const ML::CV::Camera<float>& camera) {
//   using namespace ML::Container;
//   using namespace ML::Math::Algebra;
//   using namespace ML::CV;
//   using ML::CV::Frustum;

//   StackMatrixAllocator<typename ML::CV::TranslationMatrix<float>> translation = {
//     pose.translation[0], pose.translation[1], pose.translation[2]};

//   StackMatrixAllocator<typename ML::CV::RotationMatrix<float>> rotation;
//   GetRotationMatrixFromQuaternion(pose.rotation, rotation.matrix);

//   const Frustum<float> frustum = MakeFrustum(rotation.matrix, translation.matrix, camera,
//                                              ML::Frame::kWidth, ML::Frame::kHeight, 0.10f, 0.f);

//   constexpr uint8_t kFrontTopLeft = ML::EnumToIntegral(Frustum<float>::Corners::FrontTopLeft);
//   constexpr uint8_t kBackTopLeft = ML::EnumToIntegral(Frustum<float>::Corners::BackTopLeft);
//   constexpr uint8_t kBackTopRight = ML::EnumToIntegral(Frustum<float>::Corners::BackTopRight);
//   constexpr uint8_t kBackBottomRight = ML::EnumToIntegral(Frustum<float>::Corners::BackBottomRight);
//   constexpr uint8_t kBackBottomLeft = ML::EnumToIntegral(Frustum<float>::Corners::BackBottomLeft);

//   const pcl::PointXYZ origin(frustum.corners_x[kFrontTopLeft], frustum.corners_y[kFrontTopLeft],
//                              frustum.corners_z[kFrontTopLeft]);
//   const pcl::PointXYZ top_left(frustum.corners_x[kBackTopLeft], frustum.corners_y[kBackTopLeft],
//                                frustum.corners_z[kBackTopLeft]);
//   const pcl::PointXYZ top_right(frustum.corners_x[kBackTopRight], frustum.corners_y[kBackTopRight],
//                                 frustum.corners_z[kBackTopRight]);
//   const pcl::PointXYZ bottom_right(frustum.corners_x[kBackBottomRight],
//                                    frustum.corners_y[kBackBottomRight],
//                                    frustum.corners_z[kBackBottomRight]);
//   const pcl::PointXYZ bottom_left(frustum.corners_x[kBackBottomLeft],
//                                   frustum.corners_y[kBackBottomLeft],
//                                   frustum.corners_z[kBackBottomLeft]);

//   viewer.removeShape(name + "origin", 0);
//   viewer.removeShape(name + "origin_top_right", 0);
//   viewer.removeShape(name + "origin_top_left", 0);
//   viewer.removeShape(name + "origin_bottom_right", 0);
//   viewer.removeShape(name + "origin_bottom_left", 0);

//   viewer.removeShape(name + "bottom_right_top_right", 0);
//   viewer.removeShape(name + "bottom_left_top_left", 0);
//   viewer.removeShape(name + "bottom_left_bottom_right", 0);
//   viewer.removeShape(name + "top_left_top_right", 0);

//   viewer.addSphere(origin, 0.025f /*radius*/, color.val[0], color.val[1], color.val[2],
//                    name + "origin", 0);
//   viewer.addLine(origin, top_right, color.val[0], color.val[1], color.val[2],
//                  name + "origin_top_right", 0);
//   viewer.addLine(origin, top_left, color.val[0], color.val[1], color.val[2],
//                  name + "origin_top_left", 0);
//   viewer.addLine(origin, bottom_right, color.val[0], color.val[1], color.val[2],
//                  name + "origin_bottom_right", 0);
//   viewer.addLine(origin, bottom_left, color.val[0], color.val[1], color.val[2],
//                  name + "origin_bottom_left", 0);

//   viewer.addLine(bottom_right, top_right, color.val[0], color.val[1], color.val[2],
//                  name + "bottom_right_top_right", 0);
//   viewer.addLine(bottom_left, top_left, color.val[0], color.val[1], color.val[2],
//                  name + "bottom_left_top_left", 0);
//   viewer.addLine(bottom_left, bottom_right, color.val[0], color.val[1], color.val[2],
//                  name + "bottom_left_bottom_right", 0);
//   viewer.addLine(top_left, top_right, color.val[0], color.val[1], color.val[2],
//                  name + "top_left_top_right", 0);
// }

// void ColorWheel(const double in, uint8_t* r_out, uint8_t* g_out, uint8_t* b_out) {
//   // Compute color
//   uint32_t temp = (uint32_t)std::min(static_cast<int>(in * 1023.0), 1023);
//   // Blue -> Blue+Green -> Green -> Green+Red -> Red
//   *r_out = (uint8_t)(temp < 512 ? 0 : (temp >= 768 ? 255 : temp - 512));
//   *g_out = (uint8_t)(temp < 256 ? temp : (temp >= 768 ? 1023 - temp : 255));
//   *b_out = (uint8_t)(temp < 256 ? 255 : (temp >= 512 ? 0 : 511 - temp));
// }
    
// int 
// main ()
// {
//     pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZRGBA>);
//     pcl::io::loadPCDFile ("my_point_cloud.pcd", *cloud);
    
//     pcl::visualization::CloudViewer viewer("Cloud Viewer");
    
//     //blocks until the cloud is actually rendered
//     viewer.showCloud(cloud);
    
//     //use the following functions to get access to the underlying more advanced/powerful
//     //PCLVisualizer
    
//     //This will only get called once
//     viewer.runOnVisualizationThreadOnce (viewerOneOff);
    
//     // //This will get called once per visualization iteration
//     viewer.runOnVisualizationThread (viewerPsycho);

//     while (!viewer.wasStopped ())
//     {
//     //you can also do cool processing here
//     //FIXME: Note that this is running in a separate thread from viewerPsycho
//     //and you should guard against race conditions yourself...
//     user_data++;
//     }
//     return 0;
// }

#include <vtkSphereSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkSmartPointer.h>
#include <vtkCamera.h>
#include <vtkPlanes.h>
#include <vtkMapper.h>
#include <vtkCameraActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
 
int main(int, char *[])
{
  // // Sphere
  // vtkSmartPointer<vtkSphereSource> sphereSource = 
  //   vtkSmartPointer<vtkSphereSource>::New();
  // sphereSource->SetRadius(400);
  // sphereSource->Update();
 
  // vtkSmartPointer<vtkPolyDataMapper> sphereMapper = 
  //   vtkSmartPointer<vtkPolyDataMapper>::New();
  // sphereMapper->SetInputConnection(sphereSource->GetOutputPort());
  // vtkSmartPointer<vtkActor> sphereActor = 
  //   vtkSmartPointer<vtkActor>::New();
  // sphereActor->SetMapper(sphereMapper);
 
  // Camera
  vtkSmartPointer<vtkCamera> camera = 
    vtkSmartPointer<vtkCamera>::New();
 
  vtkSmartPointer<vtkCameraActor> cameraActor = 
    vtkSmartPointer<vtkCameraActor>::New();
  cameraActor->SetCamera(camera);
  cameraActor->SetWidthByHeightRatio(2);
 
  // (Xmin,Xmax,Ymin,Ymax,Zmin,Zmax).
  double* bounds = new double[6];
  bounds = cameraActor->GetBounds();
  std::cout << "bounds: " << bounds[0] << " " << bounds[1] << " " << bounds[2] << " " << 
      bounds[3] << " " << bounds[4] << " " << bounds[5] << std::endl; 
  
  // Visualize
  vtkSmartPointer<vtkRenderer> renderer = 
    vtkSmartPointer<vtkRenderer>::New();
  vtkSmartPointer<vtkRenderWindow> renderWindow = 
    vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->AddRenderer(renderer);
 
  vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = 
    vtkSmartPointer<vtkRenderWindowInteractor>::New();
  renderWindowInteractor->SetRenderWindow(renderWindow);
 
  renderer->AddActor(cameraActor);
  //renderer->AddActor(sphereActor);
 
  renderer->SetBackground(1,1,1); // Background color white
  renderWindow->Render();
  renderWindowInteractor->Start();
 
 return EXIT_SUCCESS;
}