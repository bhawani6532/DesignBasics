#include "avltree.h"

avlTree::avlTree()
{
    root = nullptr;
}


avlNode* avlTree::createListNode(int data) {
    avlNode * tempNode = new avlNode();
    tempNode->value = data;
    tempNode->left = nullptr;
    tempNode->right = nullptr;
    tempNode->height = 0;
    return tempNode;
}


//insert node in the AVL BST and call the
void avlTree::insertData(int data) {
    if(root==nullptr) {
        root = createListNode(data);
    }
    else {
        insertData(root,data);
    }
}

//insert node in BST recursively
void avlTree::insertData(avlNode*& node, int data) {
    if(node==nullptr) {
        node = createListNode(data);
        node->height = 0;
    }
    else if(node->value<data) {
        insertData(node->right,data);
        int h1 = node->left->height;
        int h2 = node->right->height;
        node->height = (h1>h2?h1+1:h2+1);
    }
    else {
        insertData(node->left,data);
        int h1 = node->left->height;
        int h2 = node->right->height;
        node->height = (h1>h2?h1+1:h2+1);
    }
}


    //print sideways of the BST
void avlTree::printTree_sideways() const {
    printTree_sideways(root);
}


void avlTree::printTree_sideways(avlNode* node, string indent) const {
    if(node==nullptr)
        return;
    else{
        printTree_sideways(node->right,indent + "  ");
        cout<<indent<<node->value<<"'"<<node->height<<"'"<<indent<<endl;
        printTree_sideways(node->left,indent + "  ");
    }
}


    //clear the BST and calls a helper function to delete the BST
void avlTree::clear() {
    clear(root);
    root = nullptr;
}

    //clear the BST recursively
void avlTree::clear(avlNode* node) {
    if(node==nullptr) {
        return;
    }
    else {
        clear(node->left);
        clear(node->right);
        if(node->left == nullptr && node->right == nullptr) {
            avlNode* trash = node;
            node = nullptr;
            delete trash;
        }
    }
}

avlTree::~avlTree() {
    clear();
}
