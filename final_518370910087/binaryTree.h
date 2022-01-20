#ifndef BST_H
#define BST_H

#include <cstddef> // for definition of NULL

// DON'T MODIFY THIS HEADER FILE

class BinaryTree{
   bool empty; // Flag indicating if tree is empty or not
   int v; // value stored in root node if non-empty tree
   BinaryTree *left; // Dynamically allocated
   BinaryTree *right; // Dynamically allocated

public:
   BinaryTree();
   // EFFECTS: builds an empty binary tree
   BinaryTree(int v, const BinaryTree &lChild,
         const BinaryTree &rChild); // TODO
   // EFFECTS: builds a new tree whose root contains
   //          value v, its left subtree is a deep copy of
   //          lChild, its right subtree is a deep copy of
   //          rChild
   BinaryTree(const BinaryTree &bt);
   // EFFECTS: deep copy constructor from binary tree bt
   BinaryTree &operator=(const BinaryTree &bt);
   // MODIFIES: this
   // EFFECTS: deep copies from binary tree bt
   ~BinaryTree(); // TODO

   void removeAll(); // TODO
   // MODIFIES: this
   // EFFECTS: deallocates all the subtrees and makes tree empty

   bool isSorted(); // TODO
   // EFFECTS: returns true if the binary tree is such 
   //          that v in the root node is larger or equal
   //          to any values in the left and right subtrees.
   //          This ordering property applies recursively
   //          to the left and right subtrees.

   int depth(); // TODO
   // EFFECTS: returns the depth of the tree
   //          recall a tree with only a root has depth zero
   //          and an empty tree has depth -1
};

#endif
