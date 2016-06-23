#include <iostream>
#include <cmath>
#include "bitarray.h"

using namespace std;

ostream& operator<<(ostream& os, const BitArray& a)
{
    for(int i = 0; i < a.Length(); i++)
    {
        os << a.Query(i);
    }
    
    return os;
}
bool operator==(const BitArray& a, const BitArray& b)
{
}
bool operator!=(const BitArray& a, const BitArray& b)
{
}
BitArray::BitArray(unsigned int n)
{
    arraySize = (n/8)+1;
    
    barray = new unsigned char[arraySize];
    
    for(int i = 0; i < arraySize; i++)
        barray[i] = (int)0;
}
BitArray::BitArray(const BitArray& a)
{
    arraySize = a.arraySize;
    
    barray = new unsigned char[arraySize];
    
    for(int i = 0; i < arraySize; i++)
        barray[i] = a.barray[i];
}
BitArray::~BitArray()
{
    delete [] barray;
}
BitArray& BitArray::operator=(const BitArray& a)
{
}
unsigned int BitArray::Length() const
{
    return arraySize*8;
}
void BitArray::Set(unsigned int index)
{
    unsigned char MASK = (int)1 << (index%8);
    barray[index/8] |= MASK;
}
void BitArray::Unset(unsigned int index)
{
    unsigned char MASK = (int)1 << (index%8);
    barray[index/8] &= ~MASK;
}
void BitArray::Flip(unsigned int index)
{
    unsigned char MASK = (int)1 << (index%8-1);
    barray[index/8] ^= 1 << MASK;
}
bool BitArray::Query(unsigned int index) const
{
    unsigned char MASK = (int)1 << (index%8);
    return barray[index/8] & MASK;
}
