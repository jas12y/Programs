/*
Programmers Name: John Stubbs
      Assignment: Homework #8
            Date: 2/28/12

Description:
            This program asks the user to input a password and then verifies
            that the password is at least 6 characters long and contains at
            least one uppercase letter, one lowercase letter, and one digit.
*/
#include <iostream>
#include <string>

using namespace std;

// Function prototypes
bool validate(char[], int);

int main()
{  
   const int SIZE = 13;
   char password[SIZE];
   char *pwdptr;
   int length,
       counter = 0;
   bool valid = false,
        login = false;
   
   while (!valid)
   {
      cout << "\n\n\n\n\n\n\n\n\n";
      cout << "\tNew passwords must be at least 6 characters long and contain at" << endl
           << "\tleast one uppercase letter, one lowercase letter, and one digit." << endl;
      cout << "\n\n\t\tPlease enter your new password: ";
      
      cin.getline(password, SIZE);
      
      length = strlen(password);
      
      valid = validate(password, length);
      
      if (valid)
         cout << "\n\n\n\t\t\t\tPassword Accepted!\n\n\n\n\n\n\n";
      else
         cout << "\n\n\n\t\t\tInvalid Password -- Try Again.\n\n\n\n\n\n\n";
      
      system("PAUSE");
      system("CLS");
   }
   
   pwdptr = new char[length+1];
   
   while (counter < 3 && !login)
   {
      cout << "\n\n\n\n\n\n\n\n\n\n";
      cout << "\t\t\tPlease login with your new password."
           << "\n\n\t\tPassword: ";
      
      cin.getline(pwdptr, length+1);
      
      if(strcmp(pwdptr, password) == 0)
      {   
         cout << "\n\n\n\t\t\t\tLogin Successful!\n\n\n\n\n\n\n\n";
         login = true;
      }
      else
      {   
         cout << "\n\n\n\t\t\tIncorrect Password -- Try Again.\n\n\n\n\n\n\n\n";
         
         counter++;
      }
      
      system("PAUSE");
      system("CLS");
   }
   
   delete [] pwdptr;
   
   if (login)
   {
      cout << "\n\n\n\n\n\n\n\n\n\n";
      cout << "\t\t\t\tHave a Nice Day!"
           << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
   }
   else
   {
      cout << "\n\n\n\n\n\n\n\n\n";
      cout << "\t\tYou have exceeded the maximum number of login attempts.\n"
           << "\t\tPlease try again later. System shutting down..."
           << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
   }
   system("PAUSE");
   return 0;
}
//Validates that the password entered meets all requirements
bool validate(char password[], int size)
{
   bool upper = false,
        lower = false,
        digit = false;

   for (int i=0; i < size; i++)
   {
      if (isupper(password[i]))
         upper = true;
      if (islower(password[i]))
         lower = true;
      if (isdigit(password[i]))
         digit = true;
   }
   
   if (upper && lower && digit)
      return true;
   else
      return false;
}
