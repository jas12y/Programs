/*
Programmers Name: John Stubbs
      Assignment: #2
            Date: 2/1/13

This file defines the class Date
*/
# ifndef DATE_H
# define DATE_H
#include <iostream>

const int D_MONTH = 1;
const int D_DAY = 1;
const int D_YEAR = 2000;
const char D_FORM = 'D';

class Date
{
private:
    int month;
    int day;
    int year;
    char form;
    
public:
    
    friend ostream &operator <<(ostream &s, Date & d);

    Date();
    Date(const int m,const int d = D_DAY,const int y = D_YEAR);
    int GetMonth();
    int GetDay();
    int GetYear();
    void Input();
    void Show();
    bool Set(const int m,const int d,const int y);
    bool SetFormat(const char f = 'D');
    void Increment(const int numDays=1);
    int Compare(const Date& d);
    void Leap(const int y);
};

#endif
