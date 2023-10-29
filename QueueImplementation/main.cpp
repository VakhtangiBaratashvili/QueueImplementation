#include "Queue.h"
#include <iostream>

using namespace std;

int main() {
    Queue<int> intQueue;

    // Testing push and display
    intQueue.enqueue(10);
    intQueue.enqueue(20);
    intQueue.enqueue(30);
    cout << "Queue: " << intQueue;

    // Testing front and back
    cout << "Front element: " << intQueue.front() << endl;
    cout << "Back element: " << intQueue.back() << endl;

    // Testing pop
    intQueue.dequeue();
    cout << "Queue after pop: " << intQueue;

    // Testing copy constructor and assignment operator
    Queue<int> copiedQueue(intQueue);
    cout << "Copied queue: " << copiedQueue;
    Queue<int> assignedQueue = intQueue;
    cout << "Assigned queue: " << assignedQueue;

    return 0;
}
