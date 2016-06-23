/*
Programmers Name: John Stubbs
      Assignment: #4
            Date: 3/1/13

Implementation file for the Sale class
*/
#include <iostream>
#include <iomanip>
#include <string>
#include "sale.h"

const double SALES_TAX = 0.07;

using namespace std;

//Constructor
Sale::Sale()
{
    price = 0;
    tax = 0;
    total = 0;
}
//Loads data into the Sale object
void Sale::MakeSale(ItemType x, double amt)
{
    item = x;
    price = amt;
    if (item != CREDIT)
        tax = price * SALES_TAX;
    else
        tax = 0;
    total = price + tax;
}
//Returns Item type
ItemType Sale::Item()
{
    return item;
}
//Returns Price
double Sale::Price()
{
    return price;
}
//Returns Tax
double Sale::Tax()
{
    return tax;
}
//Returns Total
double Sale::Total()
{
    return total;
}
//Displays the Sale object data
void Sale::Display()
{
    const string ITEMS[4] = {"Book    ", "DVD     ", "Software", "Credit  "};
    
    cout << fixed << setprecision(2);

    if (item == CREDIT)
        cout << ITEMS[item] << "\t<$" << setw(7) << price << ">\tTax: $" << setw(6) << tax << "\tTotal: <$" << setw(7) << total << ">" << endl;
    else
        cout << ITEMS[item] << "\t $" << setw(7) << price << " \tTax: $" << setw(6) << tax << "\tTotal:  $" << setw(7) << total << endl;
}
