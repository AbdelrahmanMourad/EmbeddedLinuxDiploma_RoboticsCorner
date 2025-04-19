#include <iostream>
#include <vector>
#include <algorithm> // for lambdaa expression

/*  -------------------------------------------------------------------
    Session Agenda:
    ---------------
        - Dynamic Arrays.
        - Intro to OOP.
    -------------------------------------------------------------------
*/
/*  -------------------------------------------------------------------
                Object Oriented Programming (OOP)
    -------------------------------------------------------------------
    Array/ Vectors were used for homogeneous related data.abort

    what if we have non-homogeneous, different types, co-related data .... then we use struct/ class.
        example:
            Fruit   |6 B|4 B|1 B|

            struct fruit              // New Data Type.
            {
                char name[6];
                int price;
                char amount;
            };
            struct student
            {
                std::string name;
                char grade;
                float;
            };

    [IV] What / When / Why ?
    *** Not taking size in memory until I create {instance} of this struct data type.***

    [IV] Difference between struct in C vs C++ ?
        - POD (Plane Old DataType): this is the C-Style struct when used in C++
            - Don't accept functions.
            - Can accept Pointer to Functions.
        - Cpp-Style Struct
            - Accept functions.
            ****  and this is called Encapsulation, object has all it needs inside it as capsule  *****



    --------------------------------------------------------------------
    [MISRA Rule]:   When you find struct using functions... turn it into class
    --------------------------------------------------------------------

    [IV] struct vs Class ?
        - struct han no access opeators. {public-access by default}
        - Class has access-operators. {privat by default \ Can be customized}
            {public, private, protected}

    --------------------------------------------------------------------




*/

namespace HelpingFunctions
{
    // print separator function.
    void PrintSeparatorFn(void)
    {
        std::cout << "---------------------\n";
    }
    // Print Text.
    void PrintTextFn(std::string text)
    {
        std::cout << text << std::endl;
    }
}

struct Fruit
{
    int weight;
    int price_per_kg; // Kilogram.

    int total()
    {
        return weight * price_per_kg;
    }
};

int main()
{
    // // c-style in C
    // struct Fruit orange; // in this form.
    // Fruit_t orange;      // using typedef.

    // Call directly. {c-style in cpp}
    Fruit orange;

    orange.weight = 10;
    orange.price_per_kg = 20;

    std::cout << "total amount =\t" << orange.total() << "\n";

    return 0;
}

/*
    ______________________________________________
    Search Topics:
        malloc vs calloc
        presentation for difference to be presented tomorrow
            > key difference
            > sugbature between each one
    ______________________________________________
    new vs malloc (Done)
    delete vs free
    ______________________________________________
    class vs struct
    ______________________________________________
*/

/*  ______________________________________________
    Exercise:
        Search for:
            how to program Book.
            Hacker Rank for beginners.
            Leetcode for interviews.
    ______________________________________________
*/

/*  ______________________________________________
    
    Cpp
    Linux
    QNX

    HAL Cpp     --  JAVA Native Interface   --    Java on App

    Adaptive Autosar.
    Automotive Android.
        android as platform.
        android as image.
            linux administration
            shell scription
            linux files structure
            linux debugging
            SE Linux

    Computer Vision.

    ______________________________________________
*/