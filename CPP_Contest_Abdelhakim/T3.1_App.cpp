/** ______________________________________________________________________________________________

    🎓 Task 3.1: Algorithms & Lambda Expressions (Modern C++):
    ----------------------------------------------------------
    💡 Focus Topics:
        Algorithms with Predicates and _if versions
        Lambda Expressions and Capture
        for_each, remove_if, transform, etc.

    🧠 Task:
        Create a C++ program for a "vehicle diagnostic system" that processes a list of sensor values
        (like temperatures, RPM, voltage, etc.) using STL algorithms and lambda expressions.

    Requirements:
        1.  Store sensor values in a "std::vector<float>".
        2.  Use "std::for_each" and a lambda to print each value with a unit.
        3.  Use "std::remove_if" with a lambda to remove invalid readings (e.g., negative or above a max threshold).
        4.  Use "std::transform" and a lambda to convert raw values (e.g., scale voltage).
        5.  Demonstrate lambda "capture" and use "mutable lambda" where necessary.
    ______________________________________________________________________________________________
**/

/*  =====================================================================================
                                Included Libraries
    =====================================================================================   */
#include "T3.1_VehicleDiagnosticSystem.h"
#include <iostream>

/*  =====================================================================================
                                Prototypes
    =====================================================================================   */
// in the .h file

/*  =====================================================================================
                                Entry Point
    =====================================================================================   */
int main()
{
    VehicleDiagnosticSystem_t diagnosticSystem;

    // Add sensor readings
    diagnosticSystem.AddSensor(SensorData_t(25.5, 3000, 12.2));
    diagnosticSystem.AddSensor(SensorData_t(-5.0, 2800, 15.0)); // Invalid
    diagnosticSystem.AddSensor(SensorData_t(45.6, 3200, 10.8));
    diagnosticSystem.AddSensor(SensorData_t(102.3, 5000, 23.5)); // Invalid
    diagnosticSystem.AddSensor(SensorData_t(30.0, 2900, 14.0));

    // Display all sensors
    diagnosticSystem.DisplayAll();

    // Remove invalid sensors
    diagnosticSystem.RemoveInvalidSensors();
    diagnosticSystem.DisplayAll();

    // Scale voltage readings
    diagnosticSystem.ScaleSensorVoltage(1.1);
    diagnosticSystem.DisplayAll();

    return 0;
}

/*  =====================================================================================
                                Implementation - Methods
    =====================================================================================   */
// in the .cpp file

/*  =====================================================================================
                                Implementation - Operators Overloading
    =====================================================================================   */
// no need for this example.