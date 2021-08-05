#ifndef _NODO_H_
#define _NODO_H_
#include <iostream>
template <typename T>
class Nodo{
    private:
        T* elemento;
        Nodo<T>* siguiente;
    public:
        Nodo();
        Nodo(T* elemento);
        T getElemento()const;
        Nodo<T>* getSiguiente()const;
        void setElemento(T*);
        void setSiguiente(Nodo<T>*);
        ~Nodo();
};
template <typename T>
Nodo<T>::Nodo(){
    T* elem = new T();
    elemento = elem;
    siguiente = nullptr;
}
template <typename T>
Nodo<T>::Nodo(T* elemento){
    siguiente = nullptr;
    this->elemento = elemento;
}
template <typename T>
T Nodo<T>::getElemento()const{
    return *elemento;
}
template <typename T>
Nodo<T>* Nodo<T>::getSiguiente()const{
    return siguiente;
}
template <typename T>
void Nodo<T>::setElemento(T* elemento){
    this->elemento = elemento;
}
template <typename T>
void Nodo<T>::setSiguiente(Nodo<T>* siguiente){
    this->siguiente = siguiente;
}
template <typename T>
Nodo<T>::~Nodo(){
    std::cout<<"...Destruyendo Nodo...\n";
}
#endif