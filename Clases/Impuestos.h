#ifndef _IMPUESTO_H_
#define _IMPUESTO_H_
#include <iostream>
#include "ObraReparacion.h"
#include "ObraConstruccion.h"
#include "ObraEvento.h"
#include "Lista.h"
#include <list>
#include "Factura.h"
class Impuestos{
    private:
        float impuestoTotal;
        Lista<Factura> facturas;
    public:
        Impuestos(float&&,float&&,float&&);
        float getImpuestos()const;
        friend std::ostream& operator<<(std::ostream &o, const Impuestos &i);
        ~Impuestos();
};
std::ostream& operator<<(std::ostream &o, const Impuestos &i){
    o << "Recaudacion total de impuestos: " << i.getImpuestos() << "\n";
    return o;
}
Impuestos::Impuestos(float &&impuestoEventos,float &&impuestoReparaciones,float &&impuestoConstrucciones){
    impuestoTotal = 0;

    Factura *f = new Factura();
    Nodo<Factura> *ptrF = new Nodo<Factura>(std::move(f));
    ptrF = facturas.getCabeza();
    while(ptrF->getSiguiente() != nullptr){
        impuestoTotal += ptrF->getElemento().getImpuesto();
        ptrF->setSiguiente(ptrF->getSiguiente());
    }
    impuestoTotal += ptrF->getElemento().getImpuesto();

    impuestoTotal += impuestoEventos;
    impuestoTotal += impuestoConstrucciones;
    impuestoTotal += impuestoReparaciones;
    delete f;
    delete ptrF;
}
float Impuestos::getImpuestos()const{
    return impuestoTotal;
}
Impuestos::~Impuestos(){
}
#endif