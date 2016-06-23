/*
Programmers Name: John Stubbs
      Assignment: #7
            Date: 4/19/13

This program asks the user to input a string and uses a stack
to determine whether the string is a palindrome or not.
*/
#include <iostream>
#include <cstring>
#include <cctype>
#include "stack.h"

using namespace std;
//Constant string max size
const int MAXCHAR = 101;

int main(void)
{
    char inLine[MAXCHAR];
    int index = 0, counter = 0;
    char temp1[MAXCHAR], temp2[MAXCHAR];
    Stack<char> myStack;
    
    cout << "Please enter a string: ";
    cin.getline(inLine, MAXCHAR);
    
    do
    {
        while(inLine[index] != '\0' && index < MAXCHAR)
        {
            if(isalpha(inLine[index]))
            {
                temp1[counter++] = tolower(inLine[index]);
                myStack.push(tolower(inLine[index++]));
            }
            else
                index++;
        }
        
        temp1[counter] = '\0';
        
        if(myStack.isStackEmpty())
        {
            index = counter = 0;
            cout << "Invalid string, please use at least one letter." << endl;
            cout << "Please enter a string: ";
            cin.getline(inLine, MAXCHAR);
            
            if(isalpha(inLine[index]))
            {
                temp1[counter++] = tolower(inLine[index]);
                myStack.push(tolower(inLine[index++]));
            }
            else
                index++;
        }
        
    } while(myStack.isStackEmpty());
        
    while(!myStack.isStackEmpty())
    {
        for(int i = 0; i < counter; i++)
        {
            myStack.pop(temp2[i]);
        }
    temp2[counter] = '\0';
    }
    
    if(!strcmp(temp1, temp2))
        cout << "\n\"" << inLine << "\"" << " IS a palindrome" << endl;
    else
        cout << "\n\"" << inLine << "\"" << " is NOT a palindrome" << endl;
    cout << endl;
    
    return 0;
}
