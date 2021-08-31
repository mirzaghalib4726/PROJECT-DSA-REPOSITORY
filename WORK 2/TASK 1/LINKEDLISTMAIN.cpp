#include "MyLinkedList.h"

int main(void)
{
	MyLinkedList<char> A;
	A.insertAtTail('m');
	A.insertAtTail('a');
	A.insertAtTail('h');
	A.insertAtTail('a');
	A.insertAtTail('m');

	//level
	//civic
	A.displayFromHead();
	if (A.isPalindrome())
	{
		cout << "Yeah\n\n";
	}
	else
	{
		cout << "Oh No\n\n";
	}

	MyLinkedList<char> B;
	B.insertAtTail('r');
	B.insertAtTail('e');
	B.insertAtTail('d');
	B.insertAtTail('i');
	B.insertAtTail('v');
	B.insertAtTail('i');
	B.insertAtTail('d');
	B.insertAtTail('e');
	B.insertAtTail('r');

	B.displayFromHead();
	if (B.isPalindrome())
	{
		cout << "\nYeah\n\n";
	}
	else
	{
		cout << "\nOh No\n\n";
	}

	MyLinkedList<char> C;
	C.insertAtTail('A');

	C.displayFromHead();
	if (C.isPalindrome())
	{
		cout << "\nYeah\n\n";
	}
	else
	{
		cout << "\nOh No\n\n";
	}

	MyLinkedList<char> D;

	D.displayFromHead();
	if (D.isPalindrome())
	{
		cout << "\nYeah\n\n";
	}
	else
	{
		cout << "\nOh No\n\n";
	}

	MyLinkedList<int> E;
	E.insertAtTail(1);
	E.insertAtTail(2);
	E.insertAtTail(2);
	E.insertAtTail(1);

	E.displayFromHead();
	if (E.isPalindrome())
	{
		cout << "\nYeah\n\n";
	}
	else
	{
		cout << "\nOh No\n\n";
	}

	MyLinkedList<int> F;
	F.insertAtTail(1);
	F.insertAtTail(2);

	F.displayFromHead();
	if (F.isPalindrome())
	{
		cout << "\nYeah\n\n";
	}
	else
	{
		cout << "\nOh No\n\n";
	}
	return 0;
}