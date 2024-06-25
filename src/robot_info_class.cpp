#include <ros/ros.h>
#include <string>
#include <robotinfo_msgs/RobotInfo10Fields.h>  // Utilisation du message personnalisé

class RobotInfo {
public:
    RobotInfo(ros::NodeHandle& nh) : nh_(nh) {
        // Initialiser le publisher
        pub_ = nh_.advertise<robotinfo_msgs::RobotInfo10Fields>("robot_info", 10);
    }

    virtual ~RobotInfo() = default;

    virtual void publish_data() {
        robotinfo_msgs::RobotInfo10Fields msg;
        msg.data_field_01 = "robot_description: " + robot_description;
        msg.data_field_02 = "serial_number: " + serial_number;
        msg.data_field_03 = "ip_address: " + ip_address;
        msg.data_field_04 = "firmware_version: " + firmware_version;
        pub_.publish(msg);
    }

    void set_robot_description(const std::string& desc) { robot_description = desc; }
    void set_serial_number(const std::string& serial) { serial_number = serial; }
    void set_ip_address(const std::string& ip) { ip_address = ip; }
    void set_firmware_version(const std::string& firmware) { firmware_version = firmware; }

protected:
    ros::NodeHandle nh_;
    ros::Publisher pub_;
    std::string robot_description;
    std::string serial_number;
    std::string ip_address;
    std::string firmware_version;
};
