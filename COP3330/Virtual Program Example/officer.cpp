
#include "officer.h"
using namespace std;

// *********************************************************************
// *                                                                   *
// * Constructor                                                       *
// * Class Name:Officer                                                *
// *                                                                   *
// * Parameter Description: character arrays LN, FN, CT as rank        *
// *                                                                   *
// * Description:   Creates a basic officer record.  Determines if     *
// * based upon CT passed in.                                          *
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

Officer::Officer(char const*LN, char const *FN,  const char *CT)
  {
    LName=LN;
    FName=FN;
    if(CT[0]=='L')
      {
      Rank=LIEUTENANT;
      }
    else if(CT[0]=='C' && CT[1] == 'a')
      {
      Rank=CAPTAIN;
      }
      else if (CT[0]=='M' )
	{
	  Rank = MAJOR;
	}
   
    else Rank=COLONEL;
   
  }

// *********************************************************************
// *                                                                   *
// * Default Constructor  :                                            *
// * Class Name: Officer                                               *
// *                                                                   *
// *                                                                   *
// * Description:  Sets default date for the class Officer             *
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

Officer::Officer()
{
  LName=' ';
  FName=' ';
  Rank=LIEUTENANT; 
}

// *********************************************************************
// *                                                                   *
// * Member Name: getLName                                             *
// * Class Name:  Officer                                              *
// *                                                                   *
// * Parameter Description: None                                       *
// *                                                                   *
// * Description:  Returns Last Name                                   *
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

string  Officer::getLName() const
{
  return LName;
}

// *********************************************************************
// *                                                                   *
// * Member Name: getFname                                             *
// * Class Name:  Officer                                              *
// *                                                                   *
// * Parameter Description: None                                       *
// *                                                                   *
// * Description: Returns First Name of Officer                        *
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

string  Officer::getFName() const
{
  return FName;
}

// *********************************************************************
// *                                                                   *
// * Member Name: getRank                                              *
// * Class Name:  Officer                                              *
// *                                                                   *
// * Parameter Description: None                                       *
// *                                                                   *
// * Description: Returns a copy of the string Rank based upon         *
// *  the enumeration type.                                            *
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

string Officer::getRank() const
{ string RANKS [4]={"Lieutenant","Captain","Major","Colonel"}; 
  
  return RANKS[Rank]; 
/*
  static string OutCourse; 
  if(Rank==LIEUTENANT) 
    OutCourse = "Lieutenant";
  else if (Rank==CAPTAIN)
    OutCourse = "Captain";
  else if (Rank == MAJOR)
    OutCourse = "Major";
  else OutCourse = "Colonel";
  
 
  return OutCourse;
 */
		      
}


// *********************************************************************
// *                                                                   *
// * constructor                                                       *
// * Class Name:Lieutenant                                             *
// *                                                                   *
// * Parameter Description: character array LN, FN, CT (rank)          *
// *                                                                   *
// * Description: Sets the values for an object of type                *
// *   Lieutenant                                                      *
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

  
  

Lieutenant::Lieutenant(const char *LN, const char *FN, const char *CT):Officer(LN, FN, CT)
  {
    Pay = 600.00; 
}

// *********************************************************************
// *                                                                   *
// * Member Function: ComputerPay                                      *
// * Class Name: Lieutenant                                            *
// *                                                                   *
// * Parameter Description: None                                       *
// *                                                                   *
// * Description: Calculate the pay + all allowances and return the    *
// *              value.                                               *
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

double Lieutenant::ComputePay()
{

  return Pay+180.00 + 32.00;  
}
  

// *********************************************************************
// *                                                                   *
// * Member Name:  GetBasicPay                                         *
// * Class Name:   Lieutenant                                          *
// *                                                                   *
// * Parameter Description: None                                       *
// *                                                                   *
// * Description:   Returns the basic pay amount only.                 *
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

