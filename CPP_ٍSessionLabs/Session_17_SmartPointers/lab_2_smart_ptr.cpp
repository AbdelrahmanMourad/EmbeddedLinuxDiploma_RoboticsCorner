#include <iostream>

class SmartPtr /*wrapper*/
{
public:
    // Constructor => allocate the actual ptr automatically at create.
    SmartPtr()
    {
    }
    // Destructor => deallocate the actual ptr automatically at create. {avoid forgetting to delete "Memory Leak" / early delete "Dangling Pointers" / double delete "UB" }
    ~SmartPtr()
    {
    }

private:
    int *actual_ptr;
};