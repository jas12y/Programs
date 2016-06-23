// Implementation file for the Payroll class
#include <iostream>
#include <cstdlib>
#include "Payroll.h"
using namespace std;

void Payroll::setHours(double h)
{
   if (h > 60)
   {
      // Bad number of hours.
      cout << "Invalid number of hours.\n";
      exit(EXIT_FAILURE);
   }
   else
      hours = h;
}

