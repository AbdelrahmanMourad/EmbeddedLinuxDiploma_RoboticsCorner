/*
================================================================================
|   C++ Loops - Study Summary
|-------------------------------------------------------------------------------
| - Types of loops:
|     * for      : Known number of iterations.
|     * while    : Unknown number of iterations, checks condition before loop.
|     * do-while : Like while, but always runs at least once (condition checked after).
|     * Range-based for : For iterating over arrays/containers.
|     * Infinite loops  : for(;;) or while(1) for embedded or event-driven code.
| - Tips & Tricks:
|     * Use break to exit a loop early.
|     * Use continue to skip to the next iteration.
|     * Nested loops are allowed.
|     * for(;;) and while(1) are common for infinite loops.
|     * Prefer range-based for for containers/arrays in modern C++.
| --------------------------------
| - Interview Questions & Answers:
| --------------------------------
|     * Q1: Difference between while and do-while?
|       A1: while checks the condition before the loop body (may not run at all).
|          do-while checks after the body (runs at least once).
|     * Q2: When to use for vs while?
|       A2: Use for when the number of iterations is known; while when it's not.
|     * Q3: How to break/continue in nested loops?
|       A3: Use break/continue as usual; break only exits the innermost loop.
|     * Q4: How to avoid infinite loops?
|       A4: Ensure loop conditions eventually become false or use break.
|     * Q5: How to iterate over arrays or STL containers?
|       A5: Use range-based for loops or iterators.
================================================================================
*/

// Include Library.
#include <iostream>

// Example function for demonstration
void drive(void)
{
    std::cout << "Driving...\n";
}

int main()
{
    // Variables Declaration.
    int i{0};
    int j(0);
    int k = 0;

    // 1. do-while loop: runs at least once, condition checked after body
    // Don't use this in production code, just for demo.
    // Condition will not be met after first iteration
    std::cout << "do-while loop example:\n";
    do
    {
        std::cout << i << std::endl; // Print current value of i
        drive();                     // Call the example function
        i = 30;                      // Forces exit after first iteration
    } while (i <= 20); // Don't forget the semicolon ";".

    // Reset i for next loop
    i = 0;

    // 2. while loop: condition checked before body
    std::cout << "\nwhile loop example:\n";
    while (i < 5)
    {
        std::cout << i << std::endl; // Print current value of i
        i++;                         // Increment i to avoid infinite loop
    }

    // 3. for loop: classic counting loop
    std::cout << "\nfor loop example:\n";
    for (i = 0; i <= 3; i++)
    {
        std::cout << i << std::endl;
    }

    // 4. Range-based for loop: modern C++ for arrays/containers
    std::cout << "\nrange-based for loop example:\n";
    int arr[] = {10, 20, 30, 40};
    for (int val : arr)
    {
        std::cout << "val = " << val << std::endl;
    }

    // 5. Infinite while loop with break
    std::cout << "\ninfinite while loop with break:\n";
    int counter = 0;
    while (1)
    {
        std::cout << "counter = " << counter << std::endl; // Print current counter value
        if (++counter == 3)                                // Simulate a condition to break the loop
            break;                                         // Exit after 3 iterations
    }

    // 6. Infinite for loop with break on condition
    std::cout << "\ninfinite for loop with break on event:\n";
    bool Button_Pressed = false;
    int press_sim = 0;
    for (;;)
    {
        std::cout << "Waiting for button... (simulated press " << press_sim << ")\n";
        if (++press_sim == 2)      // Simulate button press after 2 iterations
            Button_Pressed = true; // Simulate button press
        if (Button_Pressed)        // Check if button is pressed
        {
            std::cout << "Button pressed! Exiting loop.\n"; // Print message on button press
            break;                                          // Exit the infinite loop
        }
    }

    // 7. Using continue to skip an iteration
    std::cout << "\nfor loop with continue (skip even numbers):\n";
    for (int k = 0; k < 6; k++)
    {
        if (k % 2 == 0) // Check if k is even
            continue;   // Skip even numbers
        std::cout << "k = " << k << std::endl; // Print only odd numbers
    }

    // 8. Nested loops example
    std::cout << "\nnested loops example:\n";
    for (int row = 1; row <= 2; row++) // Outer loop for rows
    {
        for (int col = 1; col <= 3; col++) // Inner loop for columns
        {
            std::cout << "(" << row << "," << col << ") "; // Print current row and column
        }
        std::cout << std::endl; // New line after each row
    }

    return 0;
}
