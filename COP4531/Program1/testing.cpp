/*
Programmers Name: John Stubbs
      Assignment: #3
            Date: 10/12/14
*/
#include <cstdlib>
#include <utility>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "cluster.cpp"

using namespace std;

void openFile(ifstream &inFile, char* fileName);

int main(int argc, char *argv[]) 
{
	if (argc < 4)
	{
		cout<<"Please give the arguments to the program!";
        return 1;
    }
	char* fileName = argv[1];
   	int k = atoi(argv[2]);
   	char* algo = argv[3];
   	int* a;
   	pair<int,int> closest;
   	double data, dist, temp;
	string str;
	stringstream ss;
	vector<Cluster> vc;
   	vector< vector<double> > v;
   	vector<double> p;
   	Cluster* cls;
   	ifstream inFile;

    openFile(inFile, fileName);

	while(!inFile.eof())
	{
		getline(inFile, str);
		ss << str;
	
    	while (ss >> data)
    	{
	    	p.push_back(data);
    	}

		v.push_back(p);
    	p.clear();
    	ss.clear();
	}
	p.clear();
	inFile.close();
//*********************************************************************************************************************************************
	for(int i = 0; i < v.size(); ++i)
	{
		for(int j = 0; j < v.size(); ++j)
		{
			if(v[i] == v[j])
				dist = 0;
			else
			{
				for(int x = 0; x < v[j].size(); ++x)
				{
					temp += pow(v[i][x]-v[j][x], 2);
				}
				dist = sqrt(temp);
			}
			p.push_back(dist);
			
			
			temp = 0;
		}
		cls = new Cluster(i, p);
		vc.push_back(*cls);
		p.clear();
	}
	while(vc.size() > k)
	{
		double min = 999999;
		for(int i = 0; i < vc.size(); ++i)
		{
			for(int j = 0; j < vc.size(); ++j)
			{
				if(v[i] == v[j])
					dist = 0;
				else
					dist = vc[i].getDist(vc[j]);
				if(dist < min && dist != 0)
				{
					min = dist;
					closest.first = i;
					closest.second = j;
				}
			}
		}
		vc[closest.first].merge(vc[closest.second]);
		vc.erase(vc.begin() + (closest.second));
	}
	cout << "A = [";
	for(int i = 0; i < v.size(); ++i)
	{
		for(int j = 0; j < vc.size(); ++j)
		{
			if(vc[j].isIn(i))
				cout << j << ",";
		}
	}
	cout << "]" << endl;
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
