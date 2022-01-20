/*
 * This is an exercise of VE280 Lab 10, SU2020.
 * Written by Martin Ma.
 * Latest Update: 7/17/2020.
 * Copyright © 2020 Mars-tin. All rights reserved.
 */

#ifndef MY_STACK_IMPL_H
#define MY_STACK_IMPL_H

#include <iostream>
#include "my_stack.h"


template <class T>
void Stack<T>::print()
{
    Node<T>* itr = head;
    while(itr){
        std::cout << itr->val;
        itr = itr->next;
    }
    std::cout << "\n";
}

template <class T>
void Stack<T>::removeAll(){
    while(head!= NULL) pop();
}

template <class T>
void Stack<T>::copyFrom(const Stack<T> &s){
    if(s.isEmpty()) return;
    if(head != NULL) removeAll();
    const Node<T> *temp = s.head;
    Stack<T> st;
    while(temp != NULL){
        st.push(temp->val);
        temp = temp->next;
    }
    const Node<T> *temp1 = st.head;
    while(temp1 != NULL){
        this->push(temp1->val);
        temp1 = temp1->next;
    }
}

template <class T>
Stack<T>::Stack(): head(NULL){};

template <class T>
Stack<T>::Stack(const Stack<T> &s): head(NULL) {
    copyFrom(s);
}

template <class T>
Stack<T> &Stack<T>::operator = (const Stack<T> &s){
    copyFrom(s);
    return *this;
}

template <class T>
Stack<T>::~Stack(){
    removeAll();
}

template <class T>
bool Stack<T>::isEmpty() const {
    return !head;
}

template <class T>
size_t Stack<T>::size() const {
    size_t count = 0;
    const Node<T> *temp = head;
    while(temp != NULL){
        count ++;
        temp = temp->next;
    }
    return count;
}

template <class T>
void Stack<T>::push(T val) {
    auto *node = new Node<T>;
    node->val = val;
    if(this->isEmpty()){
        node->next = NULL;
        head = node;
    }
    else{
        node->next = head;
        head = node;
    }

}

template <class T>
void Stack<T>::pop() {
    if(this->isEmpty()) throw stackEmpty{};
    Node<T> *temp = head;
    head = head->next;
    delete temp;
    temp = NULL;
}

template <class T>
T Stack<T>::top() const{
    return head->val;
}

template <class T>
void reverse(Stack<T> &s) {
    Stack<T> temp = s;
    while(!s.isEmpty()) s.pop();
    while(!temp.isEmpty()){
        s.push(temp.top());
        temp.pop();
    }
}

template <class T>
Stack<T> operator +(Stack<T> &s, T val) {
    reverse(s);
    Stack<T> temp = s;
    temp.push(val);
    reverse(temp);
    reverse(s);
    return temp;
}

template <class T>
Stack<T> operator +(Stack<T> &first, Stack<T> &second) {
    reverse(first);
    Stack<T> temp1 = first;
    Stack<T> temp2 = second;
    while(!temp2.isEmpty()){
        temp1.push(temp2.top());
        temp2.pop();
    }
    reverse(first);
    reverse(temp1);
    return temp1;
}
#endif //MY_STACK_IMPL_H