// BinarySearchTree.h

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BinarySearchTree {
private:
    Node* root;
    Node* insertRecursive(Node* current, int value);
    Node* removeRecursive(Node* current, int value);
    Node* findMin(Node* current);
    bool searchRecursive(Node* current, int value);
    void inorderTraversalRecursive(Node* current);
    void preorderTraversalRecursive(Node* current);
    void postorderTraversalRecursive(Node* current);
public:
    BinarySearchTree();
    ~BinarySearchTree();
    void insert(int value);
    void remove(int value);
    bool search(int value);
    void inorderTraversal();
    void preorderTraversal();
    void postorderTraversal();
};

#endif



