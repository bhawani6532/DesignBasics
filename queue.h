#ifndef QUEUE_H
#define QUEUE_H
#include "linkedlist.h"

    //Implementing Queue Data Structure with Linked List
class Queue
{
public:
    Queue();
    void enQueue(int data);
    int deQueue();
    bool isEmpty() const;

private:
    LinkedList dataQueue;
    ListNode* front;
    ListNode* rear;
};



#endif // QUEUE_H
