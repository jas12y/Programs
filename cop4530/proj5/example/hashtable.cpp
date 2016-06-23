#ifndef HASHTABLE_CPP
#define HASHTABLE_CPP

#include <hashtable.h>


static const unsigned int default_capacity = 11;

namespace cop4530
{
	//Returns the bucket index where the pair should be inserted
	unsigned int HashTable::Index (const string & key)
	{
		return hash_function(key) % bucketVector.capacity();
	}

	//Returns the hashed index
	unsigned int HashTable::hash_function (const string & s)
	{
		unsigned int i;
		unsigned long bigval = s[0];
		for (i = 1; i < s.size(); ++i)
			bigval = ((bigval & 65535) * 18000) + (bigval >> 16) + s[i];
		bigval = ((bigval & 65535) * 18000) + (bigval >> 16);
		return bigval & 65535;

	}

	// returns largest prime number <= n or zero if input is too large
	// This is likely to be more efficient than prime_above(), because
	// it only needs a vector of size n
	unsigned int HashTable::prime_below (unsigned int n)
	{
		if (n > max_prime)
		{
			std::cerr << "** input too large for prime_below()\n";
			return 0;
		}
		if (n == max_prime)
		{
			return max_prime;
		}
		if (n <= 1)
		{
			std::cerr << "** input too small\n";
			return 0;
		}

		// now: 2 <= n < max_prime
		vector <unsigned int> v (n + 1);
		setPrimes(v);
		while (n > 2)
		{
			if (v[n] == 1)
				return n;
			--n;
		}

		return 2;
	}

	//Sets all prime number indexes to 1. Called by method prime_below(n) 
	void HashTable::setPrimes(vector<unsigned int>& vprimes)
	{
		int i = 0;
		int j = 0;

		vprimes[0] = 0;
		vprimes[1] = 0;
		int n = vprimes.capacity();

		for (i = 2; i < n; ++i)
			vprimes[i] = 1;

		for( i = 2; i*i < n; ++i)
		{
			if (vprimes[i] == 1)
				for(j = i + i ; j < n; j += i)
					vprimes[j] = 0;
		}
	}

}
#endif

