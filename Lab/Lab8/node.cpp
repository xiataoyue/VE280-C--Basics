#include "node.h"

void Node::addChild(Node *child){
    if(child_num == n){
        tooManyChildren e;
        throw e;
    }
    children[child_num] = new Node(child->value, child->n);
    children[child_num]->parent = this;
    this->child_num ++;
}

Node::Node(int _value, int _n) {
    value = _value;
    child_num = 0;
    n = _n;
    parent = nullptr;
    children = new Node* [n];
    height = 1;
}

Node::~Node(){
    for(int i = 0; i < child_num; i++){
        delete children[i];
    }
    delete[] children;
    children = nullptr;
}

void Node::addChild(int _value) {
    if(child_num == n){
        tooManyChildren e;
        throw e;
    }
    Node child = Node(_value, n);
    addChild(&child);
}

void Node::traverse(){
    cout << value;
    for(int i = 0; i < child_num; i++){
        cout << " ";
        children[i]->traverse();
    }
}

bool Node::contain(Node *sub) {
    if(child_num == 0){
        return sub->value == value && sub->child_num == 0 && sub->n == n;
    }
    else{
        if(sub->value == value && sub->child_num == child_num && sub->n == n && sub->getHeight() == this->getHeight()){
            bool judge = true;
            for(int i = 0; i < child_num; i++){
                judge = judge && children[i]->contain(sub->children[i]);
            }
            return judge;
        }
        else{
            bool judge = false;
            for(int i = 0; i < child_num; i++){
                judge = judge || children[i]->contain(sub);
            }
            return judge;
        }
    }
}

int Node::getHeight() {
    if(child_num == 0) return 0;

    int h = 0;
    for(int i = 0; i < child_num; i++){
        if(h < children[i]->getHeight()) h = children[i]->getHeight();
    }
    return h + 1;
}

Node &Node::operator[](int i) {
    if(child_num <= i){
        invalidIndex e;
        throw e;
    }
    return *children[i];
}



