/** ______________________________________________________________________________________________

    🧠 Task 05: Vehicle Component Manager (Memory-Safe Design):
    -----------------------------------------------------------○•

    Create a C++ program that manages different types of vehicle components using
        "RAII", "move semantics", and "smart pointers".
    The goal is to simulate safe memory management for dynamically created vehicle subsystems.
    ______________________________________________________________________________________________
    ✅ Requirements
        1.  Component Class with Move Semantics
            •   Create a "Component" class with:
                ○   Explicit "move constructor"
                ○   "Move assignment operator"
                ○   Disable copy using "= delete"
            •   Demonstrate move-only behavior in main.
        2.  RAII Wrapper
            •   Implement a "ComponentManager" class that owns a "Component" using "std::unique_ptr".
            •   Demonstrate RAII: resource is released when the manager is destroyed.
            •   Add constructor accepting "std::unique_ptr<Component>&&".
        3. Polymorphic Management with Smart Pointers
            •   Create a base class VehicleModule, and derived classes like "ECU", "SensorUnit".
            •   Use "std::unique_ptr<VehicleModule>" to manage derived objects polymorphically.
        4.  Shared Ownership
            •   Simulate shared access to a logging module using "std::shared_ptr<Logger>".
            •   Create multiple classes sharing the same "Logger".
        5.  Cycle Prevention
            •   Show how "std::weak_ptr" prevents cycles in shared objects (e.g., cyclic module referencing).

    ______________________________________________________________________________________________
    🔧 Bonus (Optional)
        •   Use perfect forwarding ("std::forward", forwarding reference) in a factory function to create components efficiently.
        •   Apply the pImpl idiom in one class.
    ______________________________________________________________________________________________
    📝 Submission Checklist
        •   ".cpp" file with proper class design using move semantics and smart pointers.
        •   Output examples or a short doc showing working features.
        •   Clear comments explaining the move operations and memory handling.
        •   No memory leaks, dangling pointers, or use-after-free.
    ______________________________________________________________________________________________
**/

/*  =====================================================================================
                                Included Libraries
    =====================================================================================   */
#include <iostream>
#include <memory>
#include <string>
#include <vector>

/*  =====================================================================================
                                Prototypes/ Declarations
    =====================================================================================   */

// ===============================
// 1. Component Class (Move-only)
// ===============================
class Component
{
public:
    // Constructor
    explicit Component(std::string name);

    // Move constructor
    Component(Component &&other) noexcept;

    // Move assignment operator
    Component &operator=(Component &&other) noexcept;

    // Delete copy constructor and copy assignment to make move-only
    Component(const Component &) = delete;
    Component &operator=(const Component &) = delete;

    // Destructor
    ~Component();

    // Print component info
    void print() const;

private:
    std::string name_; // Name of the component
};

// ===============================
// 2. RAII Wrapper: ComponentManager
// ===============================
class ComponentManager
{
public:
    // Constructor takes ownership of a Component via unique_ptr
    explicit ComponentManager(std::unique_ptr<Component> &&comp);

    // Destructor (RAII: releases resource automatically)
    ~ComponentManager();

    // Print managed component info
    void print() const;

private:
    std::unique_ptr<Component> comp_; // Unique pointer to the managed component
};

// ===============================
// 3. Polymorphic Management
// ===============================

// Base class for vehicle modules
class VehicleModule
{
public:
    virtual ~VehicleModule();          // Virtual destructor for base class
    virtual void diagnose() const = 0; // Pure virtual function for diagnostics
};

// Derived: ECU
class ECU : public VehicleModule
{
public:
    void diagnose() const override; // Implementation for ECU diagnostics
};

// Derived: SensorUnit
class SensorUnit : public VehicleModule
{
public:
    void diagnose() const override; // Implementation for SensorUnit diagnostics
};

// ===============================
// 4. Shared Ownership: Logger
// ===============================
class Logger
{
public:
    Logger();
    void log(const std::string &msg) const;
};

