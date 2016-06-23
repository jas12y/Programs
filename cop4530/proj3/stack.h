/*
Programmers Name: John Stubbs
      Assignment: #3
            Date: 2/14/14
*/
#ifndef STACK_H
#define STACK_H
#include <list>
#include <iostream>

namespace cop4530
{

template <typename T>
class Stack
{   
	public:
 	
		// default zero parameter constructor
	    Stack();
	    // copy constructor
	    Stack(const Stack& rhs);
	    // move constructor
	    Stack(Stack && rhs);
	    // destructor
	    ~Stack();
	
	    // copy assignment operator
	    const Stack& operator =(const Stack& rhs);
	    // move assignment operator
	    Stack& operator =(Stack && rhs);
	
	    // MEMBER FUNCTIONS
	    
	    // number of elements
	    int size() const;
	    // check if Stack is empty
	    bool empty() const;
	    // delete all elements
	    void clear();
		// reference to the top element
	    T& top();
	    const T& top() const; 
	    // insert to the beginning
	    void push(const T& val);
	    // move version of insert
	    void push(T && val);
	    // delete first element
	    void pop();
	    // print out all elements. ofc is deliminitor
	    void print(std::ostream& os, char ofc = ' ') const;
	    
	private:
		
		std::list<T>* s;
};

// overloading comparison operators
template <typename T>
bool operator ==(const Stack<T>& lhs, const Stack<T>& rhs);

template <typename T>
bool operator !=(const Stack<T>& lhs, const Stack<T>& rhs);

template <typename T>
bool operator <(const Stack<T>& lhs, const Stack<T>& rhs);

// overloading output operator
template <typename T>
std::ostream& operator <<(std::ostream& os, const Stack<T>& a);

// include the implementation file here
#include "stack.hpp"

} // end of namespace 4530

#endif
