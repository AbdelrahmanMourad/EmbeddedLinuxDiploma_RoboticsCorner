/*
===================================================================================
Raw Pointers problems

===================================================================================
*/

#include <iostream>

/*
***************************************************************
* 1) memory leak: new without delete
* 2) double delete: leads to undefined behavior
* 3) dangling pointer: early deletion
****************************************************************
*/
// /*-------------------------------------------------------------------*/
// int main()
// {
//     int *p = new int; // raw pointer p to integer in heap dynamically allocated.
//     *p = 10;          // dereference = =Use
//     delete p;         // free the dynamic allocated memory in heap.
//     /*_______Problem(1)_______*/
//     /*****if there's no "delete" -----> "MEMORY LEAK" ******/
//     return 0;
// }
// /*-------------------------------------------------------------------*/
// int main()
// {
//     int *p = new int; // raw pointer p to integer in heap dynamically allocated.
//     *p = 10;          // dereference = Use
//     delete p;         // free the dynamic allocated memory in heap.
//     delete p;         // double delete = undefined behavior (UB)
//     /*_______Problem(2)_______*/
//     /*****if there's "Two delete" -----> "UNDEFINED BEHAVIOR" ******/
//     return 0;
// }
// /*-------------------------------------------------------------------*/
// int main()
// {
//     int *p = new int; // raw pointer p to integer in heap dynamically allocated.
//     delete p;         // free the dynamic allocated memory in heap.
//     *p = 10;          // dereference = Use
//     /*_______Problem(3)_______*/
//     /*****if you early delete before using -----> "Dangling pointer" ******/
//     return 0;
// }
// /*-------------------------------------------------------------------*/

// __________Memory leak example__________
int *fun()
{
    int *p = new int;
    return p;
}

// __________Dangling pointer example__________
int *fun()
{
    int *p = new int;
    delete p;
    return p;
}

int main()
{
    while (1)
    {
        int *p = fun();
        *p = 10;
        std::cout << "Read value= " << *p << std::endl;
    }
    return 0;
}
