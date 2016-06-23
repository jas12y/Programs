/*
Programmers Name: John Stubbs
      Assignment: Homework #11a
            Date: 3/29/12

Description:
            This program uses a structure variable to store a record to a file.
*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// Array sizes
const int NAME_SIZE = 51, NUM_SIZE = 8;

// Declare a structure for the record.
struct Data
{
   char name[NAME_SIZE];
   char courseNum[NUM_SIZE];
   int  hours;
};
// Function prototypes
int validateHours();

int main()
{
   Data courseInfo;   // To hold info about a course
   char again;        // To hold Y or N
   
   // Open a file for binary output.
   fstream course("courseData.dat", ios::out | ios::binary);

   do
   {
      cout << "Enter the following course data:\n";
      cout << "Name: ";
      cin.getline(courseInfo.name, NAME_SIZE);
      cout << "Course Number: ";
      cin.getline(courseInfo.courseNum, NUM_SIZE);
      cout << "Credit hours: ";
      courseInfo.hours = validateHours();
      // Write the contents of the courseInfo structure to the file.
      course.write(reinterpret_cast<char *>(&courseInfo), sizeof(courseInfo));

      // Find out whether the user wants to write another record.
      cout << "Do you want to enter another course? ";
      cin >> again;
      cin.ignore();  // Skip over the remaining newline.
   } while (again == 'Y' || again == 'y');
   
   // Close the file.
   course.close();
   return 0;
}
// Function Definitions
int validateHours()
{
   int hours;
   
   cin >> hours;
   
   while (hours < 1 || hours > 6)
   {
      cout << hours << " is invalid. Please enter a number between 1 and 6.\n";
      cout << "Credit hours: ";
      cin >> hours; 
   }
   
   return hours;
}
