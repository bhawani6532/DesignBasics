#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;
struct ListNode {
    int value;
    ListNode* next;
};

class LinkedList
{
public:
    LinkedList();
    LinkedList(int data);
    ~LinkedList();

    void insertData(int data, string placeData = "rear");      //done
    void remove(int data);                  //done
    bool isDataExist(int data) const;       //done
    int largestData() const;                //done
    void printList() const;                 //done
    void reverseList();                     //done
    void sortListBySelectionSort();         //done
    void sortListByMergeSort();             //done
    ListNode* getFront() const;             //done
    void clear();                           //done
    bool isEmpty();                         //done
    void sortListBySelectionSort(bool blnSwapNode);          //done


private:
    ListNode* front;

    ListNode* createListNode(int data);
    void remove(ListNode* & node, int data);
    void printList(ListNode* node) const;
    bool isDataExist(ListNode* node, int data) const;
    int largestData(ListNode* node) const;
    void reverseList(ListNode*& node);
    //void sortListBySelectionSort(ListNode* node);
    void clear(ListNode* node);
};

    //overloaded operators
ostream& operator <<(ostream& out, const LinkedList & list);

#endif // LINKEDLIST_H
