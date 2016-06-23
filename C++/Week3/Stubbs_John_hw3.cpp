/*
Programmers Name: John Stubbs
      Assignment: Homework #3
            Date: 1/25/12

This program determines the water bills for local utility customers
and displays a summary of the bills.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Function Prototypes
int getBills();
long int getData(double&, double&);
void showBill(long int, double, double);

//Global Constants
const double TAX_RATE=.07;
const double REG_RATE=.25;

int main()
{
     long int account;          //Variable for account number
     int bills;                 //Variable for number of bills to process
     double lastRdg, currRdg;   //Variables for last and current meter reading

     //Get the number of bills to process
     bills = getBills();

     system("CLS");
     
     for (int i = 0; i < bills; i++)
     {
           //Gather input from user
           account = getData(lastRdg, currRdg);
           
           //Perform calculations and display bill 
           showBill(account, lastRdg, currRdg);
     }

     return 0;
}
int getBills()
{
     int bills;     //Variable for number of bills to process
     
     cout << "\n\n\n\n\n\n\n\n\n";
     cout << "\t\tHow many bills would you like to process? > ";
     cin >> bills;
   
     //Validate input is a non-negative number
     while (bills < 0)
     {
           system("CLS");
           
           cout << "\n\n\n\n\n\n\n\n\n";
           cout << "\t\tPlease enter a non-negative number.\n"
                << "\t\tHow many bills would you like to process? > ";
           cin >> bills;
     }

     return bills;
}
long int getData(double& lastRdg, double& currRdg)
{
     long int account;     //Variable for account number
     
     cout << "\n\n\n\n\n\n";
     cout << "\t\tPlease enter the account number: ";
     cin >> account;
     
     //Validate input is a non-negative number
     while (account < 0)
     {
           cout << "\n\t\tPlease enter a non-negative number."
                << "\n\t\tPlease enter the account number: ";
           cin >> account;
     }
     
     cout << "\n\n\t\tPlease enter last months meter reading: ";
     cin >> lastRdg;
     
     //Validate input is a non-negative number
     while (lastRdg < 0)
     {
           cout << "\n\t\tPlease enter a non-negative number."
                << "\n\t\tPlease enter last months meter reading: ";
           cin >> lastRdg;
     }
      
     cout << "\n\n\t\tPlease enter this months meter reading: ";
     cin >> currRdg;
     
     //Validate input is a non-negative number
     while (currRdg < 0)
     {
           cout << "\n\t\tPlease enter a non-negative number."
                << "\n\t\tPlease enter this months meter reading: ";
           cin >> currRdg;
     }
     
     return account;
}
void showBill(long int account, double lastRdg, double currRdg)
{
     double cost, tax, total;     //Variables for cost, tax, and total
     
     cost = (currRdg - lastRdg) * REG_RATE;  //Calculate cost
     tax = cost * TAX_RATE;                  //Calculate tax
     total = cost + tax;                     //Calculate total
     
     system("CLS");
     
     //Display bill summary
     cout << showpoint << setprecision(2) << fixed;
     cout << "\n\n\n\n\n\n\n\n";
     cout << "\t\tBill Summary for Account number: " << setw(7) << account
          << "\n\t\t-----------------------------------------"
          << "\n\t\tReading last month:\t\t " << setw(8) << lastRdg
          << "\n\t\tReading this month:\t\t " << setw(8) << currRdg
          << "\n\t\t      Gallons used:\t\t " << setw(8) << currRdg - lastRdg
          << "\n\t\t        Amount due:\t\t$" << setw(8) << cost
          << "\n\t\t               Tax:\t\t$" << setw(8) << tax
          << "\n\t\t  Total amount due:\t\t$" << setw(8) << total
          << "\n\n\n\n\n\n\n\n\n";
     
     system("PAUSE");
     system("CLS");
}
