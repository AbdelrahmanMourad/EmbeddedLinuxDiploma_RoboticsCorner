#include<iostream>
#include<array>
#include<functional>

// Below Calculate functions takes a vector and 2 lambda functions in the argument list.
void Calculate (const std :: array<int,5>& arr_num, std::function<void (int)> calculateSquare,
                                                    std::function<void (int)> calculateCube)
  {   
     for (const auto& num : arr_num) {
          if (num % 2 == 0) {
              calculateSquare(num); 
          } else {
              calculateCube (num); 
          }
     }   
}

int main() {

    constexpr int array_size = 5;
    std::array<int ,array_size> nums = {1 , 2 , 3 , 4 ,5};
 
    /* []  - Capture list
       ()  - Parameter list
       -> return_type - return type
       {}  - Body of lambda function */
            
    auto lambda_square = [] (int num) -> void { 
                        std :: cout << "Number : " << num <<
                        " Square : " << num * num << std :: endl;
                        };

    auto lambda_cube   = [] (int num) -> void {
                        std :: cout << "Number : " << num <<
                        " Cube   : " << num * num * num << std :: endl; 
                        };

    Calculate (nums, lambda_square , lambda_cube);
}