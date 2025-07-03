#include <iostream>
#include <memory>

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
    int area() { return (length_ * width_); }
};

