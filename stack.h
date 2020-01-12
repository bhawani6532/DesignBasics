#ifndef STACK_H
#define STACK_H
#define MAX_DATA 1000
#include <iostream>
using namespace std;

class Stack
{
public:
    Stack();
    int peek();
    int pop();
    void pushData(int data);
    void printData();
    bool isEmpty() const;

private:
    int * arrData;
    int top;
    int myCapacity;

    void stackfull();
};

ostream& operator <<(ostream& out,Stack & stack);

#endif // STACK_H
