#include "List.h"

template <class G>
class Queue: public List<G>
{
public:
	Queue();
	Queue(const Queue<G>&);
	~Queue();
	void addElement(const G&);
	G removeElement();
	bool empty()const;
	bool full()const;
	int size()const;
	G front()const;
	void enqueue(const G&);
	G dequeue();
	void display()const;
};

template<class G>
Queue<G>::Queue():List<G>()
{
	//
}

template<class G>
Queue<G>::Queue(const Queue<G>& obj):List<G>(obj)
{
	//
}

template<class G>
Queue<G>::~Queue()
{
	//Virtual Destructor would be called first
}

template<class G>
void Queue<G>::addElement(const G& value)
{
	if (List<G>::currentSize < List<G>::maxSize)
	{
		List<G>::Arr[List<G>::currentSize++] = value;
	}
	else
	{
		G* newArray = new G[List<G>::maxSize + 1];
		for (int i = 0; i < List<G>::maxSize; i++)
		{
			newArray[i] = List<G>::Arr[i];
		}
		
		newArray[List<G>::currentSize++] = value;

		delete[] List<G>::Arr;
		List<G>::Arr = nullptr;

		List<G>::Arr = newArray;
		
		++List<G>::maxSize;
	}
}

template<class G>
G Queue<G>::removeElement()
{
	if (List<G>::currentSize > 0)
	{
		G A = List<G>::Arr[0];
		for (int i = 0; i < List<G>::currentSize - 1; i++)
		{
			List<G>::Arr[i] = List<G>::Arr[i + 1];
		}
		--List<G>::currentSize;
		return A;
	}
	else
	{
		cout << "Queue is Empty.\n";
		G Z = {};
		return Z;
	}
}

template<class G>
bool Queue<G>::empty() const
{
	if (List<G>::currentSize == 0)
	{
		return true;
	}
	return false;
}

template<class G>
bool Queue<G>::full() const
{
	if (List<G>::currentSize == List<G>::maxSize)
	{
		return true;
	}
	return false;
}

template<class G>
int Queue<G>::size() const
{
	return List<G>::currentSize;
}

template<class G>
G Queue<G>::front() const
{
	if (List<G>::currentSize != 0)
	{
		return List<G>::Arr[0];
	}
	G A = {};
	return A;
}

template<class G>
void Queue<G>::enqueue(const G& value)
{
	addElement(value);
}

template<class G>
G Queue<G>::dequeue()
{
	return removeElement();
}

template<class G>
void Queue<G>::display() const
{
	if (Queue<G>::currentSize == 0)
	{
		cout << "\nQueue is Empty\n";
		return;
	}

	cout << "\nQueue Elements are:\n";
	for (int i = 0; i < List<G>::currentSize; i++)
	{
		cout << i << ". " << List<G>::Arr[i] << endl;
	}
	cout << endl;
}