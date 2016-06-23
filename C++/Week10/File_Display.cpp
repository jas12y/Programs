//  Chapter 11, Programming Challenge 2
//  File Display Program
#include <iostream>
#include <fstream>
using namespace std;

// Constant for array size
const int SIZE = 81;

int main()
{
   ifstream file;         // File stream object
   char name[SIZE];       // To hold the file name
   char inputLine[SIZE];  // To hold a line of input
   int lines = 0;         // Line counter

   // Get the file name.
   cout << "Enter the file name: ";
   cin.getline(name, SIZE);
   
   // Open the file.
   file.open(name);
   
   // Test for errors.
   if (!file)
   {
      // There was an error so display an error
      // message and end the program.
      cout << "Error opening " << name << endl;
      exit(EXIT_FAILURE);
   }
   
   // Read the contents of the file and display
   // each line.
   while (!file.eof())
   {
      // Get a line from the file.
      file.getline(inputLine, SIZE, '\n');
      
      // Display the line.
      cout << inputLine << endl;
      
      // Update the line counter.
      lines++;
      
      // If we just displayed the 24th line, pause
      // the screen.
      if (lines == 24)
      {
         cout << "Press ENTER to continue...";
         cin.get();
         lines = 0;
      }
   }
   
   // Close the file.
   file.close();
   return 0;
}

