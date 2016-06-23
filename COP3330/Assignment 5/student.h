/*
Programmers Name: John Stubbs
      Assignment: #5
            Date: 3/22/13

This file defines the Student class
*/
#include <iostream>
#include <string>

using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

enum Subject {ENGLISH, HISTORY, MATH};

class Student
{
    protected:
        string LName;
        string FName;
        Subject course;

    public:
        Student();
        Student(const char *LN, const char *FN, const char *c);
        virtual double CalcGrade()=0;
        virtual int GetFinal()=0;
        string GetLast();
        string GetFirst();
        string GetCourse();
};
class English : public Student
{
    private:
        int attendance;
        int project;
        int midterm;
        int finalExam;
        
    public:
        English(const char *LN, const char *FN, const char *c, const int[]);
        double CalcGrade();
        int GetFinal();
};
class History : public Student
{
    private:
        int termPaper;
        int midterm;
        int finalExam;
        
    public:
        History(const char *LN, const char *FN, const char *c, const int[]);
        double CalcGrade();
        int GetFinal();
};
class Math : public Student
{
    private:
        int quiz[5];
        double quizAverage;
        int test1, test2;
        int finalExam;
        
    public:
        Math(const char *LN, const char *FN, const char *c, const int[]);
        double Average();
        double CalcGrade();
        int GetFinal();
};
#endif
