#pragma once
#include "LinkedList.h"
template <class G>
class MyCircularLinkedList : public LinkedList<G>
{
public:
	MyCircularLinkedList();
	~MyCircularLinkedList();
	 void insertAtFront(const G&);
	 G removeFromFront();
	 void insertAtEnd(const G&);
	 G removeFromEnd();
	 bool empty()const;
	 int size()const;
	 G front()const;
	 G back()const;
	 void push(const G&);
	 G pop();
	 void enQueue(const G&);
	 G deQueue();
	 void displayFromHead()const;
};

template<class G>
MyCircularLinkedList<G>::MyCircularLinkedList():LinkedList<G>()
{
	//
}

template<class G>
MyCircularLinkedList<G>::~MyCircularLinkedList()
{
	//
}

template<class G>
void MyCircularLinkedList<G>::insertAtFront(const G& value)
{
	Node<G>* newNode = new Node<G>();
	newNode->data = value;
	newNode->next = nullptr;

	if (LinkedList<G>::head == nullptr && LinkedList<G>::tail == nullptr)
	{
		LinkedList<G>::head = newNode;
		LinkedList<G>::tail = newNode;
		LinkedList<G>::tail->next = LinkedList<G>::head;
	}
	else
	{
		newNode->next = LinkedList<G>::head;
		LinkedList<G>::head = newNode;
	}
}

template<class G>
G MyCircularLinkedList<G>::removeFromFront()
{
	G value = {};
	if (LinkedList<G>::head == nullptr && LinkedList<G>::tail == nullptr)
	{
		cout << "Linked List is Empty.\n";
	}
	else if (LinkedList<G>::head == LinkedList<G>::tail)
	{
		value = LinkedList<G>::head->data;
		delete[] LinkedList<G>::head;
		LinkedList<G>::head = nullptr;
		LinkedList<G>::tail = nullptr;
	}
	else
	{
		value = LinkedList<G>::head->data;
		Node<G>* newNode = LinkedList<G>::head;
		LinkedList<G>::head = LinkedList<G>::head->next;
		delete[] newNode;
		newNode = nullptr;
		LinkedList<G>::tail->next = LinkedList<G>::head;
	}
	return value;
}

template<class G>
void MyCircularLinkedList<G>::insertAtEnd(const G& value)
{
	Node<G>* newNode = new Node<G>();
	newNode->data = value;
	newNode->next = nullptr;

	if (LinkedList<G>::head == nullptr && LinkedList<G>::tail == nullptr)
	{
		LinkedList<G>::head = newNode;
		LinkedList<G>::tail = newNode;
		LinkedList<G>::tail->next = LinkedList<G>::head;
	}
	else
	{
		LinkedList<G>::tail->next = newNode;
		LinkedList<G>::tail = newNode;
		LinkedList<G>::tail->next = LinkedList<G>::head;
	}
}

template<class G>
G MyCircularLinkedList<G>::removeFromEnd()
{
	G value = {};
	if (LinkedList<G>::head == nullptr && LinkedList<G>::tail == nullptr)
	{
		cout << "Linked List is Empty.\n";
	}
	else if (LinkedList<G>::head == LinkedList<G>::tail)
	{
		value = LinkedList<G>::head->data;
		delete[] LinkedList<G>::head;
		LinkedList<G>::head = nullptr;
		LinkedList<G>::tail = nullptr;
	}
	else
	{
		Node<G>* newNode = LinkedList<G>::head;
		while (1)
		{
			if (newNode->next == LinkedList<G>::tail)
			{
				value = newNode->next->data;
				delete[] LinkedList<G>::tail;
				LinkedList<G>::tail = nullptr;
				LinkedList<G>::tail = newNode;
				LinkedList<G>::tail->next = LinkedList<G>::head;
				break;
			}
			else
			{
				newNode = newNode->next;
			}
		}
	}
	return value;
}

template<class G>
bool MyCircularLinkedList<G>::empty() const
{
	if (LinkedList<G>::head == nullptr && LinkedList<G>::tail == nullptr)
	{
		return true;
	}
	return false;
}

template<class G>
 int MyCircularLinkedList<G>::size() const
{
	int count = {};
	Node<G>* newNode = LinkedList<G>::head;
	
	while (true)
	{
		if (newNode->next != LinkedList<G>::head)
		{
			++count;
		}
		else
		{
			++count;
			return count;
		}

		newNode = newNode->next;
	}
}

template<class G>
 G MyCircularLinkedList<G>::front() const
{
	 if (LinkedList<G>::head != nullptr)
	 {
		 return LinkedList<G>::head->data;
	 }
	 return G();
}

template<class G>
 G MyCircularLinkedList<G>::back() const
{
	 if (LinkedList<G>::tail != nullptr)
	 {
		 return LinkedList<G>::tail->data;
	 }
	 return G();
}

 template<class G>
  void MyCircularLinkedList<G>::push(const G& value)
 {
	  insertAtEnd(value);
 }

 template<class G>
  G MyCircularLinkedList<G>::pop()
 {
	 return removeFromEnd();
 }

 template<class G>
  void MyCircularLinkedList<G>::enQueue(const G& value)
 {
	  insertAtEnd(value);
 }

 template<class G>
  G MyCircularLinkedList<G>::deQueue()
 {
	 return removeFromFront();
 }

template<class G>
void MyCircularLinkedList<G>::displayFromHead() const
{
	if (LinkedList<G>::head == nullptr && LinkedList<G>::tail == nullptr)
	{
		cout << "\nEmpty.\n\n";
	}
	else
	{
		int i = {};
		Node<G>* newNode = LinkedList<G>::head;

		cout << "\nData <>\n";
		for (newNode; newNode->next != LinkedList<G>::head; newNode = newNode->next, ++i)
		{
			cout << i << ". " << newNode->data << endl;
		}
		cout << i << ". " << newNode->data << endl;
		cout << endl;
	}
}