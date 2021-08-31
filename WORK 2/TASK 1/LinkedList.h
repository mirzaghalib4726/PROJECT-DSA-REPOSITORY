#pragma once
#include "NodeJS.h"
#include <iostream>
using namespace std;

template <class G>
class LinkedList
{
protected:
	NodeJS<G>*  head;
public:
	LinkedList();
	virtual ~LinkedList();
	virtual void insertAtHead(const G&) = 0;
	virtual G deleteFromHead() = 0;
	virtual void insertAtTail(const G&) = 0;
	virtual G deleteFromTail() = 0;
	virtual bool isEmpty()const = 0;
	virtual void sortInAscendingOrder() = 0;
	virtual void sortInDescendingOrder() = 0;
	virtual bool deleteTheValue(const G&) = 0;
	virtual int searchPosition(const G&)const = 0;
	virtual void displayFromHead()const = 0;
	virtual bool isPalindrome() = 0;
};

template<class G>
LinkedList<G>::LinkedList()
{
	head = nullptr;
}

template<class G>
LinkedList<G>::~LinkedList()
{

}