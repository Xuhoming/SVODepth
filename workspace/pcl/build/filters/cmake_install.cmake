# Install script for directory: /home/cwu/Experiment/SVO/workspace/pcl/filters

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_filters")
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpcl_filters.so.1.8.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpcl_filters.so.1.8"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpcl_filters.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "/usr/local/lib")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/cwu/Experiment/SVO/workspace/pcl/build/lib/libpcl_filters.so.1.8.0"
    "/home/cwu/Experiment/SVO/workspace/pcl/build/lib/libpcl_filters.so.1.8"
    "/home/cwu/Experiment/SVO/workspace/pcl/build/lib/libpcl_filters.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpcl_filters.so.1.8.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpcl_filters.so.1.8"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpcl_filters.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "/home/cwu/Experiment/SVO/workspace/pcl/build/lib:"
           NEW_RPATH "/usr/local/lib")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_filters")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/cwu/Experiment/SVO/workspace/pcl/build/filters/pcl_filters-1.8.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_filters")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/pcl-1.8/pcl/filters" TYPE FILE FILES
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/boost.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/conditional_removal.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/crop_box.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/clipper3D.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/plane_clipper3D.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/box_clipper3D.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/crop_hull.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/extract_indices.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/filter.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/filter_indices.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/passthrough.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/shadowpoints.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/project_inliers.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/radius_outlier_removal.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/random_sample.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/normal_space.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/sampling_surface_normal.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/statistical_outlier_removal.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/voxel_grid.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/approximate_voxel_grid.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/bilateral.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/fast_bilateral.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/fast_bilateral_omp.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/voxel_grid_covariance.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/convolution.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/convolution_3d.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/voxel_grid_label.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/voxel_grid_occlusion_estimation.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/frustum_culling.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/covariance_sampling.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/median_filter.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/uniform_sampling.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/normal_refinement.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/grid_minimum.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/morphological_filter.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/local_maximum.h"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/model_outlier_removal.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_filters")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/pcl-1.8/pcl/filters/impl" TYPE FILE FILES
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/impl/conditional_removal.hpp"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/impl/crop_box.hpp"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/impl/crop_hull.hpp"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/impl/plane_clipper3D.hpp"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/impl/box_clipper3D.hpp"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/impl/extract_indices.hpp"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/impl/filter.hpp"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/impl/filter_indices.hpp"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/impl/passthrough.hpp"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/impl/shadowpoints.hpp"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/impl/project_inliers.hpp"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/impl/radius_outlier_removal.hpp"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/impl/random_sample.hpp"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/impl/normal_space.hpp"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/impl/sampling_surface_normal.hpp"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/impl/statistical_outlier_removal.hpp"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/impl/voxel_grid.hpp"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/impl/approximate_voxel_grid.hpp"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/impl/bilateral.hpp"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/impl/fast_bilateral.hpp"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/impl/fast_bilateral_omp.hpp"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/impl/voxel_grid_covariance.hpp"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/impl/convolution.hpp"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/impl/convolution_3d.hpp"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/impl/voxel_grid_occlusion_estimation.hpp"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/impl/frustum_culling.hpp"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/impl/covariance_sampling.hpp"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/impl/median_filter.hpp"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/impl/uniform_sampling.hpp"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/impl/normal_refinement.hpp"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/impl/grid_minimum.hpp"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/impl/morphological_filter.hpp"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/impl/local_maximum.hpp"
    "/home/cwu/Experiment/SVO/workspace/pcl/filters/include/pcl/filters/impl/model_outlier_removal.hpp"
    )
endif()

