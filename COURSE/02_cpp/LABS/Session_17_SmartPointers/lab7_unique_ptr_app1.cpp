#include <iostream>
#include <memory> // For Smart Pointers: unique_ptr / shared_ptr / weak_ptr

/*  ===============================================================================
                        Declarations / ProtoTypes
    =============================================================================== */
class Rectangle
{
private:
    int length_;
    int width_;

public:
    Rectangle(int l, int w) { this->length_ = l, this->width_ = w, std::cout << "Constructor Called: Rectangle.\n"; }
    ~Rectangle() { std::cout << "Destructor Called: Rectangle.\n"; }
    int area() { return (length_ * width_); }
};

/*  ===============================================================================
                        Main Function / Entry Point
    =============================================================================== */
int main()
{
    // UNIQUE_PTR_1st_Method
    std::unique_ptr<Rectangle> P1(new Rectangle(10, 5)); // Pointer to Rectangle,.. Declaration,initialization.

    // UNIQUE_PTR_2nd_Method
    std::unique_ptr<Rectangle> P2;           // Pointer to Rectangle,.. Declaration.
    P2 = std::make_unique<Rectangle>(20, 5); // Pointer to Rectangle,.. initialization.

    // UNIQUE_PTR_3rd_Method
    auto P3 = std::make_unique<Rectangle>(30, 5); // Pointer to Rectangle,.. Declaration,initialization.

    // Print Areas.
    std::cout << "Area P1= " << P1->area() << "\n"  /*50*/
              << "Area P2= " << P2->area() << "\n"  /*100*/
              << "Area P3= " << P3->area() << "\n"; /*150*/

    /*_____________________PROHIBITED ERRORS : Ownership_____________________*/
    // std::unique_ptr<Rectangle> P4 = P3; // ERROR.. Single Ownership, Can't use Copy Constructor/ Copy Assignment Operator.
    // std::unique_ptr<Rectangle> P4(P3);  // ERROR.. Single Ownership, Can't use Copy Constructor/ Copy Assignment Operator.

    /*_____________________MOVE SEMANTICS : Moving Ownership_____________________*/
    std::unique_ptr<Rectangle> P4(std::move(P3)); // New P4 is new owner, P3 is nullptr.

    // Unique pointer to array.
    std::unique_ptr<int>
    intPtr(new int[10]); // Pointer to array of integers.

    return 0;
}