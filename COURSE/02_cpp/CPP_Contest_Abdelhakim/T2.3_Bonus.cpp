/** ==============================================================================================
    // 🔍 Bonus Tasks (Optional):
    // ===========================
    // ✅ Add a friend function to access internal RPM directly
    // ✅ Add a safety limit check (bool isSafe()) that returns true if RPM < 6000
    // ✅ Use = delete to prevent copying in a variation
    //
    // 📤 Deliverables:
    // - EngineRPM.hh and EngineRPM.cc with full implementation
    // - main.cc demonstrating:
    //   --> Creating multiple objects
    //   --> Using overloaded operators
    //   --> Demonstrating copy/move behavior
    // - Include console output to indicate when special member functions are called

    ----------------------------------------------------------------------------------------------

    🔍Bonus Task (Optional)
        ✅ Add a friend function to access internal RPM directly
        ✅ Add a safety limit check (bool isSafe()) that returns true if RPM < 6000
        ✅ Use = delete to prevent copying in a variation

        📤Deliverables
            EngineRPM.hh and EngineRPM.cc with full implementation
            main.cc that:
                --> Creates multiple objects
                -->   Uses overloaded operators
                -->   Demonstrates copy/move behavior

            Include to indicate when special member functions are called

    ==============================================================================================
**/

/*  -----------------------------------------------------------------
                            Included Libraries
    -----------------------------------------------------------------*/
#include <iostream>

/*  -----------------------------------------------------------------
                            Prototypes
    -----------------------------------------------------------------*/
class EngineRPM
{
private:
    int *rpm; // Dynamically allocated RPM value

public:
    // Constructor & Destructor
    EngineRPM();                                           // Default constructor
    EngineRPM(int value);                                  // Parameterized constructor
    EngineRPM(const EngineRPM &other) /*= delete*/;        // Deleted copy constructor
    EngineRPM &operator=(const EngineRPM &other) = delete; // Deleted copy assignment
    ~EngineRPM();                                          // Destructor

    // Overloaded Operators
    EngineRPM operator+(const EngineRPM &other) const;
    bool operator==(const EngineRPM &other) const;
    bool operator!=(const EngineRPM &other) const;
    int operator()() const;
    friend std::ostream &operator<<(std::ostream &os, const EngineRPM &obj);

    // Bonus Features
    friend int getInternalRPM(const EngineRPM &obj); // Friend function to access RPM
    bool isSafe() const;                             // Safety limit check

    // Getter function
    int getRPM() const;
};

/*  -----------------------------------------------------------------
                            Entry Point
    -----------------------------------------------------------------*/
int main()
{
    EngineRPM sensor1{3000};               // Parameterized constructor
    EngineRPM sensor2{3200};               // Parameterized constructor
    EngineRPM average = sensor1 + sensor2; // Using overloaded + operator

    std::cout << "Average RPM: " << average << "\n"; // Using overloaded << operator

    if (sensor1 != sensor2)
    {
        std::cout << "RPM mismatch detected\n";
    }

    std::cout << "Sensor1 RPM via function call: " << sensor1() << "\n";                          // Using overloaded () operator
    std::cout << "Sensor2 internal RPM via friend function: " << getInternalRPM(sensor2) << "\n"; // Using friend function

    std::cout << "Sensor1 is " << (sensor1.isSafe() ? "safe" : "unsafe") << "\n";
    std::cout << "Sensor2 is " << (sensor2.isSafe() ? "safe" : "unsafe") << "\n";

    return 0;
}

/*  -----------------------------------------------------------------
                            Implementation
    -----------------------------------------------------------------*/
// Default Constructor (Initializes RPM to 0)
EngineRPM::EngineRPM() : rpm{new int{0}}
{
    std::cout << "Default Constructor: RPM set to 0\n";
}

// Parameterized Constructor (Initializes RPM to the given value)
EngineRPM::EngineRPM(int value) : rpm{new int{value}}
{
    std::cout << "Parameterized Constructor: RPM set to " << *rpm << "\n";
}

// Destructor (Cleanup)
EngineRPM::~EngineRPM()
{
    std::cout << "Destructor: Cleaning up RPM = " << *rpm << "\n";
    delete rpm;
}

// Operator + (Combine two RPM readings using their average)
EngineRPM EngineRPM::operator+(const EngineRPM &other) const
{
    return EngineRPM((*rpm + *other.rpm) / 2);
}

// Operator == (Compare RPM values)
bool EngineRPM::operator==(const EngineRPM &other) const
{
    return *rpm == *other.rpm;
}

// Operator != (Check if RPM readings differ)
bool EngineRPM::operator!=(const EngineRPM &other) const
{
    return *rpm != *other.rpm;
}

// Operator () (Return the RPM value)
int EngineRPM::operator()() const
{
    return *rpm;
}

// Operator << (Output RPM to std::cout)
std::ostream &operator<<(std::ostream &os, const EngineRPM &obj)
{
    os << "RPM: " << *obj.rpm;
    return os;
}

// _________________Friend Function (Direct Access to Internal RPM)_________________
int getInternalRPM(const EngineRPM &obj)
{
    return *obj.rpm;
}

// Safety Check (Ensure RPM is below safety limit)
bool EngineRPM::isSafe() const
{
    return *rpm < 6000;
}

// Getter Function (Retrieve RPM Value)
int EngineRPM::getRPM() const
{
    return *rpm;
}