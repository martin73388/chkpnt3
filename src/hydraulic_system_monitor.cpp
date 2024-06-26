#include <string>

// Déclaration de la structure pour contenir toutes les valeurs hydrauliques
struct HydraulicData {
    std::string hydraulic_oil_temperature;
    std::string hydraulic_oil_tank_fill_level;
    std::string hydraulic_oil_pressure;
};

class HydraulicSystemMonitor {
public:
    HydraulicSystemMonitor() = default;

    // Méthodes pour définir les valeurs des attributs
    void set_hydraulic_oil_temperature(const std::string& temp) { hydraulic_oil_temperature_ = temp; }
    void set_hydraulic_oil_tank_fill_level(const std::string& level) { hydraulic_oil_tank_fill_level_ = level; }
    void set_hydraulic_oil_pressure(const std::string& pressure) { hydraulic_oil_pressure_ = pressure; }

    // Méthodes pour obtenir les valeurs des attributs individuellement
    std::string get_hydraulic_oil_temperature() const { return hydraulic_oil_temperature_; }
    std::string get_hydraulic_oil_tank_fill_level() const { return hydraulic_oil_tank_fill_level_; }
    std::string get_hydraulic_oil_pressure() const { return hydraulic_oil_pressure_; }

    // Méthode pour obtenir toutes les valeurs des attributs sous forme d'une structure
    HydraulicData get_all_hydraulic_data() const {
        return {hydraulic_oil_temperature_, hydraulic_oil_tank_fill_level_, hydraulic_oil_pressure_};
    }

private:
    // Attributs pour stocker les valeurs des paramètres hydrauliques
    std::string hydraulic_oil_temperature_;
    std::string hydraulic_oil_tank_fill_level_;
    std::string hydraulic_oil_pressure_;
};
