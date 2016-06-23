#include <string>
#include <iostream>

using namespace std;

#ifndef OFFICER_H
#define OFFICER_H

enum RankType {LIEUTENANT, CAPTAIN, MAJOR, COLONEL};
// *********************************************************************
// *  Officer Class.  Contains the protected and public items for      *
// *  this class. This class is inherited by the classes  Colonel,     *
// *  Major, Captain, Lieutenant.                                      *
// *  Note: the two virtual functions ComputePay and GetPay...         *
// *********************************************************************
class Officer
{

public:
  Officer(const char *LN, const char *FN, const char *CT);
  Officer();
  virtual double ComputePay()=0;   // Indicates a pure virtual function
  virtual double GetBasicPay()=0;     // Indicates a pure virtual function 
  string getLName() const;
  string getFName() const;
  string getRank() const; 
  
protected:

  string LName;
  string FName;
  RankType Rank;
};  // End Class Officer;


// *********************************************************************
// * Class Lieutenant: Only has Pay.                                   *
// *********************************************************************
class Lieutenant: public Officer
{
public:
  Lieutenant(const char *LN, const char *FN, const char *CT);
  double ComputePay();      
  double GetBasicPay();    
  
private:

  double Pay;
}; // end class Lieutenant


// *********************************************************************
// * Class Captain: Has Pay and FlightPay.                             *
// *********************************************************************
class Captain: public Officer
{
public:
  Captain (const char *LN, const char *FN, const char *CT);
  double ComputePay();      
  double GetBasicPay();    
  
private:

  double Pay;
  double FlightPay; 
}; // end class Captain


// *********************************************************************
// * Class Major: Has Pay, FlightPay, and HazDuty                      *
// *********************************************************************
class Major:  public Officer
{
public:
  Major(const char *LN, const char *FN, const char *CT);
  double ComputePay(); 
  double GetBasicPay();
  
private:
  double Pay;
  double FlightPay;
  double HazDuty; 

}; // end class Major
// *********************************************************************
// * Class Colonel: Has Pay, FlightPay, HazDuty, and OClubTab          *
// *********************************************************************
class Colonel:  public Officer
{
public:
  Colonel(const char *LN, const char *FN, const char *CT);
  double ComputePay(); 
  double GetBasicPay();
  
private:
  double Pay;
  double FlightPay;
  double HazDuty;
  double OClubTab; 

}; // end class Major


#endif
