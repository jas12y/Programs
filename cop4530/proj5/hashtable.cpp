#ifndef HASHTABLE_CPP
#define HASHTABLE_CPP

#include "hashtable.h"


static const unsigned int default_capacity = 11;

namespace cop4530
{
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	HashTable::HashTable()
	{
		bucketVector.resize(default_capacity);
		size = 0;
	}
	HashTable::HashTable(size_t n)
	{
		if(prime_below(n) == 0)
		{
			cout << "set to default capacity\n";
			n = default_capacity;
		}
		
		bucketVector.resize(n);
		size = 0;
	}
	HashTable::~HashTable()
	{
		bucketVector.clear();
		size = 0;
	}
	bool HashTable::AddUser(pair<string,string> &p)
	{
		string str = Encrypt(p.second);
		p.second = str;
		if(!FindUser(p.first))
		{
			bucketVector[Index(p.first)].push_back(p);
			++size;
			return true;
		}
		return false;
	}
	bool HashTable::RemoveUser(const string &s)
	{
		unsigned int index;
		index = Index(s);
		pair<string,string> p;
		
		if(FindUser(s))
		{
			for(list<pair<string,string> >::iterator itr = bucketVector[index].begin(); itr != bucketVector[index].end(); ++itr)
			{
				if(itr->first == s)
					p = *itr;
			}
			bucketVector[Index(s)].remove(p);
			--size;
			return true;
		}
		return false;
	}
	bool HashTable::FindUser(const string &s)
	{
		unsigned int index;
		index = Index(s);
		
		if(!bucketVector[index].empty())
		{
			for(list<pair<string,string> >::iterator itr = bucketVector[index].begin(); itr != bucketVector[index].end(); ++itr)
			{
				if(itr->first == s)
					return true;
			}
		}
		return false;
	}
	bool HashTable::ChangePwd(pair<string,string> &p, const string &s)
	{
		string epwd = Encrypt(p.second);
		string estr = Encrypt(s);
		unsigned int index;
		index = Index(p.first);
		p.second = epwd;

		for(list<pair<string,string> >::iterator itr = bucketVector[index].begin(); itr != bucketVector[index].end(); ++itr)
		{
			if(itr->first == p.first && itr->second == p.second)
			{
				itr->second = estr;
				return true;
			}
		}
		return false;
	}
	void HashTable::Print()
	{
		for(int i = 0; i < bucketVector.size(); ++i)
		{
			cout << "v[" << i << "]: ";
			if(!bucketVector[i].empty())
			{
				for(list<pair<string,string> >::iterator itr = bucketVector[i].begin(); itr != bucketVector[i].end(); ++itr)
				{
					cout << itr->first << ":" << itr->second << "\t";
				}
			}
			cout << endl;
		}
	}
	void HashTable::LoadFile(const string &s)
	{
		ifstream inFile;
		string name, pwd;
		pair<string,string> p;
		const char* cstr;
		
		cstr = s.c_str();
		inFile.open(cstr);
		if(!inFile)
    	{
        	cout << "*****Error: Unable to open file " << s << endl;
        	return;
    	}
		
    	while(!inFile.eof())
    	{
    		getline(inFile, name, ':');
    		if(inFile.eof())
    			break;
    		getline(inFile, pwd, '\n');
    		p = make_pair(name,pwd);
    		if(!AddUser(p))
    			cout << "\n*****Error: User already exists. Could not add user.\n";
    	}
    	inFile.close();
	}
	void HashTable::WriteFile(const string &s)
	{
		ofstream outFile;
		const char* cstr;
		
		cstr = s.c_str();
		outFile.open(cstr);
		for(int i = 0; i < bucketVector.size(); ++i)
		{
			if(!bucketVector[i].empty())
			{
				for(list<pair<string,string> >::iterator itr = bucketVector[i].begin(); itr != bucketVector[i].end(); ++itr)
					outFile << itr->first << ":" << itr->second << "\n";
			}
		}
		outFile.close();
	}
	size_t HashTable::GetSize()
	{
		return size;
	}
	string HashTable::Encrypt(const string &s)
	{
		string epwd;
		char salt[] = "$1$########";

		char * pwd = new char [100];
		strcpy ( pwd, crypt(s.c_str(), salt));
		epwd.assign(pwd, 12, 22);
		return epwd;
	}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
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

