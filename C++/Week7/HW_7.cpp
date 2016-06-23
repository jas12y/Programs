//  Homework Assignment #7
//  Your name
//  A brief description of what this program does.
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//Prototype of doSomething() function
//You may not change anything about doSomething function.
void doSomething(char *); 

int main()
{
  //you may initialize your sentence array within the code;
  char sentence[91];
  //You may put your answer to question #1 here.

  //while the character captured is not the character at the end of the array 
  while (sentence[i] != '\0') 
  { 
  /*
   1. show the code to extract 4 characters 
   2. call the function doSomething() with the 4 letters just extracted. 
      Follow the function prototype declared above.
  */
  }

  return 0;
} 

void doSomething(char *word)
{
  for(int i=0;i<4;i++)
    cout << *(word+i);

  cout << endl;
}