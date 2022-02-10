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
    perimeter = 2*pi*(speed/ang_speed)
    current_distance = 0
    
    while not rospy.is_shutdown():

         #Setting the current time for distance calculus
        t0 = rospy.Time.now().to_sec()
        #Loop to move the turtle on a side of square
        while(current_distance < float(perimeter)):

            vel_msg.linear.x = abs(float(speed))
            vel_msg.angular.z = ang_speed
            print("inside distance criterion:"+str(vel_msg.linear.x)+" "+str(vel_msg.angular.z)+" "+str(current_distance)+" "+str(perimeter))
            #Publish the velocity
            velocity_publisher.publish(vel_msg)
            #Takes actual time to velocity calculus
            t1=rospy.Time.now().to_sec()
            #Calculates distancePoseStamped
            current_distance= speed*(t1-t0)
            #After the loop, stops the robot
        vel_msg.linear.x = 0
        vel_msg.angular.z = 0
        #Force the robot to stop
        velocity_publisher.publish(vel_msg)

if __name__ == '__main__':
    try:
        #Testing our function
        move()
    except rospy.ROSInterruptException: pass
