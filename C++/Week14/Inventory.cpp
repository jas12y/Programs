// Implementation file for the Inventory class
#include <iostream>
#include "Inventory.h"
using namespace std;

//*************************************
// Overloaded constructor             *
//*************************************

Inventory::Inventory(int i, int q, double c)
{ 
   itemNumber = i;
   quantity = q;
   cost = c;
   setTotalCost(); 
}

//*************************************
// setItemNumber member function      *
//*************************************

void Inventory::setItemNumber(int i)
{ 
   if (i >= 0)
      itemNumber = i;
   else
   {
      cout << "Invalid item number.\n";
      exit(EXIT_FAILURE);
   }
}

//*************************************
// setQuantity member function        *
//*************************************

void Inventory::setQuantity(int q)
{ 
   if (q >= 0)
      quantity = q;
   else
   {
      cout << "Invalid quantity.\n";
      exit(EXIT_FAILURE);
   }
}

//*************************************
// setCost member function            *
//*************************************

void Inventory::setCost(double c)
{ 
   if (c >= 0)
      cost = c;
   else
   {
      cout << "Invalid cost.\n";
      exit(EXIT_FAILURE);
   }
}

