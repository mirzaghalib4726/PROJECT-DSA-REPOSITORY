#pragma once
#include "QueueADT.h"

template <class Gen>
class CircularQueue : public QueueADT<Gen>
{
protected:
	int front;
	int rear;
public:
	CircularQueue() : QueueADT<Gen>()
	{
		//cout << "Circular Queue Default\n";
		front = 0;
		rear = 0;
	}
	CircularQueue(const int& size) : QueueADT<Gen>(size)
	{
		//cout << " Circular Queue Parameterized\n";
		front = 0;
		rear = 0;
	}
	CircularQueue(const CircularQueue<Gen>& obj) : QueueADT<Gen>(obj)
	{
		//cout << "Circular Queue Copy\n";
		this->front = obj.front;
		this->rear = obj.rear;
	}
	~CircularQueue()
	{
		//Nothing to Do
	}
	void enqueue(Gen value)   //O(1)  ---> As the Queue is Circular, we can come from the last index of the Array to the First Index of the Array, so there is no need for the O(n) --> rear has the location of last element so we can use it to add the next element
	{
		if (!full())
		{
			QueueADT<Gen>::Arr[rear % QueueADT<Gen>::maxSize] = value;
			++rear;
			++QueueADT<Gen>::currentSize;
		}
		else
		{
			cout << "Quene is Full\n";
		}
	}
	Gen dequeue()    //O(1)  ---> As the Queue is Circular, we can come from the last index of the Array to the First Index of the Array, so there is no need for the O(n) --> front has the location of first element so we can use it to remove the element
	{
		if (!empty())
		{
			Gen T = QueueADT<Gen>::Arr[front % QueueADT<Gen>::maxSize];
			++front;
			--QueueADT<Gen>::currentSize;
			return T;
		}
		else
		{
			cout << "Quene is Empty\n";
			cout << "Returning Garbage.\n";
			Gen T = {};
			return T;
		}
	}
	void displayCQ()const
	{
		cout << "CurrentSize: " << QueueADT<Gen>::currentSize << endl;
		cout << "MaxSize: " << QueueADT<Gen>::maxSize << endl;
		cout << "Front: " << front << endl;
		cout << "Rear: " << rear << endl;

		cout << "\nCircular Queue <>\n";
		for (int i = front; i < rear; ++i)
		{
			cout << i % QueueADT<Gen>::maxSize << ". " << QueueADT<Gen>::Arr[i% QueueADT<Gen>::maxSize] << endl;
		}
		cout << endl << endl;
	}
	bool full()const
	{
		if (QueueADT<Gen>::currentSize == QueueADT<Gen>::maxSize)
		{
			return true;
		}
		return false;
	}
	bool empty()const
	{
		if (QueueADT<Gen>::currentSize == 0)
		{
			return true;
		}
		return false;
	}
	int size()const
	{
		return QueueADT<Gen>::getCurrentSize();
	}
	Gen frontElement()const // O(1) we can access the front element using front
	{
		return QueueADT<Gen>::Arr[front % QueueADT<Gen>::maxSize];
	}
	Gen rearElement()const // O(1) we can access the rear element using rear
	{
		return QueueADT<Gen>::Arr[(rear - 1) % QueueADT<Gen>::maxSize];
	}
};