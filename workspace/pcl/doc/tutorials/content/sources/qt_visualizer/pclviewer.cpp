#include "pclviewer.h"
#include "build/ui_pclviewer.h"


PCLViewer::PCLViewer (QWidget *parent) :
  QMainWindow (parent),
  ui (new Ui::PCLViewer)
{
  ui->setupUi (this);
  this->setWindowTitle ("PCL viewer");

  // Setup the cloud pointer
  cloud.reset (new PointCloudT);

    // The number of points in the cloud
  cloud->points.resize (100);

  // The default color
  red   = 128;
  green = 128;
  blue  = 128;
  i = 0;
  // Set up the QVTK window
  viewer.reset (new pcl::visualization::PCLVisualizer ("viewer", false));

  // Initalize the camera
  cameraActor = vtkSmartPointer<vtkCameraActor>::New();
// Camera
  camera = vtkSmartPointer<vtkCamera>::New();
    // Visualize
  renderer = vtkSmartPointer<vtkRenderer>::New();
  renderWindow = vtkSmartPointer<vtkRenderWindow>::New();

  viewer->setCameraPosition(89.0192,15,0,108.72,-89.5459,-269.425,0.0527582,0.943426,-0.32736);
  viewer->setCameraFieldOfView(0.523599);
  viewer->setCameraClipDistances(225.417,508.059);
  viewer->setPosition(687,377);
  viewer->setSize(640,480);




    // ui->qvtkWidget->SetRenderWindow (viewer->getRenderWindow ());

    // viewer->setupInteractor (ui->qvtkWidget->GetInteractor (), ui->qvtkWidget->GetRenderWindow ());
    // ui->qvtkWidget->update ();

    // Connect "random" button and the function
    connect (ui->pushButton_random,  SIGNAL (clicked ()), this, SLOT (randomButtonPressed ()));

    // // // Connect R,G,B sliders and their functions
    // // connect (ui->horizontalSlider_R, SIGNAL (valueChanged (int)), this, SLOT (redSliderValueChanged (int)));
    // // connect (ui->horizontalSlider_G, SIGNAL (valueChanged (int)), this, SLOT (greenSliderValueChanged (int)));
    // // connect (ui->horizontalSlider_B, SIGNAL (valueChanged (int)), this, SLOT (blueSliderValueChanged (int)));
    // // connect (ui->horizontalSlider_R, SIGNAL (sliderReleased ()), this, SLOT (RGBsliderReleased ()));
    // // connect (ui->horizontalSlider_G, SIGNAL (sliderReleased ()), this, SLOT (RGBsliderReleased ()));
    // // connect (ui->horizontalSlider_B, SIGNAL (sliderReleased ()), this, SLOT (RGBsliderReleased ()));

    // // // Connect point size slider
    // // connect (ui->horizontalSlider_p, SIGNAL (valueChanged (int)), this, SLOT (pSliderValueChanged (int)));

    // viewer->addPointCloud (cloud, "cloud");
    // //pSliderValueChanged (2);
    // viewer->resetCamera ();
    // ui->qvtkWidget->update ();




}

void
PCLViewer::randomButtonPressed ()
{
  printf ("Random button was pressed\n");

  // // Set the new color
  // for (size_t i = 0; i < cloud->size(); i++)
  // {
  //   cloud->points[i].r = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
  //   cloud->points[i].g = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
  //   cloud->points[i].b = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
  // }

    i++;

    viewer->removePointCloud ("cloud");
    viewer->getRenderWindow()->GetRenderers()->GetFirstRenderer()->RemoveActor(cameraActor);
    cloud->points[i].x = i*10;
    cloud->points[i].y = 0;
    cloud->points[i].z = 0;

    cloud->points[i].r = red;
    cloud->points[i].g = green;
    cloud->points[i].b = blue;

    camera->SetPosition(i*10, 0, 0);
    camera->SetFocalPoint(0, 0, 0);
    camera->Pitch(90*i);
    //camera->Zoom(0.3);
    camera->SetClippingRange(0.1,30);
    cameraActor->SetCamera(camera);
    cameraActor->SetWidthByHeightRatio(1);

    // (Xmin,Xmax,Ymin,Ymax,Zmin,Zmax).
    double* bounds = new double[6];
    bounds = cameraActor->GetBounds();
    std::cout << "bounds: " << bounds[0] << " " << bounds[1] << " " << bounds[2] << " " << 
        bounds[3] << " " << bounds[4] << " " << bounds[5] << std::endl; 

    viewer->getRenderWindow()->GetRenderers()->GetFirstRenderer()->AddActor(cameraActor);
    
    ui->qvtkWidget->SetRenderWindow (viewer->getRenderWindow ());

    viewer->setupInteractor (ui->qvtkWidget->GetInteractor (), ui->qvtkWidget->GetRenderWindow ());
    ui->qvtkWidget->update ();

    // // Connect "random" button and the function
    // connect (ui->pushButton_random,  SIGNAL (clicked ()), this, SLOT (randomButtonPressed ()));

    // // Connect point size slider
    // connect (ui->horizontalSlider_p, SIGNAL (valueChanged (int)), this, SLOT (pSliderValueChanged (int)));

    viewer->addPointCloud (cloud, "cloud");

    //pSliderValueChanged (2);
    //ewer->resetCamera ();
    ui->qvtkWidget->update ();

  

  viewer->updatePointCloud (cloud, "cloud");
  ui->qvtkWidget->update ();
}


PCLViewer::~PCLViewer ()
{
  delete ui;
}
