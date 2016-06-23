/*
Programmers Name: John Stubbs
      Assignment: Program 4   
                  Date: 11/8/11                

Description: Displays a menu for math practice questions 
             and displays a message for the correct and incorrect
             answers.

INPUTS:
       User selection
       Answer/Guess for math question
OUTPUTS:
        Random numbers(1-10) for math problem
        Correct answer for math problem
        Number of correct/wrong answers
        Average correct (%)
*/
#include <cstdlib>
#include <iostream>
#include <iomanip>

// Global Variable Constants
#define myDate " November 8, 2011              "
#define myLab  " Program 4                     "
#define line1  "      This program will display a menu for a         "
#define line2  "      math practice problem and give a correct       "
#define line3  "      answer for the practice problem displayed.     "

using namespace std;

// Function Prototypes
void splash();
void welcome();
void menu();
void problem(char);
void errorMsg(char);
void goodbye();
void average();

// Global Variables
int gCorrect, gWrong;

int main(int argc, char *argv[])
{
    // Variables
    char choice;
    
    splash();
    welcome();

    do
    {
         system("CLS");
         
         menu();
         
         cin  >> choice;
         
         system("CLS");
         
         if (toupper(choice) == 'A' || toupper(choice) == 'B' || toupper(choice) == 'C' || toupper(choice) == 'D' || toupper(choice) == 'E')
            
            problem(choice);
         
         else if (toupper(choice) == 'F')
            
            goodbye();
            
         else
         
            errorMsg(choice);
             
    } while (choice != 'f' && choice != 'F');
    
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
void menu()
{
     cout << "\n\n\n\n"
          << "\t\t\t\tMath Practice Menu\n"
          << "\t\t\t ------------------------------\n\n"
          << "\t\t\t  A. Addition\n"
          << "\t\t\t  B. Subtraction\n"
          << "\t\t\t  C. Multiplication\n"
          << "\t\t\t  D. Integer Division\n"
          << "\t\t\t  E. Modulus\n"
          << "\t\t\t  F. Quit\n\n"
          << "\t\t\t  Enter your choice > ";
}
void problem(char choice)
{
     short random1, random2;
     unsigned seed = time(0);
     srand(seed);
    
     // Generate random numbers
     random1 = 1 + rand() % 10;
     random2 = 1 + rand() % 10;
    
     char sign [5] = {'+', '-', '*', '/', '%'};
     int guess;
     int answer[5] = {random1 + random2, random1 - random2, random1 * random2, random1 / random2, random1 % random2};
     string type[5] = {"Addition", "Subtraction", "Multiplication", "Division", "Modulus"};
     
     cout << "\n\n\n\n\n\n";
     cout << "\t\t\t\t" << type[toupper(choice) - 65] << endl
          << "\t\t\t-----------------------------\n"
          << "\t\t\t\t      " << setw(3) << random1 << endl
          << "\t\t\t\t     " << sign[toupper(choice) - 65] << setw(3) << random2 << endl
          << "\t\t\t\t     -----\n"
          << "\t\t    Enter your guess >  ";
     cin  >> guess;
     
     system("CLS");
     
     if (guess == answer[toupper(choice) - 65])
     {
         gCorrect++;
         
         cout << "\n\n\n\n\n\n";
         cout << "\t\t\t\t" << type[toupper(choice) - 65] << endl
              << "\t\t\t-----------------------------\n"
              << "\t\t\t\t      " << setw(3) << random1 << endl
              << "\t\t\t\t     " << sign[toupper(choice) - 65] << setw(3) << random2 << endl
              << "\t\t\t\t     -----\n"
              << "\t\t    That's Correct!! >  " << guess
              << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
         
         system("PAUSE");
     }
     else
     {
         gWrong++;
         
         cout << "\n\n\n\n\n\n";
         cout << "\t\t\t\t" << type[toupper(choice) - 65] << endl
              << "\t\t\t-----------------------------\n"
              << "\t\t\t\t      " << setw(3) << random1 << endl
              << "\t\t\t\t     " << sign[toupper(choice) - 65] << setw(3) << random2 << endl
              << "\t\t\t\t     -----\n"
              << "\t\t     That's Wrong... >  " << guess
              << "\n\n\t\t\t" << random1 << " " << sign[toupper(choice) - 65] << " " << random2 << " = "
              << answer[toupper(choice) - 65]
              << "\n\n\n\n\n\n\n\n\n\n\n";
              
         system("PAUSE");
     }
}
void average()
{
     int total = gCorrect + gWrong;
     
     system("CLS");
     
     cout << setprecision(0) << fixed << noshowpoint;
     cout << "\n\n\n\n\n\n\n\n"
          << "\t\t\t   Correct\t\t Wrong\n"
          << "\t\t\t   -------\t\t-------\n"
          << "\t\t\t      " << gCorrect << "\t\t\t   " << gWrong
          << "\n\n\t\t\t   Average Correct : " << (float)gCorrect/total*100 << "%"
          << "\n\n\n\n\n\n\n\n\n\n\n\n";
}
void errorMsg(char option)
{
     cout << "\n\n\n\n\n\n\n\n\n\n"
          << "\n\t\t\t   " << option << " is NOT a valid entry.\n"
          << "\t\t\t   Please make avalid entry."
          << "\n\n\n\n\n\n\n\n\n\n\n\n";
          
          system("PAUSE");
}
void goodbye()
{
     system("CLS");
     
     if (gCorrect == 0 && gWrong == 0)
     {
         cout << "\n\n\n\n\n\n\n\n\n\n"
              << "\t\t\t     Have a nice day!!"
              << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
     }
     else
     {
         cout << "\n\n\n\n\n\n\n\n\n"
              << "\t\t\tCalculating your average...\n"
              << "\t\t\t\tPlease wait..."
              << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
         
         system("PAUSE");
         
         average();
     }
}
