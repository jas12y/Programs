//  Chapter 12, Programming Challenge 9
//  File Encryption Filter
#include <iostream>
#include <fstream>
using namespace std;

// Constant for array size
const int SIZE = 81;

int main()
{
   ifstream inFile;      // Input file object
   ofstream outFile;     // Output file object
   char inName[SIZE];    // Input file name
   char outName[SIZE];   // Output file name
   char input;           // To hold a character of input

   // Get the input file name.
   cout << "Enter the input file name: ";
   cin.getline(inName, SIZE);
   
   // Open the input file.
   inFile.open(inName);

   // Test for errors.
   if (!inFile)
   {
      // There was an error so display an error
      // message and end the program.
      cout << "Error opening " << inFile << endl;
      exit(EXIT_FAILURE);
   }

   // Get the output file name.
   cout << "Enter the output file name: ";
   cin.getline(outName, SIZE);
   
   // Open the output file.
   outFile.open(outName);
   
   // Test for errors.
   if (!outFile)
   {
      // There was an error so display an error
      // message and end the program.
      cout << "Error opening " << outFile << endl;
      exit(EXIT_FAILURE);
   }
   
   // Read the contents of the input file, one
   // character at a time, encrypt it, and store
   // it in the output file.
   while (!inFile.eof())
   {
      // Get a character from inFile.
      inFile.get(input);
      
      // Encrypt the character by adding 10 to it.
      input += 10;
      
      // Write the character to outFile.
      outFile.put(input);
   }
   
   cout << "The file has been encrypted.\n";
   
   // Close both files.
   inFile.close();
   outFile.close();

   return 0;
}

