#pragma once
#include "List.h"

template<class Gen>
class Stack :	public List<Gen>
{
public:
	Stack(const int& size = 0) :List<Gen>(size)
	{
		//All done
	}
	Stack(const Stack<Gen>& obj) :List<Gen>(obj)
	{
		//All done
	}
	~Stack()
	{
		//Parent Destructor Called
	}
	void addElement(Gen value)
	{
		if (!full())
		{
			List<Gen>::Arr[List<Gen>::currentSize++] = value;
		}
		else
		{
			cout << "Quene is Full\n";
		}
	};
	Gen removeElement()
	{
		if (!empty())
		{
			return List<Gen>::Arr[--List<Gen>::currentSize];
		}
		else
		{
			cout << "Stack is Empty\n";
			cout << "Returning Garbage Value\n";
		}
		Gen T = {};
		return T;
	};
	bool empty()
	{
		if (List<Gen>::currentSize == 0)
		{
			return true;
		}
		return false;
	};
	bool full()
	{
		if (List<Gen>::currentSize == List<Gen>::maxSize)
		{
			return true;
		}
		return false;
	};
	int size()
	{
		return List<Gen>::currentSize;
	};
	Gen top()
	{
		return List<Gen>::Arr[List<Gen>::currentSize - 1];
	};
	void push(Gen value)
	{
		addElement(value);
	};
	Gen pop()
	{
		Gen T = removeElement();
		return T;
	};
	void display()const
	{
		cout << "\nCurrent Size: " << List<Gen>::currentSize << endl;
		cout << "\nMax Size: " << List<Gen>::maxSize << endl << endl;
		for (int i = 0; i < List<Gen>::currentSize; ++i)
		{
			cout << i << ". " << List<Gen>::Arr[i] << endl;
		}
	}
};