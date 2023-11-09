## Description 
The purpose of this ROS package, "mouse_node," is to broadcast mouse movement data to a ROS topic and receive mouse input from the /dev/input/mouse0 device. It is a straightforward illustration of how to build a ROS node that processes input data and publishes it to a topic.

## Usage
Clone this repository to your catkin workspace
Build the package with catkin_make
Run the node with rosrun mouse_node mouse_node
Subscribe to the topic mouse_node_topic to get the location data as std_msgs/Int32 messages