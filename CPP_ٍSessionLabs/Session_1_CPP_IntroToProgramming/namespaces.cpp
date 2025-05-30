#include "iostream"

using namespace std;

/*  --------------------------------------------------------------------------------------------
                                MEMORY LAYOUT
    --------------------------------------------------------------------------------------------
----
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

--------------------------------------------------------------------------------------------
*/

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

namespace Temperature_Sensor
{
    // Variables.
    int value = 37;

    // Functions.
    int getReading()
    {
        return value;
    }
    // User-Defined Data Types {Classes and Structures.}
}
namespace Humidity_sensor
{
    int value = 97;
    // Functions.
    int getReading()
    {
        return value;
    }
}
int main()
{
    int temp = Temperature_Sensor::getReading();
    int hum = Humidity_sensor::getReading();
    
    std::cout << " Temperature Reading " << Temperature_Sensor::value << "\n";
    std::cout << " Humadity Reading " << Humidity_sensor::value << std::endl;
}