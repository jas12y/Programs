/*
Programmers Name: John Stubbs
      Assignment: Homework #6b
            Date: 2/16/12

Description:
            This program averages the number of movies seen by the number
            of students surveyed.
*/
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
int validate();
void getSurveyData(int *, int);
float getAverage(int *, int);
void showSummary(int, float);

int main()
{
   int *movies;          //To dynamically allocate an array
   int students;         //To hold the size of the array
   float average;        //To hold the average of movies seen
   
   cout << "\n\n\n\n\n\n";
   cout << "\t\tHow many students were surveyed? ";
   
   students = validate();                     //To validate user input is positive
   
   movies = new int[students];                //Dynamically allocates memory for new array
   
   getSurveyData(movies, students);           //Populates the array with the number of movies seen
   
   average = getAverage(movies, students);    //Calculates the average movies seen by each student
   
   showSummary(students, average);            //Displays average movies seen and number of students
   
   return 0;
}
//Validates entries as positve
int validate()
{
   int num;
   
   cin >> num;
   
   while (num < 0)
   {
      cout << "\n\t\t" << num << " is invalid. Please enter a positive number. ";
      cin >> num;
   }
   
   return num;
}
//Populates the array with the number of movies seen
void getSurveyData(int *arr, int size)
{
   for (int i = 0; i < size; i++)
   {
      system("CLS");
      
      cout << "\n\n\n\n\n\n";
      cout << "\t\tEnter the number of movies seen by student " << i + 1 << ": ";
      
      *(arr + i) = validate();
   }
}
//Calculates the average movies seen by each student
float getAverage(int *arr, int size)
{
   int total = 0;
   float average;
   
   for (int i = 0; i < size; i++)
      
      total += *(arr + i);
   
   average = static_cast<float>(total) / size;
   
   return average;
}
//Displays average movies seen and number of students
void showSummary(int size, float average)
{
   system("CLS");
   
   cout << showpoint << setprecision(2) << fixed;
   cout << "\n\n\n\n\n\n\n\n\n\n";
   cout << "\t\tThe average number of movies seen by\n"
        << "\t\tthe " << size << " students surveyed is " << average
        << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
   
   system("PAUSE");
}
