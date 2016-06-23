/*
Programmers Name: John Stubbs
      Assignment: Homework #12
            Date: 4/4/12

Description:
            This program declares a class, creates two class objects, and
            displays them.
*/
#include <iostream>
#include <iomanip>
using namespace std;

// Array sizes
const int NAME_SIZE = 36, ID_SIZE = 13, MAJOR_SIZE = 21;

// Student Class Declaration
class Student
{
private:
   char name[NAME_SIZE];     // Student's name
   char idNumber[ID_SIZE];   // ID number
   char major[MAJOR_SIZE];   // Major
   double gpa;               // Student's GPA

public:
   // Mutators
   void setName(char n[])
      { strcpy(name, n); }
      
   void setIdNumber(char i[])
      { strcpy(idNumber, i); }
      
   void setMajor(char m[])
      { strcpy(major, m); }
      
   void setGpa(double g)
      { gpa = g; }
      
   // Accessors
   char* getName()
      { return name; }
      
   char* getIdNumber()
      { return idNumber; }
      
   char* getMajor()
      { return major; }
      
   double getGpa()
      { return gpa; }
};

// Function prototype
void displayStudent(Student);

int main()
{
   // Create a Student objects
   Student wystan;
   wystan.setName("Wystan H. Auden");
   wystan.setIdNumber("POE89139");
   wystan.setMajor("English Literature");
   wystan.setGpa(3.8);
   
   Student edward;
   edward.setName("Edward Teach");
   edward.setIdNumber("PIR81709");
   edward.setMajor("Piracy");
   edward.setGpa(4.0);
   
   // Display each Student's info
   displayStudent(wystan);
   displayStudent(edward);
   
   system("PAUSE");
   
   return 0;
}
void displayStudent(Student s)
{
   cout << showpoint << setprecision(1) << fixed;
   cout << "Name: " << s.getName() << endl;
   cout << "ID Number: " << s.getIdNumber() << endl;
   cout << "Major: " << s.getMajor() << endl;
   cout << "GPA: " << s.getGpa() << endl << endl;
}
