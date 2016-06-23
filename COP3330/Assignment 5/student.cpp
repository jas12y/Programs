/*
Programmers Name: John Stubbs
      Assignment: #5
            Date: 3/22/13

Implementation file for the Student class
*/
#include <iostream>
#include "student.h"

using namespace std;

// Constructor
Student::Student()
{
    LName = ' ';
    FName = ' ';
    course = ENGLISH;
}
// Constructor
Student::Student(const char *LN, const char *FN, const char *c)
{
    LName = LN;
    FName = FN;

    if (c[0] == 'E')
        course = ENGLISH;
    else if (c[0] == 'H')
        course = HISTORY;
    else
        course = MATH;
    
}
// Returns Last Name
string Student::GetLast()
{
    return LName;
}
// Returns First Name
string Student::GetFirst()
{
    return FName;
}
// Returns Course
string Student::GetCourse()
{
    string cName[3] = {"English", "History", "Math   "};
    
    return cName[course];
}
// Constructor
English::English(const char *LN, const char *FN, const char *c, const int scores[]) : Student(LN, FN, c)
{
    attendance = scores[0];
    project = scores[1];
    midterm = scores[2];
    finalExam = scores[3];
}
// Returns Final Exam
int English::GetFinal()
{
    return finalExam;
}
// Returns Final Grade Average
double English::CalcGrade()
{   
    return ((attendance*.1)+((project + midterm + finalExam)*.3));
}
// Constructor
History::History(const char *LN, const char *FN, const char *c, const int scores[]) : Student(LN, FN, c)
{
    termPaper = scores[0];
    midterm = scores[1];
    finalExam = scores[2];
}
// Returns Final Exam
int History::GetFinal()
{
    return finalExam;
}
// Returns Final Grade Average
double History::CalcGrade()
{
    return ((termPaper * .25)+(midterm * .35)+(finalExam * .4));
}
// Constructor
Math::Math(const char *LN, const char *FN, const char *c, const int scores[]) : Student(LN, FN, c)
{
    for (int i = 0; i < 5; i++)
        quiz[i] = scores[i];
    quizAverage = Average();
    test1 = scores[5];
    test2 = scores[6];
    finalExam = scores[7];
}
// Returns Quiz Average
double Math::Average()
{
    double total = 0;
    
    for (int i = 0; i < 5; i++)
        total += quiz[i];
    
    return total/5;
}
// Returns Final Exam
int Math::GetFinal()
{
    return finalExam;
}
// Returns Final Grade Average
double Math::CalcGrade()
{
    return ((quizAverage * .15)+((test1 + test2)* .25)+(finalExam * .35));
}
