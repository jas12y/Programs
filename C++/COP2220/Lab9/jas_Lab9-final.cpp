/*
Programmers Name: John Stubbs
      Assignment: Lab 9 Final  
                  Date: 11/3/11                

Description: Displays a menu for a Health Club Membership
             and displays a summery for the values entered.

INPUTS:
       User selection
       Number of months
OUTPUTS:
       Months, Fee, Membership type, Subtotal, Tax, Total,
       Total months, Count of membership types, Average for membership types,
       Total Fees, Total Tax, Grand Total
*/
#include <cstdlib>
#include <iostream>
#include <iomanip>

// Global Variable Constants
#define myDate " November 3, 2011              "
#define myLab  " Lab 9 Final                   "
#define line1  "      This program will display a menu for a         "
#define line2  "      Health Club Membership and give a price        "
#define line3  "     summery for values entered, including tax.      "

using namespace std;

// Function Prototypes
void welcome();
void splash();
void logo();
void menu();
void summary(string, float);
void counter(int, int, int);
void goodbye();
void errorMsg(char);
void errorMsg(int);

// Global Constants
const float STANDARD = 40;
const float STUDENT = 35;
const float SENIOR = 25;
const float TAX_RATE = 0.075;

// Global Variables
int gMonths;
float gTotal, gFees, gTax;

int main(int argc, char *argv[])
{
     // Variables
     char choice;
     int standard, student, senior;
     
     standard = student = senior = 0;
     
     splash();
     welcome();

     do
     {
          system("CLS");
         
          // Input Section

          menu();
         
          cin  >> choice;
         
          if (toupper(choice) == 'A')
          {
              standard++;
              
              summary("Standard", STANDARD);
          }
          else if (toupper(choice) == 'B')
          {
              student++;
              
              summary("Student", STUDENT);
          }
          else if (toupper(choice) == 'C')
          {
              senior++;
              
              summary("Senior", SENIOR);
          }
          else if (toupper(choice) == 'D')
          {
              goodbye();
          }
          else
          {
              errorMsg(choice);
          }
     } while (toupper(choice) != 'D');
     
     counter(standard, student, senior);
     
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
void logo()
{
     cout << "\n\n"
          << "\t    _  _  __    _  _  ____  ____  _  _     ___  _  _  __  __ \n"
          << "\t   ( \\/ )/__\\  ( \\( )(_  _)(_  _)( \\/ )   / __)( \\/ )(  \\/  )\n"
          << "\t    \\  //(__)\\  )  (  _)(_   )(   \\  /   ( (_-. \\  /  )    ( \n"
          << "\t     \\/(__)(__)(_)\\_)(____) (__)  (__)    \\___/ (__) (_/\\/\\_)\n\n\n\n";
}
void menu()
{
     logo();
     
     cout << "\t\t\t\tMembership Menu\n"
          << "\t\t\t ------------------------------\n\n"
          << "\t\t\t  A. Standard Membership\n"
          << "\t\t\t  B. Student Membership\n"
          << "\t\t\t  C. Senior Citizen Membership\n"
          << "\t\t\t  D. Quit the program\n\n"
          << "\t\t\t  Enter your choice > ";
}
void summary(string type, float rate)
{
     float charges, tax, totalFee;
     int months;
     
     cout << showpoint << setprecision(2) << fixed;
     
     cout << "\n\t\t\t  How many months?  > ";
     cin  >> months;
    
     system("CLS");
    
     if (months > 0)
     {
          //Processing Section
          charges = months * rate;
          tax = charges * TAX_RATE;
          totalFee = charges + tax;
          
          gMonths += months;
          gFees += charges;
          gTax += tax;
          gTotal += totalFee;
          
          logo();
          
          //Output Section                    
          cout << "\t\t\t " << type << " Membership Summery\n"
               << "\t\t\t ---------------------------\n"
               << "\t\t\t Months : " << setw (12) << months << "\n"
               << "\t\t\t Monthly Fee : $" << setw (9) << rate << "\n"
               << "\t\t\t Charges :     $" << setw (9) << charges << "\n"
               << "\t\t\t Tax :         $" << setw (9) << tax << "\n"
               << "\t\t\t Total :       $" << setw (9) << totalFee
               << "\n\n\n\n\n\n\n\n";
                         
          system("PAUSE");     
     }
     else
     {
          errorMsg(months);
     }
     
}
void counter(int standard, int student, int senior)
{
     int typeTotal = standard + student + senior;
     
     system("CLS");
     
     logo();
     
     cout << setprecision(0) << fixed << noshowpoint;
     cout << "\t\t\tTotal months for all memberships : " << gMonths
          << "\n\t\t       ========================================"
          << "\n\n\t\t\tStandard\tStudent\t\tSenior"
          << "\n\t\t       ----------------------------------------\n"
          << "\tMembrships \t" << setw(4) << standard 
          << " \t\t" << setw(4) << student 
          << " \t\t" << setw(4) << senior
          << "\n\tAverage \t" << setw(4) << (float)standard/typeTotal*100 << "%"
          << "\t\t" << setw(4) << (float)student/typeTotal*100 << "%"
          << "\t\t" << setw(4) << (float)senior/typeTotal*100 << "%"
          << "\n\t\t       ========================================\n";
     cout << showpoint << setprecision(2) << fixed;
     cout << "\t\t\t  Total Fees Collected  : $" << setw(9) << gFees << "\n"
          << "\t\t\t  Total Tax Collected   : $" << setw(9) << gTax << "\n"
          << "\t\t\t  Grand Total Collected : $" << setw(9) << gTotal << "\n"
          << "\n\n\n\n";
     
     system("PAUSE");
}
void goodbye()
{
     system("CLS");
     
     logo();
     
     cout << "\t\t\t\tHave a nice day!"
          << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
     
     system("PAUSE");
}
void errorMsg(char option)
{
     system("CLS");
     
     logo();
     
     cout << "\n\t\t\t   " << option << " is NOT a valid entry.\n"
          << "\t\t\t   Please make avalid entry."
          << "\n\n\n\n\n\n\n\n\n\n\n\n";
          
          system("PAUSE");
}
void errorMsg(int months)
{
     logo();
     
     cout << "\n\t\t\t   " << months << " is not a valid entry.\n"
          << "\t\t\t   Please enter a valid number."
          << "\n\n\n\n\n\n\n\n\n\n\n\n";
          
     system("PAUSE");
}
