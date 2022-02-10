/*
 * Stopper.h
 *
 *  Created on: Nov 23, 2021
 *      Author: sskulka
 */

#ifndef STOPPER_H_
#define STOPPER_H_

#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
class Stopper {
public:
// Tunable parameters
constexpr static double FORWARD_SPEED = 0.5;
constexpr static double MIN_SCAN_ANGLE = -30.0/180*M_PI;
constexpr static double MAX_SCAN_ANGLE = +30.0/180*M_PI;
constexpr static float MIN_DIST_FROM_OBSTACLE = 0.5; // Should be smaller than sensor_msgs::LaserScan::range_max
Stopper();
void startMoving();
private:
ros::NodeHandle node;
ros::Publisher commandPub; // Publisher to the robot's velocity command topic
ros::Subscriber laserSub; // Subscriber to the robot's laser scan topic
bool keepMoving; // Indicates whether the robot should continue moving
void moveForward();
void scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan);
};



#endif /* STOPPER_H_ */
