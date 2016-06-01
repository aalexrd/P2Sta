#pragma once
#ifndef Stack_H
#define Stack_H
#include "Node.h"

template <class NODETYPE>
class Stack
{
public:
	Stack();
	~Stack();
	bool empty() const; // Test whether container is empty
	Node<NODETYPE>* top(); // Access next element
	void push(NODETYPE& item); // Insert element
	void pop(); // Remove top element
	int size() const; // Return size
protected:
	Node<NODETYPE>* topNode; // The top of the Stack
	static Node<NODETYPE>* getNewNode(NODETYPE& data);
	int stackSize; // Number of elements
};
#endif
