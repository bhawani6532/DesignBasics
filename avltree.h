#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
using namespace std;

struct avlNode {
    int value;
    avlNode* left;
    avlNode* right;
    int height;
};

class avlTree
{
public:
    avlTree();
    ~avlTree();

    void clear();
    void insertData(int data);
    void remove(int data);
    void printTree_sideways() const;

private:
    avlNode* root;
    avlNode* createListNode(int data);
    void clear(avlNode* node);
    void insertData(avlNode* & node, int data);
    void remove(avlNode*& node, int data);
    void printTree_sideways(avlNode* node, string indent = "") const;
};

#endif // AVLTREE_H
