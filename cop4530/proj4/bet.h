/*
Programmers Name: John Stubbs
      Assignment: #4
            Date: 3/17/14
*/
#ifndef BET_H
#define BET_H
#include <list>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class BET
{
	// nested BinaryNode class
    struct BinaryNode
	{
		string data;
		BinaryNode *l_child;
		BinaryNode *r_child;
		
		BinaryNode()
		{
			data = "";
			l_child = nullptr;
			r_child = nullptr;
		}
		BinaryNode(string input)
		{
			data = input;
			l_child = nullptr;
			r_child = nullptr;
		}
		
    };
    
	public:
 	
		// default zero-parameter constructor
	    BET()
	    {
	    	root = nullptr;
	    }
	    // one-parameter constructor
	    BET(const string postfix)
	    {
	    	root = nullptr;
			if(!buildFromPostfix(postfix))
	    	{
	    		cout << "Cannot build tree\n";
	    	}	    		
	    }
	    // copy constructor
	    BET(const BET& rhs)
	    {
	    	root = clone(rhs.root);
	    }
	    // destructor
	    ~BET()
	    {
	    	makeEmpty(root);
	    }
	
	    // copy assignment operator
	    const BET& operator =(const BET& rhs)
	    {
	    	this->root = clone(rhs.root);
	    	return *this;
	    }
	
	    // MEMBER FUNCTIONS
	    
		bool buildFromPostfix(const string postfix)
		{
			BinaryNode *temp;
	    	stringstream ss;
	    	list<BinaryNode*> lst;
	    	string input;
	    	
	    	ss << postfix;
	    	
	    	if(!empty())
	    		makeEmpty(root);
	    		
	    	while(ss >> input)
	    	{
				if(input == "*" || input == "/" || input == "+" || input == "-")
				{
					if(lst.empty())
					{
						cout << "Wrong postfix expression\n";
						return false;
					}
					else
					{
						temp = new BinaryNode(input);
						temp->r_child = lst.front();
						lst.pop_front();
					}
					if(lst.empty())
					{
						cout << "Wrong postfix expression\n";
						return false;
					}
					else
					{
						temp->l_child = lst.front();
						lst.pop_front();
						lst.push_front(temp);
					}
				}
				else
	    		{
					temp = new BinaryNode(input);
					lst.push_front(temp);
				}
	    	}
	    	if(!lst.empty())
			{
				root = lst.front();
	    		lst.pop_front();
	    	}
	    	if(!lst.empty() || size() < 3 || (size() - leaf_nodes() != leaf_nodes() - 1))
	    	{
	    		cout << "Wrong postfix expression\n";
	    		return false;
	    	}
	    	
	    	return true;
		}
		void printInfixExpression()
		{
			printInfixExpression(root);
			cout << endl;
		}
		void printPostfixExpression()
		{
			printPostfixExpression(root);
			cout << endl;
		}
		size_t size()
		{
			return size(root);
		}
		size_t leaf_nodes()
		{
			return leaf_nodes(root);
		}
		bool empty()
		{
			if(size() == 0)
				return true;
			
			return false;
		}
	    
	private:
		
		void printInfixExpression(BinaryNode *n)
		{
			bool paren = false;
			
			if(n->l_child != nullptr)
			{
				if(n->l_child->data == "*" || n->l_child->data == "/" || n->l_child->data == "+" || n->l_child->data == "-")
				{
					if((n->data == "*" || n->data == "/") && (n->l_child->data == "+" || n->l_child->data == "-"))
					{
						cout << "( ";
						paren = true;
					}
				}
				printInfixExpression(n->l_child);
			}
			if(paren == true)
			{
				cout << ") ";
				paren = false;
			}
			cout << n->data << " ";
			if(n->r_child != nullptr)
			{
				if(n->r_child->data == "*" || n->r_child->data == "/" || n->r_child->data == "+" || n->r_child->data == "-")
				{
					if(n->data == "*" || n->data == "/")
					{
						cout << "( ";
						paren = true;
					}
					else if((n->data == "+" || n->data == "-") && (n->r_child->data == "+" || n->r_child->data == "-"))
					{
						cout << "( ";
						paren = true;
					}
				}
				printInfixExpression(n->r_child);
			}
			if(paren == true)
				cout << ") ";
		}
		void printPostfixExpression(BinaryNode *n)
		{
			if(n->l_child != nullptr)
			{
				printPostfixExpression(n->l_child);
			}
			if(n->r_child != nullptr)
			{
				printPostfixExpression(n->r_child);
			}
			cout << n->data << " ";
		}
		void makeEmpty(BinaryNode* &t)
		{
			if(t == nullptr)
				return;
			if(t->l_child != nullptr)
			{
				makeEmpty(t->l_child);
			}
			if(t->r_child != nullptr)
			{
				makeEmpty(t->r_child);
			}
			if(root == t)
				root = nullptr;
			
			delete t;
		}
		BinaryNode* clone(BinaryNode *t) const
		{
			BinaryNode *ptr = new BinaryNode;
			ptr->data = t->data;
			
			if(t->l_child != nullptr)
				ptr->l_child = clone(t->l_child);
			
			if(t->r_child != nullptr)
				ptr->r_child = clone(t->r_child);
			
			return ptr;
		}
		size_t size(BinaryNode *t)
		{
			if(t == nullptr)
				return 0;
			else
				return size(t->l_child) + size(t->r_child) + 1;
		}
		size_t leaf_nodes(BinaryNode *t)
		{
			if(t == nullptr)
				return 0;
			else if(t->l_child == nullptr && t->r_child == nullptr)
				return 1;
			else
				return leaf_nodes(t->l_child) + leaf_nodes(t->r_child);
		}
		
		BinaryNode *root;
};
#endif
