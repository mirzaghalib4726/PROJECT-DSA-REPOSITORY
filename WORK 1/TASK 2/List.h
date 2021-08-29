#pragma once
#include <iostream>
using namespace std;

template <class Gen>
class List
{
protected:
	Gen* Arr;
	int currentSize;
	int maxSize;
public:
	List(const int& maxSize = 0)//default + parameterized both
	{
		if (maxSize > 0)
		{
			this->currentSize = 0;
			this->maxSize = maxSize;
			this->Arr = new Gen[maxSize];
		}
		else
		{
			this->currentSize = 0;
			this->maxSize = 0;
			this->Arr = nullptr;
		}
	}
	List(const List& obj)
	{
		this->currentSize = obj.currentSize;
		this->maxSize = obj.maxSize;
		if (this->Arr != nullptr)
		{
			delete[] this->Arr;
			this->Arr = nullptr;
		}
		this->Arr = new Gen[maxSize];
		for (int i = 0; i < currentSize; ++i)
		{
			this->Arr[i] = obj.Arr[i];
		}
	}
	virtual ~List()
	{
		if (Arr != nullptr)
		{
			delete[] this->Arr;
			this->Arr = nullptr;
		}
	}
	int getCurrentSize()
	{
		return currentSize;
	}
	int getMaxSize()
	{
		return maxSize;
	}
	Gen* getArr()
	{
		Gen* AnotherArr = new Gen[maxSize];
		for (int i = 0; i < currentSize; ++i)
		{
			AnotherArr[i] = Arr[i];
		}
		return AnotherArr;
	}
	virtual void addElement(Gen value) = 0;
	virtual Gen removeElement() = 0;
};