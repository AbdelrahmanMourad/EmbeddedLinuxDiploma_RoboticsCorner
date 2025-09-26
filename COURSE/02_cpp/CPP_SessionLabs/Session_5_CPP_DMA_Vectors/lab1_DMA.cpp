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
/*
================================================================================
|   C++ Dynamic Memory Allocation (DMA) - Study Notes & Interview Q&A
|-------------------------------------------------------------------------------
| Key Concepts:
| - Static arrays: Fixed size at compile time, memory on stack or .data/.bss.
| - Dynamic arrays/vectors: Size can change at runtime, memory on heap.
| - Dynamic allocation: Use 'new' (C++), 'malloc' (C), or STL containers (vector, array).
| - Deallocation: Use 'delete'/'delete[]' (C++), 'free' (C), or let containers auto-manage.
| - Pointer itself is on stack, data is on heap.
| - Dangling pointer: Pointer to freed memory. Always set pointer to nullptr after delete/free.
|
| Types that can be dynamically allocated:
|   - Built-in types: int, double, char, etc.
|   - Arrays: int*, double*, MyClass*, etc. (with new[], delete[])
|   - Classes/structs: MyClass* obj = new MyClass(...);
|   - STL containers: std::vector, std::array, std::string, etc. (auto-managed, but can also be new'd)
|
| Libraries to include:
|   - <iostream>   : for input/output
|   - <vector>     : for std::vector (dynamic array, auto-managed)
|   - <array>      : for std::array (fixed-size, stack or heap)
|   - <memory>     : for smart pointers (std::unique_ptr, std::shared_ptr)
|   - <cstdlib>    : for malloc/free (C-style)
|
| Syntax:
|   - int* p = new int;                // single int
|   - int* arr = new int[10];          // array of int
|   - MyClass* obj = new MyClass();    // class object
|   - delete p;                        // free single object
|   - delete[] arr;                    // free array
|   - free(ptr);                       // C-style, for malloc/calloc/realloc
|   - std::vector<int> v(10);          // dynamic array, auto-managed
|   - std::array<int, 10> a;           // fixed-size array, stack or heap
|
| Tips & Tricks:
| - Always pair new/delete and new[]/delete[].
| - Never use delete on memory allocated with malloc, or free on memory allocated with new.
| - Prefer smart pointers (std::unique_ptr, std::shared_ptr) for exception safety.
| - Prefer std::vector and std::string for dynamic arrays/strings.
| - After delete/free, set pointer to nullptr to avoid dangling pointer bugs.
| - Use RAII (Resource Acquisition Is Initialization) for safe memory management.
| - std::vector and std::array manage their own memory; you rarely need to use new/delete with them.
|
| Interview Questions & Answers:
| Q1: What is the difference between static and dynamic arrays?
| A1: Static arrays have fixed size at compile time, dynamic arrays can change size at runtime and are allocated on the heap.
|
| Q2: What is the difference between malloc and new?
| A2: malloc is a C function, returns void*, does not call constructors. new is a C++ operator, returns correct type, calls constructors.
|
| Q3: How do you deallocate memory in C++?
| A3: Use delete for single objects, delete[] for arrays. Use free for malloc/calloc/realloc.
|
| Q4: What is a dangling pointer? How do you avoid it?
| A4: A pointer that points to freed memory. Avoid by setting pointer to nullptr after delete/free.
|
| Q5: What happens if you delete a pointer twice?
| A5: Undefined behavior (may crash or corrupt memory).
|
| Q6: How do you dynamically allocate an array of objects?
| A6: MyClass* arr = new MyClass[10]; delete[] arr;
|
| Q7: Why prefer std::vector over raw dynamic arrays?
| A7: std::vector manages memory automatically, resizes dynamically, and is exception safe.
|
| Q8: Can you use new/delete with STL containers?
| A8: Not needed; STL containers manage their own memory. Only use new if you want a pointer to a container.
|
| Q9: What is the difference between new/delete and new[]/delete[]?
| A9: new/delete for single objects, new[]/delete[] for arrays.
|
| Q10: What are smart pointers and why use them?
| A10: Smart pointers (std::unique_ptr, std::shared_ptr) automatically manage memory and prevent leaks.
|
| Q11: What is the difference between std::vector and std::array?
| A11: std::vector is dynamic (size can change at runtime, heap-allocated), std::array is fixed-size (size known at compile time, stack-allocated by default).
|
| Q12: How do you dynamically allocate a std::vector or std::array?
| A12: std::vector<int>* pv = new std::vector<int>(10); // rarely needed, prefer stack allocation.
|      std::array<int, 10>* pa = new std::array<int, 10>; // also rarely needed.
================================================================================
*/

