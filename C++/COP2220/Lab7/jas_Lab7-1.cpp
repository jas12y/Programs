/*
Programmers Name: John Stubbs
      Assignment: Lab 7 Part 1
                  Date: 10/12/11

Description: Displays a menu for a Health Club Membership
             and asks the user to make a selection.

INPUTS:
       User selection from menu
OUTPUTS:
*/
#include <cstdlib>
#include <iostream>

// Global Variable Constants
#define myDate " October 12, 2011              "
#define myLab  " Lab 7 Part 1                  "
#define line1  "      This program will display a menu for a         "
#define line2  "              Health Club Membership                 "
#define line3  "                                                     "

using namespace std;

// Function Prototypes
void splash();
void welcome();

int main(int argc, char *argv[])
{
    // Variables
    char choice;
    
    splash();
    welcome();
    system("CLS");

    // Input Section
    cout << "\n\n"
         << "\t    _  _  __    _  _  ____  ____  _  _     ___  _  _  __  __ \n"
         << "\t   ( \\/ )/__\\  ( \\( )(_  _)(_  _)( \\/ )   / __)( \\/ )(  \\/  )\n"
         << "\t    \\  //(__)\\  )  (  _)(_   )(   \\  /   ( (_-. \\  /  )    ( \n"
         << "\t     \\/(__)(__)(_)\\_)(____) (__)  (__)    \\___/ (__) (_/\\/\\_)\n\n\n\n"
         << "\t\t\t\tMembership Menu\n"
         << "\t\t\t ------------------------------\n\n"
         << "\t\t\t  A. Standard Membership\n"
         << "\t\t\t  B. Student Membership\n"
         << "\t\t\t  C. Senior Citizen Membership\n"
         << "\t\t\t  D. Quit the program\n\n"
         << "\t\t\t  Enter your choice > ";
    cin  >> choice;
    // Processing Section
    
    // Output Section

         
    
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
