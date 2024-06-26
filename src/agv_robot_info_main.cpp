#include "agv_robot_info_class.cpp"  // Inclure la définition de la classe dérivée
#include <ros/ros.h>

int main(int argc, char** argv) {
    ros::init(argc, argv, "agv_robot_info_node");
    ros::NodeHandle nh;

    AGVRobotInfo agv_robot_info(nh);
    agv_robot_info.set_robot_description("Mir100");
    agv_robot_info.set_serial_number("567A359");
    agv_robot_info.set_ip_address("169.254.5.180");
    agv_robot_info.set_firmware_version("3.5.8");
    agv_robot_info.set_maximum_payload("100 Kg");

    // Définir les valeurs pour le moniteur hydraulique
    agv_robot_info.set_hydraulic_oil_temperature("45C");
    agv_robot_info.set_hydraulic_oil_tank_fill_level("100%");
    agv_robot_info.set_hydraulic_oil_pressure("250 bar");


    ros::Rate loop_rate(1);  // Fréquence de publication : 1 Hz
    while (ros::ok()) {
        agv_robot_info.publish_data();
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
