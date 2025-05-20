#include "iostream"

int main()
{
    /*  _______________________________________________________
        increment:
            -------
            postfix:
            --------
            int y = x++;
            // y = 10, x =11
            -------
            prefix:
            -------
            int a =10;
            int b =11;
            // b=11 , a =11
    _______________________________________________________
    */
    for (int i = 0; i <= 5; i++)
    {
        // Body.
        std::cout << "index = " << i << std::endl;
    }
    /*________________Infinity loop_______________*/
    for (;;)
    {
        std::cout << "Infinity" << "\n";
    }
    /*________________Range-Based for loop___________________*/

    for (int n : {10, 12, 30, 4, 45}) // loop on the list elements.
    {
        std::cout << "number " << n << "\n";
    }
}