#include <iostream>
using namespace std;

#pragma once
template < class Gen>
class QueueADT
{
protected:
	Gen* Arr;
	int currentSize;
	int maxSize;
public:
	QueueADT()
	{
		this->currentSize = 0;
		this->maxSize = 0;
		this->Arr = nullptr;
	}
	QueueADT(const int& maxSize)
	{
		if (maxSize > 0)
		{
			this->currentSize = 0;
			this->maxSize = maxSize;
			this->Arr = new Gen[maxSize];
			for (int i = 0; i < maxSize; ++i)
			{
				this->Arr[i] = {};
			}
		}
	}
	QueueADT(const QueueADT<Gen>& obj)
	{
		this->currentSize = obj.currentSize;
		this->maxSize = obj.maxSize;

		this->Arr = new Gen[obj.maxSize];
		
		for (int i = 0; i < currentSize; ++i)
		{
			this->Arr[i] = obj.Arr[i];
		}
	}
	virtual ~QueueADT()
	{
		if (this->Arr != nullptr)
		{
			delete[] this->Arr;
			this->Arr = nullptr;
		}
	}
	int getCurrentSize()const
	{
		return this->currentSize;
	}
	int getMaxSize()const
	{
		return this->maxSize;
	}
	virtual void enqueue(Gen value) = 0;
	virtual Gen dequeue() = 0;
	virtual bool full()const = 0;
	virtual bool empty()const = 0;
	virtual int size()const = 0;
	virtual Gen frontElement()const = 0;
	virtual Gen rearElement()const = 0;
};