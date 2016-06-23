/*
Programmers Name: John Stubbs
      Assignment: Homework #14a
            Date: 4/19/12

Description:
            This program creates a class object, asks the user to input values
            and displays them.
*/
#include <iostream>
#include <iomanip>
#include "Inventory.h"
using namespace std;

// Function prototype
void displayInventory(Inventory);

int main()
{
   int itemNum, quantity;
   double cost;
   // Create an Inventory object
   Inventory item;
   
   cout << "Please enter the following values:" << endl;
   cout << "Item Number > ";
   cin >> itemNum;
   item.setItemNumber(itemNum);
   cout << "Quantity > ";
   cin >> quantity;
   item.setQuantity(quantity);
   cout << "Item cost > $";
   cin >> cost;
   item.setCost(cost);
   item.setTotalCost();
   
   system("CLS");
   
   displayInventory(item);
   
   system("PAUSE");
   
   return 0;
}
void displayInventory(Inventory i)
{
   cout << showpoint << setprecision(2) << fixed;
   cout << "Item Number:  " << i.getItemNumber() << endl;
   cout << "Quantity:  " << i.getQuantity() << endl;
   cout << "Cost: $" << i.getCost() << endl;
   cout << "Total cost: $" << i.getTotalCost() << endl << endl;
}
