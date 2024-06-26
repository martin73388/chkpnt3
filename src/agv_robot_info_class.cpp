#include "robot_info_class.cpp"  // Inclure la définition de la classe de base
#include "hydraulic_system_monitor.cpp"  // Inclure la définition de la classe HydraulicSystemMonitor

class AGVRobotInfo : public RobotInfo {
public:
    AGVRobotInfo(ros::NodeHandle& nh) : RobotInfo(nh), hydraulic_monitor_() {}

    void set_maximum_payload(const std::string& payload) { maximum_payload_ = payload; }

    void set_hydraulic_oil_temperature(const std::string& temp) { hydraulic_monitor_.set_hydraulic_oil_temperature(temp); }
    void set_hydraulic_oil_tank_fill_level(const std::string& level) { hydraulic_monitor_.set_hydraulic_oil_tank_fill_level(level); }
    void set_hydraulic_oil_pressure(const std::string& pressure) { hydraulic_monitor_.set_hydraulic_oil_pressure(pressure); }

    void publish_data() override {
        robotinfo_msgs::RobotInfo10Fields msg;
        msg.data_field_01 = "robot_description: " + robot_description;
        msg.data_field_02 = "serial_number: " + serial_number;
        msg.data_field_03 = "ip_address: " + ip_address;
        msg.data_field_04 = "firmware_version: " + firmware_version;
        msg.data_field_05 = "maximum_payload: " + maximum_payload_;

        // Récupérer les données hydrauliques sous forme de structure
        HydraulicData data = hydraulic_monitor_.get_all_hydraulic_data();
        msg.data_field_06 = "hydraulic_oil_temperature: " + data.hydraulic_oil_temperature;
        msg.data_field_07 = "hydraulic_oil_tank_fill_level: " + data.hydraulic_oil_tank_fill_level;
        msg.data_field_08 = "hydraulic_oil_pressure: " + data.hydraulic_oil_pressure;

        pub_.publish(msg);
    }

private:
    std::string maximum_payload_;
    HydraulicSystemMonitor hydraulic_monitor_;  // Composition: l'objet HydraulicSystemMonitor
};
