#include "Queue.h"

int main(void)
{
    Queue<int> A(20);

    A.enQueue(1);
    A.enQueue(2);
    A.enQueue(3);

    A.displayQueue();

    cout << "\nDeQueue: " << A.deQueue() << "\n\n";
    
    cout << "DeQueue: "<< A.deQueue() << "\n\n";
    
    cout << "DeQueue: "<< A.deQueue() << "\n\n";

    return 0;
}