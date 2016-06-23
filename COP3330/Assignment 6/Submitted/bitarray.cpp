/*
Programmers Name: John Stubbs
      Assignment: #6
            Date: 4/5/13

Implementation file for the BitArray class
*/
#include <cmath>
#include "bitarray.h"

const int CHAR_SIZE = sizeof(unsigned char)*8;

//Overload of the output operator
ostream& operator<<(ostream& os, const BitArray& a)
{
	os << "(";
	for (int c = 0; c < a.Length(); c++)
 		os << (int) a.Query(c);
	os << ")\n";

	return os;
}
//Overload of the equivalency operator
bool operator==(const BitArray& a, const BitArray& b)
{
	bool equal = true;
    if (a.Length() == b.Length())
	{
		for (int i = 0; i < a.Length()/CHAR_SIZE; i++)
		{
			if (!(a.barray[i] == b.barray[i]))
				equal = false;
		}
	}
	else 
	{
		equal = false;
	}
	return equal;
}
//Overload of the non-equivalency operator
bool operator!=(const BitArray& a, const BitArray& b)
{
	bool notEqual = false;
    if (a.Length() == b.Length())
	{
		for (int i = 0; i < a.Length()/CHAR_SIZE; i++)
		{
			if (!(a.barray[i] == b.barray[i]))
				notEqual = true;
		}
	}
	else 
		notEqual = true;

	return notEqual;
}
//Constructor
BitArray::BitArray(unsigned int n)
{
	arraySize = (int)(ceil(((double)n/(CHAR_SIZE)))); 

	if (!(arraySize > 0))
		arraySize = 1; 

    barray = new unsigned char[arraySize];

	for (int i = 0; i<arraySize; i++)
		barray[i] = (int)0;
}
//Overloaded Condtructor for equals operator
BitArray::BitArray(const BitArray& a)
{
	arraySize = a.Length();

	barray = new unsigned char[arraySize];

	for (int i = 0; i<arraySize; i++)
		barray[i] = a.barray[i];
}
//Destructor
BitArray::~BitArray()
{
	delete [] barray;
}
//Overload of equals operator
BitArray& BitArray::operator=(const BitArray& a)
{
	if (this == &a)
       return *this;

	delete [] barray;

	arraySize = a.Length();

	barray = new unsigned char[arraySize];
	
	for (int i = 0; i<arraySize; i++)
		barray[i] = a.barray[i];

	return *this;
}
//Returns array lenght
unsigned int BitArray::Length() const
{
	return arraySize*CHAR_SIZE;
}
//Set bit in byte of array
void BitArray::Set(unsigned int index)
{
	int tempIndex;
	unsigned char place;
	if (index >= 0 && index < arraySize*CHAR_SIZE)
	{
		tempIndex = index/CHAR_SIZE;
		place = 1 << (7 - (index % CHAR_SIZE));
		barray[tempIndex] = (barray[tempIndex] | place);
	} 
}
//Unset bit in byte of array
void BitArray::Unset(unsigned int index)
{
	int tempIndex;
	unsigned char place;
	if (index >= 0 && index < arraySize*CHAR_SIZE)
	{
		tempIndex = index/CHAR_SIZE;
		place = ~(1 << (7 - (index % CHAR_SIZE)));
		barray[tempIndex] = (barray[tempIndex] & place);
	}
}
//Flip bit in byte of array
void BitArray::Flip(unsigned int index)
{
	int tempIndex;
	unsigned char pos;
	if (index >= 0 && index < arraySize*CHAR_SIZE)
	{
		tempIndex = index/CHAR_SIZE;
		pos = (1 << (7 - (index % CHAR_SIZE)));
		barray[tempIndex] = (barray[tempIndex] ^ pos);
	}
}
//Return bool value for on or off (1 or 0)
bool BitArray::Query(unsigned int index) const
{
	bool answer = false;
	int tempIndex;
	if (index >= 0 && index < arraySize*CHAR_SIZE)
	{
		tempIndex = index/CHAR_SIZE;
        answer = (bool)(barray[tempIndex] & ( 1 << (7 - (index % CHAR_SIZE) )));
	}
	return answer;
}
