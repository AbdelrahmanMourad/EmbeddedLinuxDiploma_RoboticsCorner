#include <iostream>
#include <memory>

int main()
{

    // initialize directly.
    std::unique_ptr<double> uptr1(new double(7.5));

    // initialize using the factory method ""std::make_unique()""
    std::unique_ptr<int> uptr2 = std::make_unique<int>(1 /*value*/);

    // std::unique_ptr<int> uptr3 (uptr2); // ERRPR can't use copy constructor with unique ptrs (deleted copy constructor.)
    // std::unique_ptr<int> uptr4 = uptr2; // ERRPR  (deleted assignment operatpr.)

    return 0;
}

/*  =========================================================================================================
                            unique_ptr implementation => For interview Quesions
    =========================================================================================================   */

// RAII - Resource Acuisition is Initialization.
template <class T>
class UniquePtr /*wrapper*/
{
private:
    T *actual_ptr;

public:
    UniquePtr(T *p) : actual_ptr{p} { std::cout << "Constructor Called: UniquePtr.\n"; }
    ~UniquePtr() { delete actual_ptr, std::cout << "Destructor Called: UniquePtr.\n"; }

    // Delete What Needs To Be Prohibited: {""Any Copy operation""}.
    UniquePtr(const UniquePtr &copy) = delete;    // Copy Constructor Deleted
    T &operator=(const UniquePtr &copy) = delete; // Copy Assigment Operator Overlading Deleted.

    // Overload Operator: 1. dereference. / 2. Arrow operator
    T &operator*() { return *actual_ptr; } // reference as it must be modifiable.
};
