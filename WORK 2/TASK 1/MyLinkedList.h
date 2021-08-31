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
	void sortInAscendingOrder();
	void sortInDescendingOrder();
	bool deleteTheValue(const G&);
	int searchPosition(const G&)const;
	void displayFromHead()const;
	bool isPalindrome();
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
	NodeJS<G>* newNode = new NodeJS<G>();
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
		NodeJS<G>* newNode = LinkedList<G>::head;
		LinkedList<G>::head = LinkedList<G>::head->next;
		delete[] newNode;
		newNode = nullptr;
	}
	return value;
}

template<class G>
void MyLinkedList<G>::insertAtTail(const G& value)
{
	NodeJS<G>* newNode = new NodeJS<G>();
	newNode->data = value;
	newNode->next = nullptr;

	if (LinkedList<G>::head == nullptr)
	{
		LinkedList<G>::head = newNode;
	}
	else
	{
		NodeJS<G>* anotherNewNode = LinkedList<G>::head;
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
		NodeJS<G>* newNode = LinkedList<G>::head;
		while (1)
		{
			if (newNode->next->next == nullptr)
			{
				value = newNode->next->data;
				NodeJS<G>* anotherNewNode = newNode->next;
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
void MyLinkedList<G>::sortInAscendingOrder()
{
	if (LinkedList<G>::head == nullptr)
	{
		cout << "\nLinked List is Empty.\n";
	}
	else if (LinkedList<G>::head->next == nullptr)
	{
		cout << "\nOnly 1 Node Exists.\n";
	}
	else
	{
		NodeJS<G>* newNode = LinkedList<G>::head;
		for (newNode; newNode->next != nullptr; newNode = newNode->next)
		{
			for (NodeJS<G>* anotherNewNode = newNode->next; anotherNewNode != nullptr; anotherNewNode = anotherNewNode->next)
			{
				if (newNode->data > anotherNewNode->data)
				{
					newNode->data = newNode->data + anotherNewNode->data;
					anotherNewNode->data = newNode->data - anotherNewNode->data;
					newNode->data = newNode->data - anotherNewNode->data;
				}
			}
		}
	}
}

template<class G>
void MyLinkedList<G>::sortInDescendingOrder()
{
	if (LinkedList<G>::head == nullptr)
	{
		cout << "\nLinked List is Empty.\n";
	}
	else if (LinkedList<G>::head->next == nullptr)
	{
		cout << "\nOnly 1 Node Exists.\n";
	}
	else
	{
		NodeJS<G>* newNode = LinkedList<G>::head;
		for (newNode; newNode->next != nullptr; newNode = newNode->next)
		{
			for (NodeJS<G>* anotherNewNode = newNode->next; anotherNewNode != nullptr; anotherNewNode = anotherNewNode->next)
			{
				if (newNode->data < anotherNewNode->data)
				{
					newNode->data = newNode->data + anotherNewNode->data;
					anotherNewNode->data = newNode->data - anotherNewNode->data;
					newNode->data = newNode->data - anotherNewNode->data;
				}
			}
		}
	}
}

template<class G>
bool MyLinkedList<G>::deleteTheValue(const G& value)
{
	if (LinkedList<G>::head == nullptr)
	{
		cout << "Linked List is Empty.\n";
	}
	else if (LinkedList<G>::head->data == value)
	{
		deleteFromHead();
		return true;
	}
	else
	{
		NodeJS <G>* newNode = LinkedList<G>::head;
		for (newNode; newNode->next != nullptr; newNode = newNode->next)
		{
			if (newNode->next->data == value)
			{
				NodeJS<G>* anotherNewNode = newNode->next;
				newNode->next = newNode->next->next;
				delete[] anotherNewNode;
				anotherNewNode = nullptr;
				return true;
			}
		}
	}
	return false;
}

template<class G>
int MyLinkedList<G>::searchPosition(const G& value) const
{
	if (LinkedList<G>::head == nullptr)
	{
		cout << "Linked List is Empty.\n";
		return -1;
	}
	else
	{
		NodeJS <G>* newNode = LinkedList<G>::head;
		int index = 0;
		for (newNode; newNode !=nullptr; newNode = newNode->next)
		{
			++index;
			if (newNode->data == value)
			{
				return index;
			}
		}
	}
	return -1;
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
		NodeJS<G>* newNode = LinkedList<G>::head;
		for (newNode; newNode != nullptr; newNode = newNode->next, ++i)
		{
			cout << i << ". " << newNode->data << endl;
		}
		cout << endl;
	}
}

template<class G>
bool MyLinkedList<G>::isPalindrome()
{
	if (LinkedList<G>::head == nullptr)
	{
		return false;
	}
	else if (LinkedList<G>::head->next == nullptr)
	{
		return true;
	}

	NodeJS<G>* newNode = LinkedList<G>::head;
	int size = 0;
	while (newNode != nullptr)
	{
		++size;
		newNode = newNode->next;
	}
	
	NodeJS<G>* newNode1 = nullptr;
	
	int size1 = {};
	int size2 = {};

	for (int i = 0; i <= size / 2; ++i)
	{
		size1 = i;
		size2 = size - i - 1;
		newNode = LinkedList<G>::head;
		newNode1 = LinkedList<G>::head;

		while (size1 != 0)
		{
			size1 -= 1;
			newNode = newNode->next;
		}

		while (size2 != 0)
		{
			size2 -= 1;
			newNode1 = newNode1->next;
		}

		if (newNode->data != newNode1->data)
		{
			return false;
		}
	}
	return true;
}