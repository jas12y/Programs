/*
Programmers Name: John Stubbs
      Assignment: Homework #5
            Date: 2/9/12

Description:
            This program grades a students exam.
            
For 50 students, if I could assume the answers were going to be given in a single
file seperated by names, I would add a char/string array to hold the student's name
and change the student array to a two-dimensional array with 50 rows and NUM_QUESTION
columns, create a loop in the main to run through the process 50 times, and adjust the 
functions accordingly to read and display the names.
*/
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// Function prototypes
void readFile(char[], char[], int);
int compareAnswers(char[], char[], int);
void displayTestResults(int, int);

int main()
{
   // Constant for the number of questions
   const int NUM_QUESTIONS = 20;
      
   // Number of questions missed.
   int numMissed;
   
   // Array to hold the correct answers
   char correct[NUM_QUESTIONS];
   
   // Array to hold the student's answers
   char student[NUM_QUESTIONS];
   
   // Read the correct answers.
   readFile("CorrectAnswers.txt", correct, NUM_QUESTIONS);
   
   // Read the student's answers.
   readFile("StudentAnswers.txt", student, NUM_QUESTIONS);
   
   // Compare the student's answers with the correct
   // answers.
   numMissed = compareAnswers(student, correct, NUM_QUESTIONS);
   
   // Display the test results.
   displayTestResults(numMissed, NUM_QUESTIONS);
   
   system("PAUSE");
   
   return 0;
}

//********************************************************
// The readFile function reads the contents of           *
// an answer file into an array.                         *
//********************************************************

void readFile(char filename[], char array[], int size)
{
   // Loop counter
   int count = 0;
   
   // File stream object.
   ifstream inFile;
   
   // Open the file.
   inFile.open(filename);

   // Read the contents of the file into the array.
   while (count < size)
   {
      //Reads file data into array
      inFile >> array[count];
      
      // Increment the counter.
      count++;
   }   
   
   // Close the file.
   inFile.close();
}

//********************************************************
// The compareAnswers function compares the elements of  *
// the student array with the elements of the correct    *
// array. And display the wrong answers.                 *
//********************************************************

int compareAnswers(char student[], char correct[],
                    int size)
{
   int numMissed = 0;
   
   cout << "\t\tQuestions Missed" << "\tCorrect" << "\t\tStudent"
        << "\n\t\t-----------------------------------------------\n";
   
   for (int i = 0; i < size; i++)
   {
      if (student[i] != correct[i])
      {
         cout << "\t\t\t" << i + 1 << "\t\t   " << correct[i] << "\t\t   " << student[i] << endl;
         
         numMissed++;
      }
   }
   
   return numMissed;
}

//********************************************************
// displayTestResults displays the test statistics.      *
//********************************************************

void displayTestResults(int numMissed, int numQuestions)
{
   float average = ((float)numQuestions - numMissed)/numQuestions * 100;
   
   cout << showpoint << setprecision(1) << fixed;
   cout << "Wrong Answers: " << numMissed << "\nAverage: " << average << "%\t";
   
   if (average >= 70)
   
      cout << "\tPass\n";
   
   else
      
      cout << "\tFail\n";
}
