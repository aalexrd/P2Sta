#include "Stack.h"


template <class NODETYPE>
Stack<NODETYPE>::Stack() : topNode(nullptr), stackSize(0)
{
}

template <class NODETYPE>
Stack<NODETYPE>::~Stack()
{
	if (!empty())
	{
		Node<NODETYPE> *actualPtr = topNode, *tempPtr;
		while (actualPtr)
		{
			tempPtr = actualPtr;
			actualPtr = actualPtr->getNextPtr();
			delete tempPtr;
		}
	}
}

template <class NODETYPE>
bool Stack<NODETYPE>::empty() const
{
	return topNode == nullptr;
}

template <class NODETYPE>
Node<NODETYPE>* Stack<NODETYPE>::top()
{
	Node<NODETYPE>* newPtr = new Node<NODETYPE>;
	char* csrc = reinterpret_cast<char *>(topNode);
	char* cdest = reinterpret_cast<char *>(newPtr);
	for (int i = 0; i < sizeof(topNode); i++)
		cdest[i] = csrc[i];
	pop();
	return newPtr;
}

template <class NODETYPE>
void Stack<NODETYPE>::push(NODETYPE& item)
{
	Node<NODETYPE>* newPtr = getNewNode(item);
	if (empty())
		topNode = newPtr;
	else
	{
		newPtr->setNextPtr(topNode);
		topNode = newPtr;
	}
	++stackSize;
}

template <class NODETYPE>
void Stack<NODETYPE>::pop()
{
	if (empty())
		return;
	Node<NODETYPE>* temp = topNode;
	topNode = topNode->getNextPtr();
	delete temp;
	--stackSize;
	if (stackSize == 0)
		topNode = nullptr;
}

template <class NODETYPE>
int Stack<NODETYPE>::size() const
{
	return stackSize;
}

template <class NODETYPE>
Node<NODETYPE>* Stack<NODETYPE>::getNewNode(NODETYPE& data)
{
	return new Node<NODETYPE>(data);
}

//force compile of this templates:
template class Stack<int>;
