/*
Programmers Name: John Stubbs
      Assignment: Lab 13 Part 2
                  Date: 12/1/11

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
#include <string>

// Global Variable Constants
#define myDate " December 1, 2011              "
#define myLab  " Lab 13 Part 2                 "
#define line1  "      This program will ask you to enter a           "
#define line2  "       number for the amount of scores you           "
#define line3  "   would like to average and display a summary.      "

using namespace std;

// Function Prototypes
void splash();
void welcome();
int validate(int,int);
char getGrade(float);
void summary(int,int,string[],int[]);

int main(int argc, char *argv[])
{
    const int SIZE = 4;
    int limit, scores[SIZE];
    string exams[] = {"Exam 1 ", "Midterm", "Exam 2 ", "Final  "};
    int total = 0;
    
    splash();
    welcome();
    
    cout << "\n\n\n\n\n\n\n\n\n\n\n"
         << "\t\tHow many scores would you like to average?(1-4) ";
    
    limit = validate(1,4);            
    
    system("CLS");
    
    for (int i = 0; i < limit; i++)
    {
          cout << "\n\n\n\n\n\n\n\n\n"
               << "\t\t\tEnter score for " << exams[i] << ": ";
          
          scores[i] = validate(0,100);
          
          total += scores[i];
          
          system("CLS");
    }
    
    summary(limit,total,exams,scores);
    
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
char getGrade(float average)
{
     char grade;
     
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

     return grade;
}
void summary(int limit,int total,string exams[],int scores[])
{
     float average = (float)total / limit;
     
     cout << showpoint << setprecision(2) << fixed;
     cout << "\n\n\n\n\n\n"
          << "\t\t\tSummary for scores entered\n"
          << "\t\t\t--------------------------\n"
          << "\t\t\tNumber of scores :  " << limit << endl;
          
          for (int i = 0; i < limit; i++)
    
               cout << "\t\t\tScore for " << exams[i] << ":  " << scores[i] << endl;
               
     cout << "\t\t\tTotal for scores :  " << total << endl
          << "\t\t\tAverage of scores:  " << average << "%\n"
          << "\t\t\tGrade            :  " << getGrade(average)
          << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
}
