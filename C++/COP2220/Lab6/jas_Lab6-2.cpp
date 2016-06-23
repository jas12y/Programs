/*
Programmers Name: John Stubbs
      Assignment: Lab 6 Part 2
                  Date: 10/2/11

Description: Asks the user to enter a date (mm-dd-yy)
             and checks the month and day.

INPUTS:
        date (mm-dd-yy)
OUTPUTS:
        weather the month is between 1 and 12
        weather the day is between 1 and 31
        
*/
#include <cstdlib>
#include <iostream>
#include <iomanip>

// Global Variable Constants
#define myDate " October 2, 2011               "
#define myLab  " Lab 6 Part 2                  "
#define line1  "      This program will ask you to enter a date      "
#define line2  "         and check that the month and day            "
#define line3  "               entered are both valid.               "

using namespace std;

// Function Prototypes
void splash();
void welcome();

int main(int argc, char *argv[])
{
    // Variables
    unsigned short mm, dd, yy;
    char sep1, sep2;
    
    splash();
    welcome();
    system("CLS");
    
    // Input Section
    cout << "\n\n\n\n\n\n\n\n\n"
         << "\t\tPlease enter a date (mm-dd-yy): ";
    cin  >> mm >> sep1 >> dd >> sep2 >> yy;
    system("CLS");
    
    // Output Section
    if (mm >= 1 && mm <= 12)
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n"
             << "\t\t\t    " << mm << " is a valid month.\n";

        if (dd >= 1 && dd <= 31)
        {
            cout << "\t\t\t    " << dd << " is a valid day.";
        }
        else
        {
            cout << "\t\t\t    " << dd << " is NOT a valid day.\n"
                 << "\t\t\tPlease enter a number between 1 and 31.";
        }
        
        cout << "\n\n\n\n\n\n\n\n\n\n\n";
    }
    else
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n"
             << "\t\t\t    " << mm << " is NOT a valid month."
             << "\n\t\t\tPlease enter a number between 1 and 12.";
        cout << "\n\n\n\n\n\n\n\n\n\n\n";
    }
             
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
