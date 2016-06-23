/*
Programmers Name: John Stubbs
      Assignment: Lab 5 Part 1
                  Date: 9/27/11

Description: Generates a random number between 1 and 10
             and asks the user to guess the number
*/
#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

// Global Variable Constants
#define myDate " September 27, 2011            "
#define myLab  " Lab 5 Part 1                  "
#define line1  "      This program will generate a random number     "
#define line2  "      between 1 and 10 and ask you to guess          "
#define line3  "      what number the computer has generated         "

using namespace std;

// Function Prototypes
void splash();
void welcome();

int main(int argc, char *argv[])
{
    // Variables
    int guess, random;
    unsigned seed = time(0);
    
    srand(seed);
    
    splash();
    welcome();
    system("CLS");

    // Generate a random number
    random = 1 + rand() % 10;
    
    // Input Section
    cout << "\n\n\n\n\n\n\n\n\n\n\n"
         << "\tCan you guess what number the computer is thinking? (1-10) > ";
    cin  >> guess;
    system ("CLS");
    
    // Output Section
    cout << "\n\n\n\n\n\n\n\n\n\n\n"
         << "\t\t              You guessed: " << guess << "\n"
         << "\t\tThe computer was thinking: " << random
         << "\n\n\n\n\n\n\n\n\n\n\n\n";
         
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
    cout << "\n\n\n\n"
         << "\t               ,'``.._   ,'``.\n"
         << "\t              :,--._:)\\,:,._,.:       \"All Glory to\n"
         << "\t              :`--,''   :`...';\\      the HYPNO TOAD!\"\n"
         << "\t               `,'       `---'  `.\n"
         << "\t               /                 :\n"
         << "\t              /                   \\\n"
         << "\t            ,'                     :\\.___,-.\n"
         << "\t           `...,---'``````-..._    |:       \\\n"
         << "\t             (                 )   ;:    )   \\  _,-.\n"
         << "\t              `.              (   //          `'    \\\n"
         << "\t               :               `.//  )      )     , ;\n"
         << "\t             ,-|`.            _,'/       )    ) ,' ,'\n"
         << "\t            (  :`.`-..____..=:.-':     .     _,' ,'\n"
         << "\t             `,'\\ ``--....-)='    `._,  \\  ,') _ '``._\n"
         << "\t          _.-/ _ `.       (_)      /     )' ; / \\ \\`-.'\n"
         << "\t         `--(   `-:`.     `' ___..'  _,-'   |/   `.)\n"
         << "\t             `-. `.`.``-----``--,  .'\n"
         << "\t               |/`.\\`'        ,','); \n"
         << "\t                   `         (/  (/\n";
    cout << "\n\n\n";     
    system("PAUSE");
}
