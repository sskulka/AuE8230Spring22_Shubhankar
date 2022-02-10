Hello,

My name is Shubhankar Kulkarni, a student concentrating in vehicle autonomy at CU-ICAR, Clemson University.
This repository is targeted to store codes created primarily for ROS-based Applications for AuE823. 

Assignment2: 

package assignment2_ws in /catkin_ws/src contains the codes.

source files-
Circle: ~/catkin_ws/src/assignment2_ws/src/scripts/circle.py
Open-loop Square: ~/catkin_ws/src/assignment2_ws/src/scripts/square_openloop_2.py
Closed-loop Square: ~/catkin_ws/src/assignment2_ws/src/scripts/square_closedloop.py

videos-
circle.webm, square_closedloop.webm, square_openloop.webm

Deploying codes-

1.  chmod u+x ~/catkin_ws/src/assignment2_ws/src/scripts/$code$.py
2.  Download catkin_ws
3.  In Terminal, cd ~/catkin_ws 
4.  catkin_make
5.  In Terminal, $ roscore
6.  In new Terminal, $ rosrun turtlesim turtlesim_node
7.  In new Terminal, $ rosrun assignment2_ws $code$.py
