#!/usr/bin/env python
from cmath import pi
import rospy
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose


     
def move():
    
    # Starts a new node
    rospy.init_node('assignment2_ws', anonymous=True)
    velocity_publisher = rospy.Publisher('/turtle1/cmd_vel', Twist, queue_size=10)
    vel_msg = Twist()

    #Receiveing the user's input
    print("Let's move your robot")
    speed = 0.2
    ang_speed = 0.2
    distance = 2
    
    while not rospy.is_shutdown():

        current_distance = 0
        current_angle = 0
        iCounter = 0

        #Loop to move the turtle in square
        while(iCounter < 4) :

             #Setting the current time for distance calculus
            t0 = rospy.Time.now().to_sec()
            #Loop to move the turtle on a side of square
            while(current_distance < float(distance)):

                vel_msg.linear.x = abs(float(speed))
                print("inside distance criterion:")
                #Publish the velocity
                velocity_publisher.publish(vel_msg)
                #Takes actual time to velocity calculus
                t1=rospy.Time.now().to_sec()
                #Calculates distancePoseStamped
                current_distance= speed*(t1-t0)
            #After the loop, stops the robot
            vel_msg.linear.x = 0
            #Force the robot to stop
            velocity_publisher.publish(vel_msg)

            #Loop to rotate the turtle on the edge
            t0 = rospy.Time.now().to_sec()
            while(current_angle < float(pi/2)) :
                vel_msg.angular.z = ang_speed
                #Publish the velocity
                velocity_publisher.publish(vel_msg)

                #Create a subscriber to turtle1/pose topic
                #rospy.Subscriber('/turtle1/pose', Pose, callback)
                #rate = rospy.Rate(10)
                #current_angle = Pose()

                #x = TurtleBot()
                #current_angle.theta = x.pose.theta 

                t2=rospy.Time.now().to_sec()
                current_angle = ang_speed*(t2-t0)

                print("the angle is:" + str(ang_speed*(t2-t0)))

            #After the loop, stops the robot
            vel_msg.angular.z = 0
            #Force the robot to stop
            velocity_publisher.publish(vel_msg)    
            iCounter=iCounter+1
            current_distance = 0
            current_angle = 0
                 

        #serviceAng = rospy.Service("/turtle1/teleport_relative")

if __name__ == '__main__':
    try:
        #Testing our function
        move()
    except rospy.ROSInterruptException: pass