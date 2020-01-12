#include "linkedlist.h"

    // Constructor to initialise the front node = NULL, it means empty list
LinkedList::LinkedList() {
    front = nullptr;
}

    // Constructor to initialise the front node and add data to it.
LinkedList::LinkedList(int data) {
    front = nullptr;
    front = new ListNode();
    front->next = nullptr;
    front->value = data;
}

    // Creates a new node and insert a new data
ListNode* LinkedList::createListNode(int data) {
    ListNode* tempListNode = new ListNode();
    tempListNode->next = nullptr;
    tempListNode->value = data;
    return tempListNode;
}

    // Insert data
void LinkedList::insertData(int data, string placeData) {
    if(front == nullptr) {
        front = createListNode(data);
        return;
    }
    else if(placeData == "rear") {
        ListNode* tempListNode = front;
        while(tempListNode->next != nullptr) {
            tempListNode = tempListNode->next;
        }
        ListNode* newListNode = createListNode(data);
        tempListNode->next = newListNode;
        return;
    }
    else if (placeData == "front") {
        ListNode* newListNode = createListNode(data);
        newListNode->next = front;
        front = newListNode;
        return;
    }
    else {
        ListNode* tempListNode = front;
        while(tempListNode->value < data && tempListNode->next!= nullptr) {
            tempListNode = tempListNode->next;
        }
        if(tempListNode == front) {
            if(tempListNode->value < data) {
                insertData(data,"rear");
            }
            else {
                insertData(data,"front");
            }
        }
        else if(tempListNode->value < data && tempListNode->next == nullptr){
            insertData(data,"rear");
        }
        else {
            ListNode* tempList = front;
            while(tempList-> next != tempListNode) {
                tempList = tempList->next;
            }
           ListNode * newListNode = createListNode(data);
           newListNode->next = tempListNode;
           tempList->next = newListNode;
        }
    }
}

    //remove an element from the list and calls private function to remove an element recursively.
void LinkedList::remove(int data) {
    if(front == nullptr)
        return;
    remove(front,data);
}

    //remove an element from the list recursively.
void LinkedList::remove(ListNode* & node, int data) {
    if(node == nullptr) {
        return;
    }
    else if(node->next == nullptr && node->value == data) {
        ListNode* trash = node;
        node = nullptr;
        delete trash;
    }
    else {
        if(node->value == data) {
            ListNode* trash = node;
            node = node->next;
            delete trash;
            return;
        }
        else {
            remove(node->next,data);
        }
    }
}

    // predicate function whether the particular data exist or not.
    // calls private function to get it recursively. The function is a overloading function.
bool LinkedList::isDataExist(int data) const{
    if(front==nullptr)
        throw("List is empty. ");
    return isDataExist(front,data);
}

    // The function is a overloading function,which decides whether the particular data exist or not.
bool LinkedList::isDataExist(ListNode * node, int data) const{
    if(node==nullptr) {
        return false;
    }
    else if(node->value == data) {
        return true;
    }
    else {
        return isDataExist(node->next,data);
    }
}

    //returns the largest value in the list
int LinkedList::largestData() const{
    if(front==nullptr)
        throw("List is empty. ");
    return largestData(front);
}

    //returns the largest data recursively
int LinkedList::largestData(ListNode * node) const{
    if(node->next == nullptr) {
        return node->value;
    }
    else {
        int x = node->value;
        int y = largestData(node->next);
        return (x>y?x:y);
    }
}

    // public function to print the list
    // calls private function to print the list in recursively
void LinkedList::printList() const{
    printList(front);
}

    //private function to print the list in recursively
void LinkedList::printList(ListNode * node) const{
    if(node==nullptr) {
        return;
    }
    else {
        cout<<node->value<<" ";
        printList(node->next);
        return;
    }
}

    //reversing the LinkedList by calling a helper function
void LinkedList::reverseList(){
    if (front == nullptr) {
        return;
    }
    reverseList(front);
}

    //reversing the LinkedList recursively and pointing the front to the last Node of the list
void LinkedList::reverseList(ListNode* & node){
    if(node->next == nullptr) {
        return;
    }
    else {
        ListNode* tempListNode = node;
        node = node->next;
        reverseList(node);
        ListNode* tempListNode2 = tempListNode->next;
        tempListNode2->next = tempListNode;
        tempListNode->next = nullptr;
    }
}

    //Sort the linked list using Selection Sort
