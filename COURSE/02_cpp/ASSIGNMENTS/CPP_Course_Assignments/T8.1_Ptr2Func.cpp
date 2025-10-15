
/*________________________________________________________________________________________________________

    Task(8.1): Ptr2Func:
    --------------------
        Implement a C++ program that defines two functions to perform addition and
        subtraction of two numbers. Then, use function pointers to allow the user to
        choose which operation to perform.

        Example:
            Input:
                Choose operation (+, -): +
                Enter The first number: 50
                Enter The second number: 70
            Output:
                The result = 120
___________________________________________________________________________________________________________*/

/*  -------------------------------------------------------------------
                    Included Libraries.
    ------------------------------------------------------------------- */
#include <iostream>

/*  -------------------------------------------------------------------
                        Functions implementation
    ------------------------------------------------------------------- */
int Add(int x, int y) { return (x + y); }
int Sub(int x, int y) { return (x - y); }
void TakeInputs(int &x, int &y)
{
    std::cout << "Enter The first number: ";
    std::cin >> x;
    std::cout << "Enter The second number: ";
    std::cin >> y;
}
void PrintResult(int result) { std::cout << "The result = " << result; }

/*  -------------------------------------------------------------------
                        Entry Point
    ------------------------------------------------------------------- */
int main()
{
    char op;
    int x, y, res;
    int (*ptr2func)(int, int);

    std::cout << "Choose operation (+, -): ";
    std::cin >> op;

    if (op == '+')
    {
        ptr2func = &Add;
        TakeInputs(x, y);
        res = ptr2func(x, y);
        PrintResult(res);
    }
    else if (op == '-')
    {
        ptr2func = &Sub;
        TakeInputs(x, y);
        res = ptr2func(x, y);
        PrintResult(res);
    }
    else
    {
        std::cout << "Wrong input, please try again later!";
    }

    return 0;
}


