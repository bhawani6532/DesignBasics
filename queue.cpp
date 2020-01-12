#include "queue.h"
#include "linkedlist.h"

Queue::Queue()
{
    front = nullptr;
    rear = nullptr;
}

void Queue::enQueue(int data) {
    if(this->front==nullptr) {
        dataQueue.insertData(data);
        this->front = dataQueue.getFront();
        this->rear = dataQueue.getFront();
    }
    else {
       dataQueue.insertData(data,"rear");
       this->rear = this->rear->next;
    }
}

int Queue::deQueue() {
    if(this->front!=nullptr) {
        int data = this->front->value;
        dataQueue.remove(data);
        this->front = dataQueue.getFront();
        if(this->front == nullptr) {
            this->rear = nullptr;
        }
        return data;
    }
    else {
        throw("There is no data in the list as Queue is empty.");
    }
}

bool Queue::isEmpty() const {
    if(this->front!=nullptr) {
        return false;
    }
    return true;
}
