/*________________________________________________________________________________________________________

    Task(7.1):
    ----------
        Write a program in C++ to check whether a number is prime or not.

        A prime number is a whole number greater than 1 that cannot be exactly divided by any
        whole number other than itself and 1 (e.g. 2, 3, 5, 7, 11, ....).

        Sample Output:
            Input a number to check prime or not: 13
            The entered number is a prime number.
    ________________________________________________________________________________________________________

        Use Case:
            Number 5 is prime
                5/2=2 -> remainder 1
                5/3=2 -> remainder 2
                5/4=2 -> remainder 1
            Number 6 is not prime
                6/2=3 -> remainder 0 -> return false
                6/3=2 -> remainder 0 -> return false
                6/4=2 -> remainder 2
                6/5=1 -> remainder 1
            Number 11 is prime
                11/2=5  -> Remainder 1
                11/3=3  -> Remainder 2
                11/4=2  -> Remainder 3
                11/5=2  -> Remainder 1
                11/6=1  -> Remainder 5
                11/7=1  -> Remainder 4
                11/8=1  -> Remainder 3
                11/9=1  -> Remainder 2
                11/10=1 -> Remainder 1
                11/11=1 -> Remainder 0
___________________________________________________________________________________________________________*/

/*  -------------------------------------------------------------------
                        Included Libraries.
    ------------------------------------------------------------------- */
#include <iostream>

/*  -------------------------------------------------------------------
                        Functions prototype
    ------------------------------------------------------------------- */
bool isPrime(int num);
void PrintPrimeStatus(bool flag, int num);

/*  -------------------------------------------------------------------
                        Entry Point
    ------------------------------------------------------------------- */
int main()
{
    // ____________Main_Program____________
    // Declare container variable.
    int num;

    //  Take user input number.
    std::cout << "Input a number to check prime or not: ";
    std::cin >> num;

    // Check if the number is prime or not.
    PrintPrimeStatus(isPrime(num), num);

    // ____________Debug_Section____________
    // Try the algorithm big range.
    // for (int i = -3; i <= 33; i++)
    // {
    //     PrintPrimeStatus(isPrime(i), i);
    // }

    // // Print for Debugging.
    // int num = 11;
    // for (int i = 1; i <= num; i++)
    //     std::cout << num << "/" << i << "=" << num / i << "\t-> Remainder " << num % i << std::endl;

    return 0;
}

/*  -------------------------------------------------------------------
                        Functions implementation
    ------------------------------------------------------------------- */
void PrintPrimeStatus(bool flag, int num)
{
    if (flag)
        std::cout << "The entered number\t" << num << "\tis a prime number." << std::endl;
    else
        std::cout << "The entered number\t" << num << "\tis not a prime number." << std::endl;
}

bool isPrime(int num)
{
    // If number is (-ve) or zero or 1, it is not prime
    if (num <= 1)
        return false;

    // Check divisibility from 2 to sqrt(num).
    // If number is larger than 3 it will enter the loop to check.
    for (int i = 2; i <= (num / 2); i++)
    {
        if (num % i == 0)
            return false;
    }
    // if num equals 2 or 3 its prime number without entering the loop.
    return true;
}