void LinkedList::sortListBySelectionSort(){
    if(front == nullptr)
        return;
    ListNode* tempCurrentListNode = front;
    ListNode* tempPreviousListNode= front;
    ListNode* tempMinDataNode = tempPreviousListNode;
    int minData;
    while(tempPreviousListNode!=nullptr) {
        tempCurrentListNode = tempPreviousListNode->next;
        minData = tempPreviousListNode->value;
        tempMinDataNode = tempPreviousListNode;
        while(tempCurrentListNode != nullptr) {
            if(minData>tempCurrentListNode->value) {
                minData = tempCurrentListNode->value;
                tempMinDataNode = tempCurrentListNode;
            }
            tempCurrentListNode = tempCurrentListNode->next;
        }
        tempMinDataNode->value = tempPreviousListNode->value;
        tempPreviousListNode->value = minData;
        tempPreviousListNode = tempPreviousListNode->next;
    }
}

    //sort the linked list using Selection Sort by swapping the nodes.
void LinkedList::sortListBySelectionSort(bool blnSwapNode) {
    if(!blnSwapNode) {
        if(front==nullptr)
            return;
    }
    else {
        if(front->next==nullptr)
            return;
        ListNode* currentNode;
        ListNode* baseNode;
        ListNode* basePrevNode;
        ListNode* minPrevNode;
        ListNode* tempNode;
        ListNode* tempBaseNode;
        int minValue;
        baseNode = front;
        basePrevNode = nullptr;
        bool isNewFrontExist;
        isNewFrontExist = false;
        bool findNode;
        while(baseNode->next!=nullptr){
            currentNode = baseNode;
            minPrevNode = baseNode;
            minValue = currentNode->value;
            findNode = false;
            while(currentNode->next!=nullptr) {
                if(minValue>currentNode->next->value) {
                    minValue = currentNode->next->value;
                    minPrevNode = currentNode;
                    findNode = true;
                }
                currentNode = currentNode->next;
            }
            if(findNode) {
                if(isNewFrontExist) {
                    tempNode = minPrevNode->next;
                    tempBaseNode = baseNode->next;
                    minPrevNode->next = baseNode;
                    baseNode->next = tempNode->next;
                    if(baseNode!=minPrevNode) {
                       tempNode->next = tempBaseNode;
                    }
                    else {
                        tempNode->next = baseNode;
                    }
                    basePrevNode->next = tempNode;
                    basePrevNode = basePrevNode->next;
                    baseNode = basePrevNode->next;

                }
                else{
                    tempNode = minPrevNode->next;
                    minPrevNode->next = baseNode;
                    basePrevNode = baseNode->next;
                    baseNode->next = tempNode->next;
                    tempNode->next = basePrevNode;
                    basePrevNode = tempNode;
                    baseNode = basePrevNode->next;
                    front = basePrevNode;
                    isNewFrontExist = true;
                }
            }
            else {
                if(isNewFrontExist) {
                    basePrevNode = basePrevNode->next;
                    baseNode = basePrevNode->next;
                    }
                else {
                    basePrevNode = front;
                    baseNode = basePrevNode->next;
                    isNewFrontExist = true;
                }
            }
            //cout<<*this;
        }

    }

}

    //Sort the linked list using Merge Sort
void LinkedList::sortListByMergeSort(){


}

    //get the first node address
ListNode* LinkedList::getFront() const {
    return front;
}

    //The predicate method to check whether the LinkedList is empty or not.
bool LinkedList::isEmpty(){
    return(front==nullptr?false:true);
}

    //Delete the LinkedList. Calls a recursive function to delete it.
void LinkedList::clear(){
    clear(front);
    front = nullptr;
}

    //Recursive function to delete LinkedList.
void LinkedList::clear(ListNode* node) {
    if(node==nullptr){
        return;
    }
    else {
        ListNode * trash = node;
        clear(node->next);
        delete trash;
    }
}

    //Destructor function : clears the dynamic memory allocated to this list, garbage collection
LinkedList::~LinkedList() {
    clear();
}

    //output the list
ostream& operator <<(ostream& out, const LinkedList & list) {
    ListNode * node = list.getFront();
    out<<"{";
    while(node!=nullptr) {
        out<<node->value;
        if(node->next!=nullptr) {
            out<<"->";
        }
        node = node->next;
    }
    out<<"}";
    out<<endl;
    return out;
}
