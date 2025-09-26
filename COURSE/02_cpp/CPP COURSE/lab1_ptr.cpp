#include <iostream>
/*  Call by address (Cpp) == call by reference (c)  */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    // Define Variables.
    int x = 10, y = 20;

    // before
    std::cout << "------------\nBefore Swap:\n";
    std::cout << "x = " << x << " , y = " << y << std::endl;
    std::cout << "&x = " << &x << " , &y = " << &y << std::endl;
    // printf("x= %x , y= %X \n", &x, &y);  // Use if wanna select specific format specifiers.

    // Swap The Values.
    swap(&x, &y);

    // After.
    std::cout << "------------\nAfter Swap:\n";
    std::cout << "x = " << x << " , y = " << y << std::endl;
    std::cout << "&x = " << &x << " , &y = " << &y << std::endl;
    // printf("x= %x , y= %X \n", &x, &y);  // Use if wanna select specific format specifiers.

    return 0;
}