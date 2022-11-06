#ifndef BEHAIVOR_ENGINE_H
#define BEHAIVOR_ENGINE_H

#include "geometry_msgs/Twist.h"
#include "nav_msgs/Odometry.h"
#include "sensor_msgs/LaserScan.h"
#include <sensor_msgs/Imu.h>
#include <geometry_msgs/Vector3.h>
#include <eigen_conversions/eigen_msg.h>
#include <cv_bridge/cv_bridge.h>

#include <list>
#include <ros/ros.h>
#include <string>
#include <ctime>
#include <chrono>
#include <cmath>



class behaivorEngine 
{
private:
  /// Communicate with nodes
  ros::NodeHandle n;
  
  /// Laser data
  ros::Subscriber laser_sub;
  std::vector<float> laser_range;
  std::string laser_topic;
  
  /// Image Raw
  // ros::Subscriber image_raw;
  // static const std::string IMAGE_TOPIC = "/camera/color/image_raw";
  
  /// Human pose
  ros::Subscriber human_pose;
  std::human_pose_topic;
  std::vector<double> human;
  int hc; // Human count
  std::string hd; // Human detection
  double hx; // Human position on x
  double hy; // Human position on y
  double hz; // Human position on z

  /// Velocity data
  ros::Publisher vel_pub;
  geometry_msgs::Twist vel_msg;
  std::string vel_topic;
  
  /// Odometry data
  ros::Subscriber odom_sub;
  std::string odom_topic;
  float x_pos;
  float y_pos;
  float z_pos;

  void laser_callback(const sensor_msgs::LaserScan::ConstPtr &laser_msg);
  void odom_callback(const nav_msgs::Odometry::ConstPtr &odom_msg);
  void human_detection(const pura_executaion::Human::ConstPtr &human_detect_msg); // rostopic info /human_pose
  
public:
  BehaivorEngine();
  void move();
  void move_forward(int n_secs);
  void move_backwards(int n_secs);
  void turn(string clock, int n_secs);
  void stop_moving();
  float get_position(int param);
  std::list<float> get_position_full();
  double get_time();
  float get_laser(int index);
  float *get_laser_full();
};

#endif
