#include "binarytreeset.h"

    //Constructor to set root=NULL
BinaryTreeSet::BinaryTreeSet()
{
    root = nullptr;
}

    //Constructor to create a node and insert data in it.
BinaryTreeSet::BinaryTreeSet(int data)
{
    //root = new TreeNode();
    //root->value = data;
    //root->left = nullptr;
    //root->right = nullptr;
    root = createListNode(data);
}

    //to create a node and insert data in it.
TreeNode* BinaryTreeSet::createListNode(int data) {
    TreeNode * tempNode = new TreeNode();
    tempNode->value = data;
    tempNode->left = nullptr;
    tempNode->right = nullptr;
    return tempNode;
}

    //insert node in the BST and call the
void BinaryTreeSet::insertData(int data) {
    if(root==nullptr) {
        root = createListNode(data);
    }
    else {
        insertData(root,data);
    }
}

    //insert node in BST recursively
void BinaryTreeSet::insertData(TreeNode*& node, int data) {
    if(node==nullptr) {
        node = createListNode(data);
    }
    else if(node->value<data) {
        insertData(node->right,data);
    }
    else {
        insertData(node->left,data);
    }
}

    //BST Tree represent
void BinaryTreeSet::printList_Tree() {
    if(root==nullptr) {
        return;
    }
    //BFSData.insert(pair<1,queue.enQueue(root->value)>)
    que.push(root);
    printList_Tree(root);
}

    //BST Tree output
void BinaryTreeSet::printList_Tree(TreeNode* node, string indent)  {
    while(!que.empty()) {
        node = que.front();
        if(node->left!=nullptr) {
            que.push(node->left);
        }
        if(node->right!=nullptr) {
            que.push(node->right);
        }
        if(!que.empty()) {
            cout<<" "<<indent<<que.front()->value;
            que.pop();
        }
        //printList_Tree(node->left, indent);
        //printList_Tree(node->right, indent);
        //cout<<endl;
    }

}

    //print the BST and calls the function recursively
void BinaryTreeSet::printList_inorder() const {
    cout<<"Inorder Traversal : {";
    printList_inorder(root);
    cout<<"}"<<endl;
}

    //print the BST in inorder traversal
void BinaryTreeSet::printList_inorder(TreeNode* node) const {
    if(node==nullptr) {
        return;
    }
    else {   
        printList_inorder(node->left);
        cout<<node->value<<" ";
        printList_inorder(node->right);
    }
}

    //print the BST and calls the function recursively
void BinaryTreeSet::printList_preorder() const {
    cout<<"Preorder Traversal : {";
    printList_preorder(root);
    cout<<"}"<<endl;
}

    //print the BST in inorder traversal
void BinaryTreeSet::printList_preorder(TreeNode* node) const {
    if(node==nullptr) {
    return;
    }
    else {
        cout<<node->value<<" ";
        printList_preorder(node->left);
        printList_preorder(node->right);
    }
}

//print the BST in post order and calls the function recursively
void BinaryTreeSet::printList_postorder() const {
    cout<<"Postorder Traversal : {";
    printList_postorder(root);
    cout<<"}"<<endl;
}

//print the BST in postorder traversal
void BinaryTreeSet::printList_postorder(TreeNode* node) const {
    if(node==nullptr) {
    return;
    }
    else {
    printList_postorder(node->left);
    printList_postorder(node->right);
    cout<<node->value<<" ";
    }
}

    //print sideways of the BST
void BinaryTreeSet::printTree_sideways() const {
    printList_sideways(root);
}

void BinaryTreeSet::printList_sideways(TreeNode* node, string indent) const {
    if(node==nullptr)
        return;
    else{
        printList_sideways(node->right,indent + "  ");
        cout<<indent<<node->value<<endl;
        printList_sideways(node->left,indent + "  ");
    }
}


void BinaryTreeSet::printPairSum(int sum) {
    printPairSum(root,sum);
}

void BinaryTreeSet::printPairSum(TreeNode* node, int sum) {
    //stack.printData();
    //cout<<endl;
    if(node==nullptr){
    }
    printPairSum(node->left,sum);
    while(!stack.isEmpty()) {
        if(sum==(node->value+stack.peek())) {
            cout<<node->value<<","<<stack.pop()<<endl;
            break;
        }
        else if(sum>(node->value+stack.peek())) {
            stack.pushData(node->value);
            break;
        }
        else if(sum<(node->value+stack.peek())) {
            stack.pop();
        }
    }
    if(stack.isEmpty()){
        if(sum >= node->value) stack.pushData(node->value);
    }
    printPairSum(node->right,sum);return;

}


int BinaryTreeSet::getHeight() const {
    return getHeight(root);
}


int BinaryTreeSet::getHeight(TreeNode* node) const {
    if(node==nullptr) {
        return 0;
    }
    else {
        int x = getHeight(node->left);
        int y = getHeight(node->right);
        return (x>y?x+1:y+1);
    }
}

void BinaryTreeSet::mirrorTree() {
    root = mirrorTree(root);
}


TreeNode * BinaryTreeSet::mirrorTree(TreeNode* & node) {
    if(node==nullptr) {
        return nullptr;
    }
    else {
        TreeNode * temp = node->left;
        node->left = node->right;
        node->right = temp;
        TreeNode * x = mirrorTree(node->left);
        TreeNode * y = mirrorTree(node->right);
        return node;
    }
}

    //clear the BST and calls a helper function to delete the BST
void BinaryTreeSet::clear() {
    clear(root);
    root = nullptr;
}

    //clear the BST recursively
void BinaryTreeSet::clear(TreeNode* node) {
    if(node==nullptr) {
        return;
    }
    else {
        clear(node->left);
        clear(node->right);
        if(node->left == nullptr && node->right == nullptr) {
            TreeNode* trash = node;
            node = nullptr;
            delete trash;
        }
    }
}

BinaryTreeSet::~BinaryTreeSet() {
    clear();
}
