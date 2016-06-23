/*
Programmers Name: John Stubbs
      Assignment: Lab 4 Part 2
                  Date: 9/20/11

Description: Reads data from a file, displays the data
             and displays a message for the user.
*/
#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

// Global Variable Constants
#define myDate " September 20, 2011            "
#define myLab  " Lab 4 Part 2                  "
#define line1  "      This program will read data from a file        "
#define line2  "         and display it on the screen with a         "
#define line3  "                message for the user.                "

using namespace std;

// Function Prototypes
void splash();
void welcome();

int main(int argc, char *argv[])
{
    // Variables
    ifstream infile;
    string filename, title;
    int week1, week2;
    
    splash();
    welcome();
    system("CLS");

    // Input Section
    cout << "\n\n\n\n\n\n\n\n";
    cout << "\tWhat is the name of the file you wish to open? ";
         
    getline(cin,filename);
    
    system("CLS");
    
    infile.open(filename.c_str());
    
    if (infile)
    {
        getline(infile,title);
        infile >> week1 >> week2;
        infile.close();
        
        // Output Section
        cout << "\n\n\n\n\n\n";
        cout << "\t\t        Data Retrieved Successfully\n\n\n";
        cout << "\t\t\t         Movie title: " << title
             << "\n\t\t\tLast week attendance: " << week1
             << "\n\t\t\tThis week attendance: " << week2
             << "\n\n\n\n\t\t\t      Have a nice day!!"
             << "\n\n\n\n\n\n\n\n\n";
    }
    
    else
    {
        // Else Output
        system("CLS");
        cout << "\n\n\n\n\n\n\n\n\n"
             << "\t\t\tThe file " << filename << " doesn't exist.\n\n"
             << "\t\t\t  Please enter a valid file.\n"
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
    cout << " \n\n\n"
         <<  "\t\t             ,aaaaaaaaaaaaaaaa,\n"
         <<  "\t\t            dP\"    \"8,       `Y,\n"
         <<  "\t\t           d'       )Y,       `Yaa     \"Remember to recycle\n"
         <<  "\t\t          d'       ,P Y,        ,P          your code.\"\n"
         <<  "\t\t         d'       ,P   Ya      ,P\n"
         <<  "\t\t         `\"aa,   ,P    d'     ,P             - J. Stubbs\n"
         <<  "\t\t              \"baP     `\"\"\"\"\"\"    ,aa,\n"
         <<  "\t\t    Y\"\"\"\"\"\"\"Y,                  aP' `Y,\n"
         <<  "\t\t    ,P       Ya,             ,P\"'    `Y,\n"
         <<  "\t\t   ,P         `Y             `b       `Y,\n"
         <<  "\t\t  ,P        ,d\"'              `b       )P\n"
         <<  "\t\t   \"b      ,d'            ,a,  `b     ,d'\n"
         <<  "\t\t    \"b    ,daaaaaaaaa    ,P 8aaaabaaadP'\n"
         <<  "\t\t     \"b  ,8'        8   ,P           d'\n"
         <<  "\t\t      \"b,8'         8  ,P           d'\n"
         <<  "\t\t        \"8          8  `b          d'\n"
         <<  "\t\t         \"b,        8   `b        d'\n"
         <<  "\t\t          `\"\"\"\"\"\"\"\"\"\"    `b 8\"\"\"\"\"'\n"
         <<  "\t\t                           \"'\n"
         << " \n\n\n";
    system("PAUSE");
}
