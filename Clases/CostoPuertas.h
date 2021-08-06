#ifndef _COSTOPUERTAS_H_
#define _COSTOPUERTAS_H_
#include <iostream>
class CostoPuertas{
    private:
        float costo;
        std::string tienda;
        float impuesto;
    public:
        CostoPuertas();
        CostoPuertas(float,std::string);
        void setCosto(float);
        void setImpuesto(float);
        void setTienda(std::string);
        float getCosto()const;
        float getImpuesto()const;
        std::string getTienda()const;
        friend std::ostream& operator<<(std::ostream &o,const CostoPuertas &p);
        ~CostoPuertas();
};
std::ostream& operator<<(std::ostream &o,const CostoPuertas &p){
    o << "Costo Puertas: " << p.getCosto() << "\n";
    o << "Tienda Puertas: " << p.getTienda() << "\n";
    o << "Impuesto Puertas: " << p.getImpuesto() << "\n";
    return o;
}
CostoPuertas::CostoPuertas(){
    std::cout<<"Ingrese el costo de las puertas: "; std::cin>>costo;
    std::cout<<"Ingrese nombre de tienda: "; std::cin>>tienda;
    impuesto=0.18*costo;
}
CostoPuertas::CostoPuertas(float costo, std::string tienda){
    this->costo=costo;
    this->tienda=tienda;
    impuesto=0.18*costo;
}
void CostoPuertas::setCosto(float costo){
    this->costo = costo;
}
void CostoPuertas::setImpuesto(float impuesto){
    this->impuesto = impuesto;
}
void CostoPuertas::setTienda(std::string tienda){
    this->tienda = tienda;
}
float CostoPuertas::getCosto()const{
    return costo;
}
float CostoPuertas::getImpuesto()const{
    return impuesto;
}
std::string CostoPuertas::getTienda()const{
    return tienda;
}
CostoPuertas::~CostoPuertas(){
}
#endif