#ifndef SIEVE_H
#define SIEVE_H
#include <iostream>
#include "bitarray.h"

using namespace std;

void Sieve(BitArray& a)
{
    for(int i = 0; i < a.Length(); i++)
    {
        a.Set(i);
    }
    a.Unset(0);
    a.Unset(1);
}
#endif
