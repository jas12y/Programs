/*
Programmers Name: John Stubbs
      Assignment: Lab 11 Part 1
                  Date: 11/15/11               

Description:

INPUTS:
        Number from user

OUTPUTS:
        Return value from function

*/
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

// Global Variable Constants
#define myDate " November 15, 2011             "
#define myLab  " Lab 11 Part 1                 "
#define line1  "      This program will ask the user for a           "
#define line2  "       number and display the number as a            "
#define line3  "         value returned from a function.             "

using namespace std;

// Function Prototypes
void splash();
void welcome();
int getNumber(string, int);

// Global Variables

int main(int argc, char *argv[])
{
    // Variables
    int number;
    
    splash();
    welcome();
    
    // Valid call statement
    cout << "\n\n\n\n\n\n\n\n\n\n\n"
         << "\t\t\tgetNumber() returned " << getNumber("age", 110)
         << "\n\n\n\n\n\n\n\n\n\n\n";
    
    system("PAUSE");
    
    // Invalid call statement
    getNumber("invalid 1", 99);
    
    cout << "\n\n\n\n\n\n\n\n\n\n\n"
         << "\t\t\tgetNumber() returned " << number
         << "\n\n\n\n\n\n\n\n\n\n\n";
    
    system("PAUSE");
    
    // Valid call statement
    number = getNumber("your favorite", 10);
    
    cout << "\n\n\n\n\n\n\n\n\n\n\n"
         << "\t\t\tgetNumber() returned " << number
         << "\n\n\n\n\n\n\n\n\n\n\n";
    
    system("PAUSE");
    
    // Invalid call statement
    getNumber("invalid 2", 99);
    
    cout << "\n\n\n\n\n\n\n\n\n\n\n"
         << "\t\t\tgetNumber() returned " << number
         << "\n\n\n\n\n\n\n\n\n\n\n";
    
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
}
int getNumber(string msg, int limit)
{
     int number;
     
     system("CLS");
     
     cout << "\n\n\n\n\n\n\n\n\n\n\n"
          << "\t\t\tEnter a number for " << msg << ": ";
     cin >> number;
     
     while (number > limit)
     {
           system("CLS");
           
           cout << "\n\n\n\n\n\n\n\n\n\n\n"
                << "\t\t\t" << number << " is invalid.\n"
                << "\t\t\tMust be " << limit << " or less\n"
                << "\t\t\tEnter a number for " << msg << ": ";
           cin >> number;
     }
     system("CLS");
     
     return number;
}
