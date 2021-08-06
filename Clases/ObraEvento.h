#ifndef _OBRAEVENTO_H_
#define _OBRAEVENTO_H_
#include <iostream>
#include "Lista.h"
#include "CostoMueble.h"
#include "CostoImplementos.h"
#include "CostoPersonal.h"
#include "Obra.h"
class ObraEvento : protected Obra{
    private:
        float costoTotal;
        Lista<CostoMueble> muebles;
        Lista<CostoImplementos> implementos;
        CostoPersonal personal;
    public:
        ObraEvento();
        float getCostoTotal()const;
        Lista<CostoMueble> getMuebles()const;
        Lista<CostoImplementos> getImplementos()const;
        CostoPersonal getPersonal()const;
        void setCostoTotal(float);
        void setMuebles(Lista<CostoMueble>);
        void setImplementos(Lista<CostoImplementos>);
        void setPersonal(CostoPersonal);
        float getImpuestoTotal();
        friend std::ostream& operator<<(std::ostream &o, const ObraEvento &e);
        ~ObraEvento();
};
std::ostream& operator<<(std::ostream &o, const ObraEvento &e){
    o << "Nombre de Evento: " <<e.getNombreObra() << "\n";
    o << "Muebles utilizados:\n" <<e.getMuebles() << "\n";
    o << "Implementos utilizados:\n" <<e.getImplementos() << "\n";
    o << "Personal Contratado:\n" <<e.getPersonal() << "\n";
    o << "Costo Total de Evento: " <<e.getCostoTotal() << "\n";
    return o;
}
ObraEvento::ObraEvento() : Obra(){
    costoTotal=0;
    CostoMueble mu(0," "," "," ");
    CostoImplementos i(0," "," "," ");
    
    Nodo<CostoMueble> *muPtr = new Nodo<CostoMueble>(&mu);
    muPtr = muebles.getCabeza();
    while(muPtr->getSiguiente() != nullptr){
        costoTotal += muPtr->getElemento().getCosto();
        muPtr = muPtr->getSiguiente();
    }
    costoTotal += muPtr->getElemento().getCosto();
    
    Nodo<CostoImplementos> *iPtr = new Nodo<CostoImplementos>(&i);
    iPtr = implementos.getCabeza();
    while(iPtr->getSiguiente() != nullptr){
        costoTotal += iPtr->getElemento().getCosto();
        iPtr = iPtr->getSiguiente();
    }
    costoTotal += iPtr->getElemento().getCosto();
    costoTotal += personal.getCosto();
}
float ObraEvento::getCostoTotal()const{
    return costoTotal;
}
Lista<CostoMueble> ObraEvento::getMuebles()const{
    return muebles;
}
Lista<CostoImplementos> ObraEvento::getImplementos()const{
    return implementos;
}
CostoPersonal ObraEvento::getPersonal()const{
    return personal;
}
void ObraEvento::setMuebles(Lista<CostoMueble> muebles){
    this->muebles = muebles;
}
void ObraEvento::setImplementos(Lista<CostoImplementos> implementos){
    this->implementos = implementos;
}
void ObraEvento::setPersonal(CostoPersonal personal){
    this->personal = personal;
}
float ObraEvento::getImpuestoTotal(){
    float impuesto = 0;
    Lista<CostoMueble> copiaM = muebles;
    Lista<CostoMueble> *ptrM = &copiaM;
    while(ptrM->getCabeza()->getSiguiente() != nullptr){
        impuesto += ptrM->getCabeza()->getElemento().getImpuesto();
        ptrM->getCabeza()->setSiguiente(ptrM->getCabeza()->getSiguiente());
    }
    impuesto += ptrM->getCabeza()->getElemento().getImpuesto();

    Lista<CostoImplementos> copiaI = implementos;
    Lista<CostoImplementos> *ptrI = &copiaI;
    while(ptrI->getCabeza()->getSiguiente() != nullptr){
        ptrI->getCabeza()->getElemento().getImpuesto();
        ptrI->getCabeza()->setSiguiente(ptrI->getCabeza()->getSiguiente());
    }
    impuesto += ptrI->getCabeza()->getElemento().getImpuesto();
    return impuesto;
}
ObraEvento::~ObraEvento(){
    std::cout<<"...Destruyendo ObraEvento...\n";
}
#endif