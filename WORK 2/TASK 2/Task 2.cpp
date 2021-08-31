#include "MyLinkedList.h"

void StackMenu(MyLinkedList<char>& A)
{
	int input = {};
	do
	{
		cout << "\nPress 1 to insert a value\n";
		cout << "Press 2 to remove a value\n";
		cout << "Press 3 to Display the Stack\n";
		cout << "Press 0 to Exit\n";

		cout << "\nPlease enter your input: ";
		cin >> input;
		
		if (input == 1)
		{
			char inp = {};
			cout << "Enter Character: ";
			cin >> inp;
			A.insertAtTail(inp);
		}
		else if (input == 2)
		{
			A.deleteFromTail();
		}
		else if (input == 3)
		{
			A.displayFromHead();
		}
		else if (input == 0)
		{
			cout << "\nProgram Exiting\n";
		}
		else
		{
			cout << "\nWrong Input.\n Try Again.\n";
		}
	} while (true);
}

void QueueMenu(MyLinkedList<char>& A)
{
	int input = {};
	do
	{
		cout << "\nPress 1 to insert a value\n";
		cout << "Press 2 to remove a value\n";
		cout << "Press 3 to Display the Queue\n";
		cout << "Press 0 to Exit\n";

		cout << "\nPlease enter your input: ";
		cin >> input;

		if (input == 1)
		{
			char inp = {};
			cout << "Enter Character: ";
			cin >> inp;
			A.insertAtTail(inp);
		}
		else if (input == 2)
		{
			A.deleteFromHead();
		}
		else if (input == 3)
		{
			A.displayFromHead();
		}
		else if (input == 0)
		{
			cout << "\nProgram Exiting\n";
		}
		else
		{
			cout << "\nWrong Input.\n Try Again.\n";
		}
	} while (true);
}

int main(void)
{
	MyLinkedList<char> A;

	int choice = {};

	while (true)
	{
		cout << "\nDo you want to work in Stack or Queue? (1 for Stack || 2 for Queue): ";
		cin >> choice;

		if (choice == 1)
		{
			StackMenu(A);
			break;
		}
		else if (choice == 2)
		{
			QueueMenu(A);
			break;
		}
		else
		{
			cout << "\nWrong Input.\n Try Again\n";
		}
	}
	return 0;
}