/*
Programmers Name: John Stubbs
      Assignment: Lab 10 Final
                  Date: 11/13/11

Description: This program asks the user to enter a number for the
             amount of scores they would like to average and display
             a summary for the scores entered.
INPUTS:
        Number of scores to average
        Scores
OUTPUTS:
        Displays a summary of number of scores entered,
        average of scores, and a grade for the average.
*/
#include <cstdlib>
#include <iostream>

// Global Variable Constants
#define myDate " November 13, 2011             "
#define myLab  " Lab 10 Final                  "
#define line1  "      This program will ask you to enter a           "
#define line2  "       number for the amount of scores you           "
#define line3  "   would like to average and display a summary.      "

using namespace std;

// Function Prototypes
void splash();
void welcome();

int main(int argc, char *argv[])
{
    int limit, score, average;
    char grade;
    int total = 0;
    
    splash();
    welcome();
    
    cout << "\n\n\n\n\n\n\n\n\n\n\n"
         << "\t\tHow many scores would you like to average?(1-4) ";
    cin >> limit;
    
    system("CLS");
    
    while (limit < 1 || limit > 4)
    {
          cout << "\n\n\n\n\n\n\n\n\n\n"
               << "\t" << limit << " is not a valid number. Enter a number between 1 and 4: ";
          cin >> limit;
          
          system("CLS");
    }
    
    for (int i = 1; i <= limit; i++)
    {
          cout << "\n\n\n\n\n\n\n\n\n"
               << "\t\t\t\tEnter score " << i << ": ";
          cin >> score;
          
          while (score < 0 || score > 100)
          {
                system("CLS");
                
                cout << "\n\n\n\n\n\n\n\n\n\n\t"
                     << score << " is not valid. Enter a score from 0 to 100: ";
                cin >> score;
          }
          
          total += score;
          
          system("CLS");
    }
    
    average = total / limit;
    
    if (average < 60)
          
          grade = 'F';
    
    else if (average < 70)
    
          grade = 'D';
    
    else if (average < 80)
    
          grade = 'C';
    
    else if (average < 90)
    
          grade = 'B';
    
    else
    
          grade = 'A';
    
    cout << "\n\n\n\n\n\n"
         << "\t\t\tSummary for scores entered\n"
         << "\t\t\t--------------------------\n"
         << "\t\t\tNumber of scores :  " << limit << endl
         << "\t\t\tTotal for scores :  " << total << endl
         << "\t\t\tAverage of scores:  " << average << "%\n"
         << "\t\t\tGrade            :  " << grade
         << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
         
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
