/** ______________________________________________________________________________________________

    🧠 Task 04: Automotive Diagnostic and Logging System:
    ------------------------------------------------------

    You are to build a C++ program that simulates a simple "automotive diagnostic system"
        that supports multiple sensor types and handles runtime errors.

    ✅ Requirements
        1.  Inheritance and Virtual Functions
            •   Create a base class "Sensor" with a virtual function "readValue()".
            •   Create at least 2 derived classes (e.g., TemperatureSensor, RPMCounter) that override "readValue()".
        2.  Polymorphism
            •   Store a list of "Sensor*" and iterate over them using dynamic dispatch to read values.
            •   Demonstrate static vs dynamic type behavior.
        3.  Virtual Destructors
            •   Make sure base class has a virtual destructor to manage cleanup safely.
        4.  Custom Exception Handling
            •   Define a "SensorException" class inheriting from "std::exception".
            •   Throw this exception from any sensor if the value is invalid (e.g., sensor failure or unrealistic value).
            •   Catch the exception using:
                ○   Specific catch.
                ○   Catch-all handler.
                ○   "std::exception" mechanism.
        5.  Exception Safety
            •   Implement an exception-safe sensor update function using "copy-and-swap idiom" or "noexcept" and demonstrate proper error safety.


    📝 Submission Checklist
        •   ".cpp" file with proper class design and error handling.
        •   Output sample or screenshots (in comments or separate doc).
        •   Code must include comments for clarity.
        •   Follow naming conventions and modular design.


    Sample Output:
        Static type: Sensor*, Dynamic type: TemperatureSensor
            TemperatureSensor value: 90
        Static type: Sensor*, Dynamic type: RPMCounter
            RPMCounter value: 3000
        Static type: Sensor*, Dynamic type: TemperatureSensor
            [SensorException caught] TemperatureSensor: Value out of range!
        Static type: Sensor*, Dynamic type: RPMCounter
            [SensorException caught] RPMCounter: Value out of range!
        Before update: 25
        After update: 30

    ○•
    ______________________________________________________________________________________________
**/

/*  =====================================================================================
                                Included Libraries
    =====================================================================================   */
#include <iostream>  // For input/output
#include <vector>    // For std::vector
#include <memory>    // For std::unique_ptr
#include <exception> // For std::exception
#include <string>    // For std::string
#include <algorithm> // For std::swap

/*  =====================================================================================
                                Prototypes/ Declarations
    =====================================================================================   */

// ===================== Custom exception class for sensor errors =====================
class SensorException : public std::exception
{
    std::string message; // Store error message
public:
    // Constructor to set the error message
    SensorException(const std::string &msg);
    // Override what() to return the error message
    const char *what() const noexcept override;
};

// ===================== Base class for all sensors =====================
class Sensor
{
public:
    // Virtual destructor for safe cleanup of derived classes
    virtual ~Sensor();
    // Virtual function to read the sensor value
    virtual double readValue() const = 0; // Pure virtual: must be overridden
    // Virtual function to get sensor name/type
    virtual std::string getName() const = 0;
};

// ===================== Derived class: Temperature sensor =====================
class TemperatureSensor : public Sensor
{
    double temperature; // Store the temperature value
public:
    // Constructor to set initial temperature
    TemperatureSensor(double temp) : temperature(temp) {}
    // Override readValue to return temperature, throw exception if unrealistic
    double readValue() const override;
    // Override getName
    std::string getName() const override;
    // Exception-safe update using copy-and-swap idiom
    void update(double newTemp) noexcept;
};

// ===================== Derived class: RPM counter =====================
class RPMCounter : public Sensor
{
    int rpm; // Store the RPM value
public:
    // Constructor to set initial RPM
    RPMCounter(int r) : rpm(r) {}
    // Override readValue to return RPM, throw exception if unrealistic
    double readValue() const override;
    // Override getName
    std::string getName() const override;
    // Exception-safe update using copy-and-swap idiom
    void update(int newRpm) noexcept;
};

// ===================== Helping Functions =====================
// Function to demonstrate static vs dynamic type behavior
void staticVsDynamicDemo(Sensor *sensor);

/*  =====================================================================================
                                Entry Point
    =====================================================================================   */
