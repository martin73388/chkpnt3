#include "robot_info_class.cpp"  // Inclure la définition de la classe de base

class AGVRobotInfo : public RobotInfo {
public:
    AGVRobotInfo(ros::NodeHandle& nh) : RobotInfo(nh) {}

    void set_maximum_payload(const std::string& payload) { maximum_payload = payload; }

    void publish_data() override {
        robotinfo_msgs::RobotInfo10Fields msg;
        msg.data_field_01 = "robot_description: " + robot_description;
        msg.data_field_02 = "serial_number: " + serial_number;
        msg.data_field_03 = "ip_address: " + ip_address;
        msg.data_field_04 = "firmware_version: " + firmware_version;
        msg.data_field_05 = "maximum_payload: " + maximum_payload;
        pub_.publish(msg);
    }

private:
    std::string maximum_payload;
};
