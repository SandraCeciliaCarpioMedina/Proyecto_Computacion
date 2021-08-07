#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<iostream>
#include"Node.h"
#include"Iterator.h"

using namespace std;

template<typename T>

class LinkedList {
    private:
        int size;
        Node<T> *head,*tail;
    public:
        LinkedList();
        void pushFront(T);
        void pushBack(T);
        void pop(int);
        void popFront();   //elimina el primer elemento
        void popBack();    //elimina el ultimo elemento
        Iterator<T> begin();
        Iterator<T> end();
        //void print();
        Iterator<T> print();
        ~LinkedList();
};

    template<typename T>
    LinkedList<T>::LinkedList(){
        head=nullptr;
        tail=nullptr;
        size=0;
    }

    template<typename T>
    void LinkedList<T>::pushFront(T new_data){
        Node<T>* new_node= new Node<T>;
        new_node->setElem(new_data);
        if(head == nullptr){         //si nuestra LinkedList esta vacia
            head=new_node;
            tail=new_node;
        }
        else{
            new_node->setNext(head);
            head=new_node;
        }
        size++;
    }

    template<typename T>
    void LinkedList<T>::pushBack(T new_data){
        Node<T>* new_node= new Node<T>;
        new_node->setElem(new_data);
        if(head == nullptr){         //si nuestra LinkedList esta vacia
            head=new_node;
            tail=new_node;
        }
        else{
            tail->setNext(new_node);
            tail=tail->getNext();
        }
        size++;
    }

    template<typename T>
    void LinkedList<T>::pop(int pos){
        Node<T>* eliminar=head;       //nodo que queremos eliminar
        Node<T>* aux=head;       //nodo que ubicaremos una posición antes del nodo a eliminar
        if(pos == 1)
            head=head->getNext();
        else{
            for( int i=2; i < pos; i++){
                aux=aux->getNext();
            }
            eliminar=aux->getNext();
            aux->setNext(eliminar->getNext());
        }
        delete eliminar;    //eliminamos el nodo
        size--;
    }

    template<typename T>
    void LinkedList<T>::popFront(){       //elimina el primer elemento
        delete head;
        head=head->getNext();
        size--;
    }

    template<typename T>
    void LinkedList<T>::popBack(){      //elimina el ultimo elemento
        Node<T>* aux=head;
        if(size==1){
            delete tail;
            tail=nullptr;
        }
        else{
            while(aux->getNext()!=tail)  //ubicamos el nodo aux antes de tail
                aux=aux->getNext();
            delete tail;
            tail=aux;
            tail->setNext(nullptr);
        }
        size--;
    }

    template<typename T>
    Iterator<T> LinkedList<T>::begin(){
        return Iterator<T>(head);
    }

    template<typename T>
    Iterator<T> LinkedList<T>::end(){
        return Iterator<T>(tail);
    }

    /*template<typename T>
    void LinkedList<T>::print(){
        Node<T>* aux=head;
        for( int i=0; i < size; i++){
            cout<<aux->getElem()<<" ";
            aux=aux->getNext();
        }
        cout<<endl;
    }*/

    template<typename T>
    //hacemos uso de la clase Iterator para mostrar el contenido de nuestra LinkedList
    Iterator<T> LinkedList<T>::print(){
        Iterator<T> it;
        for(it=begin(); it!=end(); ++it)
            cout<<*it<<" ";
        cout<<*it<<endl;
    }

    template<typename T>
    LinkedList<T>::~LinkedList(){
        while(head != nullptr){     //avanzamos y eliminamos nodo por nodo
            delete head;
            head=head->getNext();
        }
    }

#endif
