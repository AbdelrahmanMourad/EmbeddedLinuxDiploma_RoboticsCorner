/*
    Modulus Example
        Calculating the day of the week

*/

#include <iostream>

// Automatic starting from zero, if set to start num it will increment by 1.
// can tell him data type to choose its max size.
enum WEEK_DAYS_t : std::uint8_t
{
    MONDAY = 0,
    TUESDAY = 1,
    WEDNESDAY = 2,
    THURSDAY = 3,
    FRIDAY = 4,
    SATURDAY = 5,
    SUNDAY = 6,
    MAX_NUM_DAYS = 7,
};

int main()
{
    // Inputs.
    int currentDay = 4;  // Let: 4:Thursday.
    int MeetingDay = 10; // Should be 0: Monday

    // Calculations.
    std::uint16_t day = (currentDay + MeetingDay) % 7;

    // Print Outputs.
    switch (day)
    {
    case 0:
        std::cout << "Day after 10 days =  " << day << ":" << "MONDAY" << "\n";
        break;
    case 1:
        std::cout << "Day after 10 days =  " << day << ":" << "TUESDAY" << "\n";
        break;
    case 2:
        std::cout << "Day after 10 days =  " << day << ":" << "WEDNESDAY" << "\n";
        break;
    case 3:
        std::cout << "Day after 10 days =  " << day << ":" << "THURSDAY" << "\n";
        break;
    case 4:
        std::cout << "Day after 10 days =  " << day << ":" << "FRIDAY" << "\n";
        break;
    case 5:
        std::cout << "Day after 10 days =  " << day << ":" << "SATURDAY" << "\n";
        break;
    case 6:
        std::cout << "Day after 10 days =  " << day << ":" << "SUNDAY" << "\n";
        break;
    default:
        std::cout << "Invalid day" << std::endl;
        break;
    }

    // Return E_OK Status.
    return 0;
}