// Example classes sharing Logger
class ModuleA
{
public:
    ModuleA(std::shared_ptr<Logger> logger);
    void doSomething() const;

private:
    std::shared_ptr<Logger> logger_;
};

class ModuleB
{
public:
    ModuleB(std::shared_ptr<Logger> logger);
    void doSomethingElse() const;

private:
    std::shared_ptr<Logger> logger_;
};

// ===============================
// 5. Cycle Prevention with weak_ptr
// ===============================
class Node : public std::enable_shared_from_this<Node>
{
public:
    Node(const std::string &name);
    void setNext(std::shared_ptr<Node> next);
    void setPrev(std::shared_ptr<Node> prev);
    void print() const;

private:
    std::string name_;
    std::weak_ptr<Node> prev_; // weak_ptr prevents cycle
    std::shared_ptr<Node> next_;
};

// ===============================
// 6. Bonus: Factory with Perfect Forwarding
// ===============================
template <typename T, typename... Args>
std::unique_ptr<T> makeComponent(Args &&...args);

/*  =====================================================================================
                                Main Functions - Entry Point
    =====================================================================================   */

int main()
{
    std::cout << "\n--- 1. Move-only Component Demo ---\n";
    // Create a move-only component using std::make_unique
    auto comp1 = std::make_unique<Component>("Engine");
    // Move comp1 to comp2 (comp1 becomes empty, comp2 owns the resource)
    auto comp2 = std::move(comp1);
    if (!comp1)
        std::cout << "comp1 is now empty after move.\n";
    comp2->print(); // Print info of comp2

    std::cout << "\n--- 2. RAII ComponentManager Demo ---\n";
    // Demonstrate RAII: manager owns and releases the component automatically
    {
        ComponentManager manager(std::make_unique<Component>("Transmission"));
        manager.print(); // Print managed component
    } // manager goes out of scope, component is destroyed

    std::cout << "\n--- 3. Polymorphic VehicleModule Demo ---\n";
    // Create a vector of unique_ptr to VehicleModule (base class)
    std::vector<std::unique_ptr<VehicleModule>> modules;
    modules.push_back(std::make_unique<ECU>());        // Add ECU module
    modules.push_back(std::make_unique<SensorUnit>()); // Add SensorUnit module
    for (const auto &mod : modules)
    {
        mod->diagnose(); // Call diagnose() polymorphically
    }

    std::cout << "\n--- 4. Shared Logger Demo ---\n";
    // Create a shared Logger for multiple modules
    auto logger = std::make_shared<Logger>();
    ModuleA a(logger);                                               // ModuleA shares Logger
    ModuleB b(logger);                                               // ModuleB shares Logger
    a.doSomething();                                                 // ModuleA logs a message
    b.doSomethingElse();                                             // ModuleB logs a message
    std::cout << "Logger use_count: " << logger.use_count() << "\n"; // Show shared count

    std::cout << "\n--- 5. Cycle Prevention with weak_ptr Demo ---\n";
    // Create two nodes and link them (next is shared_ptr, prev is weak_ptr)
    auto node1 = std::make_shared<Node>("Node1");
    auto node2 = std::make_shared<Node>("Node2");
    node1->setNext(node2); // Node1 -> Node2
    node2->setPrev(node1); // Node2 <- Node1 (weak_ptr prevents cycle)
    node1->print();        // Print Node1 info
    node2->print();        // Print Node2 info

    std::cout << "\n--- 6. Bonus: Factory with Perfect Forwarding ---\n";
    // Factory creates a component efficiently
    auto comp3 = makeComponent<Component>("Battery");
    comp3->print(); // Print info

    return 0;
}

/*  =====================================================================================
                                Implementation - Methods/ Operators Overloading
    =====================================================================================   */

// -------- Component --------

