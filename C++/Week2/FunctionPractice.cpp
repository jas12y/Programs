// This program demonstrates many of the characteristics of
// a good function-driven program.
// The program determines the average number of days missed
// by employees at a company.
// Notice the syntax and the input validation.

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
int getNumEmps(void);         
int getDaysMissed(int);       
double avgDaysMissed(int, int);  

int main()
{
   int    employees,   // The number of employees
          daysAbsent;  // Total days absent of all employees
   double daysPerEmp;  // Average days absent per employee

   // Get the number of employees.
   employees = getNumEmps();
   
   // Get the number of days absent for each employee.
   daysAbsent = getDaysMissed(employees);
   
   // Get the average number of days missed per employee.
   daysPerEmp = avgDaysMissed(employees, daysAbsent);

   // Display the results.
   cout << fixed << showpoint << setprecision(1);
   cout << "\nThe average number of days missed per ";
   cout << "employee is " << daysPerEmp << endl;

   return 0;

}  // End of main function.

//*******************************************************************
// Function getNumEmps. This function asks the user to enter        *
// the number of employees in the company. Validation is performed  *
// to verify at least one employee, the value entered is            *
// then returned to function main.                                  *
//*******************************************************************

int getNumEmps()
{
   int emps;

   // Get the number of employees.
   cout << "How many employees does the company have? ";
   cin  >> emps;

   // Validate the input.
   while (emps < 1)
   {  cout << "The number of employees must be one or greater. "
           << "Please re-enter: ";
      cin  >> emps;
   }
   return emps;

}  // End of function getNumEmps

//*******************************************************************
// Function daysMissed. Accepts as an argument the number of        *
// employees in the company. User is asked to enter the             *
// number of days missed by each employee. Validation performed to  *
// confirm negative number is not entered. The total days missed    *
// by all employees is returned.                                    *
//*******************************************************************

int getDaysMissed(int numEmps)
{
   int days,            // The days missed by a given employee
       totalMissed = 0; // Accumulator for total days missed   

   for (int emp = 1; emp <= numEmps; emp++)  
   {  
      // Get number of days missed...
      cout << "Days missed by employee #" 
		     << setw(2) << emp << ": ";
      cin  >> days;
      
      // Validat the input...
      while (days < 0)
      {  cout << "Days missed must be zero or greater. "
              << "Please re-enter: ";
         cin  >> days;
      }
      
      // Accumulate the number of days missed.
      totalMissed += days; 
   }

   // Return the total days missed.
   return totalMissed;

}  // End of function getDaysMissed

//*******************************************************************
// Function aveDaysMissed. This function accepts the number of      *
// employees and the total number of days missed by all employees   *
// as arguments. The average number of days missed is calculated    *
// and returned.                                                    *
//*******************************************************************
 
double avgDaysMissed(int emps, int days)
{
   return static_cast<double>(days) / emps;

}  // End of function avgDaysMissed

