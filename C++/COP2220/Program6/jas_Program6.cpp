/*
Programmers Name: John Stubbs
      Assignment: Program 6 
                  Date: 12/1/11

Description:
            This program takes the user's entered monthly sales and calculates
            the total sales and average sales and displays them in a summary
            marking the highest and lowest sellers.
INPUTS:
        Monthly sales for each type of salsa
OUTPUTS:
        Total sales, Average sales, Highest and Lowest sellers
*/
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

// Global Variable Constants
#define myDate " December 1, 2011              "
#define myLab  " Program 6                     "
#define line1  "    Enter the monthly sales for each type of salsa   "
#define line2  "   and see a summary of the sales entered, including "
#define line3  "   total sales, average sales, and high/low sellers. "

using namespace std;

// Function Prototypes
void splash();
void welcome();
int validate();
int lowest(int[],int);
int highest(int[],int);
void summary(int,int,string[],int[]);

int main(int argc, char *argv[])
{
    const int SIZE = 5;
    int jarSales[SIZE];
    string salsa[] = {"Mild  ", "Medium", "Sweet ", "Hot   ", "Zesty "};
    int total = 0;
    
    splash();
    welcome();
    
    system("CLS");
    
    for (int i = 0; i < SIZE; i++)
    {
          cout << "\n\n\n\n\n\n\n\n\n"
               << "\t\tEnter the monthly sales for " << salsa[i] << ": ";
          
          jarSales[i] = validate();
          
          total += jarSales[i];
          
          system("CLS");
    }
    
    summary(SIZE,total,salsa,jarSales);
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
// Function Definitions
void splash()
{
     cout << "\n\n"
          << "\t  When it absolutely, positively has to be DESTROYED overnight!\n"
          << "\t\t\t           _.-.\n"
          << "\t\t\t        .-.  `) |  .-. \n"
          << "\t\t\t    _.'`. .~./  \\.~. .`'._\n"
          << "\t\t\t .-' .'.'.'.-|  |-.'.'.'. '-.\n"
          << "\t\t\t  `'`'`'`'`  \\  /  `'`'`'`'`\n"
          << "\t\t\t             /||\\    .'\\  .-\"'.\n"
          << "\t\t\t           _//||\\\\._  \\ \\/ (_) )\n"
          << "\t\t\t         .'     `.  '..'  ,-..'\n"
          << "\t\t\t  ___,  /.'      /    \\'\\ \\\n"
          << "\t\t\t  ', | |  '-. .-;      | \\.'\n"
          << "\t\t\t  / |' |     '.\\       |\n"
          << "\t\t\t  | |  |       ;`''.   |\n"
          << "\t\t\t  | \\   \\      (    / /\n"
          << "\t\t\t  \\  '.'`'.     '-, ;'\n"
          << "\t\t\t   )    .'``'-:__;-'\n"
          << "\t\t\t  <_.-,  `._;-._\n"
          << "\t\t\t       `-.,_   /\n"
          << "\t\t\t            `\\/\n"
          << "\t\t\t  United States Marine Corps\n\n\n";
     
     system("PAUSE");
}
void welcome()
{
     cout << "\n\n\n";
     cout << "\t /--------------------------------------------------------------\\ \n"
          << "\t |                      About This Program                      | \n"
          << "\t +--------------------------------------------------------------+ \n"
          << "\t |                                                              | \n"
          << "\t |                                                              | \n"
          << "\t |             Programmer's Name: John Stubbs                   | \n"
          << "\t |                          Date:" myDate                      "| \n"
          << "\t |               Name of program:" myLab                       "| \n"
          << "\t |                                                              | \n"
          << "\t |    /-------------------- Description --------------------\\   | \n"
          << "\t |    |" line1                                             "|   | \n"
          << "\t |    |" line2                                             "|   | \n"
          << "\t |    |" line3                                             "|   | \n"    
          << "\t |    \\-----------------------------------------------------/   | \n"
          << "\t |                                                              | \n"
          << "\t |                                                              | \n"
          << "\t |                                                              | \n"
          << "\t \\--------------------------------------------------------------/ \n";
     cout << "\n\n\n\n";
     system("PAUSE");
     system("CLS");
}
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
int lowest(int jarSales[],int limit)
{
     int low = jarSales[0];
     
     for (int i = 1; i < limit; i++)
     {
          if (low > jarSales[i])
              low = jarSales[i];
     }
     
     return low;
}
int highest(int jarSales[],int limit)
{
     int high = jarSales[0];
     
     for (int i = 1; i < limit; i++)
     {
          if (high < jarSales[i])
              high = jarSales[i];
     }
     
     return high;
}
void summary(int limit, int total,string salsa[],int jarSales[])
{
     float average;
     int low = lowest(jarSales,limit);
     int high = highest(jarSales,limit);
     average = (float)total / limit;
     
     cout << showpoint << setprecision(2) << fixed;
     cout << "\n\n\n\n\n\n"
          << "\t\t\tSummary for sales entered\n"
          << "\t\t\t-------------------------\n";
          
     for (int i = 0; i < limit; i++)
     {
          if (jarSales[i] == low)
    
               cout << "\t\t\tSales for " << salsa[i] << ":  " << jarSales[i] << " (Lowest)" << endl;
    
          else if (jarSales[i] == high)
           
               cout << "\t\t\tSales for " << salsa[i] << ":  " << jarSales[i] << " (Highest)" << endl;
                
          else
           
               cout << "\t\t\tScore for " << salsa[i] << ":  " << jarSales[i] << endl;
     }
     cout << "\t\t\tTotal sales     :  " << total << endl
          << "\t\t\tAverage sales   :  " << average << endl
          << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
}
