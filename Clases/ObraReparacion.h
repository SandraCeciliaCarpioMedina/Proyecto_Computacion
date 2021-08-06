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
    o << "Costo Total de Reparaciones: " << r.getCostoTotal() << "\n";
    o << "Reparaciones:\n";
    o << r.getReparaciones() << "\n";
    o << "Personal Contratado:\n";
    o << r.getPersonal() << "\n";
    return o;
}
ObraReparacion::ObraReparacion() : Obra(){
    costoTotal = 0;
    CostoReparaciones *r = new CostoReparaciones(0," ");
    
    Nodo<CostoReparaciones> *rPtr = new Nodo<CostoReparaciones>(r);
    rPtr = reparaciones.getCabeza();
    while(rPtr->getSiguiente() != nullptr){
        costoTotal += rPtr->getElemento().getCosto();
        rPtr->setSiguiente(rPtr->getSiguiente());
    }
    costoTotal += rPtr->getElemento().getCosto();
    costoTotal += personal.getCosto();
    delete rPtr;
    delete r;
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
    CostoReparaciones *r = new CostoReparaciones(0," ");
    Nodo<CostoReparaciones> *ptr = new Nodo<CostoReparaciones>(r);
    ptr = reparaciones.getCabeza();
    while(ptr->getSiguiente() != nullptr){
        impuestos += ptr->getElemento().getImpuesto();
        ptr->setSiguiente(ptr->getSiguiente());
    }
    impuestos += ptr->getElemento().getImpuesto();
    delete r;
    delete ptr;
    return impuestos;
}
ObraReparacion::~ObraReparacion(){
}
#endif