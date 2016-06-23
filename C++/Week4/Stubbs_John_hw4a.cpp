/*
Programmers Name: John Stubbs
      Assignment: Homework #4a
            Date: 1/31/12
            
This program gets five days of sales data from the user
and displays the total, average, highest, and lowest amounts.
*/
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
double sumArray(double[], int);
double getHighest(double[], int);
double getLowest(double[], int);
int getSize();

int main()
{
   int size;               // To hold the size of the array
   double sales[100],      // To hold sales amounts
          total,           // To hold the total sales
          average,         // To hold the average
          highest,         // To hold the highest sales
          lowest;          // To hold the lowest sales

   size = getSize();
   
   // Get the sales data.
   for (int count = 0; count < size; count++)
   {
      cout << "Day " << (count +1) <<": ";
      cin >> sales[count];
   }

   // Get the total sales.
   total = sumArray(sales, size);

   // Calculate the average.
   average = total / size;

   // Find the highest sales amount.
   highest = getHighest(sales, size);

   // Find the lowest sales amount.
   lowest = getLowest(sales, size);

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

   while (size > 0)
   {
      size--;
      total += array[size];
   }
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
   int count = 1;
   double highest;

   highest = array[0];
   do
   {
      if (array[count] > highest)
         highest = array[count];
      
      count++;
         
   } while (count < size);
   
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
int getSize()
{
   int size;
   
   cout << "How many days would you like to analyze? > ";
   cin >> size;
   
   while (size <= 0 || size > 100)
   {
      cout << "\nPlease choose a number between 1 and 100."
           << "\nHow many days would you like to analyze? > ";
      cin >> size;
   }
   
   return size;
}
