#include "CircularQueue.h"
#include <fstream>


int main(void)
{
	ifstream fin;
	CircularQueue<int> A(10);

	fin.open("Input.txt", ios::in);
	if (fin.is_open())
	{
		int numberOfQueries = {};
		fin >> numberOfQueries;
		
		int inputValue = {};
		while (numberOfQueries != 0)
		{
			
			fin >> inputValue;
			
			if (inputValue == 1)
			{
				fin >> inputValue;
				A.enqueue(inputValue);
			}
			else if (inputValue == 2)
			{
				cout << "DeQueue: " << A.dequeue() << endl << endl;
			}
			else
			{
				A.displayCQ();
			}

			--numberOfQueries;
		}
	}
	else
	{
		cout << "Input File is Corrupt.\n";
	}

	A.displayCQ();

	fin.close();

	system("pause");
	return 0;
}