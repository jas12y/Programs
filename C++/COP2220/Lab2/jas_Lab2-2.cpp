/*
Programmers Name: John Stubbs
      Assignment: Lab 2-2
            Date: 9/4/11

Description: Displays a joke.
*/
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "\n\n\n";
    cout << "\t /--------------------------------------------------------------\\ \n"
         << "\t |                      About This Program                      | \n"
         << "\t +--------------------------------------------------------------+ \n"
         << "\t |                                                              | \n"
         << "\t |                                                              | \n"
         << "\t |             Programmer's Name: John Stubbs                   | \n"
         << "\t |                          Date: 9/4/11                        | \n"
         << "\t |               Name of program: Lab 2-2                       | \n"
         << "\t |                                                              | \n"
         << "\t |    /-------------------- Description --------------------\\   | \n"
         << "\t |    |  This program tells a joke. I don't know many       |   | \n"
         << "\t |    |            good ones so here it goes.               |   | \n"
         << "\t |    \\-----------------------------------------------------/   | \n"
         << "\t |                                                              | \n"
         << "\t |                                                              | \n"
         << "\t |                                                              | \n"
         << "\t \\--------------------------------------------------------------/ \n";
    cout << "\n\n\n\n";
    system("PAUSE");
    
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
    return EXIT_SUCCESS;
}
