#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "publisher_node_turtle_forwardcp");
    ros::NodeHandle n;

    ros::Publisher pub ;
    pub = n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 50);
    ros::Rate loop_rate(10);

    geometry_msgs::Twist msg;

    while (ros::ok())
    {
        msg.linear.x = 0.5;
        pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
