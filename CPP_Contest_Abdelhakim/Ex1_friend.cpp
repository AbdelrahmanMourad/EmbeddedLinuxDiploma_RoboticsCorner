#include <iostream>
#include <vector>

// forward declaration for classes (to avoid undeclared class errors)
class CAR1;
class CAR2;

// Example Class
class Engine_t
{
private:
    float RPM_, Temperature_, Pressure_;

public:
    // Friend Function/ class method/ class
    friend class CAR1; // Friend Class.
    // friend float CAR2::get_Engine_RPM(const Engine_t &source); // Friend Method of other class(Not working).
    // friend float CAR2::get_Engine_PRS(const Engine_t &source); // Friend Method of other class(Not working).
    // friend float CAR2::get_Engine_TMP(const Engine_t &source); // Friend Method of other class(Not working).
    friend class CAR2;                                   // Friend Class.
    friend void PrintEngineData(const Engine_t &source); // Friend Function.

    // Constructor & Destructor.
    Engine_t(float R = 0, float T = 0, float P = 0) : RPM_{R}, Temperature_{T}, Pressure_{P} { std::cout << "Engine Construcotr Called\n"; }
    ~Engine_t() { std::cout << "Engine Destructor Called.\n"; }
    // Methods.
    void set_all(float R = 0, float T = 0, float P = 0)
    {
        this->Temperature_ = T;
        this->Pressure_ = P;
        this->RPM_ = R;
    }
};

void PrintEngineData(const Engine_t &source) { std::cout << source.Pressure_ << "/t" << source.RPM_ << "/t" << source.Temperature_ << "\n"; }

class CAR1
{
private:
public:
    std::vector<float> _EngineData(const Engine_t &source)
    {
        std::vector<float> EngineDataVector;
        EngineDataVector.push_back(source.RPM_);
        EngineDataVector.push_back(source.Pressure_);
        EngineDataVector.push_back(source.Temperature_);

        // return the vector of data.
        return EngineDataVector;
    }
    void PrintEngineData(const Engine_t &source)
    {
        std::cout << source.Pressure_ << "/t" << source.RPM_ << "/t" << source.Temperature_ << "\n";
    }
};

class CAR2
{
private:
public:
    float get_Engine_RPM(const Engine_t &source) { return source.RPM_; }
    float get_Engine_PRS(const Engine_t &source) { return source.Pressure_; }
    float get_Engine_TMP(const Engine_t &source) { return source.Temperature_; }
    void PrintEngineData(const Engine_t &source)
    {
        std::cout << source.Pressure_ << "/t" << source.RPM_ << "/t" << source.Temperature_ << "\n";
    }
};

int main()
{
    Engine_t Engine1(33.33, 44.44, 55.55);
    CAR1 car1;
    CAR2 car2;
    PrintEngineData(Engine1);
    car1.PrintEngineData(Engine1);
    car2.PrintEngineData(Engine1);

    return 0;
}