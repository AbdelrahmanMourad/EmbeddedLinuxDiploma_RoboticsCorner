#include <iostream>

/*
    Example of the delegate constructor.
    Operator Overloading.
*/
class Shape
{
public:
    // Default Constructor
    Shape() : Shape(0, 0)
    {
        std::cout << "in default height= " << h_ << "\twidth= " << w_ << std::endl;
    }
    // // To Tell it to make a default constructor automatically.
    // Shape() = default;

    // Parameterized Constructor.
    Shape(int h, int w) : h_(h), w_{w}
    {
        std::cout << "height= " << h_ << "\twidth= " << w_ << std::endl;
    }

    // copy constructor
    Shape(const Shape &copy)
    {
        this->h_ = copy.h_;
        this->w_ = copy.w_;
        std::cout << "Copy Constructor\n";
    }

    // Assignment operator  ############################    they only used with primitive data types.
    // operator overloading ############################    define how the operator can work with new user-defined data types
    // Operator overloading.
    Shape operator=(Shape &shape)
    {
        return *this;
    }
    // Operator overloading.
    Shape operator+(Shape shape)
    {
        Shape temp;
        temp.h_ = this->h_ + shape.h_;
        temp.w_ = this->w_ + shape.w_;
        return temp;
    }
    int getHeight()
    {
        return h_;
    }
    int getWidth()
    {
        return w_;
    }

private:
    int h_;
    int w_;
};

int main()
{
    Shape shape; // Call Default, which delegate the paramtererized 1st, then the default.
    Shape rect(2, 4);
    shape = rect; // Assignment Operator ############ Rect was declared before ########

    // is that possible? Yes, but the compiler will generate something similar to assignment operator.
    Shape square = rect + shape; // rect.operator+(shape);
    std::cout << "square height " << square.getHeight() << " wdith " << square.getWidth() << "\n";

    // Copy constructor ////////////////////////////////////////
    Shape shape2(shape);   // Create shape2 from shape copy.
    Shape shape3 = shape2; // Copy Constructor new shape3 from shape2  (Compiler Generate Copy Constructor by default).
    // ############ shape3 was not declared before ########


    // Tomorrow Inheritance & Polymorphism & operator Overloading.
    
    return 0;
}
