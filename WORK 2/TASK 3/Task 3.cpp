#include "MyLinkedList.h"

int main(void)
{
	MyLinkedList<int> A;

	int input = {};
	
	while (true)
	{
		cout << "\nPress 1 to insert into Linked List\n";
		cout << "Press 2 to display the Linked List\n";
		cout << "Press 0 to exit from the program.\n";

		cout << "\nPlease enter your input: ";
		cin >> input;

		if (input == 1)
		{
			int value = {};
			cout << "Enter value to insert: ";
			cin >> value;
			A.insertInOrder(value);
		}
		else if (input == 2)
		{
			A.displayFromHead();
		}
		else if (input == 0)
		{
			cout << "\nProgram Exiting.\n";
			break;
		}
		else
		{
			cout << "\nWrong Input.\nTry Again.\n";
		}
	}
	return 0;
}