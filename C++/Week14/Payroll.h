// Specification file for the Payroll class
#ifndef PAYROLL_H
#define PAYROLL_H

class Payroll
{
private:
	double hours;
	double payRate;
	
public:
	// Constructor
	Payroll()
	   { hours = 0; payRate = 0; }
	
	// Mutators
	void setHours(double);

	void setPayRate(double r)
		{ payRate = r; }
	
	// Accessors
	double getHours() const
		{ return hours; }

	double getPayrate() const
		{ return payRate; }

	double getTotalPay() const
		{ return hours * payRate; }
};



#endif
