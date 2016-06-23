/*
Programmers Name: John Stubbs
      Assignment: Lab 7 Final 
                  Date: 10/12/11

Description: Displays a menu for a Health Club Membership
             and displays a summery for the values entered.

INPUTS:
       User selection
       Number of months
OUTPUTS:
        Total fee for months and type entered
        Including tax
*/
#include <cstdlib>
#include <iostream>
#include <iomanip>

// Global Variable Constants
#define myDate " October 12, 2011              "
#define myLab  " Lab 7 Final                   "
#define line1  "      This program will display a menu for a         "
#define line2  "      Health Club Membership and give a price        "
#define line3  "     summery for values entered, including tax.      "

const float STANDARD = 40;
const float STUDENT = 35;
const float SENIOR = 25;
const float TAX_RATE = 0.075;

using namespace std;

// Function Prototypes
void splash();
void welcome();
void logo();

int main(int argc, char *argv[])
{
    // Variables
    char choice;
    int months;
    float charges;
    float tax;
    float totalFee;
    
    cout << showpoint << setprecision(2) << fixed;
    
    splash();
    welcome();

    do
    {
         system("CLS");
         
         // Input Section
         logo();
         cout << "\t\t\t\tMembership Menu\n"
              << "\t\t\t ------------------------------\n\n"
              << "\t\t\t  A. Standard Membership\n"
              << "\t\t\t  B. Student Membership\n"
              << "\t\t\t  C. Senior Citizen Membership\n"
              << "\t\t\t  D. Quit the program\n\n"
              << "\t\t\t  Enter your choice > ";
         cin  >> choice;
         
         
              if (choice == 'a' || choice == 'A')
              {
                    cout << "\n\t\t\t  How many months?  > ";
                    cin  >> months;
                    
                    system("CLS");
                    
                    if (months > 0)
                    {    
                         // Processing Section
                         charges = months * STANDARD;
                         tax = charges * TAX_RATE;
                         totalFee = charges + tax;
                         
                         // Output Section
                         logo();
                         cout << "\t\t\t Standard Membership Summery\n"
                              << "\t\t\t ---------------------------\n"
                              << "\t\t\t Months : " << setw (12) << months << "\n"
                              << "\t\t\t Monthly Fee : $" << setw (9) << STANDARD << "\n"
                              << "\t\t\t Charges :     $" << setw (9) << charges << "\n"
                              << "\t\t\t Tax :         $" << setw (9) << tax << "\n"
                              << "\t\t\t Total :       $" << setw (9) << totalFee
                              << "\n\n\n\n\n\n\n\n";
                         
                         system("PAUSE");     
                         system("CLS");
                    }
                    else
                    {
                         logo();
                         cout << "\n\t\t\t   " << months << " is not a valid entry.\n"
                              << "\t\t\t   Please enter a valid number."
                              << "\n\n\n\n\n\n\n\n\n\n\n";
                         
                         system("PAUSE");
                    }
             }
             else if (choice == 'b' || choice == 'B')
             {
                    cout << "\n\t\t\t  How many months?  > ";
                    cin  >> months;
                    
                    system("CLS");
                    
                    if (months > 0)
                    {
                         // Processing Section
                         charges = months * STUDENT;
                         tax = charges * TAX_RATE;
                         totalFee = charges + tax;
                         
                         // Output Section
                         logo();
                         cout << "\t\t\t Standard Membership Summery\n"
                              << "\t\t\t ---------------------------\n"
                              << "\t\t\t Months : " << setw (12) << months << "\n"
                              << "\t\t\t Monthly Fee : $" << setw (9) << STUDENT << "\n"
                              << "\t\t\t Charges :     $" << setw (9) << charges << "\n"
                              << "\t\t\t Tax :         $" << setw (9) << tax << "\n"
                              << "\t\t\t Total :       $" << setw (9) <<totalFee
                              << "\n\n\n\n\n\n\n\n";
                        
                         system("PAUSE");
                    }
                    else
                    {
                         logo();
                         cout << "\n\t\t\t   " << months << " is not a valid entry.\n"
                              << "\t\t\t   Please enter a valid number."
                              << "\n\n\n\n\n\n\n\n\n\n\n\n";
                         
                         system("PAUSE");
                    }
             }
             else if (choice == 'c' || choice == 'C')
             {
                    cout << "\n\t\t\t  How many months?  > ";
                    cin  >> months;
                    
                    system("CLS");
                    
                    if (months > 0)
                    {                    
                         // Processing Section
                         charges = months * SENIOR;
                         tax = charges * TAX_RATE;
                         totalFee = charges + tax;
                         
                         // Output Section
                         logo();
                         cout << "\t\t\t Standard Membership Summery\n"
                              << "\t\t\t ---------------------------\n"
                              << "\t\t\t Months : " << setw (12) <<months << "\n"
                              << "\t\t\t Monthly Fee : $" << setw (9) <<SENIOR << "\n"
                              << "\t\t\t Charges :     $" << setw (9) << charges << "\n"
                              << "\t\t\t Tax :         $" << setw (9) << tax << "\n"
                              << "\t\t\t Total :       $" << setw (9) <<totalFee
                              << "\n\n\n\n\n\n\n\n";
                         
                         system("PAUSE");
                    }
                    else
                    {
                         logo();
                         cout << "\n\t\t\t   " << months << " is not a valid entry.\n"
                              << "\t\t\t   Please enter a valid number."
                              << "\n\n\n\n\n\n\n\n\n\n\n\n";
                         
                         system("PAUSE");
                    }
             }
             else if (choice == 'd' || choice == 'D')
             {
                    system("CLS");
                    
                    logo();
                    cout << "\t\t\t\tHave a nice day!"
                         << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

             }
             else
             {
                    system("CLS");
                    
                    logo();
                    cout << "\n\t\t\t   " << choice << " is NOT a valid entry.\n"
                         << "\t\t\t   Please make avalid entry."
                         << "\n\n\n\n\n\n\n\n\n\n\n\n";
                    
                    system("PAUSE");
             }
         } while (choice != 'd' && choice != 'D');
         
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
    cout << " \n\n"
         << "\t\t                     ;~\n"
         << "\t\t                   ./|\\.\n"
         << "\t\t                 ./ /| `\\.\n"
         << "\t\t                /  | |   `\\.\n"
         << "\t\t               |   | |     `\\.\n"
         << "\t\t               |    \\|       `\\.\n"
         << "\t\t             .  `----|__________\\.\n"
         << "\t\t              \\-----''----.....___\n"
         << "\t\t               \\               \"\"/\n"
         << "\t\t          ~^~^~^~^~^`~^~^`^~^~^`^~^~^\n"
         << "\t\t           ~^~^~`~~^~^`~^~^~`~~^~^~\n"
         << "\t\t  ____   __   __  __    __  __ _   ___    __  ____ \n"
         << "\t\t / ___) / _\\ (  )(  )  (  )(  ( \\ / __)  (  )/ ___)\n"
         << "\t\t \\___ \\/    \\ )( / (_/\\ )( /    /( (_ \\   )( \\___ \\\n"
         << "\t\t (____/\\_/\\_/(__)\\____/(__)\\_)__) \\___/  (__)(____/\n\n"
         << "\t\t\t      ____  _  _  __ _  _\n"
         << "\t\t\t     (  __)/ )( \\(  ( \\/ \\\n"
         << "\t\t\t      ) _) ) \\/ (/    /\\_/\n"
         << "\t\t\t     (__)  \\____/\\_)__)(_)\n"
         << " \n\n\n";
    system("PAUSE");
}
void logo()
{
     cout << "\n\n"
         << "\t    _  _  __    _  _  ____  ____  _  _     ___  _  _  __  __ \n"
         << "\t   ( \\/ )/__\\  ( \\( )(_  _)(_  _)( \\/ )   / __)( \\/ )(  \\/  )\n"
         << "\t    \\  //(__)\\  )  (  _)(_   )(   \\  /   ( (_-. \\  /  )    ( \n"
         << "\t     \\/(__)(__)(_)\\_)(____) (__)  (__)    \\___/ (__) (_/\\/\\_)\n\n\n\n";
}
