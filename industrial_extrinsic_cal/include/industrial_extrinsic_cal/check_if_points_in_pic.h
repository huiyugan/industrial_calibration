/*
    Software License Agreement (Apache License)
    Copyright (c) 2014, Southwest Research Institute
    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/
#ifndef check_if_points_in_pic_h_
#define check_if_points_in_pic_h_

#include <iostream>
#include "tf/transform_datatypes.h"
#include <industrial_extrinsic_cal/ros_transform_interface.h>
#include <Eigen/Eigen>





class make_main_smaller
{
public:
  std::string from_frame_param;
  std::string to_frame_param;
  void create_rviz_target(Eigen::Vector3d corner_points[4], geometry_msgs::PoseArray& msg);
  void create_transform_listener(tf::StampedTransform& tf_transform, tf::TransformListener& tf_listen);
  make_main_smaller();
private:
};
#endif