// Example code for all types of dynamic allocation and deallocation
#include <iostream>
#include <array>
#include <vector>
#include <memory> // for smart pointers
#include <cstdlib> // for malloc/free

struct MyStruct
{
    int x;
    MyStruct(int v) : x(v) { std::cout << "MyStruct(" << x << ") constructed\n"; }
    ~MyStruct() { std::cout << "MyStruct(" << x << ") destroyed\n"; }
};

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
    /*********************** */
    // --- C++ Dynamic Allocation ---
    int *p0 = new int;     // uninitialized
    int *p1 = new int(80); // initialized to 80
    *p1 = 10;
    ++(*p1);               // increment value
    delete p0;
    delete p1;
    p0 = nullptr; p1 = nullptr;

    // --- C-style malloc/free ---
    int *p2 = (int *)malloc(sizeof(int));
    *p2 = 55;
    free(p2);
    p2 = nullptr;
 
    /******************************* */

    // example
    // int *pn = new int(80); // allocate.
    // *pn = add(*pn, 100);   // use.
    // delete pn;             // deallocation.

    // vector<int>list;

    /*********************************************************************************/
    // --- Built-in type ---
    int *pi = new int(42);
    std::cout << "*pi = " << *pi << std::endl;
    delete pi;
    pi = nullptr;

    // --- Array of built-in type ---
    double *darr = new double[5]{1.1, 2.2, 3.3, 4.4, 5.5};
    std::cout << "darr[2] = " << darr[2] << std::endl;
    delete[] darr;
    darr = nullptr;

    // --- Struct/class object ---
    MyStruct *ps = new MyStruct(10);
    delete ps;
    ps = nullptr;

    // --- Array of objects ---
    MyStruct *arr_struct = new MyStruct[3]{{1}, {2}, {3}};
    delete[] arr_struct;
    arr_struct = nullptr;

    // --- Dynamic STL vector (auto-managed) ---
    std::vector<int> v = {1, 2, 3, 4};
    v.push_back(5);
    std::cout << "v.size() = " << v.size() << std::endl;

    
    
    // --- Dynamic STL container (auto-managed) ---
    // --- Dynamic STL vector on heap (rarely needed) ---
    std::vector<int> *pv = new std::vector<int>({10, 20, 30});
    pv->push_back(40);
    std::cout << "pv->size() = " << pv->size() << std::endl;
    delete pv;
    pv = nullptr;

    // --- std::array (fixed-size, stack or heap) ---
    std::array<int, 4> a1 = {1, 2, 3, 4}; // stack
    std::cout << "a1[2] = " << a1[2] << std::endl;
    // Dynamic allocation (rarely needed)
    std::array<int, 4>* pa = new std::array<int, 4>({5, 6, 7, 8});
    std::cout << "(*pa)[2] = " << (*pa)[2] << std::endl;
    delete pa;
    pa = nullptr;

    // --- Smart pointers (recommended) ---
    auto uptr = std::make_unique<MyStruct>(99);  // unique_ptr
    auto sptr = std::make_shared<MyStruct>(100); // shared_ptr

    // --- Dangling pointer example ---
    int *pd = new int(123);
    delete pd;
    // pd is now dangling! Don't use it!
    pd = nullptr; // Safe

    return 0;
}