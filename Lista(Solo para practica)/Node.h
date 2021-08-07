#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template<typename T>

class Node {
    private:
        T elem;
        Node *next;
    public:
        Node();
        Node(T);
        T getElem();
        void setElem(T);
        Node<T>* getNext();
        void setNext(Node<T>*);
};

    template<typename T>
    Node<T>::Node(){
        //elem=0;
        next=nullptr;
    }

    template<typename T>
    Node<T>::Node(T e){
        elem=e;
        next=nullptr;
    }

    template<typename T>
    T Node<T>::getElem(){
        return elem;
    }

    template<typename T>
    void Node<T>::setElem(T e){
        elem=e;
    }

    template<typename T>
    Node<T>* Node<T>::getNext(){
        return next;
    }

    template<typename T>
    void Node<T>::setNext(Node<T> *n){
        next=n;
    }

#endif

