// BinarySearchTree.cpp

#include "BinarySearchTree.h"
#include <iostream>

BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

BinarySearchTree::~BinarySearchTree() {
    // TODO: Implement destructor to delete all nodes in the BST
}

Node* BinarySearchTree::insertRecursive(Node* current, int value) {
    if (current == nullptr) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    if (value < current->data) {
        current->left = insertRecursive(current->left, value);
    } else if (value > current->data) {
        current->right = insertRecursive(current->right, value);
    }

    return current;
}

void BinarySearchTree::insert(int value) {
    root = insertRecursive(root, value);
}

Node* BinarySearchTree::removeRecursive(Node* current, int value) {
    if (current == nullptr) {
        return nullptr;
    }

    if (value < current->data) {
        current->left = removeRecursive(current->left, value);
    } else if (value > current->data) {
        current->right = removeRecursive(current->right, value);
    } else {
        if (current->left == nullptr && current->right == nullptr) {
            delete current;
            return nullptr;
        } else if (current->left == nullptr) {
            Node* temp = current->right;
            delete current;
            return temp;
        } else if (current->right == nullptr) {
            Node* temp = current->left;
            delete current;
            return temp;
        } else {
            Node* minNode = findMin(current->right);
            current->data = minNode->data;
            current->right = removeRecursive(current->right, minNode->data);
        }
    }

    return current;
}

void BinarySearchTree::remove(int value) {
    root = removeRecursive(root, value);
}

Node* BinarySearchTree::findMin(Node* current) {
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

bool BinarySearchTree::searchRecursive(Node* current, int value) {
    if (current == nullptr) {
        return false;
    }

    if (value == current->data) {
        return true;
    } else if (value < current->data) {
        return searchRecursive(current->left, value);
    } else {
        return searchRecursive(current->right, value);
    }
}

bool BinarySearchTree::search(int value) {
    return searchRecursive(root, value);
}

void BinarySearchTree::inorderTraversalRecursive(Node* current) {
    if (current != nullptr) {
        inorderTraversalRecursive(current->left);
        std::cout << current->data << " ";
        inorderTraversalRecursive(current->right);
    }
}

void BinarySearchTree::inorderTraversal() {
    inorderTraversalRecursive(root);
    std::cout << std::endl;
}

void BinarySearchTree::preorderTraversalRecursive(Node* current) {
    if (current != nullptr) {
        std::cout << current->data << " ";
        preorderTraversalRecursive(current->left);
        preorderTraversalRecursive(current->right);
    }
}

void BinarySearchTree::preorderTraversal() {
    preorderTraversalRecursive(root);
    std::cout << std::endl;
}

void BinarySearchTree::postorderTraversalRecursive(Node* current) {
    if (current != nullptr) {
        postorderTraversalRecursive(current->left);
        postorderTraversalRecursive(current->right);
        std::cout << current->data << " ";
    }
}

void BinarySearchTree::postorderTraversal() {
    postorderTraversalRecursive(root);
    std::cout << std::endl;
}