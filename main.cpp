#include "linkedlist.h"
#include "stack.h"
#include "binarytreeset.h"
#include "testbacktracking.h"
#include "avltree.h"
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
using namespace std;

void BackTrackingTest();
void LinkedListTest();
void StackTest();
void BSTreeTest();
void readRandomValues();
int main()
{

    //int choice;
    //readRandomValues();
    //cout<<"Bhawani"<<endl;
    //LinkedListTest();
    //StackTest();
    BSTreeTest();
    //BackTrackingTest();
    //cin >> choice;

    //While the input entered is not an integer, prompt the user to enter an integer.
    //while(!cin)
    //{
        //cout << "That was no integer! Please enter an integer: ";
        //cin.clear();
        //cin.ignore();
        //cin >> choice;
    //}

    return 0;
}

void LinkedListTest() {

        LinkedList list(5);
        list.remove(5);
        list.insertData(1,"rear");
        list.insertData(13,"rear");
        list.insertData(15,"rear");
        list.insertData(11,"rear");
        list.insertData(105,"rear");
        list.insertData(51,"rear");
        //list.reverseList();
        //list.sortListBySelectionSort(true);
        //list.remove(11);
        cout<<list;
        cout<<endl<<"Largest number in the list: "<<list.largestData()<<endl;
        if(list.isDataExist(10)){
            cout<<"10 exists\n";
        }
        else if(list.isDataExist(15)) {
               cout<<"15 exists\n";
        }
}

void StackTest(){
    Stack stack;
    stack.pushData(12);
    stack.pushData(1);
    stack.pushData(122);
    stack.pushData(109);
    stack.pushData(52);
    stack.pushData(11);
    stack.pop();
    stack.pop();
    cout<<stack.pop()<<" "<<stack.peek()<<endl;
    stack.printData();

}

void BSTreeTest() {
    BinaryTreeSet BStree;
    BStree.insertData(30);
    BStree.insertData(70);
    BStree.insertData(-25);
    BStree.insertData(40);
    BStree.insertData(60);
    BStree.insertData(80);
    BStree.insertData(110);
    BStree.insertData(2);
    BStree.insertData(5);
    BStree.insertData(-5);
    BStree.insertData(88);
    BStree.insertData(75);
    BStree.insertData(25);
    BStree.insertData(55);
    BStree.insertData(65);
    BStree.insertData(43);
    BStree.printList_Tree();
    cout<<"-----------------------------------"<<endl;
    //BStree.mirrorTree();
    //BStree.printList_sideways();
    //BStree.printList_Tree();
    //BStree.printList_inorder();
    //BStree.printList_postorder();
    //BStree.printPairSum(55);
    //cout<<"Height of the tree = "<<BStree.getHeight()<<endl;
    BStree.clear();
}

void BackTrackingTest() {
    testBacktracking testBackTrack;
    //testBackTrack.permuteString("GOGO");
    //testBackTrack.printBinaryData(5);
    testBackTrack.readMap();
    testBackTrack.runTest();
    testBackTrack.outputMap();

    //testBackTrack.nQueenTest();
    //testBackTrack.nQueenOutputMap();

    //sleep_for(nanoseconds(1000000000));
    //testBackTrack.outputMap();
    //sleep_for(nanoseconds(100000000000));
    //testBackTrack.outputMap();
}

void readRandomValues() {
    srand(1);
}
