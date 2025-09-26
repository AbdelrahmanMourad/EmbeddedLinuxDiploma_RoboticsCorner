/*
================================================================================
|   C++ Move Semantics and Smart Pointers
================================================================================
*/

/*  ================================================================================
                            Included Libraries
    ================================================================================ */
#include <iostream> // For std::cout, std::cin
// #include <memory>   // For smart pointers like std::unique_ptr, std::shared_ptr, std::weak_ptr
// #include <utility>  // For std::move

/*  ================================================================================
                            Definitions
    ================================================================================ */
template <typename T>
class MySharedPtr
{
private:
    T *actual_ptr_;
    int *counter;

public:
    MySharedPtr(T data) // Parameterized Constructor.
    {
        actual_ptr_ = new T(data); // DMA allocate ptr, assign data inside.
        counter = new int(1);      // DMA allocate ptr, assign 1 inside for 1st time.
        (*counter)++;              // Increase the counter by 1.
        std::cout << "Constructor Called: Object \"" << *actual_ptr_ << "\" Created 'ParameterizedConstructor'.\n";
    }
    MySharedPtr(const MySharedPtr &otherPtr) // Copy Constructor.
    {
        this->actual_ptr_ = otherPtr.actual_ptr_;
        this->counter = otherPtr.counter;
        (*counter)++;
        std::cout << "Constructor Called: Object \"" << *actual_ptr_ << "\" Created 'CopyConstructor'.\n";
    }
    ~MySharedPtr() // Destructor.
    {
        (*counter)--;
        if ((*counter) == 0)
            delete actual_ptr_, counter;
        std::cout << "Destructor Called: Object \"" << *actual_ptr_ << "\" Deleted.\n";
    }
    MySharedPtr &operator=(MySharedPtr &rhs_ptr) // Assigment Operator
    {
        this->actual_ptr_ = rhs_ptr.actual_ptr_;
        this->counter = rhs_ptr.counter;
        (*counter)++;
    }

    int getCount(void) { return *(this->counter); }
};

/*  ================================================================================
                            Main() - Entry Point
    ================================================================================ */
int main()
{
    MySharedPtr<int> ptr1(20); // Parameterized Constructor.
    std::cout << "Count= " << ptr1.getCount() << std::endl;
    MySharedPtr<int> ptr2{25}; // Parameterized Constructor.
    std::cout << "Count= " << ptr1.getCount() << std::endl;
    MySharedPtr<int> ptr3{ptr1}; // Copy Constructor.
    std::cout << "Count= " << ptr1.getCount() << std::endl;
    ptr3 = ptr2; // Assignment Operator.
    std::cout << "Count= " << ptr1.getCount() << std::endl;

    return 0;
}

/*  ================================================================================
                            Implementations
    ================================================================================ */