#include <iostream>

// RAII - Resource Acuisition is Initialization.
template <class T>
class UniquePtr /*wrapper*/
{
public:
    UniquePtr(T *p) : actual_ptr{p}
    {
        /*
         * Constructor => allocate the actual ptr automatically at create.
         * Constructor called automatically.
         **/
    }

    UniquePtr(const UniquePtr & copy)= delete;    // Copy Constructor Deleted
    ~UniquePtr()
    {
        /*
         * Destructor => deallocate the actual ptr automatically at create.
         * {avoid forgetting to delete "Memory Leak" / early delete "Dangling Pointers" / double delete "UB" }
         * Destructor called automatically
         **/

        delete actual_ptr;
    }



    // overload dereference
    T& operator*() { return *actual_ptr; } // reference as it must be modifiable.

private:
    T *actual_ptr;
};

struct Fruit
{
};

int main()
{

    UniquePtr<Fruit> orange_ptr(new Fruit);
    UniquePtr<double> smart(new double(8.1));
    std::cout << "Value= " << *smart << "\n";
    *smart = 10.0;
    std::cout << "Value= " << *smart << "\n";

    return 0;
}