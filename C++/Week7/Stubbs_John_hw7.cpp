/*
Programmers Name: John Stubbs
      Assignment: Homework #7
            Date: 2/23/12

Description:
            This program displays 4 alphabetic letters from a sentence at a time
            until there are no more or not enough letters to display 4.
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
using namespace std;

//Prototype of doSomething() function
//You may not change anything about doSomething function.
void doSomething(char *); 

int main()
{
  int counter = 0,
      i = 0;
  char arr[5];
  //you may initialize your sentence array within the code;
  char sentence[91] = "iPhone5 is on its way";
  // To enter your own sentence
  //cin.getline(sentence, 91);
  //You may put your answer to question #1 here.
  /* 
   The array's declared size is correct for a character array to hold 90 elements.
   The extra element is for the null terminator to indicate the end of the array.
  */
  //while the character captured is not the character at the end of the array 
  while (sentence[i] != '\0') 
  { 
   //1. show the code to extract 4 characters
   if (isalpha(sentence[i]))
   {
      arr[counter] = sentence[i];
      counter++;
   }
   if (counter == 4)
   {  
      doSomething(arr);
      counter = 0;
   }
   //2. call the function doSomething() with the 4 letters just extracted. 
   //   Follow the function prototype declared above.
   i++;
  }
  system("PAUSE");
  return 0;
} 

void doSomething(char *word)
{
  for(int i=0;i<4;i++)
    cout << *(word+i);

  cout << endl;
}
