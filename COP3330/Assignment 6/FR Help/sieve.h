#include "bitarray.h"
#include <cmath>
#ifndef _SIEVE_H
#define _SIEVE_H

void mark(BitArray& sie, int prime)
{
	int length = sie.Length();
	int currentPrime = prime+prime;
	while ( currentPrime < length)
	{
		sie.Unset(currentPrime);
		currentPrime += prime;
	}
	
}

 void Sieve(BitArray& sie)
 {
	int length = sie.Length();
	for (int a=0; a < length; a++)
	{
		sie.Set(a);
	}
	sie.Unset(0);
	sie.Unset(1);
	for (int b=2; b <  (int)sqrt((double)length)+1; b++)
	{
		if (sie.Query(b))
		{
			mark(sie, b);
		}
	}
 }

 #endif