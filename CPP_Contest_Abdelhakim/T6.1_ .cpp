/** ______________________________________________________________________________________________
    
    🧠 Task 06: Embedded Timer and Sensor Configuration Tool:
    ----------------------------------------------------------○•

    Create a small embedded-focused simulation that shows how a control unit:
        •   Records time durations
        •   Uses compile-time features for performance
        •   Interfaces with legacy C-style APIs
    ______________________________________________________________________________________________
    ✅ Requirements
        1. Time Handling (Chrono)
            •   Use std::chrono::steady_clock to measure time elapsed during a simulated sensor reading loop.
            •   Print durations using chrono::duration_cast.
        2. Bitsets & Tuples
            •   Use std::bitset<8> to simulate a hardware register with binary flags (e.g., ON/OFF states).
            •   Create a std::tuple to hold grouped sensor data (e.g., ID, float value, timestamp).
        3. Callable and Function Binding
            •   Use std::function and std::bind to simulate assigning a control task 
                (like sensor polling or alerting) to a function pointer or functor.
        4. C Interfacing
            •   Create a mock header file with an extern "C" function (e.g., void c_read_sensor();) 
                and call it from your C++ code.
            💡  Tip: Just simulate this with a C-style function in a separate file or block.
        5. Compile-time Optimization
            •   Use constexpr functions to precompute sensor scaling or thresholds at compile time.
            •   Demonstrate use of:
                ○   constexpr if
                ○   decltype
                ○   Template function or class
    ______________________________________________________________________________________________
    🔧 Bonus (Optional):
        •   Demonstrate a variadic template to log an arbitrary number of sensor values.
        •   Show use of inline namespaces or attributes like [[nodiscard]].
    ______________________________________________________________________________________________
    📝 Submission Checklist:
        •   .cpp files with clean structure and comments.
        •   Include one README.txt or comments explaining compile-time vs runtime parts.
        •   Highlight use of templates, constexpr, and function pointers clearly.
        •   Screenshots or sample output encouraged.
    ______________________________________________________________________________________________
**/

/*  =====================================================================================
                                Included Libraries
    =====================================================================================   */
#include <iostream>

/*  =====================================================================================
                                Prototypes
    =====================================================================================   */

/*  =====================================================================================
                                Entry Point
    =====================================================================================   */

/*  =====================================================================================
                                Implementation - Methods
    =====================================================================================   */

/*  =====================================================================================
                                Implementation - Operators Overloading
    =====================================================================================   */
