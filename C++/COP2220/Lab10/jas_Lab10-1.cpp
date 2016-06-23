/*
Programmers Name: John Stubbs
      Assignment: Lab 10 Part 1
                  Date: 11/13/11

Description: This program asks the user to enter a number for the
             amount of times the user would like "Hello" to
             print to the screen.
INPUTS:
        Number of times to repeat the loop.
OUTPUTS:
        "Hello"
*/
#include <cstdlib>
#include <iostream>

// Global Variable Constants
#define myDate " November 13, 2011             "
#define myLab  " Lab 10 Part 1                 "
#define line1  "      This program will ask you to enter a           "
#define line2  "       number for the amount of times you            "
#define line3  "          would like to say \"Hello\".                 "

using namespace std;

// Function Prototypes
void splash();
void welcome();

int main(int argc, char *argv[])
{
    int limit;
    
    splash();
    welcome();
    
    cout << "\n\n\n\n\n\n\n\n\n\n\n"
         << "\t\t\tHow many time do you want to say hello? ";
    cin >> limit;
    
    system("CLS");
    
    while (limit < 1 || limit > 20)
    {
          cout << "\n\n\n\n\n\n\n\n\n\n"
               << "\t" << limit << " is not a valid number. Enter a number between 1 and 20: ";
          cin >> limit;
          
          system("CLS");
    }
    
    for (int i = 1; i <= limit; i++)
    {
          cout << "\n\t\t\tHello " << i;
    }
    
    cout << "\n\n\n\n\n";
    
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
     system("CLS");
}
