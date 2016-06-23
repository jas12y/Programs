/*
Programmers Name: John Stubbs
      Assignment: #3
            Date: 10/12/14
*/
#include <cstdlib>
#include <cstring>
#include <utility>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include "cluster.cpp"
#include <algorithm>

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
   	int a, ct;
   	pair<int,int> closest;
   	double data, dist, temp, min;
	string str;
	stringstream ss;
	vector<Cluster> vc;
   	vector< vector<double> > v, current, prev;
   	vector<double> p;
   	vector<int> m;
   	Cluster* cls;
   	ifstream inFile;

	if(strcmp(algo, "average") == 0)
		a = 1;
	else if(strcmp(algo, "kmeans") == 0)
		a = 2;
	else
		a = 0;

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

//*********************************************************************************************************************************************
	switch (a)
	{
		case 1:
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
				min = 999999;
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
    		break;
//*********************************************************************************************************************************************

//*********************************************************************************************************************************************
		case 2:
			for(int i = 0; i < v.size(); ++i)
			{
				m.push_back(i);
			}
			srand (time(NULL));
			random_shuffle (m.begin(), m.end());
			for(int i = 0; i < k; ++i)
    		{
    			cls = new Cluster(v[m[i]]);
    			cls->addPoint(m[i], v[m[i]]);
    			current.push_back(v[m[i]]);
    			vc.push_back(*cls);
			}
			for(int r = 0; r < 99; ++r)
			{
				for(int i = 0; i < v.size(); ++i)
				{
					min = 999999;
					for(int j = 0; j < vc.size(); ++j)
					{
						dist = vc[j].centerToPoint(v[i]);
						if(dist < min)
						{
							min = dist;
							ct = j;
						}
					}
					for(int x = 0; x < vc.size(); ++x)
					{
						if(vc[x].isIn(i) && x != ct)
							vc[x].removePoint(i);
					}
					vc[ct].addPoint(i, v[i]);
				}
				for(int i = 0; i < vc.size(); ++i)
				{
					prev.push_back(vc[i].getCenter());
					vc[i].setCenter();
					current.push_back(vc[i].getCenter());
				}
				if(current == prev)
					break;
				prev.clear();
				current.clear();
			}
    		break;
		default:
    		cout << "Incorrect value for clustering type.";
	}
	cout << "A = [";
	for(int i = 0; i < v.size(); ++i)
	{
		if(i !=0)
			cout << ",";
		for(int j = 0; j < vc.size(); ++j)
		{
			if(vc[j].isIn(i))
				cout << j ;
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
