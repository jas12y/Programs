#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string> 
#include "officer.h"

using namespace std;

using std::string; 

void STRTOUPPER(char * S);
void GetData (char *LN, char *FN, char *Rank);
void AddRecord (Officer **OA, const char *LN, const char *FN, const char *Rank, const int index);
void PrintReport (Officer **OA, const int i);
// *********************************************************************
// * Main Routine                                                      *
// * A program designed to demonstrate a simple case of Virtual        *
// * functions.  Uses a class called Officer that has four             *
// * classes that inherit it: Lieutenant, Captain, Major, Colonel      *
// * The Virtual functions are ComputePay and GetPay.                  *
// * Author: Dr. David Gaitros                                         *
// * Date: June 28, 2008                                               *
// *********************************************************************

int main(void)

{
  char skipchar; 
  char Filename[21];
  char LastName[21];
  char FirstName[21];
  char RankDesc[21];
  int  NumberOfRecords,RecordCounter; 
  string InputLine;
 


  cout << "Enter the number of records you want to enter " << endl;
  cin >> NumberOfRecords; 
  // *********************************************************************
  // *                                                                   *
  // *  Allocate a list of pointers to class of Officer.                 *
  // *********************************************************************
  Officer **OfficerArray = new Officer * [NumberOfRecords+1];

  RecordCounter=0;
  for (int i=0; i<NumberOfRecords; i++)
    {
      GetData (LastName, FirstName, RankDesc);
      cout << LastName << ' ' << FirstName << ' '<< RankDesc << endl;
      AddRecord (OfficerArray, LastName, FirstName, RankDesc, i); 
    } 
  PrintReport (OfficerArray, NumberOfRecords);
  system("PAUSE");
  
}

// *********************************************************************
// *                                                                   *
// * Member Name: STRTOUPPER                                           *
// *                                                                   *
// *                                                                   *
// * Parameter Description: char * S                                   *
// *                                                                   *
// * Description:  Takes in a character S and if it is an alphabetic   *
// *   character it returns the upper case of it.                      *
// *                                                                   *
// * Date: 6/28/2008                                                   *
// * Programmer:  Dr.David Gaitros                                     *
// *                                                                   *
// * Disclaimer:  This code was written as part of the solution        *
// *              to programming problems assigned in Object Oriented  *
// *              Programming Course (COP 3330) as taught in the       *
// *              Computer Science Department at Florida State         *
// *              University.  The selling, sharing, distribution, or  *
// *              use of this code not authorized by the faculty of    *
// *              the Computer Science Department is explicitly        *
// *              forbidden and is considered a violation of the       *
// *              academic honor code.                                 *
// *********************************************************************
// *********************************************************************




void STRTOUPPER( char * S)

{
  int i=0;

  while (S[i] != '\0' && i < 21)
    {
      S[i] = toupper(S[i++]);
    }
}

// *********************************************************************
// *                                                                   *
// * Member Name: GetData                                              *
// *                                                                   *
// * Parameter Description: character arrays, LN,FN,Rank               *
// *                                                                   *
// * Description:  Ask the user to input Last Name, First Name, ,      *
// *    and rank of an individual.  Returns the values through         *
// *    the relative addressed parameters.                             *
// *                                                                   *
// * Date: 6/28/2008                                                   *
// * Programmer:  Dr.David Gaitros                                     *
// *                                                                   *
// * Disclaimer:  This code was written as part of the solution        *
// *              to programming problems assigned in Object Oriented  *
// *              Programming Course (COP 3330) as taught in the       *
// *              Computer Science Department at Florida State         *
// *              University.  The selling, sharing, distribution, or  *
// *              use of this code not authorized by the faculty of    *
// *              the Computer Science Department is explicitly        *
// *              forbidden and is considered a violation of the       *
// *              academic honor code.                                 *
// *********************************************************************
// *********************************************************************


void GetData (char *LN, char *FN, char *Rank)
{

  cout << "Enter the LastName with no spaces=> :" ;
  cin >> LN;
  cout << endl << "Enter the First Name with no spaces => :";
  cin >> FN;
  cout << endl << "Enter the Rank of the Person => :";
  cin >> Rank;
  cout << endl;
}

// *********************************************************************
// *                                                                   *
// * Function Name: AddRecord                                          *
// *                                                                   *
// * Parameter Description: Officer array OA,  character arrays,       *
// *      LN,FN,Rank, and record location int i                        *
// *                                                                   *
// * Description:  Very important function.  Looks at the rank and     *
// *  adds the appropriate sub-class to the structure.                 *
// *                                                                   *
// * Date: 6/28/2008                                                   *
// * Programmer:  Dr.David Gaitros                                     *
// *                                                                   *
// * Disclaimer:  This code was written as part of the solution        *
// *              to programming problems assigned in Object Oriented  *
// *              Programming Course (COP 3330) as taught in the       *
// *              Computer Science Department at Florida State         *
// *              University.  The selling, sharing, distribution, or  *
// *              use of this code not authorized by the faculty of    *
// *              the Computer Science Department is explicitly        *
// *              forbidden and is considered a violation of the       *
// *              academic honor code.                                 *
// *********************************************************************
// *********************************************************************

void AddRecord (Officer **OA, const char *LN, const char *FN, const char *Rank, const int i)
{
   if(Rank[0] == 'L') 
     OA[i] = new Lieutenant(LN,FN,Rank);
   else if(Rank[0]=='C' && Rank[1]=='a')
     OA[i] = new Captain(LN,FN,Rank);
   else if(Rank[0]=='M')
     OA[i] = new Major(LN,FN,Rank);
   else OA[i] = new Colonel(LN,FN,Rank);
}
// *********************************************************************
// *                                                                   *
// * Function Name:  PrintReport                                       *
// *                                                                   *
// * Parameter Description: Officer ** OA array of objects.            *
// *                                                                   *
// * Description: prints the information for all objects of type       *
// *   Officer.                                                        *
// *                                                                   *
// * Date: 1/1/2008                                                    *
// * Programmer:  Dr.David Gaitros                                     *
// *                                                                   *
// * Disclaimer:  This code was written as part of the solution        *
// *              to programming problems assigned in Object Oriented  *
// *              Programming Course (COP 3330) as taught in the       *
// *              Computer Science Department at Florida State         *
// *              University.  The selling, sharing, distribution, or  *
// *              use of this code not authorized by the faculty of    *
// *              the Computer Science Department is explicitly        *
// *              forbidden and is considered a violation of the       *
// *              academic honor code.                                 *
// *********************************************************************
// *********************************************************************

void PrintReport (Officer **OA, const int i)
{
  cout <<endl << endl << "Officer Reporting System " << endl;
  
  for (int j=0; j<i; j++)
    { cout << OA[j]->getLName() << ' ' << OA[j]->getFName() << "  Rank:  " << OA[j]->getRank() <<"Basic Pay: $"<<OA[j]->GetBasicPay()
	   <<" Total Pay:  $"<< OA[j]->ComputePay()<<endl;
    }
} 
  
