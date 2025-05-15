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
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
/*  -----------------------------------------------------------------
                            Declarations
    -----------------------------------------------------------------*/

// Write your Student class here
class Student
{
private:
    vector<int> scores;

public:
    void input()
    {
        for (int i = 0; i < 5; i++)
        {
            int score;
            cin >> score;
            scores.push_back(score);
        }
    }

    int calculateTotalScore()
    {
        int total = 0;
        for (int i = 0; i < 5; i++)
        {
            total += scores[i];
        }
        return total;
    }
};

/*  -----------------------------------------------------------------
                            Entry Point
    -----------------------------------------------------------------*/

int main()
{
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students

    for (int i = 0; i < n; i++)
    {
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        int total = s[i].calculateTotalScore();
        if (total > kristen_score)
        {
            count++;
        }
    }

    // print result
    cout << count;

    return 0;
}
/*  -----------------------------------------------------------------
                            Implementation
    -----------------------------------------------------------------*/
