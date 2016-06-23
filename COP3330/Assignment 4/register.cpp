/*
Programmers Name: John Stubbs
      Assignment: #4
            Date: 3/1/13

Implementation file for the Register class
*/
#include <iostream>
#include "register.h"

using namespace std;

//Constructor
Register::Register(const int num, const double amt)
{
    id = num;
    tillAmt = amt;
    current_empty = 0;
    current_size = BLOCK_SIZE;
    Sales = new Sale[BLOCK_SIZE];
}
//Destructor
Register::~Register()
{
    delete [] Sales;
}
//Returns Register ID
int Register::GetID()
{
    return id;
}
//Returns Register Amount
double Register::GetAmount()
{
    return tillAmt;
}
//Creates a Sale object in the Sales array and adjusts the Register Amount
//Checks for available space and adjusts if necessary
void Register::RingUpSale(const ItemType item, const double price)
{
    if (current_empty == current_size)
        Grow();
    
    Sales[current_empty].MakeSale(item, price);
    Sales[current_empty].Display();
    
    if (item == CREDIT)
        tillAmt -= price;
    else
        tillAmt += Sales[current_empty].Total();
    
    current_empty++;
}
//Displays last Sale in array
void Register::ShowLast()
{
    if (current_empty == 0)
        cout << "No Sales" << endl;
    else
        Sales[current_empty - 1].Display();
}
//Displays all Sales in array
void Register::ShowAll()
{
    if (current_empty == 0)
        cout << "No Sales" << endl;
    else
    {
        for (int i = 0; i < current_empty; i++)
            Sales[i].Display();
    }
}
//Cancels last Sale in Array
void Register::Cancel()
{
    if (current_empty == 0)
        cout << "No Sales" << endl;
    else
    {
        current_empty--;

        if (Sales[current_empty].Item() == CREDIT)
            tillAmt += Sales[current_empty].Total();
        else
            tillAmt -= Sales[current_empty].Total();
            Sales[current_empty].MakeSale(CREDIT,0);
    }
    if (current_size - current_empty > BLOCK_SIZE)
        Shrink();
}
//Displays the total tax for recent Sales
double Register::SalesTax(int num)
{
    double totalTax = 0;
    if (num > current_empty - 1)
        num = current_empty - 1;
    
    if (num < 0)
        cout << "**Invalid entry**" << endl;
    else
    {
        if (current_empty == 0)
            cout << "No Sales" << endl;
        else
        {
            for (int i = 1; i <= num; i++)
                totalTax += Sales[current_empty - i].Tax();
        }
    }
    return totalTax;
}
//Increases the array size
void Register::Grow()
{
    Sale* temp = new Sale[current_size + BLOCK_SIZE];
    
    for (int i = 0; i < current_empty; i++)
        temp[i] = Sales[i];
    
    delete [] Sales;
    Sales = temp;
    current_size += BLOCK_SIZE;
    
    cout << "Increasing size to " << current_size << endl;
}
//Decreases the array size
void Register::Shrink()
{
    Sale* temp = new Sale[current_size - BLOCK_SIZE];
    
    for (int i = 0; i < current_empty; i++)
        temp[i] = Sales[i];
    
    delete [] Sales;
    Sales = temp;
    current_size -= BLOCK_SIZE;
    
    cout << "Decreasing size to " << current_size << endl;
}
