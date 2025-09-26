/*
================================================================================
|   C++ for Loop Patterns - Quick Reference Table
|-------------------------------------------------------------------------------
| Use Case                  | Example Pattern
|---------------------------|-----------------------------------------------|
| Classic increment         | for (int i = 0; i < N; i++)                  |
| Classic decrement         | for (int i = N; i >= 0; i--)                 |
| Custom step               | for (int i = 0; i < N; i += step)            |
| Multiple variables        | for (int i = 0, j = N; i < j; i++, j--)      |
| Infinite loop             | for (;;)                                     |
| Range-based (array/list)  | for (int n : arr)                            |
| Range-based with ref      | for (int& n : arr)                           |
| No initialization         | int k; for (; k < N; k++)                    |
| No condition              | for (int i = 0;; i++)                        |
| No increment              | for (int i = 0; i < N;) { ...; i++; }        |
| Nested loops              | for (...) { for (...) { ... } }              |
================================================================================

================================================================================
|   Prefix vs Postfix Increment (++i vs i++)
|-------------------------------------------------------------------------------
| Prefix (++i):   Increments the value, then uses it in the expression.
|                 int a = 10;
|                 int b = ++a; // a = 11, b = 11
|
| Postfix (i++):  Uses the value in the expression, then increments it.
|                 int x = 10;
|                 int y = x++; // y = 10, x = 11
================================================================================
*/

#include "iostream"

int main()
{
    // 1. Classic for loop (increment)
    for (int i = 0; i <= 5; i++)
    {
        std::cout << "index = " << i << std::endl;
    }

    // 2. Classic for loop (decrementing)
    for (int i = 5; i >= 0; i--)
    {
        std::cout << "reverse index = " << i << std::endl;
    }

    // 3. Custom step (increment by 2)
    for (int i = 0; i <= 10; i += 2)
    {
        std::cout << "even index = " << i << std::endl;
    }

    // 4. Multiple variables in for loop
    for (int i = 0, j = 10; i < j; i++, j--)
    {
        std::cout << "i = " << i << ", j = " << j << std::endl;
    }

    // 5. Infinite loop (use with caution!)
    // for (;;) {
    //     std::cout << "Infinity" << "\n";
    // }

    // 6. Range-based for loop (array)
    int arr[] = {1, 2, 3, 4, 5};
    for (int n : arr)
    {
        std::cout << "number " << n << "\n";
    }

    // 7. Range-based for loop (list of elements)
    for (int n : {10, 12, 30, 4, 45})
    {
        std::cout << "number " << n << "\n";
    }

    // 8. Range-based for loop with reference (modify elements)
    for (int& n : arr)
    {
        n *= 2; // double each element
    }
    for (int n : arr)
    {
        std::cout << "doubled number " << n << "\n";
    }

    // 9. For loop with no initialization (external variable)
    int k = 0;
    for (; k < 3; k++)
    {
        std::cout << "k = " << k << std::endl;
    }

    // 10. For loop with no condition (break inside)
    for (int m = 0;; m++)
    {
        if (m > 2) break;
        std::cout << "m = " << m << std::endl;
    }

    // 11. For loop with no increment (increment inside body)
    for (int x = 0; x < 3;)
    {
        std::cout << "x = " << x << std::endl;
        x++;
    }

    // 12. Nested for loops (2D array or matrix)
    int matrix[2][3] = {{1,2,3},{4,5,6}};
    for (int row = 0; row < 2; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            std::cout << "matrix[" << row << "][" << col << "] = " << matrix[row][col] << std::endl;
        }
    }

    return 0;
}