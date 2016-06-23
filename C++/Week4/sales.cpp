// This program gets five days of sales data from the user
// and displays the total, average, highest, and lowest amounts.
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
double sumArray(double[], int);
double getHighest(double[], int);
double getLowest(double[], int);

int main()
{
   const int NUM_DAYS = 5; // Number of days
   double sales[NUM_DAYS], // To hold sales amounts
          total,           // To hold the total sales
          average,         // To hold the average
          highest,         // To hold the highest sales
          lowest;          // To hold the lowest sales

   // Get the sales data.
   cout << "Enter the sales for this week.\n";
   for (int count = 0; count < NUM_DAYS; count++)
   {
      cout << "Day " << (count +1) <<": ";
      cin >> sales[count];
   }

   // Get the total sales.
   total = sumArray(sales, NUM_DAYS);

   // Calculate the average.
   average = total / NUM_DAYS;

   // Find the highest sales amount.
   highest = getHighest(sales, NUM_DAYS);

   // Find the lowest sales amount.
   lowest = getLowest(sales, NUM_DAYS);

   // Display the results.
   cout << fixed << showpoint << setprecision(2);
   cout << "The total sales are $" << total << endl;
   cout << "The average sales amount is $" << average << endl;
   cout << "The highest sales amount is $" << highest << endl;
   cout << "The lowest sales amount is $" << lowest << endl;
   cout << "\n\n\n";
   
   system("PAUSE");
   return 0;
}

//***************************************************
// Definition of sumArray                           *
// This function accepts a double array and its size *
// as arguments. The sum of the array's elements    *
// is returned as an double.                         *
//***************************************************

double sumArray(double array[], int size)
{
   double total = 0; // Accumulator

   for (int count = 0; count < size; count++)
      total += array[count];
   return total;
}

//****************************************************
// Definition of getHighest                          *
// This function accepts a double array and its size  *
// as arguments. The highest value in the array is   *
// returned as an double.                             *
//****************************************************

double getHighest(double array[], int size)
{
   double highest;

   highest = array[0];
   for (int count = 1; count < size; count++)
   {
      if (array[count] > highest)
         highest = array[count];
   }
   return highest;
}

//****************************************************
// Definition of getLowest                           *
// This function accepts a double array and its size  *
// as arguments. The lowest value in the array is    *
// returned as an double.                             *
//****************************************************

double getLowest(double array[], int size)
{
   double lowest;

   lowest = array[0];
   for (int count = 1; count < size; count++)
   {
      if (array[count] < lowest)
         lowest = array[count];
   }
   return lowest;
}
