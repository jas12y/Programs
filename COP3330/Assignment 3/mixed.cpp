/*
Programmers Name: John Stubbs
      Assignment: #3
            Date: 2/15/13

Implementation file for the Mixed class
*/
#include "mixed.h"
#include <iostream>

using namespace std;

//Overload of the input operator
istream& operator>>(istream& s, Mixed& m)
{
    int i, n, d;
    char c1, c2;
        
    s >> i >> n >> c2 >> d;
    
    m.interger = i;

    if ((i < 0 && n >= 0) || (i > 0 && n >=0) || i == 0)
        m.num = n;
    else
    {
        m.interger = 0;
        m.num = 0;
        m.den = 1;
    }
    if (d >= 1)
       m.den = d;
    else
    {
        m.interger = 0;
        m.num = 0;
        m.den = 1;
    }
    return s;
}
//Overload of the output operator
ostream& operator<<(ostream& s, const Mixed& m)
{
    if (m.interger != 0)
        s << m.interger << " ";
    if (m.interger == 0 && m.num == 0)
        s << m.interger;
    else if (m.num != 0)
        s << m.num << "/" << m.den;
    
    return s;
}
//Overloaded Default Constructor
Mixed::Mixed(int i)
{
    interger = i;
    num = 0;
    den = 1;
}
//Constructor
Mixed::Mixed(int i, int n, int d)
{
    interger = i;

    if ((i < 0 && n >= 0) || (i > 0 && n >=0) || i == 0)
        num = n;
    else
    {
        interger = 0;
        num = 0;
        den = 1;
    }
    if (d >= 1)
       den = d;
    else
    {
        interger = 0;
        num = 0;
        den = 1;
    }
}
//Returns a decimal equivalent of the mixed number
double Mixed::Evaluate()
{
    double deci;
    
    if (interger < 0)
        deci = interger - ((double)num/(double)den);
    else
        deci = interger + ((double)num/(double)den);
    
    return deci;    
}
//Converts the mixed number to a fraction
void Mixed::ToFraction()
{
    if (interger != 0)
    {
        if (interger < 0)
            num = (den * interger) - num;
        else
            num = (den * interger) + num;
        interger = 0;
    }
}
//Converts the mixed number to its lowest terms
void Mixed::Simplify()
{
    int lcd;
    bool isneg = false;
    
    if (interger < 0)
    {
        interger *= -1;
        isneg = true;
    }
    else if (num < 0)
    {
        num *= -1;
        isneg = true;
    }
    if (num > den)
    {
        interger += num/den;
        
        num = num % den;
    }
    lcd = Lcd();
    num = num/lcd;
    den = den/lcd;
    
    if (den == 1)
    {
        interger += num;
        num = 0;
    }
    if (isneg && interger != 0)
        interger *= -1;
    else if (isneg && interger == 0)
        num *= -1;
}
//Finds the lowest common denominator(provided by Dr. Gaitros in class)
int Mixed::Lcd()
{
    int a = num;
    int b = den;
    int temp;

    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    
    if (a < 0)
        a *= -1;
    
    return a;
}
//Overload of the prefix increment operator
Mixed Mixed::operator++()
{
    interger++;
    
    return Mixed(interger, num, den);
}
//Overload of the postfix increment operator
Mixed Mixed::operator++(int i)
{
    int temp = interger;
    
    interger++;
    
    return Mixed(temp, num, den);
}
//Overload of the prefix decrement operator
Mixed Mixed::operator--()
{
    interger--;
    
    return Mixed(interger, num, den);
}
//Overload of the postfix decrement operator
Mixed Mixed::operator--(int i)
{
    int temp = interger;
    
    interger--;
    
    return Mixed(temp, num, den);
}
//Overload of the equivalency operator
bool Mixed::operator==(const Mixed m1)
{
    bool equal = false;
    Mixed temp1(interger, num, den);
    Mixed temp2 = m1;
    temp1.Simplify();
    temp2.Simplify();
    
    if (temp1.interger == temp2.interger && temp1.num == temp2.num && temp1.den == temp2.den)
        equal = true;
    
    return equal;
}
//Overload of the not equivanent operator
bool Mixed::operator!=(const Mixed m1)
{
    bool nEqual = true;
    Mixed temp1(interger, num, den);
    Mixed temp2 = m1;
    temp1.Simplify();
    temp2.Simplify();
    
    if (temp1.interger == temp2.interger && temp1.num == temp2.num && temp1.den == temp2.den)
        nEqual = false;
    
    return nEqual;
}
//Overload of the greater than or equal to operator
bool Mixed::operator>=(const Mixed m1)
{
    bool gEqual = false;
    Mixed temp1(interger, num, den);
    Mixed temp2 = m1;
    temp1.Simplify();
    temp2.Simplify();
    
    if (temp1.interger > temp2.interger)
        gEqual = true;
    else if (temp1.interger == temp2.interger && (temp1.num * temp2.den) > (temp2.num * temp1.den))
        gEqual = true;
    else if (temp1.interger == temp2.interger && temp1.num == temp2.num && temp1.den == temp2.den)
        gEqual = true;
    
    return gEqual;
}
//Overload of the less than or equal to operator
bool Mixed::operator<=(const Mixed m1)
{
    bool lEqual = false;
    Mixed temp1(interger, num, den);
    Mixed temp2 = m1;
    temp1.Simplify();
    temp2.Simplify();
    
    if (temp1.interger < temp2.interger)
        lEqual = true;
    else if (temp1.interger == temp2.interger && (temp1.num * temp2.den) < (temp2.num * temp1.den))
        lEqual = true;
    else if (temp1.interger == temp2.interger && temp1.num == temp2.num && temp1.den == temp2.den)
        lEqual = true;
    
    return lEqual;
}
//Overload of the greater than operator
bool Mixed::operator>(const Mixed m1)
{
    bool gThan = false;
    Mixed temp1(interger, num, den);
    Mixed temp2 = m1;
    temp1.Simplify();
    temp2.Simplify();
    
    if (temp1.interger > temp2.interger)
        gThan = true;
    else if (temp1.interger == temp2.interger && (temp1.num * temp2.den) > (temp2.num * temp1.den))
        gThan = true;
    
    return gThan;
}
//Overload of the less than operator
bool Mixed::operator<(const Mixed m1)
{
    bool lThan = false;
    Mixed temp1(interger, num, den);
    Mixed temp2 = m1;
    temp1.Simplify();
    temp2.Simplify();
    
    if (temp1.interger < temp2.interger)
        lThan = true;
    else if (temp1.interger == temp2.interger && (temp1.num * temp2.den) < (temp2.num * temp1.den))
        lThan = true;
    
    return lThan;
}
//Overload of the addition operator
const Mixed operator+(const Mixed m1, const Mixed m2)
{
    Mixed sum;
    Mixed temp1 = m1;
    Mixed temp2 = m2;
    temp1.ToFraction();
    temp2.ToFraction();
    
    sum.num = (temp1.num * temp2.den) + (temp2.num * temp1.den);
    sum.den = temp1.den * temp2.den;
    if (sum.interger < 0 && sum.num < 0)
        sum.num *= -1;
        
    sum.Simplify();
    
    return sum;
}
//Overload of the subtraction operator
const Mixed Mixed::operator-(const Mixed m1)
{
    Mixed sub;
    Mixed temp1(interger, num, den);
    Mixed temp2 = m1;
    temp1.ToFraction();
    temp2.ToFraction();
    
    sub.num = (temp1.num * temp2.den) - (temp2.num * temp1.den);
    sub.den = temp1.den * temp2.den;
    if (sub.interger < 0 && sub.num < 0)
        sub.num *= -1;
        
    sub.Simplify();
    
    return sub;
}
//Overload of the multiply operator
const Mixed Mixed::operator*(const Mixed m1)
{
    Mixed mult;
    Mixed temp1(interger, num, den);
    Mixed temp2 = m1;
    temp1.ToFraction();
    temp2.ToFraction();
    
    mult.num = temp1.num * temp2.num;
    mult.den = temp1.den * temp2.den;
        
    mult.Simplify();
    
    return mult;
}
//Overload of the division operator
const Mixed Mixed::operator/(const Mixed m1)
{
    Mixed div;
    Mixed temp1(interger, num, den);
    Mixed temp2 = m1;
    temp1.ToFraction();
    temp2.ToFraction();
    
    div.num = temp1.num * temp2.den;
    div.den = temp1.den * temp2.num;
    
    if ((div.den < 0 && div.num < 0) || (div.den < 0 && div.num > 0))
    {
        div.den *= -1;
        div.num *= -1;
    }
        
    div.Simplify();
    
    return div;
}
