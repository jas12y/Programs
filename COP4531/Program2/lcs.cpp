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
#include <string>

using namespace std;

void openFile(ifstream &inFile, char* fileName);
void lcs(string &data1, string &data2);
int max(int a, int b);

int main(int argc, char *argv[]) 
{
	if (argc < 1)
	{
		cout<<"Please give a file name to the program!";
        return 1;
    }
	char* fileName = argv[1];
   	string data1, data2;
	string str;
	stringstream ss;
   	ifstream inFile;

    openFile(inFile, fileName);

	while(!inFile.eof())
	{
		getline(inFile, str);
		ss << str;

    	while (ss >> data1)
    	{
    		ss >> data2;
			lcs(data1, data2);
    	}
    	ss.clear();
	}
	inFile.close();

    return(EXIT_SUCCESS);
}
int max(int a, int b)
{
	if(a >= b)
		return a;
	return b;
}
void lcs(string &data1, string &data2)
{
	int m = data1.length();
	int n = data2.length();
	int c[m+1][n+1];
	
	for(int i = 0; i <= m; ++i)
	{
		for(int j = 0; j <= n; ++j)
		{
			if(i == 0 || j == 0)
				c[i][j] = 0;
			else if(data1[i-1] == data2[j-1])
				c[i][j] = c[i-1][j-1] + 1;
			else
				c[i][j] = max(c[i-1][j], c[i][j-1]);
		}
	}
	int index = c[m][n];
	int i = m, j = n;
	char x[index+1];
	x[index] = '\0';
	
	while(i > 0 && j > 0)
	{
		if(data1[i-1] == data2[j-1])
		{
			x[index-1] = data1[i-1];
			--i;
			--j;
			--index;
		}
		else if(c[i-1][j] > c[i][j-1])
			--i;
		else
			--j;
	}
	cout << x << endl;
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
