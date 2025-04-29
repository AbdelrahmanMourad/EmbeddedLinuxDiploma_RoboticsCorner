#include <iostream>
/*  Reference in C++
        better than pointers that it doesn't use memory. (Alias)
*/

/*  __________________________________Interview Questions (IV):__________________________________

        Difference between ref & ptr?

            -------------
            -   Pointer:
            -------------
                -> Initialization to null: can be initialized with null {int * p = nullptr; //OK} {int * p; //OK}
                -> Can be assigned to multiple variables. {int *p =&x;  p=&y;}
                -> Can be memory dynamically allocated. (Supported.)
                -> Support multi level indirect addressing and dereferences.
            --------------
            -   Reference:
            --------------
                -> Initialization to null: Can't be initialize with null (must be initialized to variable.) {int &r = nullptr //Error}  {int &r;    // Error}
                -> Can be assigned to multiple variables. {int &r = x;  r=y;}
                -> Can't be memory dynamically allocated. (Not Supported.)
                -> No level of indirection (as its Alias to memory location).

    ______________________________________________________________________________________________
*/

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    std::cout << "Inside Function SWAP\n-----------------\n";
    printf("addresses of Reference: x=%X , y=%X\n", &a, &b);
    printf("addresses of Variables: x=%d , y=%d\n", a, b);
    std::cout << "-----------------\n";
}

int main()
{
    //_____________________________Multi level Pointer indirect addressing (pointer)_____________________
    int var = 10;
    int *p1 = &var;  // Pointer is called "indirect addressing". (Change the value in adress indirectly)
    int **p2 = &p1;  // Pointer to Pointer to integer. [Two level indirection].
    int ***p3 = &p2; // Pointer to Pointer to Pointer to integer. [Three level indirection].

    //_____________________________Multi level Pointer indirect addressing (pointer)_____________________
    int x = 5;
    int &r1 = x;  // &x = &r1
    int &r2 = r1; // &x = &r1 = &r2
    int &r3 = r2; // &x = &r1 = &r2 = &r3

    // // Reference.
    // int x = 10;
    // int y = 20;
    // int &r = x; // "&r and x are the same address in memory (No new memory address consumed)" = "Alias" = "محمد وحمادة مثلا اسمين لنفس المكان في الميموري"
    // int &t = y;

    // // before
    // std::cout << "------------\nBefore Swap:\n";
    // std::cout << "r = " << r << " , y = " << y << std::endl;
    // std::cout << "x = " << x << " , t = " << t << std::endl;

    // swap(x, y);

    // // before
    // std::cout << "------------\nBefore Swap:\n";
    // std::cout << "r = " << r << " , y = " << y << std::endl;
    // std::cout << "x = " << x << " , t = " << t << std::endl;
    // printf("addresses of Variables: x=%X , y=%X\n", &x, &y);

    return 0;
}