int main()
{
    // Create a list of sensors using smart pointers for automatic memory management
    std::vector<std::unique_ptr<Sensor>> sensors;
    sensors.push_back(std::make_unique<TemperatureSensor>(90.0));   // Valid temperature
    sensors.push_back(std::make_unique<RPMCounter>(3000));          // Valid RPM
    sensors.push_back(std::make_unique<TemperatureSensor>(-100.0)); // Invalid temperature (will throw)
    sensors.push_back(std::make_unique<RPMCounter>(12000));         // Invalid RPM (will throw)

    // Iterate over sensors and read their values using dynamic dispatch (polymorphism)
    for (const auto &sensorPtr : sensors)
    {
        try
        {
            // Demonstrate static vs dynamic type
            staticVsDynamicDemo(sensorPtr.get());

            // Try to read the sensor value (may throw)
            double value = sensorPtr->readValue();
            std::cout << sensorPtr->getName() << " value: " << value << std::endl;
        }
        catch (const SensorException &ex)
        { // Specific catch for SensorException
            std::cout << "[SensorException caught] " << ex.what() << std::endl;
        }
        catch (const std::exception &ex)
        { // Catch other std::exception types
            std::cout << "[std::exception caught] " << ex.what() << std::endl;
        }
        catch (...)
        { // Catch-all handler for any other exceptions
            std::cout << "[Unknown exception caught]\n";
        }
    }

    // Demonstrate exception-safe update
    TemperatureSensor tempSensor(25.0);
    std::cout << "\nBefore update: " << tempSensor.readValue() << std::endl;
    tempSensor.update(30.0); // Safe update
    std::cout << "After update: " << tempSensor.readValue() << std::endl;

    // Uncomment to see exception safety in action (will throw if value is out of range)
    // tempSensor.update(300.0); // Out of range, but update is noexcept and safe

    return 0; // Program ends, smart pointers clean up sensors automatically
}

/*  =====================================================================================
                                Implementation - Methods
    =====================================================================================   */

// ===================== Custom exception class for sensor errors =====================

// Constructor to set the error message
SensorException::SensorException(const std::string &msg) : message(msg) {}
// Override what() to return the error message
const char *SensorException::what() const noexcept
{
    return message.c_str();
}

// ===================== Base class for all sensors =====================

// Virtual destructor for safe cleanup of derived classes
Sensor::~Sensor()
{
    // For demonstration, print when a sensor is destroyed
    // std::cout << "Sensor destroyed\n";
}

// ===================== Derived class: Temperature sensor =====================

// Constructor to set initial temperature
TemperatureSensor::TemperatureSensor(double temp) : temperature(temp)
{
}
// Override readValue to return temperature, throw exception if unrealistic
double TemperatureSensor::readValue() const
{
    if (temperature < -50 || temperature > 200) // Unrealistic range
        throw SensorException("TemperatureSensor: Value out of range!");
    return temperature;
}
// Override getName
std::string TemperatureSensor::getName() const
{
    return "TemperatureSensor";
}
// Exception-safe update using copy-and-swap idiom
void TemperatureSensor::update(double newTemp) noexcept
{
    TemperatureSensor tempCopy(newTemp);
    std::swap(temperature, tempCopy.temperature);
    // If swap fails (very rare), no state is changed
}

// ===================== Derived class: RPM counter =====================
// Override readValue to return RPM, throw exception if unrealistic
double RPMCounter::readValue() const
{
    if (rpm < 0 || rpm > 10000) // Unrealistic range
        throw SensorException("RPMCounter: Value out of range!");
    return static_cast<double>(rpm);
}
// Override getName
std::string RPMCounter::getName() const
{
    return "RPMCounter";
}
// Exception-safe update using copy-and-swap idiom
void RPMCounter::update(int newRpm) noexcept
{
    RPMCounter rpmCopy(newRpm);
    std::swap(rpm, rpmCopy.rpm);
}

// ===================== Helping Functions =====================
// Function to demonstrate static vs dynamic type behavior
void staticVsDynamicDemo(Sensor *sensor)
{
    // Static type: Sensor*
    // Dynamic type: Actual object (TemperatureSensor or RPMCounter)
    std::cout << "Static type: Sensor*, Dynamic type: " << sensor->getName() << "\n";
}

/*  =====================================================================================
                                Implementation - Operators Overloading
    =====================================================================================   */
