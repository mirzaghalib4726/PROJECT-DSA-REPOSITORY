#include "Stack.h"

using namespace std;

template <class Gen>
class Queue
{
private:
    Stack<Gen> A;
public:
    Queue(const int& size = 0) :A(size)
    {
        //All Done
    }
    void enQueue(const Gen& value)
    {
        Stack<Gen> B(A.getMaxSize());

        while (!A.empty())
        {
            B.push(A.top());
            A.pop();
        }

        // Push value into A
        A.push(value);

        // Push everything back to A
        while (!B.empty()) 
        {
            A.push(B.top());
            B.pop();
        }
    }

    // Dequeue an item from the queue
    Gen deQueue()
    {
        // if first stack is empty
        if (A.empty())
        {
            cout << "Queue is Empty";
            exit(0);
        }

        // Return top of s1
        Gen Z = A.top();
        A.pop();
        
        return Z;
    }

    void displayQueue()const
    {
        A.display();
    }
};