/** ______________________________________________________________________________________________
    
    🧠 Task 05: Vehicle Component Manager (Memory-Safe Design):
    -----------------------------------------------------------○•

    Create a C++ program that manages different types of vehicle components using   
        "RAII", "move semantics", and "smart pointers". 
    The goal is to simulate safe memory management for dynamically created vehicle subsystems.
    ______________________________________________________________________________________________
    ✅ Requirements
        1.  Component Class with Move Semantics
            •   Create a "Component" class with:
                ○   Explicit "move constructor"
                ○   "Move assignment operator"
                ○   Disable copy using "= delete"
            •   Demonstrate move-only behavior in main.
        2.  RAII Wrapper
            •   Implement a "ComponentManager" class that owns a "Component" using "std::unique_ptr".
            •   Demonstrate RAII: resource is released when the manager is destroyed.
            •   Add constructor accepting "std::unique_ptr<Component>&&".
        3. Polymorphic Management with Smart Pointers
            •   Create a base class VehicleModule, and derived classes like "ECU", "SensorUnit".
            •   Use "std::unique_ptr<VehicleModule>" to manage derived objects polymorphically.
        4.  Shared Ownership
            •   Simulate shared access to a logging module using "std::shared_ptr<Logger>".
            •   Create multiple classes sharing the same "Logger".
        5.  Cycle Prevention
            •   Show how "std::weak_ptr" prevents cycles in shared objects (e.g., cyclic module referencing).
    
    ______________________________________________________________________________________________
    🔧 Bonus (Optional)
        •   Use perfect forwarding ("std::forward", forwarding reference) in a factory function to create components efficiently.
        •   Apply the pImpl idiom in one class.
    ______________________________________________________________________________________________
    📝 Submission Checklist
        •   ".cpp" file with proper class design using move semantics and smart pointers.
        •   Output examples or a short doc showing working features.
        •   Clear comments explaining the move operations and memory handling.
        •   No memory leaks, dangling pointers, or use-after-free.
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
