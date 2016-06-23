/*
Programmers Name: John Stubbs
      Assignment: #3
            Date: 2/14/14
*/
#include "stack.h"

using namespace std;
using namespace cop4530;

// default zero parameter constructor
template <typename T>
Stack<T>::Stack()
{
	s = new list<T>;
}
// destructor
template <typename T>
Stack<T>::~Stack()
{
	s->clear();
	delete s;
}
// copy constructor
template <typename T>
Stack<T>::Stack(const Stack& rhs)
{
	s = new list<T>;
	for(typename list<T>::const_reverse_iterator rit = rhs.s->rbegin(); rit != rhs.s->rend(); ++rit)
		s->push_front(*rit);
}
// copy assignment operator
template <typename T>
const Stack<T>& Stack<T>::operator =(const Stack& rhs)
{
	for(typename list<T>::const_reverse_iterator rit = rhs.s->rbegin(); rit != rhs.s->rend(); ++rit)
		s->push_front(*rit);
	return *this;
}
// move constructor
template <typename T>
Stack<T>::Stack(Stack && rhs)
{
	s = new list<T>;
	for(typename list<T>::const_reverse_iterator rit = rhs.s->rbegin(); rit != rhs.s->rend(); ++rit)
		s->push_front(*rit);
	rhs.s->clear();
}
// move assignment operator
template <typename T>
Stack<T>& Stack<T>::operator =(Stack && rhs)
{
	for(typename list<T>::const_reverse_iterator rit = rhs.s->rbegin(); rit != rhs.s->rend(); ++rit)
		s->push_front(*rit);
	rhs.s->clear();
}
// MEMBER FUNCTIONS

// number of elements
template <typename T>
int Stack<T>::size() const
{
	return s->size();
}
// check if Stack is empty
template <typename T>
bool Stack<T>::empty() const
{
	return s->empty();
}
// delete all elements
template <typename T>
void Stack<T>::clear()
{
	s->clear();
}
// reference to the top element
template <typename T>
T& Stack<T>::top()
{
	return s->front();
}
template <typename T>
const T& Stack<T>::top() const
{
	return s->front();
}
// insert to the beginning
template <typename T>
void Stack<T>::push(const T& val)
{
	s->push_front(val);
}
// move version of insert
template <typename T>
void Stack<T>::push(T && val)
{
	s->push_front(val);
}
// delete first element
template <typename T>
void Stack<T>::pop()
{
	s->pop_front();
}
// print out all elements. ofc is deliminitor
template <typename T>
void Stack<T>::print(std::ostream& os, char ofc) const
{
	for(typename list<T>::const_reverse_iterator rit = s->rbegin(); rit != s->rend(); ++rit)
		os << *rit << ofc;
}
// overloading comparison operators
template <typename T>
bool operator ==(const Stack<T>& lhs, const Stack<T>& rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	Stack<T> ltemp = lhs;
	Stack<T> rtemp = rhs;
	
	while(!ltemp.empty())
	{
		if(ltemp.top() != rtemp.top())
			return false;
		ltemp.pop();
		rtemp.pop();
	}
	
	return true;
}
template <typename T>
bool operator !=(const Stack<T>& lhs, const Stack<T>& rhs)
{
	return !(lhs == rhs);
}
template <typename T>
bool operator <(const Stack<T>& lhs, const Stack<T>& rhs)
{
	if (lhs.size() != rhs.size())
		return lhs.size() < rhs.size();
	else if(lhs == rhs)
		return false;
		
	Stack<T> ltemp = lhs;
	Stack<T> rtemp = rhs;
	
	while(!ltemp.empty())
	{
		if(ltemp.top() > rtemp.top())
			return false;
		
		ltemp.pop();
		rtemp.pop();
	}
	return true;
}
// overloading output operator
template <typename T>
ostream& operator <<(ostream& os, const Stack<T>& a)
{
	a.print(os);
	return os;
}
