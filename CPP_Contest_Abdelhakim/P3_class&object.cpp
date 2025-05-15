/** -----------------------------------------------------------------------------------------------
    Problem[3]: C - Classes and Objects:
    ------------------------------------

    A class defines a blueprint for an object. We use the same syntax to declare objects of a class as we use to declare variables of other basic types. For example:

        1.      Box box1;          // Declares variable box1 of type Box
        2.      Box box2;          // Declares variable box2 of type Box

    Kristen is a contender for valedictorian of her high school. She wants to know how many students (if any) have scored higher than her in the  exams given during this semester.

    Create a class named "Student" with the following specifications:
        • An instance variable named "scores" to hold a student's "5" exam scores.
        • A "void input()"" function that reads "5" integers and saves them to "scores".
        • An "int calculateTotalScore()" function that returns the sum of the student's scores.


    Input Format
        Most of the input is handled for you by the locked code in the editor.
        In the void Student::input() function, you must read  scores from stdin and save them to your  instance variable.

    Constraints
        1 <=    n       <= 100
        1 <= exmscore   <= 50

    Output Format
        In the "int Student::calculateTotalScore()" function, you must return the student's total grade (the sum of the values in ).
        The locked code in the editor will determine how many scores are larger than Kristen's and print that number to the console.

    Input
        3
        30 40 45 10 10
        40 40 40 10 10
        50 20 30 10 10
    Output
        1

    Explanation
        Kristen's grades are on the first line of grades. Only  student scored higher than her.

    -----------------------------------------------------------------------------------------------
**/

/*  -----------------------------------------------------------------
                            Included Libraries
    -----------------------------------------------------------------*/
#include <iostream> // io stream.
#include <vector>   // vetors for DMA.
// #include <sstream>  // String Stream (ss).
// #include <iterator>

/*  -----------------------------------------------------------------
                            Declarations
    -----------------------------------------------------------------*/
class Student
{
public:
    // Methods.
    void input(void)
    {
        for (auto &score : this->scores_)
        {
            std::cin >> score;
            if (score >= 50)
                score = 50;
        }
    }
    void calculateTotalScore(void)
    {
        for (auto score : this->scores_)
        {
            this->sum_ += score;
            // std::cout << "sum=" <<sum_<<"\n ";
        }
        // return this->sum_;
    }
    int get_sum(void) { return this->sum_; }

private:
    // variables.
    int scores_[5]{0};
    int sum_{0};
};

namespace HelpingFunctions
{
    int compare(std::vector<Student> All_Students)
    {
        // Assumign the main character has it's instance first at index[0]
        int main_score_sum = All_Students[0].get_sum();
        int numberOfHigherScoreStudents{0};

        for (auto it = All_Students.begin(); it != All_Students.end(); ++it)
        {
            if (main_score_sum < it->get_sum())
                numberOfHigherScoreStudents++;
        }

        return numberOfHigherScoreStudents;
    }
}

/*  -----------------------------------------------------------------
                            Entry Point
    -----------------------------------------------------------------*/
int main()
{
    // Get Number of Students
    int n;
    std::cin >> n;

    // Declare contrainers.
    std::vector<Student> All_Students;

    // Get Data and Calculate the Sum of Scores.
    for (int i = 0; i < n; i++)
    {
        // Create instances.
        All_Students.push_back(Student());
        // std::cout << All_Students.size() << ">>>>Size\n";

        // Fill Data from user.
        All_Students[i].input();
        All_Students[i].calculateTotalScore();
        // std::cout << "Sum:\t" << All_Students[i].get_sum() << "\n";
    }

    // Compare.
    std::cout << HelpingFunctions::compare(All_Students) << std::endl;

    return 0;
}

/*  -----------------------------------------------------------------
                            Implementation
    -----------------------------------------------------------------*/
