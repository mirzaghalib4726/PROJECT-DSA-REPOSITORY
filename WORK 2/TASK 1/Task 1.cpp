#include "MyLinkedList.h"

int main(void)
{
	MyLinkedList<char> A;
	A.insertAtTail('r');
	A.insertAtTail('a');
	A.insertAtTail('h');
	A.insertAtTail('a');
	A.insertAtTail('m');

	A.insertAtHead('b');
	A.insertAtHead('A');

	A.displayFromHead();

	//size() – Returns the number of elements in the list.
	cout << "\nSize: " << A.size() << endl;

	//front() – Returns the value of the first element in the linked list.
	cout << "\nFront Element: " << A.front() << endl;
	
	//back() – Returns the value of the last element in the linked list.
	cout << "\nRear Element: " << A.rear() << endl;

	//removeFromFront() – Removes the first element of the linked list, and reduces size of the linked list by 1.
	cout << "\nRemove From Head\n";
	A.deleteFromHead();
	A.displayFromHead();
	
	//RemoveFromEnd() – Removes the last element of the linked list, and reduces size of the linked          list by 1.
	cout << "\nRemove From Tail\n";
	A.deleteFromTail();
	A.displayFromHead();

	//empty() – Returns whether the list is empty(1) or not(0).
	if (A.isEmpty())
	{
		cout << "\nLinked List is Empty\n";
	}
	else
	{
		cout << "\nLinked List is not Empty\n";
	}
	
	return 0;
}