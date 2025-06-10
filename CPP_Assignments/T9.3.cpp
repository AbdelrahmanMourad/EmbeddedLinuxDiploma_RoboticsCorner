
/*________________________________________________________________________________________________________

    Task(9.3) Lambda expression:
    ----------------------------

   	- Steps: 
		1. Define and Initialize Variables:
            ○ Define three integer variables: x, y, and z with initial values of 3, 9, and 10, respectively. 
		2. Lambda Function - Capture by Reference: 
			○ Create a lambda function print that captures all variables by reference using [&]. This lambda: 
				- Multiplies x, y, and z by 2. 
				- Prints the updated values of x, y, and z.
		3. Lambda Function - Capture by Value: 
			○ Create another lambda function print_value that captures all variables by value using [=]. This lambda: 
				- Prints the values of x, y, and z, but since the variables are captured by value, it does not modify them. 
				- The values printed are the ones after the changes made by the previous lambda 
                    (since it's captured after that lambda call). 
		4. Lambda Function - Capture Specific Variables by Reference: 
			○ Define a lambda function print_only_two that captures only x and y by reference, taking one parameter factor. 
			○ The lambda: 
				- Increments x and y by the factor. 
				- Prints the updated values of x and y, but does not modify z as it's not captured. 
		5. Main Function Execution: 
			○ Call the print lambda to modify and print the values of x, y, and z. 
			○ Call the print_value lambda to print the values of x, y, and z after the changes. 
            ○ Call the print_only_two lambda with a factor (e.g., 10) to update and print only x and y
___________________________________________________________________________________________________________*/

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










