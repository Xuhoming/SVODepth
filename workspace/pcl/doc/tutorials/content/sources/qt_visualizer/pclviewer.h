#ifndef PCLVIEWER_H
#define PCLVIEWER_H

#include <iostream>

// Qt
#include <QMainWindow>

// Point Cloud Library
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>


// Visualization Toolkit (VTK)
#include <vtkRenderWindow.h>
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

typedef pcl::PointXYZRGBA PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

namespace Ui
{
  class PCLViewer;
}

class PCLViewer : public QMainWindow
{
  Q_OBJECT

public:
  explicit PCLViewer (QWidget *parent = 0);
  ~PCLViewer ();

public slots:
  void
  randomButtonPressed ();

  // void
  // RGBsliderReleased ();

  // void
  // pSliderValueChanged (int value);

  // void
  // redSliderValueChanged (int value);

  // void
  // greenSliderValueChanged (int value);

  // void
  // blueSliderValueChanged (int value);

protected:
  boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
  PointCloudT::Ptr cloud;
    // Initalize the camera
  vtkSmartPointer<vtkCameraActor> cameraActor;
// Camera
  vtkSmartPointer<vtkCamera> camera;
    // Visualize
  vtkSmartPointer<vtkRenderer> renderer;
  vtkSmartPointer<vtkRenderWindow> renderWindow;

  unsigned int red;
  unsigned int green;
  unsigned int blue;
  size_t i;
private:
  Ui::PCLViewer *ui;

};

#endif // PCLVIEWER_H
