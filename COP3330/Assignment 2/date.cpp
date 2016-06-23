/*
Programmers Name: John Stubbs
      Assignment: #2
            Date: 2/1/13

Implementation file for the Date class
*/
#include <iostream>
#include <string>
#include "date.h"

using namespace std;

int DAYS[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const string MONTHS[13] = {" ", "Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sep", "Oct", "Nov", "Dec"};
const string TWODIGITS[100] = {"00", "01", "02", "03", "04", "05", "06", "07", "08", "09",
                               "10", "11", "12", "13", "14", "15", "16", "17", "18", "19",
                               "20", "21", "22", "23", "24", "25", "26", "27", "28", "29",
                               "30", "31", "32", "33", "34", "35", "36", "37", "38", "39",
                               "40", "41", "42", "43", "44", "45", "46", "47", "48", "49",
                               "50", "51", "52", "53", "54", "55", "56", "57", "58", "59",
                               "60", "61", "62", "63", "64", "65", "66", "67", "68", "69",
                               "70", "71", "72", "73", "74", "75", "76", "77", "78", "79",
                               "80", "81", "82", "83", "84", "85", "86", "87", "88", "89",
                               "90", "91", "92", "93", "94", "95", "96", "97", "98", "99"};
ostream &operator <<(ostream &S, Date & d)
{
    S << d.month << "/" << d.day << "/" << d.year << endl;
    
    return s;
}

//Default Constructor
Date::Date()
{
    month = 1;
    day = 1;
    year = 2000;
}
//Constructor
Date::Date(int m, int d, int y)
{
    Set(m, d, y);
}
//Returns the month
int Date::GetMonth()
{
    return month;
}
//Returns the day
int Date::GetDay()
{
    return day;
}
//Return the year
int Date::GetYear()
{
    return year;
}
//Allows user to input date and verifies it it valid
void Date::Input()
{
    int m, d, y;
    char c1, c2;
    
    cout << "Please enter a date(mm/dd/yyyy): ";
    cin >> m >> c1 >> d >> c2 >> y;
    
    while (Set(m, d, y) == false)
    {
        cout << "\nPlease enter a valid date(mm/dd/yyyy): ";
        cin >> m >> c1 >> d >> c2 >> y;
    }
}
//Displays the date in the proper format
void Date::Show()
{
    switch(form)
    {
        case 'D':
            cout << month << "/" << day << "/" << year << endl;
            break;
        case 'T':
            cout << TWODIGITS[month] << "/" << TWODIGITS[day] << "/" << TWODIGITS[year%100] << endl;
            break;
        case 'L':
            cout << MONTHS[month] << " " << day << ", " << year << endl;
            break;
        default:
            cout << month << "/" << day << "/" << year << endl;
    }
}
//Sets the values for the date and return true for success and false for failure
bool Date::Set(int m, int d, int y)
{
    bool set = true;
    
    Leap(y);
    
    if (m >= 1 && m <= 12)
        month = m;
    else
        set = false;
    if (d >=1 && d <= DAYS[m])
        day = d;
    else
        set = false;
    if (y >=1)
        year = y;
    else
        set = false;
    if (set == false)
    {
        month = 1;
        day = 1;
        year = 2000;
    }

    return set;
}
//Sets the format for output and returns true for success and false for failure
bool Date::SetFormat(char f)
{
    bool fset = true;
    
    switch (f)
    {
        case 'd':
        case 'D':
            form = 'D';
            break;
        case 't':
        case 'T':
            form = 'T';
            break;
        case 'l':
        case 'L':
            form = 'L';
            break;
        default:
            form = 'D';
            fset = false;
    }
    
    return fset;
}
//Increase the date by num days
void Date::Increment(int num)
{

    for (int i = 0; i < num; i++)
    {
        if ((day + 1) <= DAYS[month])
            day++;
        else if (month < 12)
        {
            day = 1;
            month = month + 1;
        }
        else
        {
            year = year + 1;
            day = 1;
            month = 1;
            Leap(year);
        }
    }
}
//Compares the calling date with the passed value to see if greater, less than, or equal
int Date::Compare(const Date& d)
{
    int comp = 0;
    Date temp = d;
   
    if (year < temp.GetYear())
        comp = -1;
    else if (year == temp.GetYear() && month < temp.GetMonth())
        comp = -1;
    else if (year == temp.GetYear() && month == temp.GetMonth() && day < temp.GetDay())
        comp = -1;
    else if (year == temp.GetYear() && month == temp.GetMonth() && day == temp.GetDay())
        comp = 0;
    else
        comp = 1;
    
    return comp;
}
//Check to see if year is a leap year
void Date::Leap(int y)
{
    if (y%4 == 0)
        DAYS[2] = 29;
    else
        DAYS[2] = 28;
    if (y%100 == 0)
    if (y%400 == 0)
        DAYS[2] = 29;
    else
        DAYS[2] = 28;
}
