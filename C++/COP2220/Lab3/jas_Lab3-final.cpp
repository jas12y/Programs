/*
Programmers Name: John Stubbs
      Assignment: Lab 3
            Date: 9/14/11

Description: Calculates the users gross pay, net pay and taxes.
*/
#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>

// Global Variable Constants
#define myDate " September 14, 2011            "
#define myLab  " Lab 3 Part 3                  "
#define line1  "      This program will calculate your gross pay,    "
#define line2  "           your net pay and your taxes               "
#define line3  "         and display them in a payment summery       "

const float TAX_RATE = 0.3;

using namespace std;

// Function Prototypes
void splash();
void welcome();

int main(int argc, char *argv[])
{
    // Variables
    int hours;
    float rate, grossPay, netPay, tax;
    
    cout << showpoint << setprecision(2) << fixed;
    
    splash();
    welcome();
    system("CLS");
    
    // Input Section
    cout << "\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t   How many hours did you work? ";
    cin >> hours;
    system("CLS");
    cout << "\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t   How much do you get paid per hour? $";
    cin >> rate;
    
    // Processing Section
    grossPay = hours * rate;
    tax = grossPay * TAX_RATE;
    netPay = grossPay - tax;
    
    // Output Section
    system("CLS");
    cout << "\n\n\n\n\n\n\n\n\n\n"
         << "\t\t\t        Pay Summery\n"
         << "\t\t\t--------------------------\n"
         << "\t\t\tYour hours worked: " << setw(4) << hours << endl
         << "\t\t\tYour rate of pay: $" << setw(7) << rate << endl
         << "\t\t\tYour gross pay is $" << setw(7) << grossPay << endl
         << "\t\t\t      Your tax is $" << setw(7) << tax << endl
         << "\t\t\t  Your net pay is $" << setw(7) << netPay << endl
         << "\n\n\n\n\n\n\n\n\n";
         
    system("PAUSE");
    system("CLS");
    
    cout << "\n\n\n\n\n\n\n\n\n\n"
         << "\t\tThat looks better. Taxes still stink though."
         << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
         
    system("PAUSE");
    return EXIT_SUCCESS;
}

// Function Definitions
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
}    

void splash()
{
    cout << " \n\n\n"
         << " \n\t\t              _ "    
         << " \n\t\t             (_)           _ "
         << " \n\t\t          _         .=.   (_) "
         << " \n\t\t         (_)   _   //(`)_ "
         << " \n\t\t              //`\\/ |\\ 0`\\\\       \"All the world "
         << " \n\t\t              ||-.\\_|_/.-||        loves a clown.\""
         << " \n\t\t              )/ |_____| \\(    _        ~ Cole Porter"
         << " \n\t\t             0   #/\\ /\\#  0   (_) "
         << " \n\t\t                _| o o |_ "
         << " \n\t\t         _     ((|, ^ ,|)) "
         << " \n\t\t        (_)     `||\\_/||` "
         << " \n\t\t                 || _ ||      _ "
         << " \n\t\t                 | \\_/ |     (_) "
         << " \n\t\t             0.__.\\   /.__.0 "
         << " \n\t\t              `._  `\"`  _.' "
         << " \n\t\t       jgs       / ;  \\ \\ "
         << " \n\t\t               0'-' )/`'-0 "
         << " \n\t\t                   0` "
         << " \n\n\n";
    system("PAUSE");
}
