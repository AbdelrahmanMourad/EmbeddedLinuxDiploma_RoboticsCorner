/*  ===========================================================================================
    Modulus Example:
        Calculating the day of the week
    Description:
        This program calculates the day of the week after a given number of days from a specified current day.
        It uses an enumeration to represent the days of the week and performs calculations using the modulus operator.

    =========================================================================================== 
*/
/*  ===========================================================================================
                                    Included Libraries.
    =========================================================================================== */
#include <iostream>

/*  ===========================================================================================
                                    Declarations.
    =========================================================================================== */
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



/*  ===========================================================================================
                                    Main() - Entry Point
    =========================================================================================== */
int main()
{
    // Inputs.
    int currentDay = 0; // Lets assume current day is Monday. (or let "4==Thursday")
    int MeetingDay = 0; // Number of days until meeting.

    GetUserInput(currentDay, MeetingDay);

    // Calculations.
    std::uint16_t day = (currentDay + MeetingDay) % MAX_NUM_DAYS;  /// <==> (currentDay + MeetingDay) % MAX_NUM_DAYS;
    // This will give us the day of the week after MeetingDay days from currentDay.

    // Print Outputs.
    PrintDayOutput(day, MeetingDay);

    // Return E_OK Status.
    return 0;
}

/*  ===========================================================================================
                                    Implementations
    =========================================================================================== */
void GetUserInput(int& currentDay, int& MeetingDay)
{
    std::cout << "Enter current day (0:Monday, 1:Tuesday, ..., 6:Sunday): ";
    std::cin >> currentDay;
    std::cout << "Enter number of days until meeting: ";
    std::cin >> MeetingDay;
}

void PrintDayOutput(std::uint16_t day, int MeetingDay)
{
    std::cout << "Day after " << MeetingDay << " days =  " << day << ":";
    switch (day)
    {
    case MONDAY:
        std::cout << "MONDAY\n";
        break;
    case TUESDAY:
        std::cout << "TUESDAY\n";
        break;
    case WEDNESDAY:
        std::cout << "WEDNESDAY\n";
        break;
    case THURSDAY:
        std::cout << "THURSDAY\n";
        break;
    case FRIDAY:
        std::cout << "FRIDAY\n";
        break;
    case SATURDAY:
        std::cout << "SATURDAY\n";
        break;
    case SUNDAY:
        std::cout << "SUNDAY\n";
        break;
    default:
        std::cout << "Invalid day" << std::endl;
        break;
    }
}