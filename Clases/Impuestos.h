#ifndef _IMPUESTO_H_
#define _IMPUESTO_H_
#include <iostream>
#include "ObraReparacion.h"
#include "ObraConstruccion.h"
#include "ObraEvento.h"
#include "Lista.h"
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

    Lista<Factura> copiaFacturas = facturas;
    Lista<Factura> *ptrF = &copiaFacturas;
    while(ptrF->getCabeza()->getSiguiente() != nullptr){
        impuestoTotal += ptrF->getCabeza()->getElemento().getImpuesto();
        ptrF->getCabeza()->setSiguiente(ptrF->getCabeza()->getSiguiente());
    }
    impuestoTotal += ptrF->getCabeza()->getElemento().getImpuesto();

    impuestoTotal += impuestoEventos;
    impuestoTotal += impuestoConstrucciones;
    impuestoTotal += impuestoReparaciones;
}
float Impuestos::getImpuestos()const{
    return impuestoTotal;
}
Impuestos::~Impuestos(){
    std::cout<<"...Destruyendo Impuestos...\n";
}
#endif