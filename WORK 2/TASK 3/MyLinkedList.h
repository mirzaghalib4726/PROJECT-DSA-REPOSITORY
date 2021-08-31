#pragma once
#include "LinkedList.h"
template <class G>
class MyLinkedList : public LinkedList<G>
{
public:
	MyLinkedList();
	~MyLinkedList();
	void insertAtHead(const G&);
	G deleteFromHead();
	void insertAtTail(const G&);
	G deleteFromTail();
	bool isEmpty()const;
	void displayFromHead()const;
	G front()const;
	G rear()const;
	int size()const;
	void insertInOrder(const G&);
};

template<class G>
MyLinkedList<G>::MyLinkedList():LinkedList<G>()
{
	//Nothing
}

template<class G>
MyLinkedList<G>::~MyLinkedList()
{
	//Nothing
}

template<class G>
void MyLinkedList<G>::insertAtHead(const G& value)
{
	Node<G>* newNode = new Node<G>();
	newNode->data = value;
	newNode->next = nullptr;

	if (LinkedList<G>::head == nullptr)
	{
		LinkedList<G>::head = newNode;
	}
	else
	{
		newNode->next = LinkedList<G>::head;
		LinkedList<G>::head = newNode;
	}
}

template<class G>
G MyLinkedList<G>::deleteFromHead()
{
	G value = {};
	if (LinkedList<G>::head == nullptr)
	{
		cout << "Linked List is Empty.\n";
	}
	else if (LinkedList<G>::head->next == nullptr)
	{
		value = LinkedList<G>::head->data;
		delete[] LinkedList<G>::head;
		LinkedList<G>::head = nullptr;
	}
	else
	{
		value = LinkedList<G>::head->data;
		Node<G>* newNode = LinkedList<G>::head;
		LinkedList<G>::head = LinkedList<G>::head->next;
		delete[] newNode;
		newNode = nullptr;
	}
	return value;
}

template<class G>
void MyLinkedList<G>::insertAtTail(const G& value)
{
	Node<G>* newNode = new Node<G>();
	newNode->data = value;
	newNode->next = nullptr;

	if (LinkedList<G>::head == nullptr)
	{
		LinkedList<G>::head = newNode;
	}
	else
	{
		Node<G>* anotherNewNode = LinkedList<G>::head;
		while (1)
		{
			if (anotherNewNode->next == nullptr)
			{
				anotherNewNode->next = newNode;
				break;
			}
			anotherNewNode = anotherNewNode->next;
		}
	}
}

template<class G>
G MyLinkedList<G>::deleteFromTail()
{
	G value = {};
	if (LinkedList<G>::head == nullptr)
	{
		cout << "Linked List is Empty.\n";
	}
	else if (LinkedList<G>::head->next == nullptr)
	{
		value = LinkedList<G>::head->data;
		delete[] LinkedList<G>::head;
		LinkedList<G>::head = nullptr;
	}
	else
	{
		Node<G>* newNode = LinkedList<G>::head;
		while (1)
		{
			if (newNode->next->next == nullptr)
			{
				value = newNode->next->data;
				Node<G>* anotherNewNode = newNode->next;
				newNode->next = newNode->next->next;
				delete[] anotherNewNode;
				anotherNewNode = nullptr;
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
bool MyLinkedList<G>::isEmpty() const
{
	if (LinkedList<G>::head == nullptr)
	{
		return true;
	}
	return false;
}

template<class G>
void MyLinkedList<G>::displayFromHead() const
{
	if (LinkedList<G>::head == nullptr)
	{
		cout << "Linked List is Empty.\n";
	}
	else
	{
		int i = 0;
		Node<G>* newNode = LinkedList<G>::head;
		for (newNode; newNode != nullptr; newNode = newNode->next, ++i)
		{
			cout << i << ". " << newNode->data << endl;
		}
		cout << endl;
	}
}

template<class G>
G MyLinkedList<G>::front() const
{
	Node<G>* newNode = LinkedList<G>::head;
	if (newNode != nullptr)
	{
		return newNode->data;
	}
	G A = {};
	return A;
}

template<class G>
G MyLinkedList<G>::rear() const
{
	Node<G>* newNode = LinkedList<G>::head;
	if (newNode == nullptr)
	{
		G A = {};
		return A;
	}
	while (newNode->next != nullptr)
	{
		newNode = newNode->next;
	}
	return newNode->data;
}

template<class G>
int MyLinkedList<G>::size() const
{
	int count = {};
	Node<G>* newNode = LinkedList<G>::head;
	while (newNode != nullptr)
	{
		++count;
		newNode = newNode->next;
	}
	return count;
}

template<class G>
void MyLinkedList<G>::insertInOrder(const G& value)
{
	Node<G>* newNode = new Node<G>();
	newNode->data = value;
	newNode->next = nullptr;

	if (LinkedList<G>::head == nullptr)
	{
		LinkedList<G>::head = newNode;
	}
	else
	{		
		if (value < LinkedList<G>::head->data)
		{
			insertAtHead(value);
			delete newNode;
			newNode = nullptr;
		}
		else
		{
			Node<G>* anotherNewNode = LinkedList<G>::head;
			while (true)
			{
				if (anotherNewNode->next == nullptr)
				{
					anotherNewNode->next = newNode;
					break;
				}
				else if (value <= anotherNewNode->next->data)
				{
					newNode->next = anotherNewNode->next;
					anotherNewNode->next = newNode;
					break;
				}
				

				anotherNewNode = anotherNewNode->next;
			}
		}
	}
}