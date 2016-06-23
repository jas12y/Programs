#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <crypt.h>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <utility>
#include <stdlib.h>

using namespace std;

namespace cop4530
{

static const unsigned int max_prime = 64997;

class HashTable
  {
  public:
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  	HashTable();
  	HashTable(size_t n);
  	~HashTable();
  	bool AddUser(pair<string,string> &p);
  	bool RemoveUser(const string &s);
  	bool FindUser(const string &s);
  	bool ChangePwd(pair<string,string> &p, const string &s);
  	void Print();
  	void LoadFile(const string &s);
  	void WriteFile(const string &s);
  	size_t GetSize();
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  private:
    unsigned int Index (const string &);
    unsigned int hash_function   (const string& );
    unsigned int prime_below(unsigned int);
    void setPrimes(vector<unsigned int> &);
    vector < list < pair <string, string> > > bucketVector;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    string Encrypt(const string &s);
    size_t size;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  };
}

#endif
