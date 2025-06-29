
/*________________________________________________________________________________________________________

    Task(15.2): Strategy Pattern:
    ------------------------------

    Requirements:
    -   Implement a simple Strategy Design Pattern for calculating vehicle speed based on
        different car brands.

        1.  Abstract Interface:
            *   Define an interface IStrategy with a pure virtual method calculateSpeed().
                This will act as a base for different strategies representing how vehicle
                speed is determined.
        2.  Concrete Strategy Classes:
            *   Create two classes "StrategyBMW" and "StrategyMini" that inherit from "IStrategy".
                Implement the "calculateSpeed()" method in each class, where:
                _   StrategyBMW should print "BMW Strategy".
                _   StrategyMini should print "Mini Cooper Strategy".
        3.  Vehicle Class:
            *   Create a class Vehicle that accepts an "IStrategy*" in its constructor. This
                strategy will define how the vehicle calculates its speed.
            *   The Vehicle class will have a "VehicleSpeed()" method that calls the
                strategy's "calculateSpeed()" method.
        4.  Main Function:
            *   Create two instances of Vehicle, one using StrategyBMW and the other
                using StrategyMini.
            *   Call the VehicleSpeed() function on each instance to see the result of the
                strategy in action.
        5.  Create a class diagram for all the classes using "https://app.diagrams.net/"
___________________________________________________________________________________________________________*/

/*  -------------------------------------------------------------------
                    Included Libraries.
    ------------------------------------------------------------------- */
#include <iostream>

/*  -------------------------------------------------------------------
                        Functions Prototype
    ------------------------------------------------------------------- */
class IStrategy
{
public:
    virtual void calculateSpeed() = 0;
    IStrategy() { std::cout << "Constructor Called: IStrategy.\n"; }
    ~IStrategy() { std::cout << "Destructor Called: IStrategy.\n"; }
};

class StrategyBMW : public IStrategy
{
public:
    void calculateSpeed() override { std::cout << "BMW Strategy.\n"; }
    StrategyBMW() { std::cout << "Constructor Called: StrategyBMW.\n"; }
    ~StrategyBMW() { std::cout << "Destructor Called: StrategyBMW.\n"; }
};

class StrategyMini : public IStrategy
{
public:
    void calculateSpeed() override { std::cout << "Mini Cooper Strategey.\n"; }
    StrategyMini() { std::cout << "Constructor Called: StrategyMiniCooper.\n"; }
    ~StrategyMini() { std::cout << "Destructor Called: StrategyMiniCooper.\n"; }
};

class Vehicle
{
private:
    IStrategy *ptr_Istrategy_;

public:
    Vehicle(IStrategy *Ptr_Istrategy) : ptr_Istrategy_{Ptr_Istrategy}
    {
        if (dynamic_cast<StrategyBMW *>(ptr_Istrategy_))
        {
            std::cout << "Constructor Called: Vehicle ==> BWM.\n";
        }
        else
        {
            std::cout << "Constructor Called: Vehicle ==> MiniCooper.\n";
        }
    }
    ~Vehicle()
    {
        delete ptr_Istrategy_;
        ptr_Istrategy_ = nullptr;
        std::cout << "Destructor Called: Vehicle... resource deallocated.\n";
    }
    void VehicleSpeed() { ptr_Istrategy_->calculateSpeed(); }
};

/*  -------------------------------------------------------------------
                        Entry Point
    ------------------------------------------------------------------- */
int main()
{
    // StrategyBMW BMW1;
    // StrategyMini Mini1;

    // Vehicle V1{&BMW1};
    // Vehicle V2{&Mini1};
    // std::cout << "-------------------------------------------------------------------------------------" << std::endl;

    Vehicle V1{new StrategyBMW};
    Vehicle V2{new StrategyMini};

    V1.VehicleSpeed(), V2.VehicleSpeed();

    return 0;
}

/*  -------------------------------------------------------------------
                        Functions implementation
    ------------------------------------------------------------------- */
