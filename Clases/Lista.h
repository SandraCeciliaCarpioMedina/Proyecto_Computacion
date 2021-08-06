#ifndef _LISTA_H_
#define _LISTA_H_
#include <iostream>
#include "Nodo.h"
template <typename T>
class Lista;
template <typename T>
std::ostream& operator <<(std::ostream &o, const Lista<T> &l);
template <typename T>
class Lista{
    private:
        int tam;
        Nodo<T>* cabeza;
    public:
        Lista();
        Lista(Nodo<T>*);
        int getTam()const;
        Nodo<T>* getCabeza()const;
        void setCabeza(Nodo<T>*);
        void insertar();
        friend std::ostream& operator<< <>(std::ostream &o, const Lista<T> &l);
        ~Lista();
};
template <typename T>
Lista<T>::Lista(){
    int opc;
    tam = 0;
    cabeza = nullptr;
    std::cout<<"Bienvenido a una lista nueva.\n";
    std::cout<<"Ingrese -1 si no desea ingresar valores, caso contrario ingrese cualquier numero\n";
    std::cin>>opc;
    while (opc != -1){
        insertar();
        std::cout<<"Ingrese -1 si no desea ingresar valores, caso contrario ingrese cualquier numero\n";
        std::cin>>opc;
    }
}
template <typename T>
Lista<T>::Lista(Nodo<T>* cabeza){
    tam = 1;
    this->cabeza = cabeza;
    Nodo<T>* nPtr = cabeza;
    while (nPtr->getSiguiente() != nullptr){
        tam+=1;
        nPtr = nPtr->getSiguiente();
    }
    nPtr->setSiguiente(nPtr->getSiguiente());
}
template <typename T>
int Lista<T>::getTam()const{
    return tam;
}
template <typename T>
Nodo<T>* Lista<T>::getCabeza()const{
    return cabeza;
}
template <typename T>
void Lista<T>::setCabeza(Nodo<T>* cabeza){
    tam = 1;
    this->cabeza = cabeza;
    Nodo<T>* nPtr = cabeza;
    while (nPtr->getSiguiente() != nullptr){
        tam+=1;
        nPtr = nPtr->getSiguiente();
    }
}
template <typename T>
void Lista<T>::insertar(){
    tam += 1;
    Nodo<T>* nuevo_nodo = new Nodo<T>();
    Nodo<T>* aux1 = cabeza;
    if(tam==1){
        cabeza = nuevo_nodo;
    }else{
        aux1 = cabeza;
        nuevo_nodo->setSiguiente(aux1);
        cabeza = nuevo_nodo;
    }
}
template <typename T>
std::ostream& operator<<(std::ostream& o, const Lista<T>& l){
    Nodo<T>* ptr=l.getCabeza();
    o << "Mostrando elementos de la lista:\n";
    while (ptr->getSiguiente() != nullptr){
        o << ptr->getElemento() << "\n";
        ptr = ptr->getSiguiente();
    }
    o << ptr->getElemento() <<"\n";
    return o;
}
template <typename T>
Lista<T>::~Lista(){
    std::cout<<"...Destruyendo Lista...\n";
}
#endif