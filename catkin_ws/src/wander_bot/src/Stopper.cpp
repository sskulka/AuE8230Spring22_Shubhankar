/*
 * Stopper.cpp
 *
 *  Created on: Oct 27, 2016
 *      Author: viki
 */

#include "Stopper.h"
#include "geometry_msgs/Twist.h"

Stopper::Stopper()
{
    keepMoving = true;

    // Advertise a new publisher for the robot's velocity command topic
    commandPub = node.advertise<geometry_msgs::Twist>("/cmd_vel", 10);

    // Subscribe to the simulated robot's laser scan topic
    laserSub = node.subscribe("scan", 1, &Stopper::scanCallback, this);
}

// Send a velocity command
void Stopper::moveForward(bool& keepMoving) {
	if(keepMoving){
		geometry_msgs::Twist msg; // The default constructor will set all commands to 0
		msg.linear.x = FORWARD_SPEED;
		commandPub.publish(msg);
	}
	else{
		geometry_msgs::Twist msg; // The default constructor will set all commands to 0
		msg.linear.x = 0;
		//commandPub.publish(msg);
		//change the angular velocity till the robot is
		msg.angular.z = 0.3;
		commandPub.publish(msg);
	}
}

// Process the incoming laser scan message
void Stopper::scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan)
{
	bool isObstacleInFront = false;

    // Find the closest range between the defined minimum and maximum angles
    int minIndex = ceil((MIN_SCAN_ANGLE - scan->angle_min) / scan->angle_increment);
    int maxIndex = floor((MAX_SCAN_ANGLE - scan->angle_min) / scan->angle_increment);

    geometry_msgs::Twist msg; 
    for (int currIndex = minIndex + 1; currIndex <= maxIndex; currIndex++) {
        if (scan->ranges[currIndex] < MIN_DIST_FROM_OBSTACLE )
        {
        	isObstacleInFront = true;
            break;
        }
        
    }

    if (isObstacleInFront) {
        	//ros::Rate rate(10);
            ROS_INFO("Going in if. Stop!");
            keepMoving = false;
            msg.linear.x = 0;
            //commandPub.publish(msg);
                            
            //change the angular velocity till the robot is
            msg.angular.z = 0.3;
            commandPub.publish(msg);
            //ros::spinOnce(); // Need to call this function often to allow ROS to process incoming messages
            //rate.sleep();
            
        }
        else{
        	ROS_INFO("Going in else. GO!");
        	keepMoving = true;
        	msg.angular.z = 0;
        	msg.linear.x = FORWARD_SPEED;
            commandPub.publish(msg);
        }
}

void Stopper::startMoving()
{
    ros::Rate rate(10);
    ROS_INFO("Start moving");

    // Keep spinning loop until user presses Ctrl+C or the robot got too close to an obstacle
    while (ros::ok()) {
        moveForward(keepMoving);
        ros::spinOnce(); // Need to call this function often to allow ROS to process incoming messages
        rate.sleep();
    }
    ROS_INFO("The robot should stop!");
    //geometry_msgs::Twist msg; // The default constructor will set all commands to 0
    //msg.linear.x = 0;
    //commandPub.publish(msg);
                
   	   //change the angular velocity till the robot is
    //while(!keepMoving) {
    //	msg.angular.z = 0.3;
    //    commandPub.publish(msg);
    //}
}


