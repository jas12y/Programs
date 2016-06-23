#include <iostream>
#include <string>
#include <utility>
#include <cstdlib>
#include "hashtable.h"


using namespace std;
using namespace cop4530;

void Menu();
pair<string,string> GetValues();

int main()
{
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	size_t cap;
	char choice;
	string str;
	HashTable *table;
	pair<string,string> values;
	
	cout << "Enter perferred hash table capacity: ";
	cin >> cap;
	
	table = new HashTable(cap);
	
	
	Menu();
	cin >> choice;
	
	while(choice != 'x')
	{
		switch(choice)
		{
			case 'l':
				cout << "Enter password file name to load from: ";
				cin >> str;
				table->LoadFile(str);
				break;
			case 'a':
				values = GetValues();
				if(table->AddUser(values))
					cout << "\nUser " << values.first << " added.\n";
				else
					cout << "\n*****Error: User already exists. Could not add user.\n";
				break;
			case 'r':
				cout << "Enter username: ";
				cin >> str;
				if(table->RemoveUser(str))
					cout << "\nUser " << str << " deleted.\n";
				else
					cout << "\n*****Error: User not found. Could not remove user.\n";
				break;
			case 'c':
				values = GetValues();
				cout << "\nEnter new password: ";
				cin >> str;
				if(table->FindUser(values.first))
					if(table->ChangePwd(values,str))
						cout << "\nPassword changed for user " << values.first << endl;
					else
						cout << "\n*****Error: Password incorrect.  Could not change user password\n";
				else
					cout << "\n*****Error: User not found.  Could not change user password\n";
				break;
			case 'f':
				values = GetValues();
				if(table->FindUser(values.first))
					cout << "\nUser '" << values.first << "' found.\n";
				else
					cout << "\nUser '" << values.first << "' not found.\n";
				break;
			case 'd':
				table->Print();
				break;
			case 's':
					cout <<"Size of hashtable: " << table->GetSize() << endl;
				break;
			case 'w':
				cout << "Enter password file name to write to: ";
				cin >> str;
				table->WriteFile(str);
				break;
			default:
				cout << "*****Error: Invalid entry. Try again.\n";
				break;
		}
		
		Menu();
		cin >> choice;
	}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	return(EXIT_SUCCESS);
}

void Menu()
{
  cout << "\n\n";
  cout << "l - Load From File" << endl;
  cout << "a - Add User" << endl;
  cout << "r - Remove User" << endl;
  cout << "c - Change User Password" << endl;
  cout << "f - Find User" << endl;
  cout << "d - Dump HashTable" << endl;
  cout << "s - HashTable Size" << endl;
  cout << "w - Write to Password File" << endl;
  cout << "x - Exit program" << endl;
  cout << "\nEnter choice : ";
}
pair<string,string> GetValues()
{
	pair<string,string> v;
	
	cout << "Enter username: ";
	cin >> v.first;
	cout << "Enter password: ";
	cin >> v.second;
	
	return v;
}
