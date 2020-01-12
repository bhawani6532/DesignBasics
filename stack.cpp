#include "stack.h"

Stack::Stack()
{
    top = -1;
    arrData = new int[MAX_DATA];
    myCapacity = MAX_DATA;
}

int Stack::peek() {
    if(top == -1) {
        throw("Stack is empty ");
    }
    return arrData[top];
}

int Stack::pop() {
    if(top == -1) {
        throw("Stack is empty ");
    }
    return arrData[top--];
}

void Stack::pushData(int data) {
    if(top == myCapacity) {
        cout<<"Stack is full. So creating new array for the stack";
        stackfull();
    }
     arrData[++top] = data;
}

void Stack::printData() {
    for(int i = 0; i<=top;i++) {
        cout<<arrData[i]<<" ";
    }
}

bool Stack::isEmpty() const{
    if(top==-1)
        return true;
    return false;
}

void Stack::stackfull() {
    int * arrayNew = new int[2*myCapacity];
    for(int i = 0;i<myCapacity;i++) {
        arrayNew[i] = arrData[i];
    }
    delete arrData;
    arrData = arrayNew;
    myCapacity = 2*myCapacity;
}
