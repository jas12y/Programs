/*
Programmers Name: John Stubbs
      Assignment: #1
            Date: 1/18/13

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
Diamond::Diamond( int s, char b, char f )
{
    if (s >= 1 && s <= 39)
        Dsize = s;
    else if (s > 39)
        Dsize = 39;
    else
        Dsize = 1;
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
    if (Dsize < 39)
        Dsize++;
}
//Decreases Diamond size by 1 but no lower than 1
void Diamond::Shrink()
{
    if (Dsize > 1)
        Dsize--;
}
//Sets Diamond border character between ascii value 33(!) and 126(~)
void Diamond::SetBorder(char b)
{
    if (b <= '~' && b >= '!')
        Dborder = b;
    else
        Dborder = '#';
}
//Sets Diamond fill character between ascii value 33(!) and 126(~)
void Diamond::SetFill(char f)
{
    if (f <= '~' && f >= '!')
        Dfill = f;
    else
        Dfill = '*';
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
