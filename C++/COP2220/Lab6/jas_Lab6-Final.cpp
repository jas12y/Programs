/*
Programmers Name: John Stubbs
      Assignment: Lab 6 Final 
                  Date: 10/2/11

Description: Asks the user to enter a date (mm-dd-yy)
             and checks the month, day and year.

INPUTS:
        date (mm-dd-yy)
OUTPUTS:
        magic year (yes or no)
*/
#include <cstdlib>
#include <iostream>
#include <iomanip>

// Global Variable Constants
#define myDate " October 2, 2011               "
#define myLab  " Lab 6 Final                   "
#define line1  "      This program will ask you to enter a date      "
#define line2  "         and check to see if it's a magic date.      "
#define line3  "                                                     "

using namespace std;

// Function Prototypes
void splash();
void welcome();

int main(int argc, char *argv[])
{
    // Variables
    int magic;
    unsigned short mm, dd, yy;
    char sep1, sep2;
    int monthDays[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    splash();
    welcome();
    system("CLS");
    
    // Input Section
    cout << "\n\n\n\n\n\n\n\n\n"
         << "\t\tPlease enter a date (mm-dd-yy): ";
    cin  >> mm >> sep1 >> dd >> sep2 >> yy;
    cout << "\n\t\tI will tell you if it is magic.";
    
    // Processing Section
    magic = mm * dd;

    system("CLS");
       
    // Output Section
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    
    if (mm >= 1 && mm <= 12)
    {
        if (dd >= 1 && dd <= monthDays[mm - 1])
        {
            if (yy > 0)
            {
                   if (yy == magic)
                   {
                          cout << "\t\t\t" << mm << "-" << dd << "-" << yy << " is a magic year.\n";
                   }
                   else
                   {
                          cout << "\t\t\t" << mm << "-" << dd << "-" << yy << " is valid but NOT magic.\n";
                   }
            }
            else
            {
                   cout << "\t\t\t    " << yy << " is NOT a valid year.\n"
                        << "\t\t\t Please enter a positive number for year.";
            }
        }
        else
        {
            cout << "\t\t\t    " << dd << " is NOT a valid day.\n"
                 << "\t\t\tPlease enter a number between 1 and " << monthDays [mm - 1] << ".";
        }
    }
    else
    {
        cout << "\t\t\t    " << mm << " is NOT a valid month."
             << "\n\t\t\tPlease enter a number between 1 and 12.";
    }
    
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";       
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
         << "\t        ,%&& %&& %\n"
         << "\t       ,%&%& %&%& %&\n"
         << "\t      %& %&% &%&% % &%               Gone fishin'\n"
         << "\t     % &%% %&% &% %&%&,\n"
         << "\t     &%&% %&%& %& &%& %\n"
         << "\t    %%& %&%& %&%&% %&%%&\n"
         << "\t    &%&% %&% % %& &% %%&\n"
         << "\t    && %&% %&%& %&% %&%'\n"
         << "\t     '%&% %&% %&&%&%%'%\n"
         << "\t      % %& %& %&% &%%\n"
         << "\t        `\\%%.'  /`%&'\n"
         << "\t          |    |            /`-._           _\\\\/\n"
         << "\t          |,   |_          /     `-._ ..--~`_\n"
         << "\t          |;   |_`\\_      /  ,\\\\.~`  `-._ -  ^\n"
         << "\t          |;:  |/^}__..-,@   .~`    ~    `o ~\n"
         << "\t          |;:  |(____.-'     '.   ~   -    `    ~\n"
         << "\t          |;:  |  \\ / `\\       //.  -    ^   ~\n"
         << "\t          |;:  |\\ /' /\\_\\_        ~. _ ~   -   //-\n"
         << "\t        \\\\/;:   \\'--' `---`           `\\\\//-\\\\///\n"
         << " \n\n\n";
    system("PAUSE");
}
