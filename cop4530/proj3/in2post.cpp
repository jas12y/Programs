/*
Programmers Name: John Stubbs
      Assignment: #3
            Date: 2/14/14
*/
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cctype>
#include "stack.h"


using namespace std;
using namespace cop4530;

bool Convert(const string&, Stack<string>&);
int Eval(const string&, Stack<string>&, Stack<float>&);
bool IsNum(string&);
bool Parens(Stack<string>);

int main() 
{
	Stack<string> postfix;
	Stack<float> output;
	string expression;
	int x;

	cout << "Enter infix expression (\"exit\" to quit): ";
	getline(cin, expression);

	while(expression != "exit" && !cin.eof())
	{
//****************************************************************************************************************************************************
		x = Eval(expression, postfix, output);
		if(x == 0)
		{
			cout << "\nPostfix expression: " << postfix;
			cout << "\nPostfix evaluation: " << postfix << "= " << output;
		}
		else if(x == 1)
		{
			cout << "\nPostfix expression: " << postfix;
			cout << "\nPostfix evaluation: " << postfix << "= " << postfix;
		}
//****************************************************************************************************************************************************
		postfix.clear();
		output.clear();
		cout << "\nEnter infix expression (\"exit\" to quit): ";
		getline(cin, expression);
	}

	cout << endl;

	return(EXIT_SUCCESS);
}
bool Parens(Stack<string> test)
{
	while(!test.empty())
	{
		if(test.top() == "(")
			return true;
		test.pop();
	}
	return false;
}
bool IsNum(string& test)
{
	bool deci = false;
	for(int i =0; i < test.length(); ++i)
	{
		if(test.at(i) == '.' && !deci)
		{
			deci = true;
			
		}
		else if(!isdigit(test.at(i)))
		{
			return false;
		}
	}
	return true;
}
bool Convert(const string& expression, Stack<string>& postfix)
{
	Stack<string> ops;
	stringstream ss;
	string input;
	int count = 0;

	ss << expression;

	while(ss >> input)
	{
		if(input == "(")
		{
			ops.push(input);
		}
		else if(input == ")")
		{
			if(!Parens(ops))
			{
				cout << "\nError: Infix expression: ";
				cout << expression;
				cout << " has mismatched parens!";
				return false;
			}
			while(!ops.empty() && ops.top() != "(")
			{
				postfix.push(ops.top());
				ops.pop();
			}
			ops.pop();
		}
		else if(input == "*")
		{
			if(ops.empty() || ops.top() == "(" || ops.top() == "+" || ops.top() == "-")
				ops.push(input);
			else
			{
				while(!ops.empty() && ops.top() != "(" && ops.top() != "+" && ops.top() != "-")
				{
					postfix.push(ops.top());
					ops.pop();
				}
				ops.push(input);
			}
		}
		else if(input == "/")
		{
			if(ops.empty() || ops.top() == "(" || ops.top() == "+" || ops.top() == "-")
				ops.push(input);
			else
			{
				while(!ops.empty() && ops.top() != "(" && ops.top() != "+" && ops.top() != "-")
				{
					postfix.push(ops.top());
					ops.pop();
				}
				ops.push(input);
			}
		}
		else if(input == "+")
		{
			if(ops.empty() || ops.top() == "(")
				ops.push(input);
			else
			{
				while(!ops.empty() && ops.top() != "(")
				{
					postfix.push(ops.top());
					ops.pop();
				}
				ops.push(input);
			}
		}
		else if(input == "-")
		{
			if(ops.empty() || ops.top() == "(")
				ops.push(input);
			else
			{
				while(!ops.empty() && ops.top() != "(")
				{
					postfix.push(ops.top());
					ops.pop();
				}
				ops.push(input);
			}
		}
		else
		{
			++count;
			postfix.push(input);
		}
	}
	if(Parens(ops))
	{
		cout << "\nError: Infix expression: ";
		cout << expression;
		cout << " has mismatched parens!";
		return false;
	}
	else if(ops.empty() && postfix.size() <= 1)
		return true;
	else if(ops.empty() && (count -1) != (postfix.size() - count) + ops.size())
	{
		cout << "\nError: missing operators in expression";
		return false;
	}
	else if((count - 1) != (postfix.size() - count) + ops.size())
	{
		if((count - 1) > (postfix.size() - count) + ops.size())
			cout << "\nError: missing operators in expression";
		else
			cout << "\nError: missing operands in expression";
		return false;
	}
	while(!ops.empty())
	{
		postfix.push(ops.top());
		ops.pop();
	}
	return true;
}
int Eval(const string& expression, Stack<string>& postfix, Stack<float>& operands)
{
	float num, oprnd1, oprnd2;
	stringstream ss, conv;
	string input;

	if(!Convert(expression, postfix))
		return -1;

	ss << postfix;

	while(ss >> input)
	{
		if(IsNum(input))
		{
			conv << input;
			conv >> num;
			operands.push(num);
		}
		else if(input == "*")
		{
			if(operands.size() < 2)
			{
				cout << "\nError: missing operands in the expression";
				return -1;
			}
			oprnd1 = operands.top();
			operands.pop();
			oprnd2 =operands.top();
			operands.pop();
			num = oprnd1 * oprnd2;
			operands.push(num);
		}
		else if(input == "/")
		{
			if(operands.size() < 2)
			{
				cout << "\nError: missing operands in the expression";
				return -1;
			}
			oprnd1 = operands.top();
			operands.pop();
			oprnd2 =operands.top();
			operands.pop();
			num = oprnd2 / oprnd1;
			operands.push(num);
		}
		else if(input == "+")
		{
			if(operands.size() < 2)
			{
				cout << "\nError: missing operands in the expression";
				return -1;
			}
			oprnd1 = operands.top();
			operands.pop();
			oprnd2 =operands.top();
			operands.pop();
			num = oprnd1 + oprnd2;
			operands.push(num);
		}
		else if(input == "-")
		{
			if(operands.size() < 2)
			{
				cout << "\nError: missing operands in the expression";
				return -1;
			}
			oprnd1 = operands.top();
			operands.pop();
			oprnd2 =operands.top();
			operands.pop();
			num = oprnd2 - oprnd1;
			operands.push(num);
		}
		else
		{
			return 1;
		}
		conv.clear();
	}
	return 0;
}
