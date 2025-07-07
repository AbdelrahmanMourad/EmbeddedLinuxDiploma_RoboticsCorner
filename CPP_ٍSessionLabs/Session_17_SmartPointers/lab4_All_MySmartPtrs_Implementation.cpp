/*
================================================================================
|   C++ Smart Pointers: MySharedPtr, MyUniquePtr, MyWeakPtr - Study Summary
|-------------------------------------------------------------------------------
| What are Smart Pointers?
| - Smart pointers are classes that manage dynamic memory automatically.
| - They help prevent memory leaks and dangling pointers.
| - C++ STL provides: std::unique_ptr, std::shared_ptr, std::weak_ptr (in <memory>).
|
| Custom Implementations:
| - MyUniquePtr: Owns a resource exclusively (cannot be copied, only moved).
| - MySharedPtr: Reference-counted ownership. Multiple pointers can share the same resource.
| - MyWeakPtr: Non-owning reference to a resource managed by MySharedPtr (does not affect ref count).
|
| Usage & Differences:
| - Use UniquePtr when only one owner is needed (fastest, safest).
| - Use SharedPtr when multiple owners are needed (reference counting).
| - Use WeakPtr to break cycles or observe a resource without extending its lifetime.
|
| Tips & Tricks:
| - Always prefer smart pointers over raw pointers for heap memory.
| - Never use delete/free with smart pointers.
| - Avoid circular references with shared pointers (use weak pointers).
| - Use std::make_unique / std::make_shared for exception safety.
|
| Interview Q&A:
| Q1: What is a smart pointer? Why use them?
| Q2: Difference between unique_ptr, shared_ptr, and weak_ptr?
| Q3: How does shared_ptr manage memory?
| Q4: What is a circular reference? How to avoid it?
| Q5: Can you copy a unique_ptr? Why/why not?
| Q6: When does an object managed by shared_ptr get deleted?
| Q7: What happens if you delete a raw pointer managed by a smart pointer?
| Q8: How do you implement a simple reference-counted pointer?
================================================================================
*/

/*
================================================================================
    🚪 Why Use explicit in Constructors?
        🧭 Purpose:
            To prevent implicit conversions or copy-initialization from values
            that could accidentally match the constructor signature.
        ✅ Example (with explicit)
            _____________________________________________________________________________
            |                                                                           |
            |    class Foo {                                                            |
            |        public:                                                            |
            |            explicit Foo(int x) {}                                         |
            |        };                                                                 |
            |                                                                           |
            |        Foo f1 = Foo(42);   // ✅ OK                                       |
            |        Foo f2 = 42;        // 🚫 Error! Prevents unintended conversion.   |
            |___________________________________________________________________________|
        ==> Without explicit, Foo f2 = 42; would compile, which may not be what the developer intended.

================================================================================
*/

/*  ================================================================================
                                Included Libraries
    ================================================================================ */
#include <iostream>
#include <memory>
#include <vector>

/*  ================================================================================
                                Declarations
    ================================================================================ */
class Device
{
private:
    std::string name_;

public:
    Device(const std::string &name) : name_(name) { std::cout << "[Device: " << name_ << "] Created.\n"; }
    ~Device() { std::cout << "[Device: " << name_ << "] Destroyed.\n"; }
    void operate() const { std::cout << "[Device: " << name_ << "] Operating...\n"; }
};

namespace DEMO
{
    void shared_ptr_demo()
    {
        std::cout << "\n--- Shared Pointer Demo ---\n";

        // Initialization via "std::make_shared()" ... (preferred)
        std::shared_ptr<Device> d1 = std::make_shared<Device>("Alpha");
        std::cout << "Use count before d2: " << d1.use_count() << "\n";

        {
            // Copy: increases use_count
            std::shared_ptr<Device> d2 = d1;
            std::cout << "Use count just after d2: " << d1.use_count() << "\n";
            d2->operate();
        }

        // d2 destroyed, count decreases.
        std::cout << "Use count after d2 scope: " << d1.use_count() << "\n";
    }

