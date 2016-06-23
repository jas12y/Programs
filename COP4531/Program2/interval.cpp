/*
Programmers Name: John Stubbs
      Assignment: #5
            Date: 11/22/14
*/
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <map>

using namespace std;

void openFile(ifstream &inFile, char* fileName);

int main(int argc, char *argv[]) 
{
	if (argc < 1)
	{
		cout<<"Please give a file name to the program!";
        return 1;
    }
	char* fileName = argv[1];
   	char data, begin;
   	int s, f;
   	int min = 999999;
	string str;
	stringstream ss;
	map<char, pair<int, int> > j;
	typedef map<char, pair<int, int> >::iterator itr;
   	pair<int, int> t;
   	vector<char> v;
   	ifstream inFile;

    openFile(inFile, fileName);

	while(!inFile.eof())
	{
		getline(inFile, str);
		ss << str;

    	while (ss >> data)
    	{
    		ss >> s;
    		ss >> f;
    		t = make_pair(s, f);
    		j.insert(pair<char, pair<int, int> >(data, t));
    		if(f < min)
    		{
    			min = f;
    			begin = data;
    		}
    	}
    	ss.clear();
	}
	inFile.close();
	v.push_back(begin);
	for(itr i = j.begin(); i != j.end(); ++i)
	{
		if(i->second.first >= j[begin].second)
		{
			v.push_back(i->first);
			begin = i->first;
		}
	}
	for(int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << endl;
	}
    return(EXIT_SUCCESS);
}
void openFile(ifstream &inFile, char* fileName)
{
    inFile.open(fileName);

    while(!inFile)
    {
        cout << "Error opening file..." << endl;
        exit(0);
    }
}
