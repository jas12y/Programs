/*
Programmers Name: John Stubbs
      Assignment: Program 2
                  Date: 9/28/11

Description: Simulates a magic eight ball and answers a
             yes or no question with 1 of 20 responses.

INPUTS:
       A question from the user
OUTPUTS:
        One of twenty responses
*/
#include <cstdlib>
#include <iostream>
#include <string>

// Global Variable Constants
#define myDate " September 28, 2011            "
#define myLab  " Magic 8 Ball                  "
#define line1  "      This program simulates a magic eight ball      "
#define line2  "        and will answer all of your yes or no        "
#define line3  "        queries with one of twenty responses.        "

using namespace std;

// Function Prototypes
void splash();
void welcome();

int main(int argc, char *argv[])
{
    // Variables
    int random;
    string query;
    unsigned seed;
      
    splash();
    welcome();
    system("CLS");
    
    do
    {
        // Generate a random number
        seed = time(0);
        srand(seed);
        random = 1 + rand() % 20;
        
        // Input Section
        cout << "\n\n\n\n\n\n\n\n\n\n\n"
             << "\t\tWhat would you like to ask the Magic 8-Ball?\n"
             << "\t\t\t(Hit ctrl-c to quit)\n\n\t\t";
        getline (cin, query);
        system ("CLS");
        
        // Output Section
        cout << "\n\n\n\n\n"
             << "\t\t\tYou asked the Magic 8-Ball:\n\n\t\t\t"
             << "\"" << query << "\""
             << "\n\n\n\n\n\t\t\tThe Magic 8-Ball says:\n\n\t\t\t";
        if (random == 1)
        {
            cout << "\"It is certain\"";
        }
        else if (random == 2)
        {
            cout << "\"It is decidedly so\"";
        }
        else if (random == 3)
        {
            cout << "\"Without a doubt\"";
        }
        else if (random == 4)
        {
            cout << "\"Yes - definitely\"";
        }
        else if (random == 5)
        {
            cout << "\"You may rely on it\"";
        }
        else if (random == 6)
        {
            cout << "\"As I see it, yes\"";
        }
        else if (random == 7)
        {
            cout << "\"Most likely\"";
        }
        else if (random == 8)
        {
            cout << "\"Outlook good\"";
        }
        else if (random == 9)
        {
            cout << "\"Signs point to yes\"";
        }
        else if (random == 10)
        {
            cout << "\"Yes\"";
        }
        else if (random == 11)
        {
            cout << "\"Reply hazy, try again\"";
        }
        else if (random == 12)
        {
            cout << "\"Ask again later\"";
        }
        else if (random == 13)
        {
            cout << "\"Better not tell you now\"";
        }
        else if (random == 14)
        {
            cout << "\"Cannot predict now\"";
        }
        else if (random == 15)
        {
            cout << "\"Concentrate and ask again\"";
        }
        else if (random == 16)
        {
            cout << "\"Don't count on it\"";
        }
        else if (random == 17)
        {
            cout << "\"My reply is no\"";
        }
        else if (random == 18)
        {
            cout << "\"My sources say no\"";
        }
        else if (random == 19)
        {
            cout << "\"Outlook not so good\"";
        }
        else
        {
            cout << "\"Very doubtful\"";
        }

        cout << "\n\n\n\n\n\n\n\n\n\n";
        system("PAUSE");
        system("CLS");
    } while (random > 0);
    
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
    cout << "\t\t\t  /\\/\\   __ _  __ _(_) ___ \n"
         << "\t\t\t /    \\ / _` |/ _` | |/ __|\n"
         << "\t\t\t/ /\\/\\ \\ (_| | (_| | | (__ \n"
         << "\t\t\t\\/    \\/\\__,_|\\__, |_|\\___|\n"
         << "\t\t\t              |___/        \n"
         << "\t\t\t          _......._\n"
         << "\t\t\t       .-:::::::::::-.\n"
         << "\t\t\t     .:::::::::::::::::.\n"
         << "\t\t\t    :::::::' .-. `:::::::\n"
         << "\t\t\t   :::::::  :   :  :::::::\n"
         << "\t\t\t  ::::::::  :   :  ::::::::\n"
         << "\t\t\t  :::::::::._`-'_.:::::::::\n"
         << "\t\t\t  :::::::::' .-. `:::::::::\n"
         << "\t\t\t  ::::::::  :   :  ::::::::\n"
         << "\t\t\t   :::::::  :   :  :::::::\n"
         << "\t\t\t    :::::::._`-'_.:::::::\n"
         << "\t\t\t     `:::::::::::::::::'\n"
         << "\t\t\t       `-:::::::::::-'\n"
         << "\t\t\t          `'''''''`\n"
         << "\t\t\t        ___       _ _ \n"
         << "\t\t\t       / __\\ __ _| | |\n"
         << "\t\t\t      /__\\/// _` | | |\n"
         << "\t\t\t     / \\/  \\ (_| | | |\n"
         << "\t\t\t     \\_____/\\__,_|_|_|\n";

    system("PAUSE");
}
