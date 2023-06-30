// main.cpp
#include <iostream>
#include "BinarySearchTree.h"

int main() {
    BinarySearchTree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    bst.inorderTraversal();    // Output: 20 30 40 50 60 70 80
    bst.preorderTraversal();   // Output: 50 30 20 40 70 60 80
    bst.postorderTraversal();  // Output: 20 40 30 60 80 70 50

    bst.remove(30);
    bst.remove(60);

    bst.inorderTraversal();    // Output: 20 40 50 70 80

    std::cout << bst.search(40) << std::endl; // Output: 1 (true)
    std::cout << bst.search(60) << std::endl; // Output: 0 (false)

    return 0;
}
