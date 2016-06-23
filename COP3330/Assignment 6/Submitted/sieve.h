/*
Programmers Name: John Stubbs
      Assignment: #6
            Date: 4/5/13

Implementation file for the Sieve function
*/
#include "bitarray.h"
#include <cmath>
#ifndef SIEVE_H
#define SIEVE_H

//Unset all multiples of next prime
void Mark(BitArray& a, int num)
{
	int length = a.Length();
	int currentPrime = num+num;
	while ( currentPrime < length)
	{
		a.Unset(currentPrime);
		currentPrime += num;
	}
	
}
//Set all and find prime numbers
void Sieve(BitArray& a)
{
	int length = a.Length();
	for (int i = 0; i < length; i++)
		a.Set(i);

	a.Unset(0);
	a.Unset(1);

	for (int j = 2; j < (int)sqrt((double)length)+1; j++)
	{
		if (a.Query(j))
			Mark(a,j);
	}
}

#endif
