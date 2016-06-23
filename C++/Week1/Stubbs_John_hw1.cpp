/*
Programmers Name: John Stubbs
      Assignment: Homework #1
            Date: 1/10/12

This program averages 3 test scores. It repeats as
many times as the user wishes.
*/

#include <iostream>
using namespace std;

int validateScore();
char validateAgain();

int main()
{
   int score[3];       // Three scores
   double average;     // Average score
   char again;         // To hold Y or N input

   do
   {
      // Get three scores.
      cout << "\n\n\n\t\t    Enter 3 scores and I will average them\n\n";
      for (int i = 0; i <= 2; i++)
          {
          cout << "\n\t\t\t    Please enter score #" << i+1 << ": ";
          score[i] = validateScore();
          }
      
      // Calculate and display the average.
      average = (score[0] + score[1] + score[2]) / 3.0;
      cout << "\n\t\t\t    The average is " << average << ".\n";
      
      // Does the user want to average another set?
      cout << "\n\t\t    Do you want to average another set? (Y/N)"
           << "\n\tIf you enter any other letter, you will be asked to enter again. ";
      again = validateAgain();
      
   } while (again == 'Y' || again == 'y');
   return 0;
}
int validateScore()
{
     int value;
     
     cin >> value;
     
     while (value < 0 )
     {
           cout << "\n\t\t      I'm sorry. " << value << " is not a valid entry."
                << "\n\t\t\tPlease enter a positive number: ";
           cin >> value;
     }
     
     return value;
}
char validateAgain()
{
     char choice;
     
     cin >> choice;
     
     while (toupper(choice) != 'Y' && toupper(choice) != 'N')
     {
           cout << "\n\t\t\tI'm sorry. " << choice << " is not a valid choice."
                << "\n\t\t\t\tPlease try again."
                << "\n\n\t\t    Do you want to average another set? (Y/N) "
                << "\n\tIf you enter any other letter, you will be asked to enter again. ";
           cin >> choice;
     }
     
     system("CLS");
     
     return choice;
}
