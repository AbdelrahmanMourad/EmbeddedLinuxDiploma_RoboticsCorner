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
#include <iostream>    // For input/output
#include <chrono>      // For time measurement
#include <bitset>      // For simulating hardware registers
#include <tuple>       // For grouping sensor data
#include <functional>  // For std::function and std::bind
#include <thread>      // For std::this_thread::sleep_for
#include <random>      // For simulating sensor values
#include <type_traits> // For decltype, std::is_same
#include <cstdint>     // For fixed-width integer types

/*  =====================================================================================
                                Mock C Header (C Interfacing)
    =====================================================================================   */
// Simulate a legacy C API function
extern "C" void c_read_sensor()
{
    std::cout << "[C API] Reading sensor (legacy C function called)\n";
}

/*  =====================================================================================
                                Compile-time Optimization
    =====================================================================================   */
// constexpr function for scaling sensor values at compile time
constexpr float scale_sensor(float value, float factor)
{
    return value * factor;
}

// Template for compile-time threshold check
template <typename T>
constexpr bool is_above_threshold(T value, T threshold)
{
    return value > threshold;
}

/*  =====================================================================================
                                Variadic Template Logger (Bonus)
    =====================================================================================   */
// Variadic template to log any number of sensor values
template <typename... Args>
void log_sensor_values(Args &&...args)
{
    std::cout << "[Logger] Sensor values: ";
    ((std::cout << args << " "), ...); // Fold expression (C++17)
    std::cout << std::endl;
}

/*  =====================================================================================
                                Sensor Polling Functor
    =====================================================================================   */
struct SensorPoller
{
    void operator()() const
    {
        std::cout << "[Functor] Polling sensor...\n";
    }
};
/*  =====================================================================================
                                Namespace for Versioning (Inline Namespace)
    =====================================================================================   */
 namespace v1
    {
        inline namespace impl
        {
            void versioned_func() { std::cout << "Using versioned function (v1)\n"; }
        }
    }

/*  =====================================================================================
                                Main Entry Point
    =====================================================================================   */
int main()
{
    // 1. Time Handling (Chrono)
    std::cout << "=== Simulated Sensor Reading Loop ===\n";
    auto start = std::chrono::steady_clock::now(); // Start timer

    float sensor_sum = 0.0f;
    int num_reads = 5;
    std::default_random_engine eng{std::random_device{}()};
    std::uniform_real_distribution<float> dist(10.0f, 100.0f);

    for (int i = 0; i < num_reads; ++i)
    {
        float value = dist(eng); // Simulate sensor value
        sensor_sum += value;
        std::cout << "Sensor reading " << i + 1 << ": " << value << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate delay
    }

    auto end = std::chrono::steady_clock::now(); // End timer
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Total time elapsed: " << duration.count() << " ms\n\n";

    // 2. Bitsets & Tuples
    std::bitset<8> hw_register; // 8-bit hardware register
    hw_register.set(0);         // Set bit 0 (e.g., sensor ON)
    hw_register.set(3);         // Set bit 3 (e.g., alert ON)
    std::cout << "Hardware register state: " << hw_register << std::endl;

    // Tuple for grouped sensor data: (ID, value, timestamp)
    using SensorTuple = std::tuple<int, float, std::uint64_t>;
    SensorTuple sensor_data = std::make_tuple(42, 55.5f, static_cast<std::uint64_t>(std::chrono::steady_clock::now().time_since_epoch().count()));
    std::cout << "Sensor Tuple - ID: " << std::get<0>(sensor_data)
              << ", Value: " << std::get<1>(sensor_data)
              << ", Timestamp: " << std::get<2>(sensor_data) << std::endl;

    // 3. Callable and Function Binding
    std::function<void()> control_task; // Function pointer-like object

    // Assign a lambda
    control_task = []()
    { std::cout << "[Lambda] Control task: Alert triggered!\n"; };
    control_task();

    // Assign a functor
    control_task = SensorPoller();
    control_task();

    // Assign a regular function using std::bind
    control_task = std::bind(c_read_sensor);
    control_task();

    // 4. C Interfacing
    std::cout << "\nCalling legacy C API directly:\n";
    c_read_sensor();

    // 5. Compile-time Optimization
    constexpr float scale = scale_sensor(10.0f, 1.5f); // Computed at compile time
    std::cout << "Compile-time scaled value: " << scale << std::endl;

    float runtime_value = 25.0f;
    float runtime_scaled = scale_sensor(runtime_value, 2.0f); // Computed at runtime
    std::cout << "Runtime scaled value: " << runtime_scaled << std::endl;

    // Use constexpr if and decltype in a template
    int int_val = 15;
    float float_val = 15.5f;
    std::cout << "Is int_val above threshold 10? " << (is_above_threshold(int_val, 10) ? "Yes" : "No") << std::endl;
    std::cout << "Is float_val above threshold 20.0? " << (is_above_threshold(float_val, 20.0f) ? "Yes" : "No") << std::endl;

    // 6. Bonus: Variadic template logger
    log_sensor_values(1, 2.5, "OK", 42);

    // 7. Bonus: [[nodiscard]] attribute and inline namespace
    [[nodiscard]] auto get_sensor_id() -> int { return 123; }
    int sid = get_sensor_id(); // Compiler warns if result is unused

    // Inline namespace demonstration (for versioning, not strictly needed here) (Not working in C++14)
    // namespace v1
    // {
    //     inline namespace impl
    //     {
    //         void versioned_func() { std::cout << "Using versioned function (v1)\n"; }
    //     }
    // }
    v1::versioned_func();

    return 0;
}
/*  =====================================================================================
    README / Documentation for Beginners

    - Compile-time vs Runtime:
        * constexpr functions (like scale_sensor) are evaluated at compile time if arguments are known.
        * Templates with constexpr if allow code to be chosen at compile time.
        * Runtime values (like sensor readings) are computed during program execution.

    - Templates:
        * is_above_threshold is a template function that works for any type (int, float, etc).
        * log_sensor_values is a variadic template that can log any number of arguments.

    - Function pointers and functors:
        * std::function can hold lambdas, functors, or regular functions.
        * std::bind can turn a function into a callable object.

    - C Interfacing:
        * extern "C" allows C++ to call C functions (simulated here).

    - Bitset and Tuple:
        * std::bitset simulates hardware registers.
        * std::tuple groups different types of sensor data together.

    - [[nodiscard]]:
        * Warns if the return value of a function is ignored.

    - Inline namespace:
        * Used for versioning APIs (not required, but shown for completeness).
=====================================================================================   */
