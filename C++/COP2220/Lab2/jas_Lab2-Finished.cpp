/*
Programmers Name: John Stubbs
      Assignment: Lab 2-Finished
            Date: 9/7/11

Description: Displays a joke.
*/
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    // Variables
    string pet = "Simon", breed = "Shiba Inu", slacker = "Jane";
    char color[6] = "brown", size[7] = "medium", excuse[7] = "forgot";
    short age = 10;
    float cost = 97.84;             

    cout << "\n\n\n";
    cout << "\t /--------------------------------------------------------------\\ \n"
         << "\t |                      About This Program                      | \n"
         << "\t +--------------------------------------------------------------+ \n"
         << "\t |                                                              | \n"
         << "\t |                                                              | \n"
         << "\t |             Programmer's Name: John Stubbs                   | \n"
         << "\t |                          Date: 9/7/11                        | \n"
         << "\t |               Name of program: Lab 2-Finished                | \n"
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
