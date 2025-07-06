// /*────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────*/
// /*  
// 🔧 RAII Example — Smart Pointer for Hardware Resource
//         In a real embedded system, this ensures that the motor driver is always
//         initialized and properly cleaned up—critical for safety in automotive applications.
// */
// class MotorController
// {
//     std::unique_ptr<HardwareDriver> driver; // RAII handle

// public:
//     MotorController()
//         : driver(std::make_unique<HardwareDriver>())
//     {
//         // Resource is acquired at construction and released automatically
//     }
// };

// /*
// 🚗 AUTOSAR-Like Example — Injected Dependency via References
//         This approach avoids unnecessary copies and ensures deterministic behavior,
//         which aligns well with the AUTOSAR platform design philosophy.
// */

// class ECU
// {
//     ConfigManager &config; // Reference must be initialized
//     const uint8_t nodeId;  // Immutable

// public:
//     ECU(ConfigManager &cfg, uint8_t id)
//         : config(cfg), nodeId(id)
//     {
//         // No copy of config—reference guarantees up-to-date access
//         // nodeId never changes once set
//     }
// };
// /*────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────*/


/* ────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
 * ──────────────────────────────────────────────────────────────
 * Constructor Initializer List – What Can and Cannot Be Initialized
 * ──────────────────────────────────────────────────────────────
 * ✅ Allowed:
 *   - const members            → Must be initialized here.
 *   - reference members (&)    → Must be bound at construction.
 *   - base classes             → Required in derived class constructors.
 *   - member objects           → Prefer initializer list to avoid default + copy.
 *   - move/copy construction   → Use initializer list for efficiency.
 *   - array of objects         → Constructed via default/member constructors.
 *
 * ❌ Not Initialized Here:
 *   - static members           → Initialized outside the class.
 *   - arrays of built-ins      → Must be filled in constructor body.
 *   - union members            → Special case; typically not used here.
 *   - most regular built-ins   → Optional, but not required.
 *
 * Summary: Use initializer lists when necessary and when doing so avoids
 * performance penalties or construction ambiguity—especially in RAII or
 * AUTOSAR contexts where deterministic behavior is critical.
 *
 * ────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
 */

#include <iostream>
#include <memory>
#include <string>

/*
 * ──────────────────────────────────────────────────────────────
 * SensorDriver – Represents a low-level RAII-enabled hardware module
 * ──────────────────────────────────────────────────────────────
 * - Acquires the hardware resource on construction
 * - Releases the resource (clean shutdown) on destruction
 */
class SensorDriver
{
public:
    SensorDriver(const std::string &port) { std::cout << "[SensorDriver] Initialized on port " << port << '\n'; }
    ~SensorDriver() { std::cout << "[SensorDriver] Cleanly shut down\n"; }
    int read() const { return 42; /* Simulated sensor reading*/ }
};

/*
 * ──────────────────────────────────────────────────────────────
 * SensorConfig – Read-only configuration data injected by reference
 * ──────────────────────────────────────────────────────────────
 * - Immutable after creation
 * - Can be reused across multiple components
 */
class SensorConfig
{
public:
    const std::string port;
    const int samplingRate;
    SensorConfig(std::string p, int rate) : port(std::move(p)), samplingRate(rate) {}
};

/*
 * ──────────────────────────────────────────────────────────────
 * SensorManager – AUTOSAR-style service component
 * ──────────────────────────────────────────────────────────────
 * - Uses initializer list for:
 *     → reference (SensorConfig&)
 *     → RAII object (std::unique_ptr<SensorDriver>)
 *     → const ID
 * - Demonstrates safe encapsulation of ownership and initialization
 */
class SensorManager
{
    const SensorConfig &config;           // Reference: must use initializer list
    std::unique_ptr<SensorDriver> driver; // RAII: manages low-level driver
    const int sensorId;                   // Const member

public:
    SensorManager(const SensorConfig &cfg, int id) : config(cfg), driver(std::make_unique<SensorDriver>(cfg.port)), sensorId(id) {}
    void sampleSensor() const
    {
        std::cout << "[SensorManager #" << sensorId << "] Reading: "
                  << driver->read() << " @ " << config.samplingRate << " Hz\n";
    }
};

/*
 * ──────────────────────────────────────────────────────────────
 * main – Simulated embedded entrypoint
 * ──────────────────────────────────────────────────────────────
 * - Creates a SensorConfig with immutable properties
 * - Passes it to the SensorManager, which performs a sensor read
 */
int main()
{
    SensorConfig myConfig("COM3", 10);
    SensorManager manager(myConfig, 7);

    manager.sampleSensor();

    return 0;
}

/****************************************************************************************
 * To Run:                                                                              *
 *          "g++ -std=c++17 sensor_system.cpp -o sensor_system && ./sensor_system"      *
 ****************************************************************************************
 */