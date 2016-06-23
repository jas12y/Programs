//  Chapter 11, Programming Challenge 4
//  Weather Statistics
#include <iostream>
using namespace std;

// Constant for the number of months
const int NUM_MONTHS = 12;

// Declaration of the WeatherInfo structure
struct WeatherInfo
{
   double rain;         // Total rainfall
   double high;         // High temperature
   double low;          // Low temperature
   double averageTemp;  // Average temperature     
};

int main()
{
   // Create an array of WeatherInfo structures
   WeatherInfo year[NUM_MONTHS];
   int index = 0;         // Loop counter

   // Get the weather data for each month.
   cout << "Enter the following information:\n";
   for (index = 0; index < NUM_MONTHS; index++)
   {
      // Get the rainfall.
      cout << "Month " << (index + 1) << endl;
      cout << "\tTotal Rainfall: ";
      cin >> year[index].rain;
      
      // Get the high temperature.
      cout << "\tHigh Temperature: ";
      cin >> year[index].high;
      
      // Validate the high temperature.
      while (year[index].high < -100 || year[index].high > 140)
      {
         cout << "ERROR: Temperature must be in the range "
              << "of -100 through 140.\n";
         cout << "\tHigh Temperature: ";
         cin >> year[index].high;
      }

      // Get the low temperature.
      cout << "\tLow Temperature: ";
      cin >> year[index].low;
      
      // Validate the low temperature.
      while (year[index].low < -100 || year[index].low > 140)
      {
         cout << "ERROR: Temperature must be in the range "
              << "of -100 through 140.\n";
         cout << "\tLow Temperature: ";
         cin >> year[index].low;
      }

      // Calculate the average temperature.
      year[index].averageTemp = 
            (year[index].high + year[index].low) / 2.0;
   }

   // Calculate total annual rainfall
   double totalRain = 0;
   for (index = 0; index < NUM_MONTHS; index++)
      totalRain += year[index].rain;
   
   // Calculate average monthly rainfall
   double aveMonthRain = totalRain / NUM_MONTHS;
   
   // Calculate the average monthly average temperature
   double aveTotal = 0, aveAve;
   for (index = 1; index < NUM_MONTHS; index++)
      aveTotal += year[index].averageTemp;
   aveAve = aveTotal / NUM_MONTHS;
   
   // Find the highest & lowest temperatures
   double highest, lowest, highMonth = 0, lowMonth = 0;
   highest = year[0].high;
   lowest = year[0].low;
   for (index = 1; index < NUM_MONTHS; index++)
   {
      if (year[index].high > highest)
      {
         highest = year[index].high;
         highMonth = index;
      }
      
      if (year[index].low < lowest)
      {
         lowest = year[index].low;
         lowMonth = index;
      }
   }
   // Display findings.
   cout << "\nTotal Rainfall: " << totalRain << endl;
   cout << "Average Monthly Rain: " << aveMonthRain << endl;
   cout << "Average Monthly Average Temperature: " << aveAve << endl;
   cout << "Highest Temperature: " << highest;
   cout << "  (Month " << (highMonth + 1) << ")\n";
   cout << "Lowest Temperature: " << lowest;
   cout << "  (Month " << (lowMonth + 1) << ")\n\n";
   
   return 0;
}

