// Chapter 6, Programming Challenge 1
// Markup
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototype
double retail(double, double);   

int main()
{
   double wholeSale,     // Wholesale price
          markUp,        // Markup percentage
          sellingPrice;  // Retail selling price

   // Get the wholesale cost.
   cout << "Enter the item's wholesale cost: ";
   cin  >> wholeSale;
   
   // Validate the wholesale cost.
   while (wholeSale < 0)
   {
      cout << "Re-enter the value using a "
           << "non-negative number only.\n";
      cout << "Enter the item's wholesale cost: ";
      cin  >> wholeSale;
   }

   // Get the markup percentage.
   cout << "Enter the item's markup percentage "
        << "(e.g. 15.0): ";
   cin >> markUp;
   
   // Validate the markup percentage.
   while (markUp < 0)
   {  
      cout << "Re-enter the value using a "
           << "non-negative number only.\n";
      cout << "Enter the item's markup percentage "
           << "(e.g. 15.0): ";
      cin >> markUp;
   }
   
   // Call retail function, passing it wholeSale
   // and markUp as arguments. Store the value it
   // returns in the sellingPrice variable.
   sellingPrice = retail(wholeSale, markUp);
   
   // Display the results.
   cout << fixed << showpoint << setprecision(2);
   cout << "The retail price is $" 
        << sellingPrice << endl;

   return 0;

}  // End of main function

//*************************************************
// retail function                                *
// This function accepts an item's wholesale cost *
// and markUp percentage as arguments. It uses    *
// them to calculate the retail price, which is   *
// returned from the function.                    *
//*************************************************

double retail(double whole, double mark)
{
   double price;  // To hold the retail price
   
   // Calculate the retail price.
   price = whole + (whole * (mark/100));
   
   // Return the retail price.
   return price;
}