    void unique_ptr_demo()
    {
        std::cout << "\n--- Unique Pointer Demo ---\n";

        // Initialization via "std::make_unique()" ... (preferred).
        std::unique_ptr<Device> u1 = std::make_unique<Device>("Beta");
        u1->operate();

        // Ownership transfer via move.
        std::unique_ptr<Device> u2 = std::move(u1);
        std::cout << "std::unique_ptr<Device> u2 = std::move(u1);\n";
        if (!u1)
            std::cout << "u1 no longer owns the device.\n";

        u2->operate();
    }

    void weak_ptr_demo()
    {
        std::cout << "\n--- Weak Pointer Demo ---\n";

        std::shared_ptr<Device> d3 = std::make_shared<Device>("Gamma");

        // WeakPtr ovserves shared ownership without extending lifetime.
        std::weak_ptr<Device> wptr = d3;
        std::cout << "Use count after lock: " << d3.use_count() << "\n";

        if (auto locked = wptr.lock())
        {
            locked->operate();
            std::cout << "Use count after lock: " << locked.use_count() << "\n";
        }

        // Destroy original shared_ptr
        d3 = nullptr;

        if (wptr.expired())
            std::cout << "wptrr expired after shared_ptr deleted.\n\n\n";
    }
};

/*  ================================================================================
                                My Smart Pointers Declarations/Implementations
    ================================================================================ */

// ======================= MyUniquePtr Implementation ===========================
template <typename T>
class MyUniquePtr
{
private:
    T *actual_ptr_;

public:
    // Constructor
    explicit MyUniquePtr(T *p = nullptr) : actual_ptr_(p) {}

    // Destructor
    ~MyUniquePtr() { delete actual_ptr_; }

    // Delete copy constructor and copy assignment (unique ownership)
    MyUniquePtr(const MyUniquePtr &) = delete;
    MyUniquePtr &operator=(const MyUniquePtr &) = delete;

    // Move constructor
    MyUniquePtr(MyUniquePtr &&other) noexcept : actual_ptr_(other.actual_ptr_)
    {
        other.actual_ptr_ = nullptr;
    }

    // Move assignment
    MyUniquePtr &operator=(MyUniquePtr &&other) noexcept
    {
        if (this != &other) /*Make Sure It's not the same pointer*/
        {
            delete actual_ptr_;
            actual_ptr_ = other.actual_ptr_;
            other.actual_ptr_ = nullptr;
        }
        return *this;
    }

    // Dereference operators
    T &operator*() const { return *actual_ptr_; }
    T *operator->() const { return actual_ptr_; }

    // Get raw pointer
    T *get() const { return actual_ptr_; }

    // Release ownership
    T *release()
    {
        T *temp = actual_ptr_;
        actual_ptr_ = nullptr;
        return temp;
    }

    // Reset pointer
    void reset(T *p = nullptr)
    {
        delete actual_ptr_;
        actual_ptr_ = p;
    }
};

// ======================= MySharedPtr Implementation ===========================
template <typename T>
class MySharedPtr
{
private:
    T *actual_ptr_; // 🧷 Points to the shared object in heap
    int *counter;   // 🔢 Tracks how many MySharedPtr instances point to actual_ptr_

    void release() /* Cleanup logic */
    {
        if (counter)
        {
            (*counter)--;      // One less owner.
            if (*counter == 0) // No owner left.
            {
                /*
                When counter hits 0, it's game over:
                    💀 both actual_ptr_ and counter are deleted.
                */
                delete actual_ptr_;    // Delete object.
                delete counter;        // Delete counter itself.
                actual_ptr_ = nullptr; // Null the actual pointer.
                counter = nullptr;     // Null the counter pointer.
            }
        }
    }

public:
    // Parameterized Constructor - data
    explicit MySharedPtr(T data)
    {
        /* When the object is created, memory is alocated and the reference count starts at "1" */
        actual_ptr_ = new T(data); // Allocate memory on heap for object.
        counter = new int(1);      // First Owner: initialize counter to 1.
        std::cout << "Constructor Called: Object \"" << *actual_ptr_ << "\" Created 'ParameterizedConstructor-data'.\n";
    }

