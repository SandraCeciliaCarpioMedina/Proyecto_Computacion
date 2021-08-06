#ifndef _OBRAREPARACION_H_
#define _OBRAREPARACION_H_
#include <iostream>
#include "Obra.h"
#include "Lista.h"
#include "CostoReparaciones.h"
#include "CostoPersonal.h"
class ObraReparacion : protected Obra{
    private:
        float costoTotal;
        Lista<CostoReparaciones> reparaciones;
        CostoPersonal personal;
    public:
        ObraReparacion();
        ObraReparacion(Lista<CostoReparaciones>,CostoPersonal);
        Lista<CostoReparaciones> getReparaciones()const;
        CostoPersonal getPersonal()const;
        float getCostoTotal()const;
        void setReparaciones(Lista<CostoReparaciones>);
        void setPersonal(CostoPersonal);
        float getImpuestoTotal();
        friend std::ostream& operator<<(std::ostream &o, const ObraReparacion &r);
        ~ObraReparacion();
};
ObraReparacion::ObraReparacion(Lista<CostoReparaciones> reparaciones, CostoPersonal personal){
    this->reparaciones = reparaciones;
    this->personal = personal;
}
std::ostream& operator<<(std::ostream &o, const ObraReparacion &r){
    o << "Reparaciones:\n" << r.getReparaciones() << "\n";
    o << "Personal Contratado:\n" << r.getPersonal() << "\n";
    o << "Costo Total de Reparacion: " << r.getCostoTotal() << "\n";
    return o;
}
ObraReparacion::ObraReparacion() : Obra(){
    costoTotal = 0;
    CostoReparaciones r(0," ");
    
    Nodo<CostoReparaciones> *rPtr = new Nodo<CostoReparaciones>(&r);
    rPtr = reparaciones.getCabeza();
    while(rPtr->getSiguiente() != nullptr){
        costoTotal += rPtr->getElemento().getCosto();
        rPtr->setSiguiente(rPtr->getSiguiente());
    }
    costoTotal += rPtr->getElemento().getCosto();
    costoTotal += personal.getCosto();
    delete rPtr;
}
float ObraReparacion::getCostoTotal()const{
    return costoTotal;
}
Lista<CostoReparaciones> ObraReparacion::getReparaciones()const{
    return reparaciones;
}
CostoPersonal ObraReparacion::getPersonal()const{
    return personal;
}
void ObraReparacion::setReparaciones(Lista<CostoReparaciones> reparaciones){
    this->reparaciones = reparaciones;
}
void ObraReparacion::setPersonal(CostoPersonal personal){
    this->personal = personal;
}
float ObraReparacion::getImpuestoTotal(){
    float impuestos = 0;
    Lista<CostoReparaciones> copia = reparaciones;
    Lista<CostoReparaciones> *ptr = &copia;
    while(ptr->getCabeza()->getSiguiente() != nullptr){
        impuestos += ptr->getCabeza()->getElemento().getImpuesto();
        ptr->getCabeza()->setSiguiente(ptr->getCabeza()->getSiguiente());
    }
    impuestos += ptr->getCabeza()->getElemento().getImpuesto();
    return impuestos;
}
ObraReparacion::~ObraReparacion(){
}
#endif