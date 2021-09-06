#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

template <class G>
class LinkedList
{
protected:
	Node<G>*  head;
	Node<G>* tail;
public:
	LinkedList();
	virtual ~LinkedList();
	virtual void insertAtFront(const G&) = 0;
	virtual G removeFromFront() = 0;
	virtual void insertAtEnd(const G&) = 0;
	virtual G removeFromEnd() = 0;
	virtual bool empty()const = 0;
	virtual int size()const = 0;
	virtual G front()const = 0;
	virtual G back()const = 0;
	virtual void displayFromHead()const = 0;
};

template<class G>
LinkedList<G>::LinkedList()
{
	head = nullptr;
	tail = nullptr;
}

template<class G>
LinkedList<G>::~LinkedList()
{
	if (head == nullptr && tail == nullptr)
	{
		return;
	}

	Node<G>* A = head;
	while (true)
	{
		head = head->next;

		delete[] A;
		A = nullptr;
		A = head;
		
		if (A == tail)
		{
			delete[] A;
			A = nullptr;
			break;
		}
	}
}