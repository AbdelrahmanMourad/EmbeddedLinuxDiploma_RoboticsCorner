/*
 ***************************************************************
 * Why using the design patterns is important ?
 *
 *      Maintainability  ***
 *      Testability      *****
 *      Refactoring
 *
 *****************************************************************
 **/
/*
===================================================================
    Proxy "سـاتـر"     ==  Structural   => Mutual Execlusion , Resource injection
    signleton           ==  Creational
    Adaptor             ==  Structural
===================================================================
*/

/*__________Proxy___________*/
// 1st Use case subject proxy ---> dependecy inversion --- > in the session {Multi files}

/*************************************************************************/
#include <iostream>
/*************************************************************************/
class ISeneor
{
public:
    virtual float read() = 0;
};
/*************************************************************************/
class SpeedSensor : public ISeneor
{
private:
    float speed_;

public:
    SpeedSensor() : speed_{60.0} {}
    float read() override
    {
        return speed_;
    }
};
/*************************************************************************/
class ProxySensor : public ISeneor
{
private:
    std::string password_;
    int user_id_;
    SpeedSensor speed_sensor_;
    bool isAuth()
    {
        if (user_id_ == 123 && password_ == "test_pass")
        {
            return true;
        }
        return false;
    }

public:
    ProxySensor(int UserID, std::string password) : user_id_{UserID}, password_{password}
    {
    }

    float read() override
    {
        if (isAuth())
        {
            return speed_sensor_.read();
        }
        return 0.0;
    }
};
/*************************************************************************/
int main()
{
    ProxySensor proxy(123, "test_pass");
    std::cout << "Speed= " << proxy.read() << "\n";
    return 0;
}