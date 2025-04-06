/*________________________________________________________________________________________________________

    Task(5.1):
    ----------
        Create a C++ program that lets the user calculate the area of different shapes— rectangles(R), circles(C), and triangles(T).

        Implement functions to compute the area of each shape and demonstrate their usage in the main program.

        Instructions:
            1.Define Functions:
                o Implement the following functions:
                    ▪ double calculateRectangleArea(double width, double height) - Calculates the area of a rectangle.
                    ▪ double calculateCircleArea(double radius) - Calculates the area of a circle.
                    ▪ double calculateTriangleArea(double base, double height) - Calculates the area of a triangle.
                    ▪ YOU CAN ADD MORE FUNCTIONS FOR DIFFERENT SHAPES.

            2.Create a Main Program:
                o let the user choose which shape he wants to calculate the area for and call the
                    appropriate functions to calculate their areas, then display the results.

___________________________________________________________________________________________________________*/

/* Include Section */
#include <iostream>

/* Definitions */
#define PI 3.14

/* Namespaces & Functions Prototypes */
namespace Rectangle
{
    double width{0}, height{0};
    double calculateArea(double width, double height); // Calculates the area of a rectangle.
}
namespace Circle
{
    double radius{0};
    double calculateArea(double radius); //  Calculates the area of a circle.
}
namespace Triangle
{
    double base{0}, height{0};
    double calculateArea(double base, double height); // Calculates the area of a triangle.
}

/* Entry Point */
int main()
{
    while (1)
    {
        int ShapeSelector = 0;

        // let the user choose which shape he wants to calculate the area for
        std::cout << "\nWhich shape you wanna calculate area for:" << std::endl;
        std::cout << "Rectangle:\t1\nCircle\t\t2\nTriangle\t3\nExit Program\t4\n";
        std::cin >> ShapeSelector;

        switch (ShapeSelector)
        {
        case 1: // Rectangle
            std::cout << "Enter Rectangle Width = ";
            std::cin >> Rectangle::width;
            std::cout << "Enter Rectangle Height = ";
            std::cin >> Rectangle::height;
            std::cout << "Area = " << Rectangle::calculateArea(Rectangle::width, Rectangle::height) << "\n-----------------\n";
            break;
        case 2: // Circle
            std::cout << "Enter Circle Radius = ";
            std::cin >> Circle::radius;
            std::cout << "Area = " << Circle::calculateArea(Circle::radius) << "\n-----------------\n";
            break;
        case 3: // Triangle
            std::cout << "Enter Triangle Base = ";
            std::cin >> Triangle::base;
            std::cout << "Enter Rectangle Height = ";
            std::cin >> Triangle::height;
            std::cout << "Area = " << Triangle::calculateArea(Triangle::base, Triangle::height) << "\n-----------------\n";
            break;
        case 4: // Exit
            std::cout << "Exiting.";
            break;
        default:
            std::cout << "Wrong inputs, Try again later!" << "\n-----------------\n";
            break;
        }

        if (ShapeSelector == 4)
            break; // Exit the While(1)
    }

    // Return E_OK Status.
    return 0;
}

/* Functions Implementation */
double Rectangle::calculateArea(double width, double height)
{
    return (width * height);
}
double Circle::calculateArea(double radius)
{
    return (PI * radius * radius);
}
double Triangle::calculateArea(double base, double height)
{
    return (0.5 * base * height);
}