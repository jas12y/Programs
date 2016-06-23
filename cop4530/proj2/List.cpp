/*
Programmers Name: John Stubbs
      Assignment: #2
            Date: 2/1/14
*/
#include "List.h"

using namespace std;
using namespace cop4530;

// default zero parameter constructor
template <typename T>
List<T>::const_iterator::const_iterator()
{
	current = nullptr;
}
// protected constructor
template <typename T>
List<T>::const_iterator::const_iterator(Node *p)
{
	current = p;
}
// operator*() to return element
template <typename T>
const T& List<T>::const_iterator::operator* () const
{
	return retrieve();
}
// increment/decrement operators
template <typename T>
typename List<T>::const_iterator& List<T>::const_iterator::operator++ ()
{
	current = current->next;
	return *this;
}
template <typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator++ (int)
{
	const_iterator old = *this;
	++(*this);
	return old;
}
template <typename T>
typename List<T>::const_iterator& List<T>::const_iterator::operator-- ()
{
	current = current->prev;
	return *this;
}
template <typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator-- (int)
{
	const_iterator old = *this;
	--( *this ); 
	return old;
}
// comparison operators
template <typename T>
bool List<T>::const_iterator::operator== (const const_iterator& rhs) const
{
	return current == rhs.current;
}
template <typename T>
bool List<T>::const_iterator::operator!= (const const_iterator& rhs) const
{
	return !(*this == rhs);
}
// retrieve the element refers to
template <typename T>
T& List<T>::const_iterator::retrieve() const
{
	return current->data;
}
// protected constructor
template <typename T>
List<T>::iterator::iterator(Node *p):const_iterator{p}
{
}
// operator*() to return element
template <typename T>
T& List<T>::iterator::operator* ()
{
	return const_iterator::retrieve();
}
template <typename T>
const T& List<T>::iterator::operator* () const
{
	return const_iterator::operator*();
}
// increment/decrement operators
template <typename T>
typename List<T>::iterator& List<T>::iterator::operator++ ()
{
	this->current = this->current->next;
	return *this;
}
template <typename T>
typename List<T>::iterator List<T>::iterator::operator++ (int)
{
	iterator old = *this;
	++(*this);
	return old;
}
template <typename T>
typename List<T>::iterator& List<T>::iterator::operator-- ()
{
	this->current = this->current->prev;
	return *this;
}
template <typename T>
typename List<T>::iterator List<T>::iterator::operator-- (int)
{
	iterator old = *this;
	--(*this);
	return old;
}
// default zero parameter constructor
template <typename T>
List<T>::List()
{
	init();
}
// destructor
template <typename T>
List<T>::~List()
{
	clear();
	delete head;
	delete tail;
}
// copy constructor
template <typename T>
List<T>::List(const List& rhs)
{
	init();
	for(auto & x : rhs)
		push_back(x);
}
// copy assignment operator
template <typename T>
const List<T>& List<T>::operator=(const List& rhs)
{
	List copy = rhs;
	swap(*this, copy);
	return *this;
}
// move constructor
template <typename T>
List<T>::List(List && rhs)
{
	theSize = move(rhs.theSize);
	head = rhs.head;
	tail = rhs.tail;
	rhs.theSize = 0;
	rhs.head = nullptr;
	rhs.tail = nullptr;
}
// move assignment operator
template <typename T>
List<T>& List<T>::operator=(List && rhs)
{
	swap(theSize, rhs.theSize);
	swap(head, rhs.head);
	swap(tail, rhs.tail);
	return *this;
}
// num elements with value of val
template <typename T>
List<T>::List(int num, const T& val)
{
	init();
		
	for(int i = 0; i < num; ++i)
		push_front(val);
}
// constructs with elements [start, end)
template <typename T>
List<T>::List(const_iterator start, const_iterator end)
{
	init();
	
	for(const_iterator x = start; x != end; ++x)
		push_back(*x);
}
// MEMBER FUNCTIONS
// iterator to first element
template <typename T>
typename List<T>::iterator List<T>::begin()
{
	return iterator(head->next);
}
template <typename T>
typename List<T>::const_iterator List<T>::begin() const
{
	return const_iterator(head->next);
}
// end marker iterator
template <typename T>
typename List<T>::iterator List<T>::end()
{
	return iterator(tail);
}
template <typename T>
typename List<T>::const_iterator List<T>::end() const
{
	return const_iterator(tail);
}
// number of elements
template <typename T>
int List<T>::size() const
{
	return theSize;
}
// check if list is empty
template <typename T>
bool List<T>::empty() const
{
	return size() == 0;
}
// delete all elements
template <typename T>
void List<T>::clear()
{
	while(!empty())
		pop_front();
}
// reverse the order of the elements
template <typename T>
void List<T>::reverse()
{
	Node *temp;
	Node *p = head;
	tail = head;

	while(p != NULL)
	{
		temp = p->next;
		p->next = p->prev;
		p->prev = temp;
		if(p->prev == NULL)
			head = p;
		p = p->prev;
	}
}
// reference to the first element
template <typename T>
T& List<T>::front()
{
	return *begin();
}
template <typename T>
const T& List<T>::front() const
{
	return *begin();
}
// reference to the last element
template <typename T>
T& List<T>::back()
{
	return *--end();
}
template <typename T>
const T& List<T>::back() const
{
	return *--end();
}
// insert to the beginning
template <typename T>
void List<T>::push_front(const T& val)
{
	insert(begin(), val);
}
// move version of insert
template <typename T>
void List<T>::push_front(T && val)
{
	insert(begin(), move(val));
}
// insert to the end
template <typename T>
void List<T>::push_back(const T& val)
{
	insert(end(), val);
}
// move version of insert
template <typename T>
void List<T>::push_back(T && val)
{
	insert(end(), move(val));
}
// delete first element
template <typename T>
void List<T>::pop_front()
{
	erase(begin());
}
// delete last element
template <typename T>
void List<T>::pop_back()
{
	erase(--end());
}
// remove all elements with value = val
template <typename T>
void List<T>::remove(const T& val)
{
	for(iterator itr = begin(); itr != end();)
		{
			if(*itr == val)
				itr = erase(itr);
			else
				++itr;
		}
}
// print out all elements. ofc is deliminitor
template <typename T>
void List<T>::print(std::ostream& os, char ofc) const
{
	for(const_iterator itr = begin(); itr != end(); ++itr)
		os << *itr << ofc;
}
// insert val ahead of itr
template <typename T>
typename List<T>::iterator List<T>::insert(iterator itr, const T& val)
{
	Node *p = itr.current;
	++theSize;
	return iterator(p->prev = p->prev->next = new Node(val, p->prev, p));
}
// move version of insert
template <typename T>
typename List<T>::iterator List<T>::insert(iterator itr, T && val)
{
	Node *p = itr.current;
	++theSize;
	return iterator(p->prev = p->prev->next = new Node(move(val), p->prev, p));
}
// erase one element
template <typename T>
typename List<T>::iterator List<T>::erase(iterator itr)
{
	Node *p = itr.current;
	iterator retVal(p->next);
	p->prev->next = p->next;
	p->next->prev = p->prev;
	delete p;
	--theSize;
	return retVal;
}
// erase [start, end)
template <typename T>
typename List<T>::iterator List<T>::erase(iterator start, iterator end)
{
	for(iterator itr = start; itr != end;)
		itr = erase(itr);
	
	return end;
}
template <typename T>
void List<T>::init()
{
	theSize = 0;
	head = new Node;
	tail = new Node;
	head->next = tail;
	tail->prev = head;
}
// overloading comparison operators
template <typename T>
bool operator==(const List<T>& lhs, const List<T>& rhs)
{
	if(lhs.size() == rhs.size())
	{
		typename List<T>::const_iterator itr = rhs.begin();
		
		for(typename List<T>::const_iterator x = lhs.begin(); x != lhs.end(); ++x)
		{
			if(*itr != *x)
				return false;
			++itr;
		}
		
		return true;
	}
	
	return false;
}
template <typename T>
bool operator!=(const List<T>& lhs, const List<T>& rhs)
{
	return !(lhs == rhs);
}
// overloading output operator
template <typename T>
ostream& operator<<(ostream& os, const List<T>& l)
{
	l.print(os);
	return os;
}