    // Parameterized Constructor - Pointer to data
    explicit MySharedPtr(T *ptr = nullptr)
    {
        actual_ptr_ = ptr;
        counter = (ptr ? new int(1) : nullptr);
        if (ptr)
            std::cout << "Constructor Called: Object \"" << *actual_ptr_ << "\" Created 'ParameterizedConstructor-dataPointer'.\n";
    }

    // Copy Constructor
    MySharedPtr(const MySharedPtr &otherPtr)
    {
        actual_ptr_ = otherPtr.actual_ptr_; // Share the same object.
        counter = otherPtr.counter;         // Share the sane counter.
        if (counter)
            (*counter)++; // Increment use count.
        std::cout << "Constructor Called: Object \"" << (actual_ptr_ ? *actual_ptr_ : 0) << "\" Created 'CopyConstructor'.\n";
    }

    // Assignment Operator
    MySharedPtr &operator=(const MySharedPtr &rhs_ptr)
    {
        if (this != &rhs_ptr)
        {
            release();                         // Rekease current ownership.
            actual_ptr_ = rhs_ptr.actual_ptr_; // Share the same object.
            counter = rhs_ptr.counter;         // Share the same counter.
            if (counter)
                (*counter)++; // Increment use count.
        }
        return *this;
    }

    // Destructor
    ~MySharedPtr()
    {
        release();
        if (actual_ptr_ == nullptr)
            std::cout << "Destructor Called: Object already deleted or nullptr.\n";
        else
            std::cout << "Destructor Called: Object \"" << *actual_ptr_ << "\" Deleted.\n";
    }

    // Dereference operators
    T &operator*() const { return *actual_ptr_; }
    T *operator->() const { return actual_ptr_; }

    // Get use count
    int use_count() const { return counter ? *counter : 0; }

    // Get raw pointer
    T *get() const { return actual_ptr_; }

    // Friend MyWeakPtr
    template <typename U>
    friend class MyWeakPtr;

    /*
        |======================================================|
        |           Stack                  |       Heap        |
        |==================================|===================|
        |   sptr1 ---> actual_ptr_ ------> | int(20)           |
        |            --> counter  -------> | int(2)            |  <- shared by sptr1 & sptr2
        |----------------------------------|-------------------|
        |   sptr2 ---> actual_ptr_ ------> | int(20)           |
        |            --> counter  -------> | int(2)            |
        |__________________________________|___________________|

        ================================================================
        | When sptr2 goes out of scope:                                |
        |=============================                                 |
        |    -   sptr2 destroyed                                       |
        |            *   counter becomes 1                             |
        |    -   Then sptr1 reset:                                     |
        |            *   counter becomes 0                             |
        |                => delete actual_ptr_                         |
        |                => delete counter                             |
        ================================================================
    */
};

// ======================= MyWeakPtr Implementation =============================
template <typename T>
class MyWeakPtr
{
private:
    T *actual_ptr_;
    int *counter;

public:
    // Construct from MySharedPtr
    MyWeakPtr(const MySharedPtr<T> &shared) : actual_ptr_(shared.actual_ptr_), counter(shared.counter) {}

    // Check if resource is still alive
    bool expired() const { return !counter || *counter == 0; }

    // Try to get a shared pointer (returns nullptr if expired)
    MySharedPtr<T> lock() const
    {
        if (!expired())
        {
            return MySharedPtr<T>(*this); // Copy constructor

            /*  -----------------------------------------------------------------------
                In this line:
                -------------
                    You’re copying the actual_ptr_ and counter from the MyWeakPtr,
                    just like how the copy constructor in MySharedPtr works. That means:
                        -   If counter > 0, the resource is still alive ⇒ new MySharedPtr created.
                        -   If counter == 0, the weak pointer returns a null shared pointer ⇒ no resurrection possible.
                    This avoids holding ownership, yet still lets you try to safely access the data. 🤝
                -----------------------------------------------------------------------
            */
        }
        return MySharedPtr<T>(nullptr);
    }
};

/*  ================================================================================
                                Main - Entry Point
    ================================================================================ */

