//  Homework Assignment #5
//  Exam Grader
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// Function prototypes
void readFile(char[], char[], int);
void compareAnswers(char[], char[], int, int &);
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
   compareAnswers(student, correct, NUM_QUESTIONS, numMissed);
   
   // Display the test results.
   displayTestResults(numMissed, NUM_QUESTIONS);
   
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
   while (count < size && inFile >> array[count])
   {
      // Increment the counter.
      count++;
   }
   
   // Close the file.
   inFile.close();
}

//********************************************************
// The compareAnswers function compares the elements of  *
// the student array with the elements of the correct    *
// array. For each correct answer, a 'C' is stored in    *
// the results array. For each incorrect answer, an 'I'  *
// is stored in the results array.                       *
//********************************************************

void compareAnswers(char student[], char correct[],
                    int size, int &numMissed)
{
 
}

//********************************************************
// displayTestResults displays the test statistics.      *
//********************************************************

void displayTestResults(int numMissed, int numQuestions)
{
   
}
