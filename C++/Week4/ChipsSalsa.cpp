// Chapter 7, Programming Challenge 3
// Chips and Salsa
#include<iostream>
#include <iomanip>
using namespace std;

// Function prototypes
int getTotal(int [], int);
int posOfLargest(int [], int);
int posOfSmallest(int [], int);

int main()
{
   // Constant for max string size
   const int SIZE = 10;
   
   // Constant for the number of salsa types
   const int NUM_TYPES = 5;   
   
   // Array of salsa types
   char name[NUM_TYPES][SIZE] = {"mild  ", 
                                 "medium", 
                                 "sweet ", 
                                 "hot   ", 
                                 "zesty "};  

   // Array of sales of each salsa type
   int sales[NUM_TYPES];
   
   // Total number of jars sold
   int totalJarsSold;
   
   // Subscript of the salsa that sold the most.
   int hiSalesProduct;
   
   // Subscript of the salsa that sold the least.
   int loSalesProduct;
     
   // Get the number of jars sold of each type of salsa.
   for (int type = 0; type < NUM_TYPES; type++)
   {
      // Get the number of jars sold.
      cout << "Jar sold last month of " << name[type] << ": ";
      cin  >> sales[type];
      
      // Validate the input.
      while (sales[type] < 0)
      {  cout << "Jars sold must be 0 or more.  Please re-enter: ";
         cin  >> sales[type];
      }
   }
   
   // Get total sales and high and low selling products
   totalJarsSold  = getTotal(sales, NUM_TYPES);
   hiSalesProduct = posOfLargest(sales, NUM_TYPES);
   loSalesProduct = posOfSmallest(sales, NUM_TYPES);
   
   // Displa the sales report header.
   cout << endl << endl;
   cout << "     Salsa Sales Report \n\n";
   cout << "Name              Jars Sold \n";
   cout << "____________________________\n";
   
   // Display the name and jars sold of each type.
   for (int salsaType = 0; salsaType < NUM_TYPES; salsaType++)
   {
      cout << name[salsaType] 
           << setw(21) << sales[salsaType] 
           << endl;
   }
   
   // Display the total sales, highest seller, and lowest seller.
   cout << "\nTotal Sales:" << setw(15) << totalJarsSold << endl;
   cout << "High Seller: "  << name[hiSalesProduct] << endl;
   cout << "Low Seller : " << name[loSalesProduct] << endl;    
        
   return 0;
}

/************************************************************
 *                         getTotal                         *
 * Calculates and returns the total of the values stored in *
 * the array passed to the function.                        *
 ************************************************************/
int getTotal(int array[], int numElts)
{
   int total = 0;

   for (int pos = 0; pos < numElts; pos++)
      total += array[pos];

   return total;
}


/************************************************************
 *                    posOfLargest                          *
 * Finds and returns the subscript of the array position    *
 * holding the largest value in the array passed to the     *
 * function.                                                *
 ************************************************************/
int posOfLargest(int array[], int numElts)
{
   int indexOfLargest = 0;
   
   for (int pos = 1; pos < numElts; pos++)
   {
      if (array[pos] > array[indexOfLargest])
         indexOfLargest = pos;
   }   
   return indexOfLargest;
}


/************************************************************
 *                    posOfSmallest                         *
 * Finds and returns the subscript of the array position    *
 * holding the smallest value in the array passed to the    *
 * function.                                                *
 ************************************************************/
int posOfSmallest(int array[], int numElts)
{
   int indexOfSmallest = 0;
   
   for (int pos = 1; pos < numElts; pos++)
   {
      if (array[pos] < array[indexOfSmallest])
         indexOfSmallest = pos;
   }     
   return indexOfSmallest;
}
