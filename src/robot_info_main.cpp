#include "robot_info_class.cpp"  // Inclure la définition de la classe
#include <ros/ros.h>

int main(int argc, char** argv) {
    ros::init(argc, argv, "robot_info_node");
    ros::NodeHandle nh;

    RobotInfo robot_info(nh);
    robot_info.set_robot_description("Mir100");
    robot_info.set_serial_number("567A359");
    robot_info.set_ip_address("169.254.5.180");
    robot_info.set_firmware_version("3.5.8");

    ros::Rate loop_rate(1);  // Fréquence de publication : 1 Hz
    while (ros::ok()) {
        robot_info.publish_data();
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
