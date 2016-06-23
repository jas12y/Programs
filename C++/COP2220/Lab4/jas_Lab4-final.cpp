/*
Programmers Name: John Stubbs
      Assignment: Lab 4 Final
                  Date: 9/20/11

Description: Reads data from a file, calculates and displays the gross, net,
             and distributor pay based on the data in the file.

INPUT:
      filename, movie title, adult/child tickets sold

OUTPUT:
       Profit from tickets sold, gross/net profits, distributor pay

*/
#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

// Global Variable Constants
#define myDate " September 20, 2011            "
#define myLab  " Lab 4 Final                   "
#define line1  "      This program will read data from a file        "
#define line2  "        and use it to calculate and display          "
#define line3  "     gross and net profit with distributor pay.      "

const float BO_PROFIT = .2, A_PRICE = 10.50, C_PRICE = 6.75;

using namespace std;

// Function Prototypes
void splash();
void welcome();

int main(int argc, char *argv[])
{
    // Variables
    ifstream infile;
    string filename, title;
    int adultTicket, childTicket;
    float  adultTotal, childTotal, gross, net, distPay;
    
    cout << showpoint << setprecision(2) << fixed;
    
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
        infile >> adultTicket >> childTicket;
        infile.close();
        
        // Processing Section
        adultTotal = adultTicket * A_PRICE;
        childTotal = childTicket * C_PRICE;
        gross = adultTotal + childTotal;
        net = gross * BO_PROFIT;
        distPay = gross - net;
        
        // Output Section
        cout << "\n\n\n\n\n\n"
             << "\n\t            Movie Name: " << setw(25) << title
             << "\n\t----------------------------------------------------------"
             << "\n\t            Adult Tickets Sold: " << setw(17) << adultTicket
             << "\n\t            Child Tickets Sold: " << setw(17) << childTicket
             << "\n\t----------------------------------------------------------"
             << "\n\t       Gross Box Office Profit: " << setw(10) << "$" << setw(10) << gross
             << "\n\t         Net Box Office Profit: " << setw(10) << "$" << setw(10) << net
             << "\n\t    Amount Paid to Distributor: " << setw(10) << "$" << setw(10) << distPay
             << "\n\n\n\n\n\n\n\n\n\n\n\n";
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
