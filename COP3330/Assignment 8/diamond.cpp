/*
Programmers Name: John Stubbs
      Assignment: #8
            Date: 4/26/13

Implementation file for the Diamond class
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include "diamond.h"

using namespace std;
//Default Constructor
Diamond::Diamond()
{
    Dsize = 1;
    Dborder = '#';
    Dfill = '*';
}
//Constructor
Diamond::Diamond(const int s, const char b, const char f)
{
    SetSize(s);
    SetBorder(b);
    SetFill(f);
}
//Returns Diamond size
int Diamond::GetSize()
{
    return Dsize;
}
//Returns Diamond perimeter
int Diamond::Perimeter()
{
    return 4*Dsize;
}
//Returns Diamond area
double Diamond::Area()
{
    return 2*((pow(static_cast<double>(Dsize),2))*(sqrt(3)/4));
}
//Increases Diamond size by 1 but no higher than 39
void Diamond::Grow()
{
    int temp = Dsize + 1;
    SetSize(temp);
}
//Decreases Diamond size by 1 but no lower than 1
void Diamond::Shrink()
{
    int temp = Dsize - 1;
    SetSize(temp);
}
//Sets Diamond size between 1 and 39
void Diamond::SetSize(const int s)
{
    try
    {
        if (s < 1 || s > 39) throw s;
        Dsize = s;
    }
    catch(int s)
    {
        if (s > 39)
            Dsize = 39;
        else
            Dsize = 1;
    }
}
//Sets Diamond border character between ascii value 33(!) and 126(~)
void Diamond::SetBorder(const char b)
{
    try
    {
        if (b > '~' || b < '!') throw b;
        Dborder = b;
    }
    catch(char b)
    {
        Dborder = '#';
    }
}
//Sets Diamond fill character between ascii value 33(!) and 126(~)
void Diamond::SetFill(const char f)
{
    try
    {
        if (f > '~' || f < '!') throw f;
        Dfill = f;
    }
    catch(char f)
    {
        Dfill = '*';
    }
}
//Draws the Diamond
void Diamond::Draw()
{
    //Top half of Diamond
    for (int num = 1; num <= Dsize; num++)
    {
        for (int i = Dsize - num; i > 0; i--)
        {
            cout << " ";
        }
        cout << Dborder << " ";
        Fill(num);
    }
    //Bottom half of Diamond
    for (int num = Dsize - 1; num > 0; num--)
    {
        for (int i = 0; i < Dsize - num; i++)
        {
            cout << " ";
        }
        cout << Dborder << " ";
        Fill(num);
    }
}
//Fills the Diamond
void Diamond::Fill(int s)
{
    if (s >= 3)
        {
            for (int x = s - 2; x > 0; x--)
                cout << Dfill << " ";
            cout << Dborder;
        }
        if (s == 2)
            cout << Dborder << endl;
        else
            cout << endl;
}
//Displays a summary of the Diamond
void Diamond::Summary()
{
    cout << showpoint << setprecision(2) << fixed;
    cout << "Size of diamond's side = " << Dsize << " units.\n"
         << "Perimeter of diamond = " << Perimeter() << " units.\n"
         << "Area of diamond = " << Area() << " units.\n"
         << "Diamond looks like:\n";
    Draw();
}
