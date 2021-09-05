#include "Queue.h"

template<class G> 
Queue <G> reverseQueue(Queue <G>& obj)
{
	int size = obj.size();
	Queue <G> Reverse;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < obj.size() - 1; j++)
		{
			obj.enqueue(obj.dequeue());
		}
		Reverse.enqueue(obj.dequeue());
	}
	return Reverse;
}

int main()
{
	cout << "\n\n---------- Best of Luck for the Exam ---------\n\n";
	Queue<char> q1;
	q1.enqueue('D');
	q1.enqueue('S');
	q1.enqueue('A');
	q1.enqueue(' ');
	q1.enqueue('L');
	q1.enqueue('A');
	q1.enqueue('B');
	q1.display();

	Queue<char> reverseQ1 = reverseQueue(q1);
	reverseQ1.display();

	return 0;
}