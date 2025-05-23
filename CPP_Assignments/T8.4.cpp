
/*  =====================================================================================================
    Task(8.4): Modify a Variable Captured by Lambda Expression:
    ===========================================================

        Objective: 
            Understand variable capturing in lambda expressions and how to modify captured variables.

        Instructions:
            1. Create a Lambda Expression:
                - Define a variable num in the main function and initialize it with a value.
                - Create a lambda expression that captures this variable by value.
            2. Attempt to Modify the Captured Variable:
                - Inside the lambda expression, add a line that attempts to change the value of the captured variable.
            3. Observe the Compilation Error:
                - Compile and run your code. You should see a compilation error indicating that you are 
                    trying to assign a value to a read-only variable.
            4. Fix the Compilation Error:
                - Modify the lambda expression to capture the variable by reference instead of by value.
                - Ensure that the lambda can now modify the captured variable.
            5. Verify the Changes:
                - Print the value of the variable inside and outside the lambda to confirm that the 
                    modification is successful.

        Explanation:
            - When a variable is captured by value, it is essentially a copy of the original variable. 
            - Inside the lambda, this copy is treated as a constant in terms of modification. You are only 
                modifying the copy, not the original variable.
            - Error Cause:
                - If you try to modify this copy, the lambda's internal representation treats the copy as const 
                    to prevent modification.
                - This is why you get a compilation error: assignment of read-only variable.
    =====================================================================================================
*/

/*  -------------------------------------------------------------------
                    Included Libraries.
    ------------------------------------------------------------------- */
#include <iostream>

/*  -------------------------------------------------------------------
                        Functions Prototype
    ------------------------------------------------------------------- */


/*  -------------------------------------------------------------------
                        Entry Point
    ------------------------------------------------------------------- */
int main()
{

    return 0;
}

/*  -------------------------------------------------------------------
                        Functions implementation
    ------------------------------------------------------------------- */










