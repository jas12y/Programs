/*
Programmers Name: John Stubbs
      Assignment: Program 1
            Date: 9/18/11

Description: Calculates the subtotal, tax and total for items purchased.
*/
#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>

// Global Variable Constants
#define myDate " September 18, 2011            "
#define myLab  " Program 1                     "
#define line1  "      This program will calculate the subtotal,      "
#define line2  "         tax, and total for items purchased          "
#define line3  "       and display them in a receipt summary.        "

const float TAX_RATE = 0.075;

using namespace std;

// Function Prototypes
void splash();
void welcome();

int main(int argc, char *argv[])
{
    // Variables
    string item;
    unsigned short quantity;
    float price, subTotal, tax, total;
    
    cout << showpoint << setprecision(2) << fixed;
    
    splash();
    welcome();
    system("CLS");

    // Input Section
    cout << "\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t    What item did you purchase?  ";
    cin >> item;
    cout << "\t\t    How much did the item cost? $";
    cin >> price;    
    cout << "\t\t     How many did you purchase?  ";
    cin >> quantity;
    
    // Processing Section
    subTotal = quantity * price;
    tax = subTotal * TAX_RATE;
    total = subTotal + tax;
    
    // Output Section
    system("CLS");
    cout << "\n\n\n\n\n\n\n\n"
         << "\t\t\t          Retail-Mart\n\n"
         << "\t\t\t        Receipt Summery\n"
         << "\t\t\t------------------------------\n"
         << "\t\t\t    Item purchased: " << setw(10) << item << endl
         << "\t\t\t        Item price: $" << setw(9) << price << endl         
         << "\t\t\tQuantity purchased: " << setw(10) << quantity << endl
         << "\t\t\t------------------------------\n"
         << "\t\t\t          Subtotal: $" << setw(9) << subTotal << endl
         << "\t\t\t               Tax: $" << setw(9) << tax << endl
         << "\t\t\t==============================\n"
         << "\t\t\t             Total: $" << setw(9) << total << endl
         << "\n\n\n\n\n\n\n\n\n";
         
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
         <<  "\t\t             ,aaaaaaaaaaaaaaaa,\n"
         <<  "\t\t            dP\"    \"8,       `Y,\n"
         <<  "\t\t           d'       )Y,       `Yaa     \"Remember to recycle\n"
         <<  "\t\t          d'       ,P Y,        ,P          your code.\"\n"
         <<  "\t\t         d'       ,P   Ya      ,P\n"
         <<  "\t\t         `\"aa,   ,P    d'     ,P             - J. Stubbs\n"
         <<  "\t\t              \"baP     `\"\"\"\"\"\"    ,aa,\n"
         <<  "\t\t    Y\"\"\"\"\"\"\"Y,                  aP' `Y,\n"
         <<  "\t\t    ,P       Ya,             ,P\"'    `Y,\n"
         <<  "\t\t   ,P         `Y             `b       `Y,\n"
         <<  "\t\t  ,P        ,d\"'              `b       )P\n"
         <<  "\t\t   \"b      ,d'            ,a,  `b     ,d'\n"
         <<  "\t\t    \"b    ,daaaaaaaaa    ,P 8aaaabaaadP'\n"
         <<  "\t\t     \"b  ,8'        8   ,P           d'\n"
         <<  "\t\t      \"b,8'         8  ,P           d'\n"
         <<  "\t\t        \"8          8  `b          d'\n"
         <<  "\t\t         \"b,        8   `b        d'\n"
         <<  "\t\t          `\"\"\"\"\"\"\"\"\"\"    `b 8\"\"\"\"\"'\n"
         <<  "\t\t                           \"'\n"
         << " \n\n\n";
    system("PAUSE");
}
