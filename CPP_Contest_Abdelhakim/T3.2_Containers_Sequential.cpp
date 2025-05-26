/** ______________________________________________________________________________________________

    🎓 Task 3.2: Sequential Containers & Maps in Automotive Software:
    -----------------------------------------------------------------
    💡 Focus Topics:
        •   "std::list", "std::deque", and "std::map"
        •   Container operations and iteration
        •   Insert iterators, map insertion, search

    🧠 Task:
        Design a C++ program for a "maintenance log system" that tracks service records for different car components.

    Requirements:
        1.  Use a "std::map<std::string", "std::list<std::string>>" to map component names
            (e.g., "Engine", "Brakes") to a list of maintenance tasks.
        2.  Allow adding and displaying tasks using insert iterators.
        3.  Demonstrate usage of std::deque to manage a queue of upcoming tasks.
        4.  Use at least one STL algorithm (std::find, std::sort, etc.) with your container.
        5.  Bonus: Allow user to search if a specific task exists for a component.
    ______________________________________________________________________________________________
**/

/*  =====================================================================================
                                Included Libraries
    =====================================================================================   */
#include <iostream>  // For input/output operations
#include <list>      // For using std::list container
#include <map>       // For using std::map container
#include <deque>     // For using std::deque container
#include <string>    // For using std::string
#include <algorithm> // For using STL algorithms like std::find, std::sort, etc.
#include <iterator>  // For using insert iterators

/*  =====================================================================================
                                Prototypes
    =====================================================================================   */

/*  =====================================================================================
                                Entry Point
    =====================================================================================   */
int main()
{
    // Create a map to hold component names and their maintenance tasks.
    std::map<std::string, std::list<std::string>> maintenanceLogsMap;

    // Add some initial maintenance tasks for components using initializer lists.
    maintenanceLogsMap["Engine"] = {"Oil Change", "Filter Replacement", "Spark Plug Replacement"}; // Engine tasks.
    maintenanceLogsMap["Brakes"] = {"Brake Pad Replacement", "Brake Fluid Check"};                 // Brakes tasks.
    maintenanceLogsMap["Transmission"] = {"Fluid Change", "Filter Replacement"};                   // Transmission tasks.

    // Demonstrate adding more tasks to a component using insert iterators.
    // Insert new tasks into the Engine component's task list.
    std::string component = "Engine Secondary Checks";                                      // Choose the component to add tasks to.
    std::list<std::string> newTasks = {"Air Filter Replacement", "Fuel Injector Cleaning"}; // New tasks to add.
    // std::list<std::string> newTasks = {"Timing Belt Check", "Coolant Flush"};               // New tasks to add.

    // Use std::back_inserter to insert/add newTasks to the end of the Engines's task list.
    std::copy(newTasks.begin(), newTasks.end(), std::back_inserter(maintenanceLogsMap[component]));

    // Display all maintenance tasks for each component.
    std::cout << "=== Maintenance Logs ===\n";
    for (const auto &entry : maintenanceLogsMap)
    {
        std::cout << " Component: " << entry.first << "\n\tTasks:\n"; // "mapName.first" => "Key == std::string"
        for (const auto &task : entry.second)                      // "mapName.second" => "Data == std::list<std::string>"
        {
            std::cout << "\t- " << task << "\n"; // Print each task for the component.
        }
        std::cout << "\n"; // New line for better readability.
    }

    // Demonstrate usage of std::deque to for upcoming tasks (queue-like structure)
    std::deque<std::string> upcomingTasks;                // Create a deque to hold upcoming tasks.
    upcomingTasks.push_back("Tire Rotation");             // Add tasks to the deque at the (end).
    upcomingTasks.push_back("Battery Check");             // Add more tasks at the (end)   of the deque.
    upcomingTasks.push_back("Alignment Check");           // Add more tasks at the (end)   of the deque.
    upcomingTasks.push_back("Exhaust System Inspection"); // Add more tasks at the (end)   of the deque.
    upcomingTasks.push_back("Wiper Blade Replacement");   // Add more tasks at the (end)   of the deque.
    upcomingTasks.push_front("Suspension Check");         // Add more tasks at the (front) of the deque.
    upcomingTasks.push_front("Coolant System Check");     // Add more tasks at the (front) of the deque.

    // Display upcoming tasks.
    std::cout << "\n === Upcoming Tasks Queue: ===\n"; // Print header for upcoming tasks.
    for (const auto &task : upcomingTasks)             // Iterate through the deque to display upcoming tasks.
        std::cout << "\t * " << task << "\n";            // Print each upcoming task.

    // Use STL algorithm: to find if a task exists for a component (bonus requirement).
    std::string searchComponent, searchTask;            // Variables to hold user inputs.
    std::cout << "\n Enter component to search:\t";     // Ask user for component name.
    std::getline(std::cin >> std::ws, searchComponent); // Read component name (skip whitespace). #########
    std::cout << "Enter task to search for:\t";         // Ask user for task name.
    std::getline(std::cin, searchComponent);            // Read Task name.

    auto component_iterator = maintenanceLogsMap.find(searchComponent); // Find the component in the map "mainteneaceLogMap"
    if (component_iterator != maintenanceLogsMap.end())                 // Check if the component exists in the map.
    {
        // Use "std::find" to search for the task in the component's task list.
        auto task_iterator = std::find(component_iterator->second.begin(), component_iterator->second.end(), searchTask);
        if (task_iterator != component_iterator->second.end()) // If the task is found in the list.l
        {
            std::cout << "Task '" << searchTask << "' found for component '" << searchComponent << "'.\n";
        }
        else // If the task is not found in the list.
        {
            std::cout << "Task '" << searchTask << "' not found for component '" << searchComponent << "'.\n";
        }
    }
    else
    {
        std::cout << "Compoenent \"" << searchComponent << "\" not found in the maintenance logs.\n"; // If the component is not found in the map.
    }

    return 0;
}
/*  =====================================================================================
                                Implementation - Methods
    =====================================================================================   */

/*  =====================================================================================
                                Implementation - Operators Overloading
    =====================================================================================   */
