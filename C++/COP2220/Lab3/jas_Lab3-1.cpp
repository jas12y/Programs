/*
Programmers Name: John Stubbs
      Assignment: Lab 3
            Date: 9/13/11

Description: Displays a joke.
*/
#include <cstdlib>
#include <iostream>
#include <string>
// Global Variable Constants
#define myDate " September 13, 2011            "
#define myLab  " Lab 3 Part 1                  "
#define line1  "      This program will display a joke.              "
#define line2  "         Followed by the punchline.                  "
#define line3  " Then a short paragraph about why Jane is a slacker. "

using namespace std;

// Function Prototypes
void welcome();

int main(int argc, char *argv[])
{
    // Variables
    string pet = "Simon", breed = "Shiba Inu", slacker = "Jane";
    char color[6] = "brown", size[7] = "medium", excuse[7] = "forgot";
    short age = 10;
    float cost = 97.84;             

    welcome();
    
    // The joke setup
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "    \"What do you get when you roll a hand grenade across a "
         << "kitchen floor?\" ";
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
    
    system("PAUSE");
    
    // The punchline
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t    \"Linoleum Blownapart\" ";
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
 
    system("PAUSE");
    
    // Paragraph with variables
    cout << "\n\n\n\n\n\n\n\n\n\n";
    cout << "\t My dog " << pet << " is a " << breed << ". He's a " << size << " sized " << color << " dog.\n"
         << "\t " << pet << " is about " << age << " years old and it's gonna cost me $" << cost << "\n"
         << "\t to board him at the kennel when I go out of town because " << slacker << "\n"
         << "\t " << excuse << " she said she would dog sit.\n";
    cout << "\n\n\n\n\n\n\n\n\n\n";
    
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
