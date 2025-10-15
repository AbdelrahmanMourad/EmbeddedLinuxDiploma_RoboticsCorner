/** ______________________________________________________________________________________________
    
    ✅ Task 02: Overload Operators for Embedded Logic Simulation:
    -------------------------------------------------------------
        🔁 Operators to Overload:
            - Operator +  → Combine two RPM readings (e.g., average of two sensors)
            - Operator == → Compare two RPM values
            - Operator != → Check if two RPM readings differ
            - Operator ()  → Return the RPM value from the object
            - Operator <<  → Output RPM to std::cout

     📌 Example Usage:
            EngineRPM sensor1(3000);
            EngineRPM sensor2(3200);
            EngineRPM average = sensor1 + sensor2;

            std::cout << "Average RPM: " << average << "\n";

            if (sensor1 != sensor2) {
                std::cout << "RPM mismatch detected\n";
            }
    ______________________________________________________________________________________________
    ✅  Task 02 : Overload Operators for Embedded Logic Simulation
    🔁 Operator to Overload
        "+"     --> Purpose -->     Combine two RPM readings (e.g., average of two sensors)
        "=="    --> Purpose -->     Compare two RPM values
        "!="    --> Purpose -->     Check if two readings differ
        "()"    --> Purpose -->     Return the RPM value from the object
        "<<"    --> Purpose -->     Output the RPM to std::cout
    ex.
        EngineRPM sensor1(3000);
        EngineRPM sensor2(3200);
        EngineRPM average = sensor1 + sensor2;

        std::cout << "Average RPM: " << average << "\n";

        if (sensor1 != sensor2) {
            std::cout << "RPM mismatch detected\n";
        }
    ______________________________________________________________________________________________
**/

/*  =====================================================================================
                                Included Libraries
    =====================================================================================   */
#include <iostream>

/*  =====================================================================================
                                Prototypes
    =====================================================================================   */
class EngineRPM
{
private:
    int *rpm_; // Dynamically allocated RPM value

public:
    // Constructor & Destructor
    EngineRPM();                       // Default constructor
    EngineRPM(int value);              // Parameterized constructor
    EngineRPM(const EngineRPM &other); // Copy constructor
    ~EngineRPM();                      // Destructor
    int getRPM() const;                // Getter function

    //___________Operators_to_Overload__________________
    EngineRPM &operator=(const EngineRPM &other); // Copy assignment operator
    EngineRPM operator+(const EngineRPM &other) const;
    bool operator==(const EngineRPM &other) const;
    bool operator!=(const EngineRPM &other) const;
    int operator()() const;
    friend std::ostream &operator<<(std::ostream &os, const EngineRPM &obj);
};


/*  =====================================================================================
                                Entry Point
    =====================================================================================   */
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

    std::cout << "Sensor1 RPM via function call: " << sensor1() << "\n"; // Using overloaded () operator

    return 0;
}

/*  =====================================================================================
                            Implementation - Methods
    =====================================================================================   */
// Default Constructor (Initializes RPM to 0)
EngineRPM::EngineRPM() : rpm_{new int{0}}
{
    std::cout << "Default Constructor: RPM set to 0\n";
}

// Parameterized Constructor (Initializes RPM to the given value)
EngineRPM::EngineRPM(int value) : rpm_{new int{value}}
{
    std::cout << "Parameterized Constructor: RPM set to " << *rpm_ << "\n";
}

// Copy Constructor (Deep Copy)
EngineRPM::EngineRPM(const EngineRPM &other) : rpm_{new int{*other.rpm_}}
{
    std::cout << "Copy Constructor: RPM copied, value = " << *rpm_ << "\n";
}

/*  =====================================================================================
                            Implementation - Operators Overloading
    =====================================================================================   */
// Copy Assignment Operator (Deep Copy)
EngineRPM &EngineRPM::operator=(const EngineRPM &other)
{
    if (this != &other)
    {                                // Prevent self-assignment
        delete rpm_;                 // Free previous memory
        rpm_ = new int{*other.rpm_}; // Allocate new memory and copy value
        std::cout << "Copy Assignment: RPM copied, value = " << *rpm_ << "\n";
    }
    return *this;
}

// Destructor (Cleanup)
EngineRPM::~EngineRPM()
{
    std::cout << "Destructor: Cleaning up RPM = " << *rpm_ << "\n";
    delete rpm_;
}

// Getter Function (Retrieve RPM Value)
int EngineRPM::getRPM() const
{
    return *rpm_;
}

// Default Constructor (Initializes RPM to 0)
EngineRPM::EngineRPM() : rpm_{new int{0}}
{
    std::cout << "Default Constructor: RPM set to 0\n";
}

// Parameterized Constructor (Initializes RPM to the given value)
EngineRPM::EngineRPM(int value) : rpm_{new int{value}}
{
    std::cout << "Parameterized Constructor: RPM set to " << *rpm_ << "\n";
}

// Copy Constructor (Deep Copy)
EngineRPM::EngineRPM(const EngineRPM &other) : rpm_{new int{*other.rpm_}}
{
    std::cout << "Copy Constructor: RPM copied, value = " << *rpm_ << "\n";
}

// Destructor (Cleanup)
EngineRPM::~EngineRPM()
{
    std::cout << "Destructor: Cleaning up RPM = " << *rpm_ << "\n";
    delete rpm_;
}

////////////////////////// Operators Overloading //////////////////////////////////////////

// Copy Assignment Operator (Deep Copy)
EngineRPM &EngineRPM::operator=(const EngineRPM &other)
{
    if (this != &other)
    {                                // Prevent self-assignment
        delete rpm_;                 // Free previous memory
        rpm_ = new int{*other.rpm_}; // Allocate new memory and copy value
        std::cout << "Copy Assignment: RPM copied, value = " << *rpm_ << "\n";
    }
    return *this;
}

// Operator + (Combine two RPM readings using their average)
EngineRPM EngineRPM::operator+(const EngineRPM &other) const
{
    return EngineRPM((*rpm_ + *other.rpm_) / 2);
}

// Operator == (Compare RPM values)
bool EngineRPM::operator==(const EngineRPM &other) const
{
    return *rpm_ == *other.rpm_;
}

// Operator != (Check if RPM readings differ)
bool EngineRPM::operator!=(const EngineRPM &other) const
{
    return *rpm_ != *other.rpm_;
}

// Operator () (Return the RPM value)
int EngineRPM::operator()() const
{
    return *rpm_;
}

// Operator << (Output RPM to std::cout)
std::ostream &operator<<(std::ostream &os, const EngineRPM &obj)
{
    os << "RPM: " << *obj.rpm_;
    return os;
}
