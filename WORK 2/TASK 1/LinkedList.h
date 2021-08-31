#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

template <class G>
class LinkedList
{
protected:
	Node<G>*  head;
public:
	LinkedList();
	virtual ~LinkedList();
	virtual void insertAtHead(const G&) = 0;
	virtual G deleteFromHead() = 0;
	virtual void insertAtTail(const G&) = 0;
	virtual G deleteFromTail() = 0;
	virtual bool isEmpty()const = 0;
	virtual void displayFromHead()const = 0;
	virtual G front()const = 0;
	virtual G rear()const = 0;
	virtual int size()const = 0;
};

template<class G>
LinkedList<G>::LinkedList()
{
	head = nullptr;
}

template<class G>
LinkedList<G>::~LinkedList()
{
	Node<G>* A = head;
	while (A != nullptr)
	{
		head = head->next;
		delete A;
		A = nullptr;
		A = head;
	}
}