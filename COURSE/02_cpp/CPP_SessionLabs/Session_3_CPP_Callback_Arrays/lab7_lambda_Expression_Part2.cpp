
/*________________________________________________________________________________________________________

    Task(8.5): Lambda Expressions and Function Pointers:
    ----------------------------------------------------

        Objective:
            Understand the limitations of converting lambda expressions to function pointers, particularly
            when lambdas capture variables.

        Instructions:
            1. Define Two Lambdas:
                - Lambda 1:
                    - Define a lambda that does not capture any variables and takes a parameter.
                    - This lambda should simply print the value of the parameter.
                - Lambda 2:
                    - Define a lambda that captures a variable from its surrounding scope.
                    - This lambda should print the value of the captured variable and take a parameter.
            2. Create Function Pointers:
                - Attempt to create function pointers for both lambdas.
                - Observe the compilation errors when attempting to create a function pointer for the lambda
                    that captures a variable.
___________________________________________________________________________________________________________*/

/*  ===================================================================
                    Included Libraries.
    =================================================================== */
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
// #include <utility>

/*  ===================================================================
                        Declarations and Definitions
    =================================================================== */
namespace HelpingFunctions
{
    void printSeparator(const std::string &&str)
    {
        std::cout << "\n-----------------------------------------\n"
                  << str
                  << "\n-----------------------------------------\n";
    };
};
/*  ===================================================================
                        main() - Entry Point
    =================================================================== */
