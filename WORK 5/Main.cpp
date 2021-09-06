#include "MyCircularLinkedList.h"

int main(void)
{
	MyCircularLinkedList<int> A;

	int choice = {};

	while (true)
	{
		cout << "Do you want to work with Stack? Press 1\n";
		cout << "Do you want to work with Queue? Press 2\n";
		
		cout << "\nPress input your command: ";
		cin >> choice;

		if (choice != 1 && choice != 2)
		{
			cout << "\nWrong Input.\nTry Again.\n\n";
		}
		else
		{
			break;
		}
	}

	int subchoice = {};

	if (choice == 1)
	{
		while (true)
		{
			cout << "\nPress 1 to Push.\n";
			cout << "Press 2 to Pop.\n";
			cout << "Press 3 to Display Stack.\n";
			cout << "Press 0 to Exit.\n";
			
			cout << "\nPress input your command: ";
			cin >> subchoice;

			if (subchoice == 1)
			{
				int value = {};
				cout << "\nEnter value: ";
				cin >> value;
				A.push(value);
			}
			else if(subchoice == 2)
			{
				cout << "\nPop value: " << A.pop() << endl;
			}
			else if (subchoice == 3)
			{
				A.displayFromHead();
			}
			else if (subchoice == 0)
			{
				cout << "\nThank you for Using Our System.\n";
				break;
			}
			else
			{
				cout << "\nWrong Input.\nTry Again.\n\n";
			}
		}
	}
	else
	{
		while (true)
		{
			cout << "\nPress 1 to Queue.\n";
			cout << "Press 2 to DeQueue.\n";
			cout << "Press 3 to Display Queue.\n";
			cout << "Press 0 to Exit.\n";

			cout << "\nPress input your command: ";
			cin >> subchoice;

			if (subchoice == 1)
			{
				int value = {};
				cout << "\nEnter value: ";
				cin >> value;
				A.enQueue(value);
			}
			else if (subchoice == 2)
			{
				cout << "\nDeQueue value: " << A.deQueue() << endl;
			}
			else if (subchoice == 3)
			{
				A.displayFromHead();
			}
			else if (subchoice == 0)
			{
				cout << "\nThank you for Using Our System\n";
				break;
			}
			else
			{
				cout << "\nWrong Input.\nTry Again.\n\n";
			}
		}
	}
	return 0;
}