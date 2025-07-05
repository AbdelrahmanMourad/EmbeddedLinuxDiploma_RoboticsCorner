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

/*  ================================================================================
                                Included Libraries
    ================================================================================ */
#include <iostream>

/*  ================================================================================
                                Declarations
    ================================================================================ */

// ======================= MyUniquePtr Implementation ===========================
template <typename T>
class MyUniquePtr {
private:
    T* actual_ptr_;
public:
    // Constructor
    explicit MyUniquePtr(T* p = nullptr) : actual_ptr_(p) {}

    // Destructor
    ~MyUniquePtr() { delete actual_ptr_; }

    // Delete copy constructor and copy assignment (unique ownership)
    MyUniquePtr(const MyUniquePtr&) = delete;
    MyUniquePtr& operator=(const MyUniquePtr&) = delete;

    // Move constructor
    MyUniquePtr(MyUniquePtr&& other) noexcept : actual_ptr_(other.actual_ptr_) {
        other.actual_ptr_ = nullptr;
    }

    // Move assignment
    MyUniquePtr& operator=(MyUniquePtr&& other) noexcept {
        if (this != &other) /*Make Sure It's not the same pointer*/ {
            delete actual_ptr_;
            actual_ptr_ = other.actual_ptr_;
            other.actual_ptr_ = nullptr;
        }
        return *this;
    }

    // Dereference operators
    T& operator*() const { return *actual_ptr_; }
    T* operator->() const { return actual_ptr_; }

    // Get raw pointer
    T* get() const { return actual_ptr_; }

    // Release ownership
    T* release() {
        T* temp = actual_ptr_;
        actual_ptr_ = nullptr;
        return temp;
    }

    // Reset pointer
    void reset(T* p = nullptr) {
        delete actual_ptr_;
        actual_ptr_ = p;
    }
};

// ======================= MySharedPtr Implementation ===========================
template <typename T>
class MySharedPtr {
private:
    T* actual_ptr_;
    int* counter;

    void release() {
        if (counter) {
            (*counter)--;
            if (*counter == 0) {
                delete actual_ptr_;
                delete counter;
                actual_ptr_ = nullptr;
                counter = nullptr;
            }
        }
    }

public:
    // Parameterized Constructor - data
    explicit MySharedPtr(T data) {
        actual_ptr_ = new T(data);
        counter = new int(1);
        std::cout << "Constructor Called: Object \"" << *actual_ptr_ << "\" Created 'ParameterizedConstructor-data'.\n";
    }

    // Parameterized Constructor - Pointer to data
    explicit MySharedPtr(T* ptr = nullptr) {
        actual_ptr_ = ptr;
        counter = (ptr ? new int(1) : nullptr);
        if (ptr)
            std::cout << "Constructor Called: Object \"" << *actual_ptr_ << "\" Created 'ParameterizedConstructor-dataPointer'.\n";
    }

    // Copy Constructor
    MySharedPtr(const MySharedPtr& otherPtr) {
        actual_ptr_ = otherPtr.actual_ptr_;
        counter = otherPtr.counter;
        if (counter) (*counter)++;
        std::cout << "Constructor Called: Object \"" << (actual_ptr_ ? *actual_ptr_ : 0) << "\" Created 'CopyConstructor'.\n";
    }

    // Assignment Operator
    MySharedPtr& operator=(const MySharedPtr& rhs_ptr) {
        if (this != &rhs_ptr) {
            release();
            actual_ptr_ = rhs_ptr.actual_ptr_;
            counter = rhs_ptr.counter;
            if (counter) (*counter)++;
        }
        return *this;
    }

    // Destructor
    ~MySharedPtr() {
        release();
        if (actual_ptr_ == nullptr)
            std::cout << "Destructor Called: Object already deleted or nullptr.\n";
        else
            std::cout << "Destructor Called: Object \"" << *actual_ptr_ << "\" Deleted.\n";
    }

    // Dereference operators
    T& operator*() const { return *actual_ptr_; }
    T* operator->() const { return actual_ptr_; }

    // Get use count
    int use_count() const { return counter ? *counter : 0; }

    // Get raw pointer
    T* get() const { return actual_ptr_; }

    // Friend MyWeakPtr
    template <typename U>
    friend class MyWeakPtr;
};

// ======================= MyWeakPtr Implementation =============================
template <typename T>
class MyWeakPtr {
private:
    T* actual_ptr_;
    int* counter;
public:
    // Construct from MySharedPtr
    MyWeakPtr(const MySharedPtr<T>& shared) : actual_ptr_(shared.actual_ptr_), counter(shared.counter) {}

    // Check if resource is still alive
    bool expired() const { return !counter || *counter == 0; }

    // Try to get a shared pointer (returns nullptr if expired)
    MySharedPtr<T> lock() const {
        if (!expired())
            return MySharedPtr<T>(*this); // Copy constructor
        return MySharedPtr<T>(nullptr);
    }
};

/*  ================================================================================
                                Main - Entry Point
    ================================================================================ */
    
// ======================= Main() - Usage Examples ==============================
int main() {
    std::cout << "=== MyUniquePtr Example ===\n";
    MyUniquePtr<int> uptr(new int(42));
    std::cout << "*uptr = " << *uptr << "\n";
    // MyUniquePtr<int> uptr2 = uptr; // Error: copy not allowed
    MyUniquePtr<int> uptr3 = std::move(uptr); // Move allowed

    std::cout << "\n=== MySharedPtr Example ===\n";
    MySharedPtr<int> sptr1(20);
    {
        MySharedPtr<int> sptr2 = sptr1; // Copy constructor
        std::cout << "sptr1 use_count: " << sptr1.use_count() << "\n";
        std::cout << "sptr2 use_count: " << sptr2.use_count() << "\n";
    } // sptr2 goes out of scope
    std::cout << "sptr1 use_count after sptr2 destroyed: " << sptr1.use_count() << "\n";

    std::cout << "\n=== MyWeakPtr Example ===\n";
    MyWeakPtr<int> wptr(sptr1);
    std::cout << "wptr expired? " << (wptr.expired() ? "yes" : "no") << "\n";
    sptr1 = MySharedPtr<int>(100); // Old resource deleted
    std::cout << "wptr expired after sptr1 reset? " << (wptr.expired() ? "yes" : "no") << "\n";

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