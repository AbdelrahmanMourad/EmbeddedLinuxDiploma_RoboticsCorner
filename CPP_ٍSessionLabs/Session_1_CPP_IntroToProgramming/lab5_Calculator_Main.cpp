/*
================================================================================
NOTE:
    Procedural Programming.  <-- running lines of code inside the main()
    Functional Programming.  <-- More modular design based on functions.
================================================================================
*/
/*
================================================================================
|   C++ Calculator Example - Learning Summary
|-------------------------------------------------------------------------------
| - Namespaces: Used to organize code and avoid name conflicts.
| - Classes: Used for modular, object-oriented design.
| - Enums: Used to represent operation types in a readable way.
| - Member Functions: Implement calculator operations as class methods.
| - All logic and state handled inside the class using private members.
| - Input/Output: Uses std::cin and std::cout for user interaction.
================================================================================
*/

#include <iostream>
#include "lab5.Calculator_functions.h" // If not adding Functions,cpp in complication, we get "Linking error" as it's now declared, not found the inplemenetation.

int main()
{
    // Create an instance of the calculator class from the namespace
    Calculator_Namespace::Calculator_Class calc;

    // Welcome message
    calc.Welcome_Msg();

    // Method (1)
    calc.TakeUserInputs_Operation();       // This will take user inputs and switch operations internally.
    calc.PrintOperationResult(); // Print the result of the operation.

    // // Method (2)
    // // Take user inputs and perform the operation (all logic inside the class)
    // calc.TakeUserInputs_Operation_Print();
    // No need for further output here, as the class handles all printing.
    
    return 0;
}

/*
================================================================================
|   Key Concepts Demonstrated
|-------------------------------------------------------------------------------
| 1. Namespaces group related code and prevent naming conflicts.
| 2. Classes encapsulate data and behavior (Calculator_Class).
| 3. Enums provide readable names for operation types.
| 4. Member functions access and modify only class data (no parameters).
| 5. All input/output and logic handled inside the class.
| 6. Switch-case for operation selection is encapsulated in the class.
| 7. Main function is clean and minimal.
================================================================================
*/
