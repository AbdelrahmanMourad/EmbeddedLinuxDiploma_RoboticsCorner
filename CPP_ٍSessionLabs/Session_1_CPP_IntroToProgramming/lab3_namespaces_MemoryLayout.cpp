/*  ============================================================================================
                                MEMORY LAYOUT
    ============================================================================================
    RAM:
    ----
        .data       {global and static variables which are initialized.}  &&  {Stored in ROM, run on RAM Mirror in runtime.} {Defined and Declared.}
        .bss        {global and static variables which are NOT initialized.}    && {initialize by 0 at startup code.}
        .stack      {Local variables & Context Switching.}
        .heap       {User Allocated Memory (Dynamic Memory).}
    ----
    ROM:
    ----
        .rodata     {Read only datat (for constants).}
        .text       {Program Memory.}

    {Note: Some books say both are ".text" and other books separate them as ".text" and ".rodata"}
    ============================================================================================    
*/

/*  ============================================================================================
                                NAMESPACE
    ============================================================================================
    A namespace is a declarative region that provides a scope to the identifiers 
        (the names of types, functions, variables, etc) inside it.
    Namespaces are used to organize code into logical groups and to prevent name collisions 
        that can occur especially when your code base includes multiple libraries.
    --------------------------------------------------------------------------------------------
    Example:
        -   Temperature_Sensor
        -   Humidity_Sensor
    ============================================================================================    
*/

#include "iostream"
using namespace std;

// /*___________________________BAD PRACTICE____________________________________*/
// int step;
// int value = 1000; // .data

// int main()
// {
//     step = 10;
//     // local
//     int value =0;   // .stack
// }

/*_______________________________Good Practice________________________________*/

namespace Temperature_Sensor {
    int value = 37; // Global variable for temperature value

    int getReading() {
        return value;
    }
    // You can add classes/structs here for more complex sensors
}

namespace Humidity_Sensor {
    int value = 97; // Global variable for humidity value

    int getReading() {
        return value;
    }
    // You can add classes/structs here for more complex sensors
}

int main() {
    // Accessing functions and variables from namespaces
    int temp = Temperature_Sensor::getReading();
    int hum = Humidity_Sensor::getReading();

    std::cout << "Temperature Reading: " << Temperature_Sensor::value << std::endl;
    std::cout << "Humidity Reading: " << Humidity_Sensor::value << std::endl;

    return 0;
}