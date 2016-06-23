/*
Programmers Name: John Stubbs
      Assignment: Homework #11b
            Date: 3/29/12

Description:
            This program uses a structure variable to read a record from a file.
*/
#include <iostream>
#include <fstream>
using namespace std;

const int NAME_SIZE = 51, NUM_SIZE = 8;

// Declare a structure for the record.
struct Data
{
   char name[NAME_SIZE];
   char courseNum[NUM_SIZE];
   int  hours;
};
// Function prototypes
void menu();
void displayRecords(fstream &);
void editRecords(fstream &);
int validateHours();
long byteNum(int);
void errorMsg(char);
void goodBye();

int main()
{
   char choice;
   fstream course;  // File stream object

   // Open the file for input/output in binary mode.
   course.open("courseData.dat", ios::in | ios::out | ios::binary);

   // Test for errors.
   if (!course)
   {
      cout << "Error opening file. Program aborting.\n";
      return 0;
   }
   
   do
   {
      menu();
      
      cin >> choice;
      
      if (toupper(choice) == 'A')
         
         displayRecords(course);
      
      else if (toupper(choice) == 'B')

         editRecords(course);

      else if (toupper(choice) == 'C')
      
         goodBye();
      
      else
      
         errorMsg(choice);
      
   } while (toupper(choice) != 'C');
   
   course.close();
   return 0;
}
void menu()
{  
   system("CLS");
   
   cout << "\n\n\n\n\n\n\n\n"
        << "\t\t\t--------------------------------\n"
        << "\t\t\tA. Display all records\n"
        << "\t\t\tB. Edit records\n"
        << "\t\t\tC. Exit\n"
        << "\t\t\t--------------------------------\n\n"
        << "\t\t\tEnter your selection > ";
   
}
void displayRecords(fstream &course)
{
   Data courseInfo; // To hold info about a course
   int count = 0;
   
   system("CLS");
   course.seekg(0L, ios::beg);
   
   // Read the first record from the file.
   course.read(reinterpret_cast<char *>(&courseInfo),sizeof(courseInfo));
   
   cout << "Record #\tName\t\t\tCourse Number\tCredit Hours\n"
        << "--------------------------------------------------------------------\n";
   // While not at the end of the file, display
   // the records.
   while (!course.eof())
   {
      // Display the record.
      cout << "   " << count + 1 << "\t\t" << courseInfo.name << "\t\t   " 
           << courseInfo.courseNum << "\t\t" << courseInfo.hours << "\n\n";
      
      // Read the next record from the file.
      course.read(reinterpret_cast<char *>(&courseInfo),sizeof(courseInfo));
      
      count++;
   }
   course.clear();
   system("PAUSE");
}
void editRecords(fstream &course)
{
   Data courseInfo; // To hold info about a course
   int record;
   int count = 0;
   
   system("CLS");
   course.seekg(0L, ios::beg);
   
   // Read the first record from the file.
   course.read(reinterpret_cast<char *>(&courseInfo),sizeof(courseInfo));
   
   cout << "Record #\tName\t\t\tCourse Number\tCredit Hours\n"
        << "--------------------------------------------------------------------\n";
   // While not at the end of the file, display
   // the records.
   while (!course.eof())
   {
      // Display the record.
      cout << "   " << count + 1 << "\t\t" << courseInfo.name << "\t\t   " 
           << courseInfo.courseNum << "\t\t" << courseInfo.hours << "\n\n";
      
      // Read the next record from the file.
      course.read(reinterpret_cast<char *>(&courseInfo),sizeof(courseInfo));
      
      count++;
   }
   course.clear();
   
   cout << "Enter the record number you would like to edit:\n\n";
   cin >> record;
   cin.ignore();
   course.seekg(byteNum(record-1), ios::beg);
   course.read(reinterpret_cast<char *>(&courseInfo),sizeof(courseInfo));
   cout << "Enter the following course data:\n";
   cout << "Name: ";
   cin.getline(courseInfo.name, NAME_SIZE);
   cout << "Course Number: ";
   cin.getline(courseInfo.courseNum, NUM_SIZE);
   cout << "Credit hours: ";
   courseInfo.hours = validateHours();
   
   course.seekp(byteNum(record-1), ios::beg);
   // Write the contents of the courseInfo structure to the file.
   course.write(reinterpret_cast<char *>(&courseInfo), sizeof(courseInfo));
      
}
void errorMsg(char option)
{
   cout << "\n\n"
        << "\n\t\t\t   " << option << " is NOT a valid entry.\n"
        << "\t\t\t   Please make a valid entry."
        << "\n\n\n\n";
          
   system("PAUSE");
}
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
long byteNum(int record)
{
   return sizeof(Data) * record;
}
void goodBye()
{
   cout << "\n\n"
        << "\n\t\t\tHave a nice day! Goodbye!"
        << "\n\n\n\n\n";
        
   system("PAUSE");
}
