#pragma once
#include <iostream>
using namespace std;

template <class G>
class List
{
protected:
	G* Arr;
	int maxSize;
	int currentSize;
public:
	List();
	List(const List<G>&);
	virtual ~List();
	virtual void addElement(const G&) = 0;
	virtual G removeElement() = 0;
};

template<class G>
List<G>::List()
{
	this->maxSize = 1;
	this->currentSize = 0;
	Arr = new G[maxSize];
	for (int i = 0; i < maxSize; ++i)
	{
		Arr[i] = {};
	}
}

template<class G>
List<G>::List(const List<G>& obj)
{
	if (Arr != nullptr)
	{
		delete[] Arr;
		Arr = nullptr;
	}
	Arr = new G[obj.maxSize];
	this->maxSize = obj.maxSize;
	this->currentSize = obj.currentSize;
	for (int i = 0; i < currentSize; ++i)
	{
		this->Arr[i] = obj.Arr[i];
	}
}

template<class G>
List<G>::~List()
{
	if (Arr != nullptr)
	{
		delete[] Arr;
		Arr = nullptr;
	}
}