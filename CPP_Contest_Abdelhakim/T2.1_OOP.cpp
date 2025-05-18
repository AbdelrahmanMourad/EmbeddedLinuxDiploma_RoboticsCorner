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
// #include <iostream> // For console input/output
// #include <fstream>  // For file handling
// #include <string>   // For handling string inputs

/*  -----------------------------------------------------------------
                            Declarations
    -----------------------------------------------------------------*/

/*  -----------------------------------------------------------------
                            Prototypes
    -----------------------------------------------------------------*/

/*  -----------------------------------------------------------------
                            Entry Point
    -----------------------------------------------------------------*/

/*  -----------------------------------------------------------------
                            Implementation
    -----------------------------------------------------------------*/
