#ifndef _COSTOPERSONAL_H_
#define _COSTOPERSONAL_H_
#include <iostream>
#include "Persona.h"
#include "Lista.h"
class CostoPersonal{
    private:
        float costo;
        Lista<Persona> personal;
    public:
        CostoPersonal();
        CostoPersonal(Persona);
        void setCosto(float);
        float getCosto()const;
        friend std::ostream& operator<<(std::ostream &o, const CostoPersonal &p);
        ~CostoPersonal();
};
std::ostream& operator<<(std::ostream &o, const CostoPersonal &p){
    o << "Costo Total de Personal: "<< p.getCosto() << "\n";
    o << "Personal Contratado:\n";
    o << p.personal << "\n";
    return o;
}
CostoPersonal::CostoPersonal(){
    costo = 0;
    Nodo<Persona>* ptr = personal.getCabeza();
    while(ptr->getSiguiente() != nullptr){
        costo += ptr->getElemento().getSueldo();
        ptr = ptr->getSiguiente();
    }
}
CostoPersonal::CostoPersonal(Persona p){
    costo=p.getSueldo();
}
void CostoPersonal::setCosto(float costo){
    this->costo = costo;
}
float CostoPersonal::getCosto()const{
    return costo;
}
CostoPersonal::~CostoPersonal(){
    std::cout<<"...Destruyendo CostoPersonal...\n";
}
#endif