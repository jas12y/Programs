#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <crypt.h>
#include <vector>
#include <list>
#include <string>
#include <utility>
#include <stdlib.h>

using namespace std;

namespace cop4530
{

static const unsigned int max_prime = 64997;

class HashTable
  {
  public:

  private:
    unsigned int Index (const string &);
    unsigned int hash_function   (const string& );
    unsigned int prime_below(unsigned int);
    void setPrimes(vector<unsigned int> &);
    vector < list < pair <string, string> > > bucketVector;
  };
}

#endif
