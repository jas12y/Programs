/*
Programmers Name: John Stubbs
      Assignment: Homework #14b
            Date: 4/19/12

Description:
            This program creates a class object, asks the user to input values
            and displays them.
*/
#include <iostream>
#include <iomanip>
#include "Payroll.h"
using namespace std;

// Function prototype
void displayPayroll(Payroll);

int main()
{
   double hours, rate;
   // Create a Payroll object
   Payroll emp;
   
   cout << "Please enter the following values:" << endl;
   cout << "Hours worked > ";
   cin >> hours;
   emp.setHours(hours);
   cout << "Rate of pay > $";
   cin >> rate;
   emp.setPayRate(rate);
   
   system("CLS");
   
   displayPayroll(emp);
   
   system("PAUSE");
   
   return 0;
}
void displayPayroll(Payroll p)
{
   cout << showpoint << setprecision(2) << fixed;
   cout << "Hours worked:  " << p.getHours() << endl;
   cout << "Pay rate: $" << p.getPayrate() << endl;
   cout << "Gross Pay: $" << p.getTotalPay() << endl;
}
