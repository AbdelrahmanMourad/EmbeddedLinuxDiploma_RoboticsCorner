
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
#include <functional>
/*  -------------------------------------------------------------------
						Functions Prototype
	------------------------------------------------------------------- */
void main_01_DeclareAllThenInvokeAll(void);
void main_02_InvokeOnDeclaration(void);

/*  -------------------------------------------------------------------
						Entry Point
	------------------------------------------------------------------- */
int main()
{
	main_01_DeclareAllThenInvokeAll();
	main_02_InvokeOnDeclaration();

	return 0;
}

/*  -------------------------------------------------------------------
						Functions implementation
	------------------------------------------------------------------- */

void main_01_DeclareAllThenInvokeAll(void)
{
	std::cout << "\n--------------------\nDeclare all. Then, Invoke All:\n--------------------\n";
	// Create 3 Variables with corresponding numbers.
	int x = 3, y = 9, z = 10;
	std::cout << "x= " << x << "\ty= " << y << "\tz= " << z << "\n";
	//	x=	3	,y=	9	,z=	10

	/*____________________Declare All Lambdas____________________*/
	// lambda1 => print
	std::function<void(void)> print = [&]() -> void
	{
		//	x=	3	,y=	9	,z=	10
		x *= 2;
		y *= 2;
		z *= 2;
		std::cout << "Print:\n";
		std::cout << "x= " << x << "\ty= " << y << "\tz= " << z << "\n";
		//	x=	6	,y=	18	,z=	20
	};

	// lambda1 => print_value
	std::function<void(void)> print_value = [=]() -> void
	{
		//	x=	3	,y=	9	,z=	10
		std::cout << "Print_value:\n";
		std::cout << "x= " << x << "\ty= " << y << "\tz= " << z << "\n";
		//	x=	3	,y=	9	,z=	10
	};

	// lambda1 => print_only_two
	std::function<void(int)> print_only_two = [&x, &y](int z)
	{
		//	x=	3	,y=	9	,z=	10
		int factor = 10;
		x += factor;
		y += factor;
		std::cout << "Print_only_two:\n";
		std::cout << "x= " << x << "\ty= " << y << "\tz= " << z << "\n";
		//	x=	13	,y=	19	,z=	10
	};

	/*____________________Invoke All Lambdas____________________*/
	print();
	print_value();
	print_only_two(z);
}
void main_02_InvokeOnDeclaration(void)
{
	std::cout << "\n--------------------\nInvoke On Declaration:\n--------------------\n";
	// Create 3 Variables with corresponding numbers.
	int x = 3, y = 9, z = 10;
	std::cout << "x= " << x << "\ty= " << y << "\tz= " << z << "\n";
	//	x=	3	,y=	9	,z=	10

	/*____________________Invoke On Declaration All Lambdas____________________*/
	// lambda1 => print
	[&]() -> void
	{
		//	x=	3	,y=	9	,z=	10
		x *= 2;
		y *= 2;
		z *= 2;
		std::cout << "Print:\n";
		std::cout << "x= " << x << "\ty= " << y << "\tz= " << z << "\n";
		//	x=	6	,y=	18	,z=	20
	}();
	//	x=	6	,y=	18	,z=	20

	// lambda1 => print_value
	[=]() -> void
	{
		//	x=	6	,y=	18	,z=	20
		std::cout << "Print_value:\n";
		std::cout << "x= " << x << "\ty= " << y << "\tz= " << z << "\n";
		//	x=	6	,y=	18	,z=	20
	}();
	//	x=	6	,y=	18	,z=	20

	// lambda1 => print_only_two
	[&x, &y](int z) -> void
	{
		//	x=	6	,y=	18	,z=	20
		int factor = 10;
		x += factor;
		y += factor;
		std::cout << "Print_only_two:\n";
		std::cout << "x= " << x << "\ty= " << y << "\tz= " << z << "\n";
		//	x=	16	,y=	28	,z=	10
	}(z);

	//	x=	16	,y=	28	,z=	10
}

/*  -------------------------------------------------------------------
						Summary of Lambda Behavior
	-------------------------------------------------------------------
	- Capture by **value [=]** stores a **copy** of variables when the lambda is defined.
	  -> Changes to the original variables **do not** reflect inside the lambda.
	  >>>>>>{{{""""""at the moment the lambda is defined***}}}<<<<<<

	- Capture by **reference [&]** allows the lambda to access the **current** value of variables.
	  -> Any modifications inside the lambda **affect** the original variables.

	- Function parameters (like `z` in `print_only_two`) are **passed by value by default**.
	  -> Changes to the parameter **do not** reflect outside the function unless passed by reference.

	-------------------------------------------------------------------
*/

void explain_capture_behavior()
{
	std::cout << "\n--- Lambda Capture Behavior Summary ---\n";
	std::cout << "- [=] captures by **value** (stores a copy at definition time).\n";
	std::cout << "- [&] captures by **reference** (reflects latest changes).\n";
	std::cout << "- Function parameters are **passed by value** by default.\n";
	std::cout << "- To modify parameters inside lambdas, pass them by reference.\n";
	std::cout << "----------------------------------------\n";
}
