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
                "○   std::exception" mechanism.
        5.  Exception Safety
            •   Implement an exception-safe sensor update function using "copy-and-swap idiom" or "noexcept" and demonstrate proper error safety.


    📝 Submission Checklist
        •   ".cpp" file with proper class design and error handling.
        •   Output sample or screenshots (in comments or separate doc).
        •   Code must include comments for clarity.
        •   Follow naming conventions and modular design.
    
    ○•
    ______________________________________________________________________________________________
**/

/*  =====================================================================================
                                Included Libraries
    =====================================================================================   */
#include <iostream>

/*  =====================================================================================
                                Prototypes
    =====================================================================================   */

/*  =====================================================================================
                                Entry Point
    =====================================================================================   */

/*  =====================================================================================
                                Implementation - Methods
    =====================================================================================   */

/*  =====================================================================================
                                Implementation - Operators Overloading
    =====================================================================================   */