int main()
{
    /*-----------------------------------------------------------------------------------------*/
    HelpingFunctions::printSeparator(std::move("Lambda Expressions and Function Pointers:"));
    /*-----------------------------------------------------------------------------------------*/
    // Declare variables for demonstration.
    int passedValue = 10;   // variable to be passed by value.
    int capturedValue = 42; // Variable to be captured by value.

    // Define two Lambdas:

    // Lambda 1: No capture, takes a parameter, prints the value.
    // [](int passedValue)
    auto lambda01 = [](int passedValue)
    { std::cout << "lambda 01 passed_value =   " << passedValue << std::endl; };

    // Lambda 2: Captures a variable from surrounding scope, prints the value of the captured variable and takes a parameter.
    // [capturedValue](int passedValue)
    auto lambda02 = [capturedValue](int passedValue)
    { std::cout << "lambda 02 captured_value = " << capturedValue << std::endl; };

    // calling the lambdas directly:
    std::cout << "\nCalling Lambdas Directly:\n";
    lambda01(passedValue);
    lambda02(passedValue);

    // Using function pointer for lambda01 (valid).
    void (*funcPtrToLambda01)(int) = lambda01;
    std::cout << "\nCalling funPtr2Lambds:\n";
    funcPtrToLambda01(passedValue); // Call the function pointer with a value passed.
    funcPtrToLambda01(15);          // Call the function pointer with a value passed.

    // Attempting function pointer for lambda2 (invalid)
    // void (*funcPtrToLambda02)(int) = lambda02; // This will cause a compilation error because Lambda 2 captures a variable.
    // void (*funcPtr2)(int) = lambda2; // Uncommenting this line causes an error.

    /*-----------------------------------------------------------------------------------------*/
    HelpingFunctions::printSeparator(std::move("Using Lambdas with default values, and using mutable:"));
    /*-----------------------------------------------------------------------------------------*/
    int x = 50, y = 100;

    // Print before:
    // std::cout << "Original x value outside lambda: " << x << std::endl; // Still 10, because 'x' was captured by value
    // std::cout << "Original y value outside lambda: " << y << std::endl; // Still 100, because 'y' was captured by value

    /****use "mutable" to modify the captured by value****/
    /*captured defult value*/
    auto mutableLambda = [x](int y = 0) mutable
    {
        std::cout << "Original x = " << x << "\t\t"; // 0 default, 10 if captured by value
        std::cout << ",Original y = " << y << "\n";  // 0 default, 100 if passed by value

        x += 10; // Allowed because of 'mutable'
        y += 10; // Allowed because of 'mutable'

        std::cout << "Modified x = " << x << "\t\t"
                  << ",Modified y = " << y << "\n\n";
    };

    // call the lambda:
    std::cout << "Calling mutableLambda with passed value(y=100):\n";
    mutableLambda(y);
    std::cout << "Calling mutableLambda with default value(y=0):\n";
    mutableLambda();
    mutableLambda(y);
    mutableLambda(y);

    /*-----------------------------------------------------------------------------------------*/
    HelpingFunctions::printSeparator(std::move("Calling Lambda directly on declaration:"));
    /*-----------------------------------------------------------------------------------------*/
    // Calling on declaration.
    []()
    { std::cout << "Lambda exected instantly!" << std::endl; }(); // Calls the lambda immediately.

    /*-----------------------------------------------------------------------------------------*/
    HelpingFunctions::printSeparator(std::move("Calling Lambda without pointers:"));
    /*-----------------------------------------------------------------------------------------*/
    auto Print = []()
    { std::cout << "Lambda called without function pointer.\n"; };
    Print(); // Simply calling the lambda without a function pointer.
    std::cout << std::endl
              << std::endl
              << std::endl;

    /**
     *********************************************************************************************
     * Lambda - 10 - Different Use Cases
     **********************************************************************************************
     **/
    /*-----------------------------------------------------------------------------------------*/
    HelpingFunctions::printSeparator(std::move("(1.) Lambda Returning a Value: \nUse Case: ADC Calibration Correction"));
    /*-----------------------------------------------------------------------------------------*/
    auto calibrateADC = [](float value) -> float
    {   return value * 1.1; /*Apply a gain factor for calibration*/ };

    float adcInput = 3.5;                          //  Example ADC input value.
    float correctedValue = calibrateADC(adcInput); // Example ADC corrected output value.
    std::cout << "ADC= " << adcInput << "\t,Calibrated ADC= " << correctedValue << std::endl;

    /*-----------------------------------------------------------------------------------------*/
    HelpingFunctions::printSeparator(std::move("(2.) Using \'std::for_each\' for CAN Message Filtering:\nUse Case: Filtering Even CAN Message IDs"));
    /*-----------------------------------------------------------------------------------------*/
    // #include <vector>
    // #include <algorithm>
    std::vector<int> canMessageIDs = {100, 101, 102, 103, 104}; // Define vactor of integers representing can message IDs.
    std::cout << "Accepted CAN Messages: ";
    std::for_each(canMessageIDs.begin(), canMessageIDs.end(), [](int id)
                  {
                    if (id % 2 == 0) 
                        {std::cout << id << " "; } }); // Filter even IDs and print them.
    std::cout << std::endl;

    /*-----------------------------------------------------------------------------------------*/
    HelpingFunctions::printSeparator(std::move("(3.) Using \'std::for_each\' for GPIO Pin Control: \nUse Case: Printing GPIO Pin States Dynamically"));
    /*-----------------------------------------------------------------------------------------*/
    // #include <vector>
    // #include <algorithm>
    std::vector<bool> gpioStates = {true, false, true, false, true};

    std::cout << "GPIO Pin States:\n";
    std::for_each(gpioStates.begin(), gpioStates.end(), [](bool state)
                  { std::cout << (state ? "HIGH" : "LOW") << std::endl; });

    /*-----------------------------------------------------------------------------------------*/
    HelpingFunctions::printSeparator(std::move("(4.) Using a Lambda for Interrupt Handling : \nUse Case: Handling Different Interrupt Request "));
    /*-----------------------------------------------------------------------------------------*/

    auto interruptHandler = [](int irq)
    { std::cout << "Handling IRQ: " << irq << std::endl; };

    interruptHandler(5); // Simulate handling an interrupt

    /*-----------------------------------------------------------------------------------------*/
    HelpingFunctions::printSeparator(std::move("(5.) Task Scheduling : \nUse Case: Executing a Task Every Interval "));
    /*-----------------------------------------------------------------------------------------*/
    auto taskScheduler = [](int interval)
    { std::cout << "Task executed every " << interval << "ms" << std::endl; };

    taskScheduler(100);

    /*-----------------------------------------------------------------------------------------*/
    HelpingFunctions::printSeparator(std::move("(6.) State Machine Transitions : \nUse Case: Managing State Changes in an Embedded System "));
    /*-----------------------------------------------------------------------------------------*/
    auto stateTransition = [](int state)
    { std::cout << "Transitioning to state: " << state << std::endl; };

    stateTransition(2); // Transitioning state machine

    /*-----------------------------------------------------------------------------------------*/
    HelpingFunctions::printSeparator(std::move("(7.) Signal Processing : \nUse Case: Doubling an Analog Signal Value "));
    /*-----------------------------------------------------------------------------------------*/
    auto processSignal = [](int data)
    { return data * 2; };

    std::cout << "Processed Signal: " << processSignal(50) << std::endl;

    /*-----------------------------------------------------------------------------------------*/
    HelpingFunctions::printSeparator(std::move("(8.) Low Power Mode Switching : \nUse Case: Switching Between Power States "));
    /*-----------------------------------------------------------------------------------------*/
    auto switchPowerMode = [](bool active)
    { std::cout << "System mode: " << (active ? "Active" : "Low Power") << std::endl; };

    switchPowerMode(false);

    /*-----------------------------------------------------------------------------------------*/
    HelpingFunctions::printSeparator(std::move("(9.) Error Handling: \nUse Case: Logging Error Codes Dynamically "));
    /*-----------------------------------------------------------------------------------------*/
    auto handleError = [](int errorCode)
    { std::cout << "Handling error code: " << errorCode << std::endl; };

    handleError(404); // Simulating error handling

    /*-----------------------------------------------------------------------------------------*/
    HelpingFunctions::printSeparator(std::move("(10.) Data Formatting for Communication Protocols : \nUse Case: Applying a Mask to Format Packet Data"));
    /*-----------------------------------------------------------------------------------------*/
    auto formatPacket = [](int payload)
    { return payload | 0xFF; };

    std::cout << "Formatted Packet: " << formatPacket(128) << std::endl;

    /*-----------------------------------------------------------------------------------------*/
    HelpingFunctions::printSeparator(std::move("(11.) Lambda Returning a Boolean (std::find_if): \nUse Case: Find the First Even Number"));
    /*-----------------------------------------------------------------------------------------*/
    // #include <vector>
    // #include <algorithm>

    std::vector<int> numbers = {3, 7, 8, 11, 14, 21};

    auto isEven = [](int num) -> bool
    { return num % 2 == 0; };

    auto it = std::find_if(numbers.begin(), numbers.end(), isEven);

    if (it != numbers.end())
        std::cout << "First even number: " << *it << std::endl;
    else
        std::cout << "No even numbers found." << std::endl;

    /*-----------------------------------------------------------------------------------------*/
    HelpingFunctions::printSeparator(std::move("(12.) Lambda Returning an Integer (std::transform): \nUse Case: Doubling Each Element"));
    /*-----------------------------------------------------------------------------------------*/
    // #include <vector>
    // #include <algorithm>
    std::vector<int> values = {1, 2, 3, 4, 5};
    std::vector<int> doubled(values.size());

    std::transform(values.begin(), values.end(), doubled.begin(),
                   [](int val) -> int
                   { return val * 2; });

    std::cout << "Doubled values: ";
    for (int num : doubled)
        std::cout << num << " ";
    std::cout << std::endl;

    /*-----------------------------------------------------------------------------------------*/
    HelpingFunctions::printSeparator(std::move("(13.) Lambda Returning a String (std::map + std::transform): \nUse Case: Converting Values to Messages"));
    /*-----------------------------------------------------------------------------------------*/
    // #include <vector>
    // #include <algorithm>
    // #include <string>
    std::vector<int> statusCodes = {200, 404, 500};
    std::vector<std::string> statusMessages(statusCodes.size());

    std::transform(statusCodes.begin(), statusCodes.end(), statusMessages.begin(),
                   [](int code) -> std::string
                   {
                       if (code == 200)
                           return "OK";
                       if (code == 404)
                           return "Not Found";
                       return "Server Error";
                   });

    std::cout << "Status messages: ";
    for (const auto &msg : statusMessages)
        std::cout << msg << ", ";
    std::cout << std::endl;

    /*-----------------------------------------------------------------------------------------*/
    HelpingFunctions::printSeparator(std::move("(14.) Lambda Returning a Floating Point (std::accumulate): \nUse Case: Calculating the Average"));
    /*-----------------------------------------------------------------------------------------*/
    // #include <vector>
    // #include <numeric>
    std::vector<int> numbers = {10, 20, 30, 40, 50};

    auto sumLambda = [](double acc, int num) -> double
    { return acc + num; };

    double average = std::accumulate(numbers.begin(), numbers.end(), 0.0, sumLambda) / numbers.size();

    std::cout << "Average: " << average << std::endl;

    /************************************************************************************/
    return 0;
}

