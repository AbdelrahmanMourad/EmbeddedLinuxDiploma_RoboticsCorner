#ifndef VEHICLE_DIAGNOSTIC_SYSTEM_HH
#define VEHICLE_DIAGNOSTIC_SYSTEM_HH

#include <iostream>
#include <vector>
#include <algorithm>

// ___________________ Sensor Class ____________________________
class SensorData_t
{
private:
    float Temperature_;
    float RPM_;
    float Voltage_;

public:
    // Constructors & Destructor.
    SensorData_t() /*Delegate*/ : SensorData_t(0, 0, 0) { std::cout << "SensorData Default constructor is Called.\n"; }
    SensorData_t(float T) /*Delegate*/ : SensorData_t{T, 0, 0} { std::cout << "SensorData 2-parameters constructor is Called.\n"; }
    SensorData_t(float T, float R) /*Delegate*/ : SensorData_t{T, R, 0} { std::cout << "SensorData 2-parameters constructor is Called.\n"; }
    SensorData_t(float T, float R, float V) : Temperature_{T}, RPM_{R}, Voltage_{V} { std::cout << "Parameterized Constructor is Called.\n"; }
    ~SensorData_t() { std::cout << "SensorData Destructor is Called"; }
    // Copy Constructor
    SensorData_t(const SensorData_t &other) : Temperature_{other.Temperature_}, RPM_{other.RPM_}, Voltage_{other.Voltage_} { std::cout << "SensorData Copy Constructor Called.\n"; }
    // // Move Constructor (Transfer Ownership if Dynamically Allocated).
    // SensorData_t(SensorData_t &&other) noexcept;

    // Setters
    void setTemperature(float input) { Temperature_ = input; }
    void setRPM(float input) { RPM_ = input; }
    void setVoltage(float input) { Voltage_ = input; }

    // Getters
    float getTemperature() const { return Temperature_; }
    float getRPM() const { return RPM_; }
    float getVoltage() const { return Voltage_; }

    // Utility Methods.
    void display() const
    {
        std::cout << "Temperature: " << Temperature_ << " C, "
                  << "RPM: " << RPM_ << ", "
                  << "Voltage: " << Voltage_ << "V\n";
    }
};

// ___________________ Vehicle Diagnostic System Class ____________________________
class VehicleDiagnosticSystem_t
{
private:
    std::vector<SensorData_t> AllSensorsData_;

public:
    // Constructors & Destructor
    VehicleDiagnosticSystem_t() = default;
    ~VehicleDiagnosticSystem_t() = default;

    // Methods
    void DisplayAll() const;
    void DisplayOne(int index) const;
    void AddSensor(const SensorData_t &sensor);
    void RemoveSensor(int index);

    // Data Processing Methods
    void RemoveInvalidSensors();
    void ScaleSensorVoltage(float factor);
};

#endif // VEHICLE_DIAGNOSTIC_SYSTEM_HH
