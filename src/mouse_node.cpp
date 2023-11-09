#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <unistd.h>
#include <fcntl.h>
int main(int argc, char **argv){

    // Initialize the node 
    ros::init(argc, argv, "mouse_node");
    
    // Create a node handle
    ros::NodeHandle n;   

    // Create a publisher for the mouse_node_topic
    ros::Publisher mouse_pub = n.advertise<std_msgs::Int32>("mouse_node_topic", 10); 

    struct DataMsg {
        int loc_x;
        int loc_y;
    }message;

    // Say hello
    ROS_INFO("Node has started!");

    // Way of the file
    char *path = "/dev/input/mouse1";

    // Open the file
    int fd_mouse = open(path, O_RDONLY);

    // Check if there is any error
    if(fd_mouse < 0){
        ROS_ERROR("Error occured while opening the file");
    }

    // Set buffer
    char buffer[3];
    while(ros::ok){
        int bytes = read(fd_mouse, buffer, sizeof(buffer));
        if (bytes > 0){
            // Parse the data
            for(int i = 0; i < 3; i++){
                message.loc_x = buffer[1];
                message.loc_y = buffer[2];
                mouse_pub.publish(message);
            }
        }
    }
    close(fd_mouse);
    return 0;
}