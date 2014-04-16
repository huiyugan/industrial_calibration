/*
 * Software License Agreement (Apache License)
 *
 * Copyright (c) 2014, Southwest Research Institute
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include <industrial_extrinsic_cal/camera_definition.h>

namespace industrial_extrinsic_cal
{

using std::string;
using boost::shared_ptr;
using ceres::CostFunction;
Camera::Camera()
{
  camera_name_ = "NONE";
  is_moving_ = false;
}

Camera::Camera(string name, CameraParameters camera_parameters, bool is_moving) :
    camera_name_(name), camera_parameters_(camera_parameters), is_moving_(is_moving),
    fixed_intrinsics_(true), fixed_extrinsics_(false)
{
}

Camera::~Camera()
{
}

bool Camera::isMoving()
{
  return (is_moving_);
}
void Camera::push_transform()
{
  Pose6d pose;
  pose.set_angle_axis(camera_parameters_.angle_axis[0], camera_parameters_.angle_axis[1], camera_parameters_.angle_axis[2]);
  pose.set_origin(camera_parameters_.position[0], camera_parameters_.position[1], camera_parameters_.position[2]);
  transform_interface_->push_transform(pose);
}
void Camera::pull_transform()
{
  Pose6d pose = transform_interface_->pull_transform();
  camera_parameters_.angle_axis[0] = pose.ax;
  camera_parameters_.angle_axis[1] = pose.ay;
  camera_parameters_.angle_axis[2] = pose.az;
  camera_parameters_.position[0]    = pose.x;
  camera_parameters_.position[1]    = pose.y;
  camera_parameters_.position[2]    = pose.z;
}
void Camera::set_transform_interface(boost::shared_ptr<TransformInterface> transform_interface)
{
  transform_interface_ = transform_interface;
}
boost::shared_ptr<TransformInterface> Camera::get_transform_interface()
{
  return(transform_interface_);
}
}//end namespace industrial_extrinsic_cal



