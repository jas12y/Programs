/*
Programmers Name: John Stubbs
      Assignment: Program 5   
                  Date: 11/22/11

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
#include <iomanip>

// Global Variable Constants
#define myDate " November 22, 2011             "
#define myLab  " Program 5                     "
#define line1  "      This program will ask you to enter a           "
#define line2  "       number for the amount of scores you           "
#define line3  "   would like to average and display a summary.      "

using namespace std;

// Function Prototypes
void splash();
void welcome();
int validate(int,int);
char getGrade(float);
void summary(int,int);

int main(int argc, char *argv[])
{
    int limit, score, average;
    char grade;
    int total = 0;
    
    splash();
    welcome();
    
    cout << "\n\n\n\n\n\n\n\n\n\n\n"
         << "\t\tHow many scores would you like to average?(1-4) ";
    
    limit = validate(1,4);            
    
    system("CLS");
    
    for (int i = 1; i <= limit; i++)
    {
          cout << "\n\n\n\n\n\n\n\n\n"
               << "\t\t\t\tEnter score " << i << ": ";
          
          score = validate(0,100);
          
          total += score;
          
          system("CLS");
    }
    
    summary(limit,total);
    
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
int validate(int lowLimit,int upLimit)
{
     int value;
     
     cin >> value;
     
     while (value < lowLimit || value > upLimit)
     {
           system("CLS");
           
           cout << "\n\n\n\n\n\n\n\n\n\n"
                << "\t" << value << " is not valid. Enter a number between " << lowLimit << " and " << upLimit << ": ";
           cin >> value;
     }
     
     return value;
}
void summary(int scores,int total)
{
     float average = (float)total / scores;
     char grade = getGrade(average);
     
     cout << showpoint << setprecision(2) << fixed;
     cout << "\n\n\n\n\n\n"
          << "\t\t\tSummary for scores entered\n"
          << "\t\t\t--------------------------\n"
          << "\t\t\tNumber of scores :  " << scores << endl
          << "\t\t\tTotal for scores :  " << total << endl
          << "\t\t\tAverage of scores:  " << average << "%\n"
          << "\t\t\tGrade            :  " << grade
          << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
}
char getGrade(float average)
{
     if (average < 60)
          
           return 'F';
    
     else if (average < 70)
    
           return 'D';
    
     else if (average < 80)
    
           return 'C';
    
     else if (average < 90)
    
           return 'B';
    
     else
    
           return 'A';
}
