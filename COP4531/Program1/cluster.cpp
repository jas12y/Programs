/*
Programmers Name: John Stubbs
      Assignment: #3
            Date: 10/12/14
*/
# ifndef DATE_H
# define DATE_H
#include <cstdlib>
#include <utility>
#include <cmath>
#include <map>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Cluster
{
	private:
		map<int, vector<double> > distfrompt;
		vector<double> center;
	public:
		Cluster(int id, vector<double> c)
		{
			distfrompt.insert(pair<int, vector<double> >(id, c));
		};
		Cluster(vector<double> c)
		{
			center = c;
		};
		~Cluster()
		{
			
		};
		double getDist(Cluster c)
		{
			double total = 0;
			for(map<int, vector<double> >::iterator itr = distfrompt.begin(); itr != distfrompt.end(); ++itr)
			{
				for(map<int, vector<double> >::iterator itrc = c.distfrompt.begin(); itrc != c.distfrompt.end(); ++itrc)
				{
					total += itr->second[itrc->first];
				}
			}
			return total/(distfrompt.size()*c.distfrompt.size());
		};
		void merge(Cluster c)
		{
			for(map<int, vector<double> >::iterator itrc = c.distfrompt.begin(); itrc != c.distfrompt.end(); ++itrc)
				{
					distfrompt.insert(pair<int, vector<double> >(itrc->first, itrc->second));
				}
		};
		void showMem()
		{
			for(map<int, vector<double> >::iterator itr = distfrompt.begin(); itr != distfrompt.end(); ++itr)
			{
				cout << itr->first << " ";
			}
			cout << endl;
		};
		bool isIn(int i)
		{
			map<int, vector<double> >::iterator itr = distfrompt.find(i);
			if(itr == distfrompt.end())
				return false;
			else
				return true;
		};
		void addPoint(int id, vector<double> c)
		{
			distfrompt.insert(pair<int, vector<double> >(id, c));
		};
		void removePoint(int id)
		{
			distfrompt.erase(id);
		};
		double centerToPoint(vector<double> p)
		{
			double temp, dist;
			if(center == p)
				return 0;
			else
			{
				for(int x = 0; x < center.size(); ++x)
				{
					temp += pow(center[x]-p[x], 2);
				}
				dist = sqrt(temp);
				return dist;
			}
		};
		void setCenter()
		{
			vector<double> temp;
			double total = 0;
			for(int i = 0; i < center.size(); ++i)
			{
				for(map<int, vector<double> >::iterator itr = distfrompt.begin(); itr != distfrompt.end(); ++itr)
				{
					total += itr->second[i];
				}
				temp.push_back(total/distfrompt.size());
				total = 0;
			}
			center = temp;
		};
		vector<double> getCenter()
		{
			return center;
		};
};
#endif
