// ************************************************************
// ************************************************************
// *  Box Class:                                              *
// *                                                          *
// *  Description:  A class that provides the capability to   *
// *    draw a box of varying size to standard output.  The   *
// *    box will have a border and fill character and be      *
// *    restricted to certain sizes as specified by the       *
// *    constants MINIMUMSIZE and MAXIMUMSIZE.   Boxes        *
// *    of sizes 1 and 2 have no fill characters.             *
// *                                                          *
// * Date: Aug 1, 2011                                        *
// * Author: Dr. David A. Gaitros                             *
// ************************************************************
// ************************************************************
#include <iostream>
using namespace std; 

// ************************************************************
// * Constant Definitions.                                    *
// ************************************************************
  const char LOWERBOUND='!';
  const char UPPERBOUND='~';
  const int PADDINGSIZE=80;
  const int SIZE1=1;
  const int SIZE2=2;
  const int MINIMUMSIZE=1;
  const int MAXIMUMSIZE=39;
  const char DEFAULTBORDER='#';
  const char DEFAULTFILL='*';

class Box
{
  friend bool operator!=(const Box & B1, const Box &B2);
  friend bool operator < (Box &B1, const Box &B2);
  friend bool operator==(const Box & B1, const Box & B2);

  friend istream &operator>>(istream &S,Box & B);
  friend ostream &operator<<(ostream &S,Box & B); 

  // **********************************************************
  // * Public member functions.                               *
  // **********************************************************
public:

  ~Box();     
  Box (const int boxsize=1, const char borderchar=DEFAULTBORDER,
       const char fillchar=DEFAULTFILL);
  Box(const Box & MB);
  Box &operator =(const Box & MB); 
  void Draw();
  void Shrink();
  void Grow();
  int GetSize();
  char GetFill();
  char GetBorder(); 
  int Perimeter();
  int Area();
  void SetBorder(const char borderchar);
  void SetFill(const char fillchar);
  void SetSize(const int boxsize);
  void Summary();
  ostream  &operator<<(ostream & S );

  Box operator++();
  Box operator++(int X);


 
  

// ************************************************************
// * Private Data items.                                      *
// ************************************************************
  
private:
 
  char fill;
  char border;
  int size;
}; 
  
