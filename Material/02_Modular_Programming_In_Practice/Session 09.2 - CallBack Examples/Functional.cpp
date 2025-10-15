#include<iostream>
#include<array>
#include<functional>

// c style pointer to function: void (*area)(int redius) xxxx
// c++ style std::function: std::function<void (int)> ptr1 !!!!!!!

void Calculate_area(void (*area)(int redius))
{
    std::cout << "Please enter redius\n";
    double redius;
    std::cin >> redius;
    area(redius);
}

int main()
{
    const double PI = 3.14159265359;
    auto lambda = [PI](int redius) -> void
    {
        std::cout << PI * redius * redius << std::endl;
    };

    Calculate_area(lambda);


    return 0;
}