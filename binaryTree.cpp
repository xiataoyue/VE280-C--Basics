#include "binaryTree.h"

// Implement the following methods listed below.
// You don't need to implement the other methods.
// If you decide to implement the other methods,
// DON'T INCLUDE THEM IN YOUR SUBMISSION.
//
// In your implementations, you can call any other
// methods, even those you don't need to implement.

BinaryTree::BinaryTree(int v, const BinaryTree &lChild, const BinaryTree &rChild){
   // TODO
   // You can use the initialization syntax if you want
   auto *leftt = new BinaryTree(lChild);
   auto *rightt = new BinaryTree(rChild);
   empty = false;
   this->v = v;
   this->left = leftt;
   this->right = rightt;
}

BinaryTree::BinaryTree(const BinaryTree &bt){
   // TODO
   // You can use the initialization syntax if you want
   v = bt.v;
   empty = bt.empty;
   left = bt.left;
   right = bt.right;
}

BinaryTree::~BinaryTree(){
   // TODO
   removeAll();
}


void BinaryTree::removeAll(){
   // TODO
   if(left != NULL) left->removeAll();
   if(right != NULL) right->removeAll();
   delete this;
}

bool BinaryTree::isSorted(){
   // TODO
   if(left == NULL && right == NULL) return true;
   else if(left != NULL && right != NULL){
       if(v < left->v || v < right->v) return false;
       else return left->isSorted() && right->isSorted();
   }
   else if(left != NULL){
       if(v < left->v) return false;
       else return left->isSorted();
   }
   else if(right != NULL){
       if(v < right->v) return false;
       else return right->isSorted();
   }

}

static int max(int a, int b){
    if(a >= b) return a;
    else return b;
}
int BinaryTree::depth(){
   // TODO
   if(empty) return -1;
   if(left->empty && right->empty) return 0;
   else return max(1 + left->depth(), 1 + right->depth());
}