/*  =================================================================================
    Summary:
    =================================================================================

    ---- Lambda Expressions Overview ----
        A lambda expression in C++ allows the creation of anonymous functions on-the-fly.
        Syntax:
            _________________________________________________________________
            |                                                               |
            |       [capture] (parameters) -> returnType { body }           |
            |                                                               |
            |_______________________________________________________________|

    ---- Capture Mechanisms ----
        - []            : No capture (stateless lambda)
        - [var]         : Capture var by value (copy stored within lambda)
        - [&var]        : Capture var by reference (modifications affect original)
        - [var1, &var2] : Capture var1 by value and var2 by reference
        - [=]           : Capture all variables by value
        - [=var]        : capture var by value and others by reference
        - [&]           : Capture all variables by reference

    --- Keywords Used with Lambdas ---
        - mutable   → Allows modifications of captured-by-value variables.
        - constexpr → Makes the lambda compile-time evaluable if possible.
        - noexcept  → Specifies that the lambda won't throw exceptions.
        - auto      → Used to infer the return type automatically.

    ---- Default Values in Lambdas ----
        - Default values can be provided for function parameters.
        - Captured variables cannot have default values; their values are fixed at capture time.

    ---- Calling a Lambda ----
        - Lambdas can be executed instantly upon declaration using `()`.
        - No function pointer is needed; they can be called like regular functions.

    ---- Function Pointers and Lambdas ----
        - A function pointer can store the address of a regular function.
        - Stateless lambdas (without captures) can be converted to function pointers.
        - Capturing lambdas (stateful lambdas) **cannot** be assigned to function pointers because
            they generate a unique callable object with internal storage.

    NOTE:
    ---- Key Takeaway ----
        Lambda expressions with captures generate closure objects, preventing conversion
        to regular function pointers. However, non-capturing lambdas can be safely assigned.

    =================================================================================  */