// ======================= Main() - Usage Examples ==============================
int main()
{
    /*__________________________________________________________*/
    DEMO::shared_ptr_demo();
    DEMO::unique_ptr_demo();
    DEMO::weak_ptr_demo();

    /*__________________________________________________________*/
    std::cout << "=== MyUniquePtr Example ===\n";
    MyUniquePtr<int> uptr(new int(42));
    std::cout << "*uptr = " << *uptr << "\n";
    // MyUniquePtr<int> uptr2 = uptr; // Error: copy not allowed
    MyUniquePtr<int> uptr3 = std::move(uptr); // Move allowed

    /*__________________________________________________________*/
    std::cout << "\n=== MySharedPtr Example ===\n";
    MySharedPtr<int> sptr1(20);
    {
        MySharedPtr<int> sptr2 = sptr1; // Copy constructor
        std::cout << "sptr1 use_count: " << sptr1.use_count() << "\n";
        std::cout << "sptr2 use_count: " << sptr2.use_count() << "\n";
    } // sptr2 goes out of scope
    std::cout << "sptr1 use_count after sptr2 destroyed: " << sptr1.use_count() << "\n";

    /*__________________________________________________________*/
    std::cout << "\n=== MyWeakPtr Example ===\n";
    MyWeakPtr<int> wptr(sptr1);
    std::cout << "wptr expired? " << (wptr.expired() ? "yes" : "no") << "\n";
    sptr1 = MySharedPtr<int>(100); // Old resource deleted
    std::cout << "wptr expired after sptr1 reset? " << (wptr.expired() ? "yes" : "no") << "\n";
    /*__________________________________________________________*/

    return 0;
}

/*
================================================================================
|   MyUniquePtr, MySharedPtr, MyWeakPtr - Usage, Comparison, and Interview Q&A
|-------------------------------------------------------------------------------
| MyUniquePtr:
| - Exclusive ownership. Cannot be copied, only moved.
| - Use when only one owner is needed.
| - Fastest, safest, no reference counting.
|
| MySharedPtr:
| - Reference-counted ownership. Multiple pointers can share the same resource.
| - Resource is deleted when last shared pointer is destroyed.
| - Use when multiple owners are needed.
|
| MyWeakPtr:
| - Non-owning reference to a resource managed by MySharedPtr.
| - Does not affect reference count.
| - Use to break cycles or observe resource without extending its lifetime.
|
| std::unique_ptr, std::shared_ptr, std::weak_ptr (from <memory>):
| - std::unique_ptr: Same as MyUniquePtr, but more features (custom deleters, arrays).
| - std::shared_ptr: Same as MySharedPtr, thread-safe, supports weak_ptr.
| - std::weak_ptr: Same as MyWeakPtr, can be upgraded to shared_ptr if resource is alive.
|
| Tips & Tricks:
| - Always use smart pointers for heap memory.
| - Never use delete/free with smart pointers.
| - Avoid circular references with shared pointers (use weak pointers).
| - Use std::make_unique / std::make_shared for exception safety.
|
| Interview Questions & Answers:
| Q1: What is a smart pointer? Why use them?
| A1: A class that manages dynamic memory automatically. Prevents leaks and dangling pointers.
|
| Q2: Difference between unique_ptr, shared_ptr, and weak_ptr?
| A2: unique_ptr: exclusive ownership; shared_ptr: shared ownership; weak_ptr: non-owning observer.
|
| Q3: How does shared_ptr manage memory?
| A3: Uses reference counting. Deletes resource when last shared_ptr is destroyed.
|
| Q4: What is a circular reference? How to avoid it?
| A4: When two shared_ptrs reference each other, preventing deletion. Use weak_ptr to break the cycle.
|
| Q5: Can you copy a unique_ptr? Why/why not?
| A5: No. unique_ptr cannot be copied to enforce unique ownership.
|
| Q6: When does an object managed by shared_ptr get deleted?
| A6: When the last shared_ptr owning it is destroyed or reset.
|
| Q7: What happens if you delete a raw pointer managed by a smart pointer?
| A7: Undefined behavior. Never manually delete memory managed by a smart pointer.
|
| Q8: How do you implement a simple reference-counted pointer?
| A8: Store a pointer to the resource and a pointer to a reference count. Increment on copy, decrement on destruction, delete when count reaches zero.
*/