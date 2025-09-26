/* Aggregation */

#include <iostream>

/******************** AGGREGATION REFERENCE ******************/
class Sensor // Sub Class.
{
public:
    int getReading() { return 25; }
};

class Algorithm // Super Class.
{
public:
    Algorithm(Sensor &sensor) : sensor_{sensor}
    {
        sensor_.getReading();
    }

private:
    Sensor &sensor_;
};

int main()
{
    // Aggregation_1 (Reference to instance initialized and passed from outside).
    Sensor temperature_sensor;
    Algorithm heat_compensation(temperature_sensor);

    // Aggregation_2 (Pointer initialized and passed from outside).
    OilLevel *oil_level = new OilLevel(); // or = nullptr;
    Engine engine(oil_level);

    return 0;
}

/******************** AGGREGATION POINTER ******************/
/* ___NOTE___ */
// class OilLevel; // Forward Declaration .. tell compiler it will be defined somewhere, don't display errors now
class OilLevel // Or just implement it and make an empty constructor inside it.
{
public:
    OilLevel() {}
};

class Engine
{
public:
    Engine(OilLevel *oil) : oil_{oil} {}

private:
    OilLevel *oil_;
};
