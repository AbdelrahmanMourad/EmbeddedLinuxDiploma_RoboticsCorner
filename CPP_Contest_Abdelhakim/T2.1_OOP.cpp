/** ==============================================================================================
 ✅ Task 01: Implement the EngineRPM Class with Special Member Functions:
    ================================================================
        🔧 Class Requirement
        - Create a class EngineRPM that stores an RPM value using dynamic memory allocation (new int()).

        class EngineRPM {
        private:
            int* rpm;  // dynamically allocated RPM value

        public:
            // Special Member Functions
            EngineRPM();                             // Default: initializes RPM to 0
            EngineRPM(int value);                    // Parameterized constructor
            EngineRPM(const EngineRPM& other);       // Copy constructor
            EngineRPM& operator=(const EngineRPM&);  // Copy assignment operator
            ~EngineRPM();                            // Destructor
        };

        📌 Memory Rules:
        - Must use new/delete
        - Implement deep copy
        - Use std::cout in destructor to indicate cleanup (for testing/debugging)

    ----------------------------------------------------------------------------------------------
    ✅Task 01
    ----------

        Implement the EngineRPM  Class with special Member Functions
        🔧Class Requirement

        Create a class EngineRPM that stores an RPM value using (i.e., using new int()).

        class EngineRPM {
        private:
            int* rpm;  // dynamically allocated RPM value

        public:
            // Special Member Functions
            EngineRPM();                             // Default: initializes RPM to 0
            EngineRPM(int value);                    // Parameterized constructor
            EngineRPM(const EngineRPM& other);       // Copy constructor
            EngineRPM& operator=(const EngineRPM&);  // Copy assignment
            ~EngineRPM();                            // Destructor
        };

        📌Memory Rules
        Must use new/delete
        Implement deep Copy
        Use std::cout in destructor to indicate cleanup (for demo/testing)

    ==============================================================================================


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
    int *rpm_; // Dynamically allocated RPM value

public:
    // Constructor & Destructor
    EngineRPM();                                  // Default constructor
    EngineRPM(int value);                         // Parameterized constructor
    EngineRPM(const EngineRPM &other);            // Copy constructor
    EngineRPM &operator=(const EngineRPM &other); // Copy assignment operator
    ~EngineRPM();                                 // Destructor

    // Getter function
    int getRPM() const;
};

/*  -----------------------------------------------------------------
                            Entry Point
    -----------------------------------------------------------------*/
int main()
{
    EngineRPM engine1;           // Default constructor
    EngineRPM engine2(3000);     // Parameterized constructor
    EngineRPM engine3 = engine2; // Copy constructor
    engine1 = engine2;           // Copy assignment

    std::cout << "Engine1 RPM: " << engine1.getRPM() << "\n";
    std::cout << "Engine2 RPM: " << engine2.getRPM() << "\n";
    std::cout << "Engine3 RPM: " << engine3.getRPM() << "\n";

    return 0;
}

/*  -----------------------------------------------------------------
                            Implementation
    -----------------------------------------------------------------*/
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

// Copy Assignment Operator (Deep Copy)
EngineRPM &EngineRPM::operator=(const EngineRPM &other)
{
    if (this != &other)
    {                              // Prevent self-assignment
        delete rpm_;                // Free previous memory
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