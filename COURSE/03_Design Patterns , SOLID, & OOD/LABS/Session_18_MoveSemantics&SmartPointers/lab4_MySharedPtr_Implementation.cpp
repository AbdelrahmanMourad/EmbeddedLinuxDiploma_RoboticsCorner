/*
================================================================================
|   C++ Move Semantics and Smart Pointers
================================================================================
*/

/*  ================================================================================
                            Included Libraries
    ================================================================================ */
#include <iostream> // For std::cout, std::cin
#include <memory>   // For smart pointers like std::unique_ptr, std::shared_ptr, std::weak_ptr
#include <utility>  // For std::move

/*  ================================================================================
                            Definitions
    ================================================================================ */
template <typename T>
class SharedPtr
{
public:
    SharedPtr(T data)
    {
        ptr = new T(data);    // Allocate memory for the object
        counter = new int(1); // Initialize the reference count to 1
        (*counter)++;         // Increment the reference count
    }
    SharedPtr(const SharedPtr &other) // Copy Constructor
    {
        ptr = other.ptr;         // Copy the pointer
        counter = other.counter; // Copy the reference count
        (*counter)++;            // Increment the reference count
    }

    // Copy Assignment operator
    SharedPtr &operator=(const SharedPtr &rhs)
    {
        this->ptr = rhs.ptr;         // Copy the pointer
        this->counter = rhs.counter; // Copy the reference count
        (*counter)++;                // Increment the reference count
        return *this;                // Return the current object
    }

    // Move assignment operator
    SharedPtr operator=(SharedPtr &&rhs) noexcept
    {
        if (this != &rhs) // Check for self-assignment
        {
            // Decrement the current object's reference count
            if (--(*counter) == 0)
            {
                delete ptr;     // Delete the object
                delete counter; // Delete the reference count
            }
            // Transfer ownership from rhs to this object
            ptr = rhs.ptr;
            counter = rhs.counter;
            rhs.ptr = nullptr;     // Set rhs pointer to nullptr
            rhs.counter = nullptr; // Set rhs counter to nullptr
        }
        return *this; // Return the current object
    }

    T getCount(void) { return *count; }
    
    ~SharedPtr() // Destructor
    {
        // If counter is not null, manage reference count and cleanup
        if (counter)
        {
            (*counter)--; // Decrement the reference count
            // If no more references, delete managed object and counter
            if ((*counter) == 0)
            {
                std::cout << "object " << *ptr << " is deleted" << std::endl;
                std::cout << "Reference count is zero, deleting object and counter." << std::endl;
                delete ptr;
                delete counter;
            }
            // If references remain, do nothing (object still in use elsewhere)
        }
    }

private:
    T *ptr;
    int *counter;
};

/*  ================================================================================
                            Main() - Entry Point
    ================================================================================ */
int main()
{
    SharedPtr<int> ptr1(10);   // Create a SharedPtr for an integer
    SharedPtr<int> ptr2(25);   // Copy the SharedPtr, incrementing the reference count
    SharedPtr<int> ptr3(ptr1); // Copy the SharedPtr, incrementing the reference count
    SharedPtr<int> ptr4(ptr2); // Copy the SharedPtr, incrementing the reference count

    return 0;
}

/*  ================================================================================
                            Implementations
    ================================================================================ */