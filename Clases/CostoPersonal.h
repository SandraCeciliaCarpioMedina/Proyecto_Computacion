#ifndef _COSTOPERSONAL_H_
#define _COSTOPERSONAL_H_
#include <iostream>
#include "Sueldo.h"
#include "Lista.h"
class CostoPersonal{
    private:
        float costo;
        Lista<Sueldo> personal;
    public:
        CostoPersonal();
        CostoPersonal(Lista<Sueldo>);
        void setCosto(float);
        float getCosto()const;
        Lista<Sueldo> getPersonal()const;
        friend std::ostream& operator<<(std::ostream &o, const CostoPersonal &p);
        ~CostoPersonal();
};
std::ostream& operator<<(std::ostream &o, const CostoPersonal &p){
    o << "Costo Total de Personal: "<< p.getCosto() << "\n";
    o << "Personal Contratado:\n";
    o << p.getPersonal() << "\n";
    return o;
}
CostoPersonal::CostoPersonal(){
    costo = 0;
    Sueldo s(" "," "," ",0,0,0," ",false);
    Nodo<Sueldo> *ptr = new Nodo<Sueldo>(&s);
    ptr = personal.getCabeza();
    while(ptr->getSiguiente() != nullptr){
        costo += ptr->getElemento().getSueldo();
        ptr = ptr->getSiguiente();
    }
    costo += ptr->getElemento().getSueldo();
}
CostoPersonal::CostoPersonal(Lista<Sueldo> p){
    personal = p;
    while (p.getCabeza()->getSiguiente() != nullptr){
        costo += p.getCabeza()->getElemento().getSueldo();
        p.getCabeza()->setSiguiente(p.getCabeza()->getSiguiente());
    }
    costo += p.getCabeza()->getElemento().getSueldo();
}
void CostoPersonal::setCosto(float costo){
    this->costo = costo;
}
Lista<Sueldo> CostoPersonal::getPersonal()const{
    return personal;
}
float CostoPersonal::getCosto()const{
    return costo;
}
CostoPersonal::~CostoPersonal(){
    std::cout<<"...Destruyendo CostoPersonal...\n";
}
#endif