/*
Programmers Name: John Stubbs
      Assignment: Homework #10
            Date: 3/21/12

Description:
            This program asks the user for input and output file names and
            changes all the letters to lowercase except the first letter of
            each sentence and writes the data to the output file. 
*/
#include <iostream>
#include <fstream>
using namespace std;

// Function Prototypes
void getInput(ifstream &);
void getOutput(ofstream &);
void convertData(ifstream &, ofstream &);

// Constant for array size
const int SIZE = 81;

int main()
{
   ifstream inFile;      // Input file object
   ofstream outFile;     // Output file object

   // Gets input file name, opens, and checks for errors
   getInput(inFile);

   // Gets output file name, opens, and checks for errors
   getOutput(outFile);
   
   // Changes all letters to lower case except the first one after a period
   // and saves the data to the output file
   convertData(inFile, outFile);
   
   // Close both files.
   inFile.close();
   outFile.close();
   
   system("PAUSE");

   return 0;
}
// Function Definitions
void getInput(ifstream &inFile)
{
   // Input file name
   char inName[SIZE];
   
   // Get the input file name
   cout << "Enter the input file name: ";
   cin.getline(inName, SIZE);
   
   // Open the input file
   inFile.open(inName);

   // Test for errors
   if (!inFile)
   {
      // Error message and exit the program
      cout << "Error opening file..." << endl;
      
      system("PAUSE");
      
      exit(EXIT_FAILURE);
   }
}
void getOutput(ofstream &outFile)
{
   // Output file name
   char outName[SIZE];
   
   // Get the output file name
   cout << "Enter the output file name: ";
   cin.getline(outName, SIZE);
   
   // Open the output file
   outFile.open(outName);
   
   // Test for errors
   if (!outFile)
   {
      // Error message and exit the program
      cout << "Error opening file..." << endl;
      
      system("PAUSE");
      
      exit(EXIT_FAILURE);
   }
}
void convertData(ifstream &inFile, ofstream &outFile)
{
   // To hold a character of data
   char data;
   // Test for first letter after period
   bool capLet = true;
   
   // Read the contents of the input file,
   // edit it, and store it in the output file
   while (!inFile.eof())
   {
      // Get a character from input file
      inFile.get(data);
      
      // Test to see if data is the first letter after a period
      if (isalpha(data) && capLet)
      {
         data = toupper(data);
         capLet = false;
      }

      else if (data == '.')
         capLet = true;
      
      // Convert data to lower case
      else
         data = tolower(data);
      
      // Write the character to output file
      outFile.put(data);
   }
   
   cout << "The file has been edited.\n";
}
