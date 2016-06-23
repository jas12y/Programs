// Specification file for the Inventory class
#ifndef INVENTORY_H
#define INVENTORY_H

// Inventory class declaration

class Inventory
{
private:
   int itemNumber;
   int quantity;
   double cost;
   double totalCost;
   
public:
   // Default constructor
   Inventory()
      { itemNumber = 0; quantity = 0;
        cost = 0.0; totalCost = 0.0; }

   // Overloaded constructor
   Inventory(int, int, double);

   // Mutator functions
   void setItemNumber(int);
   void setQuantity(int);
   void setCost(double);

   void setTotalCost()
      { totalCost = quantity * cost; }

   // Accessor functions
   int getItemNumber()
      { return itemNumber; }

   int getQuantity()
      { return quantity; }

   double getCost()
      { return cost; }

   double getTotalCost()
      { return totalCost; }
};


#endif
