#ifndef _OBRACONSTRUCCION_H_
#define _OBRACONSTRUCCION_H_
#include <iostream>
#include "Obra.h"
#include "CostoCemento.h"
#include "CostoFierro.h"
#include "CostoLadrillos.h"
#include "CostoClavos.h"
#include "CostoTornillos.h"
#include "CostoVentanas.h"
#include "CostoPuertas.h"
#include "CostoMaquina.h"
#include "CostoHerramientas.h"
#include "CostoMueble.h"
#include "CostoImplementos.h"
#include "CostoPersonal.h"
#include "Lista.h"
class ObraConstruccion : protected Obra{
    private:
        float costoTotal;
        Lista<CostoMaquina> maquinas;
        CostoCemento cemento;
        CostoFierro fierros;
        CostoLadrillos ladrillos;
        Lista<CostoHerramientas> herramientas;
        CostoClavos clavos;
        CostoTornillos tornillos;
        CostoVentanas ventanas;
        CostoPuertas puertas;
        Lista<CostoMueble> muebles;
        Lista<CostoImplementos> implementos;
        CostoPersonal personal;
    public:
        ObraConstruccion();
        float getCostoTotal()const;
        Lista<CostoMaquina> getListaMaquinas()const;
        CostoCemento getCostoCemento()const;
        CostoFierro getCostoFierro()const;
        CostoLadrillos getCostoLadrillos()const;
        Lista<CostoHerramientas> getListaHerramientas()const;
        CostoClavos getCostoClavos()const;
        CostoTornillos getCostoTornillos()const;
        CostoVentanas getCostoVentanas()const;
        CostoPuertas getCostoPuertas()const;
        Lista<CostoMueble> getListaMuebles()const;
        Lista<CostoImplementos> getListaImplementos()const;
        CostoPersonal getCostoPersonal()const;
        void setListaMaquinas(Lista<CostoMaquina>);
        void setCostoCemento(CostoCemento);
        void setCostoFierro(CostoFierro);
        void setCostoLadrillos(CostoLadrillos);
        void setListaHerramientas(Lista<CostoHerramientas>);
        void setCostoClavos(CostoClavos);
        void setCostoTornillos(CostoTornillos);
        void setCostoVentanas(CostoVentanas);
        void setCostoPuertas(CostoPuertas);
        void setListaMuebles(Lista<CostoMueble>);
        void setListaImplementos(Lista<CostoImplementos>);
        void setCostoPersonal(CostoPersonal);
        friend std::ostream& operator<<(std::ostream &o, const ObraConstruccion &c);
        ~ObraConstruccion();
};
std::ostream& operator<<(std::ostream &o, const ObraConstruccion &c){
    o << "Maquinas Usadas:\n" << c.getListaMaquinas() << "\n";
    o << "Cemento:\n" << c.getCostoCemento() << "\n";
    o << "Fierro:\n" << c.getCostoFierro() << "\n";
    o << "Ladrillos:\n" << c.getCostoLadrillos() << "\n";
    o << "Herramientas Usadas:\n" << c.getListaHerramientas() << "\n";
    o << "Clavos:\n" << c.getCostoClavos() << "\n";
    o << "Tornillos:\n" << c.getCostoTornillos() << "\n";
    o << "Ventanas:\n" << c.getCostoVentanas() << "\n";
    o << "Puertas:\n" << c.getCostoPuertas() << "\n";
    o << "Muebles Utilizados:\n" << c.getListaMuebles() << "\n";
    o << "Implementos Usados:\n" << c.getListaImplementos() << "\n";
    o << "Personal Contratado:\n" << c.getCostoPersonal() << "\n";
    o << "Costo Total Generado:\n" << c.getCostoTotal() << "\n";
    return o;
}
ObraConstruccion::ObraConstruccion(){
    costoTotal = 0;
    costoTotal += maquinas.getCabeza()->getElemento().getCosto();
    costoTotal += cemento.getCosto();
    costoTotal += fierros.getCosto();
    costoTotal += ladrillos.getCosto();
    costoTotal += herramientas.getCabeza()->getElemento().getCosto();
    costoTotal += clavos.getCosto();
    costoTotal += tornillos.getCosto();
    costoTotal += ventanas.getCosto();
    costoTotal += puertas.getCosto();
    costoTotal += muebles.getCabeza()->getElemento().getCosto();
    costoTotal += implementos.getCabeza()->getElemento().getCosto();
    costoTotal += personal.getCosto();
}
void ObraConstruccion::setListaMaquinas(Lista<CostoMaquina> maquinas){
    this->maquinas = maquinas;
}
void ObraConstruccion::setCostoCemento(CostoCemento cemento){
    this->cemento = cemento;
}
void ObraConstruccion::setCostoFierro(CostoFierro fierros){
    this->fierros = fierros;
}
void ObraConstruccion::setCostoLadrillos(CostoLadrillos ladrillos){
    this->ladrillos = ladrillos;
}
void ObraConstruccion::setListaHerramientas(Lista<CostoHerramientas> herramientas){
    this->herramientas = herramientas;
}
void ObraConstruccion::setCostoClavos(CostoClavos clavos){
    this->clavos = clavos;
}
void ObraConstruccion::setCostoTornillos(CostoTornillos tornillos){
    this->tornillos = tornillos;
}
void ObraConstruccion::setCostoVentanas(CostoVentanas ventanas){
    this->ventanas = ventanas;
}
void ObraConstruccion::setCostoPuertas(CostoPuertas puertas){
    this->puertas = puertas;
}
void ObraConstruccion::setListaMuebles(Lista<CostoMueble> muebles){
    this->muebles = muebles;
}
void ObraConstruccion::setListaImplementos(Lista<CostoImplementos> implementos){
    this->implementos = implementos;
}
void ObraConstruccion::setCostoPersonal(CostoPersonal personal){
    this->personal = personal;
}
float ObraConstruccion::getCostoTotal()const{
    return costoTotal;
}
CostoPersonal ObraConstruccion::getCostoPersonal()const{
    return personal;
}
Lista<CostoImplementos> ObraConstruccion::getListaImplementos()const{
    return implementos;
}
Lista<CostoMueble> ObraConstruccion::getListaMuebles()const{
    return muebles;
}
CostoPuertas ObraConstruccion::getCostoPuertas()const{
    return puertas;
}
CostoVentanas ObraConstruccion::getCostoVentanas()const{
    return ventanas;
}
CostoTornillos ObraConstruccion::getCostoTornillos()const{
    return tornillos;
}
CostoClavos ObraConstruccion::getCostoClavos()const{
    return clavos;
}
Lista<CostoHerramientas> ObraConstruccion::getListaHerramientas()const{
    return herramientas;
}
CostoLadrillos ObraConstruccion::getCostoLadrillos()const{
    return ladrillos;
}
CostoFierro ObraConstruccion::getCostoFierro()const{
    return fierros;
}
CostoCemento ObraConstruccion::getCostoCemento()const{
    return cemento;
}
Lista<CostoMaquina> ObraConstruccion::getListaMaquinas()const{
    return maquinas;
}
ObraConstruccion::~ObraConstruccion(){
    std::cout<<"...Destruyendo ObraConstruccion...\n";
}
#endif