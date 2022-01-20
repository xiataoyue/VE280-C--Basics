#ifndef PROJECT_5_RELATED_FILES_DLIST_IMPL_H
#define PROJECT_5_RELATED_FILES_DLIST_IMPL_H

#include <iostream>
#include "dlist.h"

template <class T>
bool Dlist<T>::isEmpty() const {
    return first == NULL;
}

template <class T>
void Dlist<T>::insertFront(T *op) {
    if(isEmpty()){
        node *temp = new node;
        temp->op = op;
        temp->next = NULL;
        temp->prev = NULL;
        first = temp;
        last = temp;
    }
    else{
        node *temp = new node;
        temp->op = op;
        temp->prev = NULL;
        temp->next = first;
        first->prev = temp;
        first = temp;
    }
}

template <class T>
void Dlist<T>::insertBack(T *op) {
    if(last == NULL){
        node *temp = new node;
        temp->op = op;
        temp->prev = NULL;
        temp->next = NULL;
        first = temp;
        last = temp;
    }
    else{
        node *temp = new node;
        temp->op = op;
        temp->prev = last;
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

template <class T>
T *Dlist<T>::removeFront() {
    if(isEmpty()) throw emptyList{};
    node *rm = first;
    T *temp = first->op;
    if(first == last) {
        last = NULL;
        first = NULL;
    }
    else{
        first = first->next;
        first->prev = NULL;
    }
    delete rm;
    return temp;
}

template <class T>
T *Dlist<T>::removeBack() {
    if(isEmpty()) throw emptyList{};
    node *rm = last;
    T *temp = last->op;
    if(first == last) {
        first = NULL;
        last = NULL;
    }
    else {
        last = last->prev;
        last->next = NULL;
    }
    delete rm;
    return temp;
}

template <class T>
T *Dlist<T>::remove(bool (*cmp)(const T*, const T*), T* ref){
    node *temp = first;
    while(temp != NULL){
        if(cmp(temp->op, ref)){
            T *tmp = temp->op;
            if(temp == first){
                if(temp->next == NULL){
                    first = NULL;
                    last = NULL;
                }
                else{
                    first = temp->next;
                    first->prev = NULL;
                }
            }
            else if(temp == last){
                if(temp->prev == NULL){
                    first = NULL;
                    last = NULL;
                }
                else{
                    last = last->prev;
                    last->next = NULL;
                }
            }
            else{
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            delete temp;
            temp = NULL;
            return tmp;
        }
        temp = temp->next;
    }
    return nullptr;
}

template <class T>
Dlist<T>::Dlist(): first(NULL), last(NULL) {}

template <class T>
Dlist<T>::Dlist(const Dlist<T> &l): first(NULL), last(NULL) {
    copyAll(l);
}

template <class T>
Dlist<T> &Dlist<T>::operator=(const Dlist<T> &l) {
    copyAll(l);
    return *this;
}

template <class T>
Dlist<T>::~Dlist(){
    removeAll();
}
template <class T>
void Dlist<T>::removeAll() {
    while(first != NULL && last != NULL && first != last){
        T *temp1 = removeFront();
        T *temp2 = removeBack();
        delete temp1;
        delete temp2;
    }
    if(first == last && first != NULL) {
        T *temp = removeFront();
        delete temp;
    }
}

template <class T>
void Dlist<T>::copyAll(const Dlist<T> &l) {
    if(l.isEmpty()) return;
    if(!isEmpty()) removeAll();
    node *temp = l.first;
    while(temp != NULL){
        T *ip = new T(*temp->op);
        insertBack(ip);
        temp = temp->next;
    }
}
#endif //PROJECT_5_RELATED_FILES_DLIST_IMPL_H
