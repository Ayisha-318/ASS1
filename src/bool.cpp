#include "ros/ros.h"                 
#include "std_msgs/Bool.h"           

int main(int argc, char **argv)
{
    ros::init(argc, argv, "int_talker");  

    ros::NodeHandle n;                   

    ros::Publisher pub ;
   pub = n.advertise<std_msgs::Bool>("int_count", 30);  
    ros::Rate loop_rate(10);            
    int count = 20;                       

    while (ros::ok() && count <= 100)
    {
        std_msgs::Bool int_msg;           
        int_msg.data = count;             

        ROS_INFO("%i", int_msg.data);     

        pub.publish(int_msg);     
        ros::spinOnce();                  

        loop_rate.sleep();                
        ++count;
    }

    return 0;
}
