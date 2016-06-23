/*
Programmers Name: John Stubbs
      Assignment: Lab 1
            Date: 8/30/11

Description: This program calculates the user's pay.
*/

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    double hours, rate, pay;
    
    // Get the number of hours worked.
    cout << "How many hours did you work? ";
    cin >> hours;
    
    // Get the hourly pay rate.
    cout << "How much do you get paid per hour? ";
    cin >> rate;
    
    // Calculate the pay.
    pay = hours * rate;
    
    // Display the pay.
    cout << "You have earned $" << pay << endl;
       
    system("PAUSE");
    
    system("cls");
    
    // What my boss would say LOL.
    cout << "Quit loafin' around and get back to work!" << endl;
    
    system("pause");
    return EXIT_SUCCESS;
}
