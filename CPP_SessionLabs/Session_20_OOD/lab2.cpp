/*  ================================================================================================================================
    Session content: SOLID Principle:
    ================================
        4- Design Smells:
            1. Rigid
            2. Fragile
            3. Viscous
            4. immobile
        5-  Solutions
            1. SRP
            2. OCP
            3. LSP  <-- Rectangle, Square Example
            4. ISP : Interface Segregation Principle : no client should be forced to depend on methods it doesn't use. <-- IMAchine Example
            5. DIP : Dependency inversion Principle : Depend on interface, and don't depend on concrete.

    *** Dependency injection Pattern: ==> for testability, flexability
        class MyClass{
            int* m; // Pointer
            // we need to depend it on interface, and pass it on the constructor, to simulate what i need (inject).
            MyClass(int *m);
        };
        int main(){
            MyClass mine {&M};  // HW
            MyClass mine {&m};  // Tester Func
            MyClass mine {&n};  // Stub interface
        }


    ================================================================================================================================
*/

#include <iostream>

int main()
{

    return 0;
}