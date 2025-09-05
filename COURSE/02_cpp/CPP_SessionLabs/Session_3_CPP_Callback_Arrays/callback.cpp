#include <iostream>
#include <array>
#include <algorithm>

/**
 * callback lab
 *  */

// Function for example
void welcome(std::string str)
{
    std::cout << str << std::endl;
}

void fun2(int var)
{
    std::cout << "var= " << var << std::endl;
}

void fun1(void (*callback)(int))
{
    int data = 10;
    callback(data);
}

int main()
{
    void (*ptr0)(std::string) = welcome;
    void (*ptr2)(int) = fun2;
    void (*ptr1)(void (*callback)(int)) = fun1;

    // call fn1 by ptr1, passing in param ptr2 to fn2
    ptr1(ptr2);

    return 0;
}
