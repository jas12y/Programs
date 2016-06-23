#include "bitarray.h"
#include <cmath>
#ifndef _BITARRAY_CPP
#define _BITARRAY_CPP

const int charSize = sizeof(unsigned char)*8;


ostream& operator<< (ostream& os, const BitArray& a)
{
	os << "(";
	for (int c = 0; c < a.Length(); c++)
	{	
			os << (int) a.Query(c);
	}
	os << ")\n";
	return os;
}





bool operator== (const BitArray& A, const BitArray& B)
{
	if (A.Length() == B.Length())
	{
		for (int i = 0; i < A.Length()/charSize; i++)
		{
			if (!(A.barray[i] == B.barray[i]))
			{
				return false;
			}
		}
	}
	else 
	{
		return false;
	}

	return true;
}





bool operator!= (const BitArray& A, const BitArray& B)
{

	if (A.Length() == B.Length())
	{
		for (int i = 0; i < A.Length()/charSize; i++)
		{
			if (!(A.barray[i] == B.barray[i]))
			{
				return true;
			}
		}
	}
	else 
	{
		return true;
	}

	return false;


}






BitArray::BitArray(unsigned int n)
{
	
	
	arraySize = (int)(ceil(((double)n/(charSize)))); 

	if (!(arraySize > 0))
	{
		arraySize = 1; 
	}
	barray = new unsigned char[arraySize];

	for (int i = 0; i<arraySize; i++)
	{
		barray[i] = (int)0;
	}

}    // Construct an array that can handle n bits






BitArray::BitArray(const BitArray& A)
{
	arraySize = A.Length();

	barray = new unsigned char[arraySize];

	for (int i = 0; i<arraySize; i++)
	{
		barray[i] = A.barray[i];
	}

}   // copy constructor






BitArray::~BitArray()
{
	delete [] barray;
}                 // destructor





BitArray& BitArray::operator= (const BitArray& a)
{
	if (this == &a)
	{
	return *this;
	}

	delete [] barray;
	arraySize = a.Length();

	barray = new unsigned char[arraySize];
	for (int i = 0; i<arraySize; i++)
	{
		barray[i] = a.barray[i];
	}

	return *this;
} 





unsigned int BitArray::Length() const
{

	return arraySize*charSize;
}





void BitArray::Set   (unsigned int index)
{
	int tempIndex;
	unsigned char place;
	if (index >= 0 && index < arraySize*charSize)
	{
		tempIndex = index/charSize;
		place = 1 << (7 - (index % charSize));
		
		barray[tempIndex] = (barray[tempIndex] | place);
	} 
}        // set bit with given index to 1





void BitArray::Unset (unsigned int index)
{
	int tempIndex;
	unsigned char place;
	if (index >= 0 && index < arraySize*charSize)
	{
		tempIndex = index/charSize;
		place = ~(1 << (7 - (index % charSize)));
		barray[tempIndex] = (barray[tempIndex] & place);

	}
}        // set bit with given index to 0






void BitArray::Flip  (unsigned int index)
{
	int tempIndex;
	unsigned char place;
	if (index >= 0 && index < arraySize*charSize)
	{
		tempIndex = index/charSize;
		place = (1 << (7 - (index % charSize)));
		barray[tempIndex] = (barray[tempIndex] ^ place);
	}
}        // change bit (with given index)





bool BitArray::Query (unsigned int index) const
{
	bool truth = false;
	int tempIndex;
	if (index >= 0 && index < arraySize*charSize)
	{
		tempIndex = index/charSize;
	truth = (bool) (barray[tempIndex] & ( 1 << (7 - (index % charSize) )));
	}
	return truth;
}  // return true if the given bit
					   //  is set to 1, false otherwise


#endif