double Lieutenant::GetBasicPay()
{
  return Pay;
}


// *********************************************************************
// *                                                                   *
// * Constructor                                                       *
// * Class Name: Captain                                               *
// *                                                                   *
// * Parameter Description: Character array LN, FN, and CT             * 
// *                                                                   *
// * Description:    Creates an object of type Captain and sets        *
// *    the private values.                                            *
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

Captain::Captain(const char *LN, const char *FN, const char *CT):Officer(LN, FN, CT)
  {
    Pay = 800.00;
    FlightPay=100.00; 
}

// *********************************************************************
// *                                                                   *
// * Member Name: ComputerPay                                          *
// * Class Name: Captain                                               *
// *                                                                   *
// * Parameter Description: None                                       *
// *                                                                   *
// * Description:  Returns computation of pay for a Captain            *
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

double Captain::ComputePay()
{
 
  return Pay+220.00+FlightPay + 32.00 +10000.00;

}

// *********************************************************************
// *                                                                   *
// * Member Name: GetBasicPay                                          *
// * Class Name: Captain                                               *
// *                                                                   *
// * Parameter Description: None                                       *
// *                                                                   *
// * Description:  Returns the pay only.                               *
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
  

double Captain::GetBasicPay()
{
  return Pay;
}

// *********************************************************************
// *                                                                   *
// * Constructor                                                       *
// * Class Name: Major                                                 *
// *                                                                   *
// * Parameter Description: Character Array LN, FN, and Ct             *
// *                                                                   *
// *                                                                   *
// * Description:  Establishes the basic private items for the class   *
// *   Major.                                                          *
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



Major::Major(const char *LN, const char *FN, const char *CT):Officer(LN, FN, CT)
  {
    Pay = 900.00;
    FlightPay = 100.00;
    HazDuty = 50.00; 
}

// *********************************************************************
// *                                                                   *
// * Member Name: Major                                                *
// * Class Name:  ComputerPay                                          *
// *                                                                   *
// * Parameter Description: None                                       *
// *                                                                   *
// * Description:  Returns the full pay for the person of rank Major.  *
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

double Major::ComputePay()
{

  return Pay+225.00+ FlightPay + HazDuty + 32.00;  
}
  

// *********************************************************************
// *                                                                   *
// * Member Name: GetBasicPay                                          *
// * Class Name: Major                                                 *
// *                                                                   *
// * Parameter Description: None                                       *
// *                                                                   *
// * Description:   Returns the pay only.                              *
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

double Major::GetBasicPay()
{
  return Pay;
}


// *********************************************************************
// *                                                                   *
// * Constructor                                                       *
// * Class Name: Colonel                                               *
// *                                                                   *
// * Parameter Description: Character array LN, FN, and CT             *
// *                                                                   *
// * Description:   Sets the privite items for objects of type         *
// *  Colonel.                                                         *
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

Colonel::Colonel(const char *LN, const char *FN, const char *CT):Officer(LN, FN, CT)
  {
    Pay = 1000.00;
    FlightPay = 100.00;
    HazDuty = 25.00;
    OClubTab = 100.00; 
}

// *********************************************************************
// *                                                                   *
// * Member Name:ComputerPay                                           *
// * Class Name: Colonel                                               *
// *                                                                   *
// * Parameter Description: None                                       *
// *                                                                   *
// * Description:   Returns the total pay for a person of rank         *
// *  Colonel.                                                         *
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

double Colonel::ComputePay()
{

  return Pay+ FlightPay + HazDuty + OClubTab + 300.00 + 32.00;  
}
  

// *********************************************************************
// *                                                                   *
// * Member Name:  GetBasicPay                                         *
// * Class Name:  Colonel                                              *
// *                                                                   *
// * Parameter Description: None                                       *
// *                                                                   *
// * Description: Returns the basic pay for a person of rank Colonel   *
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

double Colonel::GetBasicPay()
{
  return Pay;
}
