/*
Programmers Name: John Stubbs
      Assignment: Lab 5 Final 
                  Date: 9/27/11

Description: Generates a random number between 1 and 5
             and asks the user to guess the number
*/
#include <cstdlib>
#include <iostream>
#include <string>

// Global Variable Constants
#define myDate " September 27, 2011            "
#define myLab  " Lab 5 Final                   "
#define line1  "      This program will generate a random number     "
#define line2  "      between 1 and 5 and ask you to guess           "
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
    random = 1 + rand() % 5;
    
    // Input Section
    cout << "\n\n\n\n\n\n\n\n\n\n\n"
         << "\tCan you guess what number the computer is thinking? (1-5) > ";
    cin  >> guess;
    system ("CLS");
    
    // Output Section
    if (guess > 5)
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\n"
             << "\t\tI'm sorry...You guessed " << guess << ", and that's way too high!\n"
             << "\t\t       Please pick a number between 1 and 5.\n"
             << "\t\t\t               Try again."
             << "\n\n\n\n\n\n\n\n\n\n\n";
    }
    else if (guess < 1)
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\n"
             << "\t\tI'm sorry...You guessed " << guess << ", and that's way too low!\n"
             << "\t\t       Please pick a number between 1 and 5.\n"
             << "\t\t\t               Try again."
             << "\n\n\n\n\n\n\n\n\n\n\n";       
    }
    else if (guess > random)
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\n"
             << "\t\t\t I'm sorry...You guessed " << guess << ",\n"
             << "\t\t\t and the computer picked " << random << ".\n"
             << "\t\t\tYour guess was a little high.\n"
             << "\t\t\t  Better luck next time!"
             << "\n\n\n\n\n\n\n\n\n\n\n";
    }
    else if (guess < random)
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\n"
             << "\t\t\t I'm sorry...You guessed " << guess << ",\n"
             << "\t\t\t and the computer picked " << random << ".\n"
             << "\t\t\tYour guess was a little low.\n"
             << "\t\t\t  Better luck next time!"
             << "\n\n\n\n\n\n\n\n\n\n\n";
    }
    else
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\n"
             << "\t\t\t     You got it right!!\n"
             << "\t\t\tThe computer was thinking of " << random
             << "\n\n\n\n\n\n\n\n\n\n\n\n";   
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