Component::Component(std::string name) : name_(std::move(name))
{
    std::cout << "[Component] Constructed: " << name_ << std::endl;
}

Component::Component(Component &&other) noexcept : name_(std::move(other.name_))
{
    std::cout << "[Component] Move constructed\n";
}

Component &Component::operator=(Component &&other) noexcept
{
    if (this != &other)
    {
        name_ = std::move(other.name_);
        std::cout << "[Component] Move assigned\n";
    }
    return *this;
}

Component::~Component()
{
    std::cout << "[Component] Destroyed: " << name_ << std::endl;
}

void Component::print() const
{
    std::cout << "Component: " << name_ << std::endl;
}

// -------- ComponentManager --------

ComponentManager::ComponentManager(std::unique_ptr<Component> &&comp)
    : comp_(std::move(comp))
{
    std::cout << "[ComponentManager] Acquired component\n";
}

ComponentManager::~ComponentManager()
{
    std::cout << "[ComponentManager] Released component\n";
}

void ComponentManager::print() const
{
    if (comp_)
        comp_->print();
    else
        std::cout << "No component managed.\n";
}

// -------- VehicleModule Polymorphism --------

VehicleModule::~VehicleModule() = default;

void ECU::diagnose() const
{
    std::cout << "ECU: Running diagnostics...\n";
}

void SensorUnit::diagnose() const
{
    std::cout << "SensorUnit: Checking sensors...\n";
}

// -------- Logger (shared_ptr) --------

Logger::Logger()
{
    std::cout << "[Logger] Created\n";
}

void Logger::log(const std::string &msg) const
{
    std::cout << "[Logger] " << msg << std::endl;
}

ModuleA::ModuleA(std::shared_ptr<Logger> logger) : logger_(logger) {}

void ModuleA::doSomething() const
{
    logger_->log("ModuleA did something!");
}

ModuleB::ModuleB(std::shared_ptr<Logger> logger) : logger_(logger) {}

void ModuleB::doSomethingElse() const
{
    logger_->log("ModuleB did something else!");
}

// -------- Node (weak_ptr cycle prevention) --------

Node::Node(const std::string &name) : name_(name) {}

void Node::setNext(std::shared_ptr<Node> next)
{
    next_ = next;
}

void Node::setPrev(std::shared_ptr<Node> prev)
{
    prev_ = prev;
}

void Node::print() const
{
    std::cout << "Node: " << name_;
    if (auto prevLock = prev_.lock())
    {
        std::cout << ", Prev: " << prevLock->name_;
    }
    if (next_)
    {
        std::cout << ", Next: " << next_->name_;
    }
    std::cout << std::endl;
}

// -------- Factory with Perfect Forwarding --------

template <typename T, typename... Args>
std::unique_ptr<T> makeComponent(Args &&...args)
{
    // std::forward preserves the value category (lvalue/rvalue)
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

/*  =====================================================================================
                                Explanation for Beginners:
    =====================================================================================   */
/*
1. Move-only Component:
   - The Component class cannot be copied, only moved.
   - This prevents accidental copying and ensures unique ownership.

2. RAII (Resource Acquisition Is Initialization):
   - ComponentManager owns a Component via unique_ptr.
   - When ComponentManager is destroyed, the Component is automatically released.

3. Polymorphic Management:
   - VehicleModule is a base class; ECU and SensorUnit are derived.
   - unique_ptr<VehicleModule> can point to any derived type, enabling polymorphism.

4. Shared Ownership:
   - Logger is managed by shared_ptr, so multiple modules can use the same logger.
   - Logger is destroyed only when all shared_ptrs are gone.

5. Cycle Prevention:
   - Node uses weak_ptr for the previous pointer to prevent memory leaks from cyclic references.

6. Factory with Perfect Forwarding:
   - makeComponent efficiently creates objects, forwarding constructor arguments.

All methods are implemented outside the class declarations for clarity.
Comments and print statements explain memory management and object lifetimes.
*/