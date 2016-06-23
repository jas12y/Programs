/*
Programmers Name: John Stubbs
      Assignment: Homework #4b
            Date: 2/1/12

Description:
            This program takes the user's entered monthly sales and calculates
            the total sales and average sales and displays them in a summary
            marking the highest and lowest sellers.
*/
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Function Prototypes
int validate();
int lowest(int[],int);
int highest(int[],int);
void summary(int,int,string[],int[]);

int main(int argc, char *argv[])
{
    const int SIZE = 5;              //Number of seeds
    int packsSold[SIZE];             //To hold the amounts sold
    string seeds[] = {"Petunia ",    //Names of seeds
                      "Pansy   ",
                      "Bluebell",
                      "Marigold",
                      "Lily    "};
    int total = 0;                   //Total amount sold
    
    system("CLS");
    
    //User input for amount sold of each type
    for (int i = 0; i < SIZE; i++)
    {
          cout << "\n\n\n\n\n\n\n\n\n"
               << "\t\tEnter the monthly sales for " << seeds[i] << ": ";
          
          packsSold[i] = validate();
          
          total += packsSold[i];
          
          system("CLS");
    }
    
    summary(SIZE,total,seeds,packsSold);
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
// Function Definitions
//******************************************************************************
//Validates entries for positive values
int validate()
{
     int value;
     
     cin >> value;
     
     while (value < 0)
     {
           system("CLS");
           
           cout << "\n\n\n\n\n\n\n\n\n\n"
                << "\t" << value << " is not valid. Enter a positive number: ";
           cin >> value;
     }
     
     return value;
}
//Finds the lowest amount sold
int lowest(int packsSold[],int limit)
{
     int low = packsSold[0];
     
     for (int i = 1; i < limit; i++)
     {
          if (low > packsSold[i])
              low = packsSold[i];
     }
     
     return low;
}
//Finds the highest amount sold
int highest(int packsSold[],int limit)
{
     int high = packsSold[0];
     
     for (int i = 1; i < limit; i++)
     {
          if (high < packsSold[i])
              high = packsSold[i];
     }
     
     return high;
}
//Displays a summary of all sales
void summary(int limit, int total,string seeds[],int packsSold[])
{
     float average;                       //Holds the average sold
     int low = lowest(packsSold,limit);   //Holds lowest sold
     int high = highest(packsSold,limit); //Holds highest sold
     average = (float)total / limit;      //Calculates the average sold
     
     cout << showpoint << setprecision(2) << fixed;
     cout << "\n\n\n\n\n\n"
          << "\t\t\tSummary for sales entered\n"
          << "\t\t\t-------------------------\n";
          
     for (int i = 0; i < limit; i++)
     {
          if (packsSold[i] == low)
    
               cout << "\t\t\tSales for " << seeds[i] << ":  " << packsSold[i] << " (Lowest)" << endl;
    
          else if (packsSold[i] == high)
           
               cout << "\t\t\tSales for " << seeds[i] << ":  " << packsSold[i] << " (Highest)" << endl;
                
          else
           
               cout << "\t\t\tSales for " << seeds[i] << ":  " << packsSold[i] << endl;
     }
     cout << "\t\t\tTotal sales       :  " << total << endl
          << "\t\t\tAverage sales     :  " << average << endl
          << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
}
