#include "T3.1_VehicleDiagnosticSystem.h"

// ___________________ SensorData Implementation ____________________________
// No Need.

// ___________________ VehicleDiagnosticSystem Implementation ____________________________

// Using Lambda for printing sensor data using "for_each"
void VehicleDiagnosticSystem_t::DisplayAll() const
{
    std::cout << "--- All Sensor Readings ---\n";
    std::for_each(AllSensorsData_.begin(), AllSensorsData_.end(), [](const SensorData_t &sensor)
                  { sensor.display(); });
}

// Using Lambda for printing a single sensor data using capture
void VehicleDiagnosticSystem_t::DisplayOne(int index) const
{
    if (index >= 0 && index < AllSensorsData_.size())
    {
        // Define lambda Expression "printSensor", and Use it.
        auto printSensor = [index, this]()
        {
            AllSensorsData_[index].display();
        };
        // Calls the lambda
        printSensor();
    }
    else
    {
        std::cout << "Invalid sensor index.\n";
    }
}

/// @brief Add new sesnor and print the index size now.
/// @param sensor
void VehicleDiagnosticSystem_t::AddSensor(const SensorData_t &sensor)
{
    AllSensorsData_.push_back(sensor);
    std::cout << "Sensor Added. Its index is: " << AllSensorsData_.size() << " \n";
}

// Remove Invalid Sensor Values (Negative & Extreme Readings) using "remove_if" & "Lambda"
void VehicleDiagnosticSystem_t::RemoveInvalidSensors()
{
    AllSensorsData_.erase(std::remove_if(AllSensorsData_.begin(), AllSensorsData_.end(), [](const SensorData_t &sensor)
                                         { return sensor.getTemperature() < 0 
                                                || sensor.getRPM() < 0 
                                                || sensor.getVoltage() < 0 
                                                || sensor.getTemperature() > 100.0 
                                                || sensor.getVoltage() > 24.0; }),AllSensorsData_.end());

    std::cout << "Invalid sensors removed.\n";
}

// Scale Voltage Readings using "std::transform" & "Lambda"
void VehicleDiagnosticSystem_t::ScaleSensorVoltage(float factor)
{
    std::transform(AllSensorsData_.begin(), AllSensorsData_.end(), AllSensorsData_.begin(), [factor](SensorData_t &sensor)
                   {
        sensor.setVoltage(sensor.getVoltage() * factor);
        return sensor; });

    std::cout << "Sensor voltage scaled by factor: " << factor << "\n";
}
