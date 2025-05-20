#include <iostream>
#include <array>
#include <vector>
#include <math.h>

/*  -------------------------------------------------------------------
    Session Agenda:
    ---------------
        - Dynamic Arrays.
        - Intro to OOP.
    -------------------------------------------------------------------
*/

/*  -------------------------------------------------------------------    
                Dynamic Memory Allocation {DMA}
    -------------------------------------------------------------------    
    [IV]: what is the difference between arrays and vectors in C++?
        {Array} static: Nothing changes after execution. {Size is fixed at compile-time / can't be changed in run-time.}
            Example: 4-Bytes => static and fixed reserved at compile time.
            Allocation: .data / .bss / .stack

        {Vector} Dynamic: Size reserved can change after execution. {Size is variable at run-time.}
            Allocation: .heap
    -------------------------------------------------------------------
    Dynamic Memory Allocation:
    --------------------------
        {Allocate object in memory, and assign a pointer to it.} ----> Using {"new" operator}

            examples:
                int*p = new int;

    [IV] difference between "malloc" and "new"?
        - malloc() is a function
        - new is an operator.
            - "new" is faster since "malloc" is a function and it has overhead (Context switching).

    --------------------------------------------------------------------
    How it works ?
        heap allocation is managed by user. (allocated/malloc()/new -> usage(By Pointers) -> deallocation/free()/delete)

        NOTE: the pointer itself is in stack, but data is in heap.
        NOTE: when dallocate (delete, free()) , we delete the data, but not the pointer.
            Hence we have a {"Dangling Pointer"} we can't use after delete/free()
                Problem: Undefined behavior.
                Solution: assign to void pointer {pointer looke at safe place "location zero @ memory"}
        

    --------------------------------------------------------------------
*/

int main()
{
    // new
    // Dynamic Allocation. {using "new" operator}
    int *p0 = new int;     //*p0 -> address=0x0500 , value=0
    int *p1 = new int(80); //*p1 -> address=0x1000 , value=80
    *p1 = 10;              //*p1 -> address=0x1000 , value=10
    *p1++;                 //*p1 -> address=0x1000 , value=11
    delete p0, p1;

    // malloc()
    // Dynamic Allocation. {using malloc() function}
    // [    void* malloc(data_size)     ]   -> Need to type-cast the generic void pointer.
    // [    int* pointer = (int*)malloc(sizeof(int));    ]
    int *p2 = (int *)malloc(sizeof(int)); // C-Style Casting.
    free(p2);

    // example
    // int *pn = new int(80); // allocate.
    // *pn = add(*pn, 100);   // use.
    // delete pn;             // deallocation.

    // vector<int>list;
    return 0;
}