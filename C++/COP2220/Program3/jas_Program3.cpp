/*
Programmers Name: John Stubbs
      Assignment: Program 3   
                  Date: 10/16/11               

Description: Displays a menu for math practice questions 
             and displays a message for the correct and incorrect
             answers.

INPUTS:
       User selection
       Answer/Guess for math question
OUTPUTS:
        Random numbers(1-10) for math problem
        Correct answer for math problem
*/
#include <cstdlib>
#include <iostream>

// Global Variable Constants
#define myDate " October 16, 2011              "
#define myLab  " Program 3                     "
#define line1  "      This program will display a menu for a         "
#define line2  "      math practice problem and give a correct       "
#define line3  "      answer for the practice problem displayed.     "

using namespace std;

// Function Prototypes
void splash();
void welcome();

int main(int argc, char *argv[])
{
    // Variables
    char choice;
    short random1, random2;
    int guess, answer;
    unsigned seed = time(0);
    
    splash();
    welcome();
    
    srand(seed);

    do
    {
         system("CLS");
         
         // Generate random numbers
         random1 = 1 + rand() % 10;
         random2 = 1 + rand() % 10;
         
         // Input Section
         cout << "\n\n\n\n"
              << "\t\t\t\tMath Practice Menu\n"
              << "\t\t\t ------------------------------\n\n"
              << "\t\t\t  A. Addition\n"
              << "\t\t\t  B. Subtraction\n"
              << "\t\t\t  C. Multiplication\n"
              << "\t\t\t  D. Integer Divition\n"
              << "\t\t\t  E. Modulus\n"
              << "\t\t\t  F. Quit\n\n"
              << "\t\t\t  Enter your choice > ";
         cin  >> choice;
         
         system("CLS");
         
          if (choice == 'a' || choice == 'A')
          {
               // Processing Section
               answer = random1 + random2;
               
               cout << "\n\n\n\n\n\n\n\n\n\n"
                    << "\t\t\t\t" << random1 << " + " << random2 << " = \n\n"
                    << "\t\t\t    Enter your guess > ";
               cin  >> guess;
               
               if (guess == answer)
               {
                     cout << "\n\n\t\t\t    You are correct!!\n\n"
                          << "\t\t\t\t" << random1 << " + " << random2 << " = " << answer
                          << "\n\n\n\n\n\n";
               }
               else
               {
                     cout << "\n\n\t\t\t    WRONG! Try again.\n\n"
                          << "\t\t\t\t" << random1 << " + " << random2 << " = " << answer
                          << "\n\n\n\n\n\n";
               }
          }
          else if (choice == 'b' || choice == 'B')
          {
               // Processing Section
               answer = random1 - random2;
               
               cout << "\n\n\n\n\n\n\n\n\n\n"
                    << "\t\t\t\t" << random1 << " - " << random2 << " = \n\n"
                    << "\t\t\t    Enter your guess > ";
               cin  >> guess;
               
               if (guess == answer)
               {
                     cout << "\n\n\t\t\t    You are correct!!\n\n"
                          << "\t\t\t\t" << random1 << " - " << random2 << " = " << answer
                          << "\n\n\n\n\n\n";
               }
               else
               {
                     cout << "\n\n\t\t\t    WRONG! Try again.\n\n"
                          << "\t\t\t\t" << random1 << " - " << random2 << " = " << answer
                          << "\n\n\n\n\n\n";
               }
          }
          else if (choice == 'c' || choice == 'C')
          {
               // Processing Section
               answer = random1 * random2;
               
               cout << "\n\n\n\n\n\n\n\n\n\n"
                    << "\t\t\t\t" << random1 << " * " << random2 << " = \n\n"
                    << "\t\t\t    Enter your guess > ";
               cin  >> guess;
               
               if (guess == answer)
               {
                     cout << "\n\n\t\t\t    You are correct!!\n\n"
                          << "\t\t\t\t" << random1 << " * " << random2 << " = " << answer
                          << "\n\n\n\n\n\n";
               }
               else
               {
                     cout << "\n\n\t\t\t    WRONG! Try again.\n\n"
                          << "\t\t\t\t" << random1 << " * " << random2 << " = " << answer
                          << "\n\n\n\n\n\n";
               }
          }
          else if (choice == 'd' || choice == 'D')
          {
               // Processing Section
               answer = random1 / random2;
               
               cout << "\n\n\n\n\n\n\n\n\n\n"
                    << "\t\t\t\t" << random1 << " / " << random2 << " = \n\n"
                    << "\t\t\t    Enter your guess > ";
               cin  >> guess;
               
               if (guess == answer)
               {
                     cout << "\n\n\t\t\t    You are correct!!\n\n"
                          << "\t\t\t\t" << random1 << " / " << random2 << " = " << answer
                          << "\n\n\n\n\n\n";
               }
               else
               {
                     cout << "\n\n\t\t\t    WRONG! Try again.\n\n"
                          << "\t\t\t\t" << random1 << " / " << random2 << " = " << answer
                          << "\n\n\n\n\n\n";
               }
          }
          else if (choice == 'e' || choice == 'E')
          {
               // Processing Section
               answer = random1 % random2;
               
               cout << "\n\n\n\n\n\n\n\n\n\n"
                    << "\t\t\t\t" << random1 << " % " << random2 << " = \n\n"
                    << "\t\t\t    Enter your guess > ";
               cin  >> guess;
               
               if (guess == answer)
               {
                     cout << "\n\n\t\t\t    You are correct!!\n\n"
                          << "\t\t\t\t" << random1 << " % " << random2 << " = " << answer
                          << "\n\n\n\n\n\n";
               }
               else
               {
                     cout << "\n\n\t\t\t    WRONG! Try again.\n\n"
                          << "\t\t\t\t" << random1 << " % " << random2 << " = " << answer
                          << "\n\n\n\n\n\n";
               }
          }
          else if (choice == 'f' || choice == 'F')
          {
               cout << "\n\n\n\n\n\n\n\n\n\n"
                    << "\t\t\t\tHave a nice day!!\n"
                    << "\n\n\n\n\n\n\n\n\n\n\n\n";
          }
          else
          {
              cout << "\n\n\n\n\n\n\n\n\n"
                   << "\t\t\t    " << choice << " is NOT a valid choice.\n\n"
                   << "\t\t\t    Please try again."
                   << "\n\n\n\n\n\n\n\n\n\n\n\n";
          }
    system("PAUSE");
           
    } while (choice != 'f' && choice != 'F');
         
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
