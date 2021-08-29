#include <iostream>
#include "CircularQueue.h"

using namespace std;

int main(void)
{
	CircularQueue<int> A(10);

	A.enqueue(4);
	A.enqueue(8);
	A.enqueue(12);
	A.enqueue(16);
	A.displayCQ();

	A.dequeue();
	A.displayCQ();

	if(A.empty())
	{
		cout << "\nCircular Queue is Empty\n";
	}
	else
	{
	cout << "\nCircular Queue is not Empty\n";
	}

	if (A.full())
	{
		cout << "\nCircular Queue is Full\n";
	}
	else
	{
		cout << "\nCircular Queue is not Full\n";
	}

	cout << "\nFront Element: " << A.frontElement() << endl;

	cout << "\nRear Element: " << A.rearElement() << endl;

	return 0;
}