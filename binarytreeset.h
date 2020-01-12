#ifndef BINARYTREESET_H
#define BINARYTREESET_H
//#include "queue.h"
#include "stack.h"
#include <queue>
#include <map>
#include <iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

};

class BinaryTreeSet
{
public:
    BinaryTreeSet();
    BinaryTreeSet(int data);
    ~BinaryTreeSet();

    void insertData(int data);              //done
    void remove(int data);                  //done
    bool isDataExist(int data) const;       //done
    int largestData() const;                //done
    int getMin() const;
    int getHeight() const;
    void printList_inorder() const;         //done
    void printList_preorder() const;        //done
    void printList_postorder() const;       //done
    void printlist_mirror() const;          //done
    void printTree_sideways() const;        //done
    void printList_Tree();
    void clear();


    // Extra functions for interview
    void printPairSum(int sum);     //Print all the pairs from the BST with sum value
    void mirrorTree();

private:
    TreeNode* root;
    //map<int, Queue> BFSData;
    //Queue queue;
    Stack stack;
    queue<TreeNode*> que;
    TreeNode* createListNode(int data);
    void insertData(TreeNode* & node, int data);
    int getHeight(TreeNode* node) const;
    void printList_inorder(TreeNode* node) const;
    void printList_preorder(TreeNode* node) const;
    void printList_postorder(TreeNode* node) const;
    void printList_sideways(TreeNode* node, string indent = "") const;
    void printList_Tree(TreeNode* node, string indent = "");
    virtual void clear(TreeNode* node);

    // Extra functions for interview
    void printPairSum(TreeNode* node, int sum);
    TreeNode* mirrorTree(TreeNode* & node);

};

ostream& operator <<(ostream& out,const BinaryTreeSet & objBinary);

#endif // BINARYTREESET_H
