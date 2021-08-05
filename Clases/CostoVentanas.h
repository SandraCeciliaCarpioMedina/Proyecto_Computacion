#ifndef _COSTOVENTANAS_H_
#define _COSTOVENTANAS_H_
#include <iostream>
class CostoVentanas{
    private:
        float costo;
        std::string tienda;
        float impuesto;
    public:
        CostoVentanas();
        CostoVentanas(float,std::string);
        void setCosto(float);
        void setImpuesto(float);
        void setTienda(std::string);
        float getCosto()const;
        float getImpuesto()const;
        std::string getTienda()const;
        friend std::ostream& operator<<(std::ostream &o,const CostoVentanas &v);
        ~CostoVentanas();
};
std::ostream& operator<<(std::ostream &o,const CostoVentanas &v){
    o << "Costo Ventanas: " << v.getCosto() << "\n";
    o << "Tienda Ventanas: " << v.getTienda() << "\n";
    o << "Impuesto Ventanas: " << v.getImpuesto() << "\n";
    return o;
}
CostoVentanas::CostoVentanas(){
    std::cout<<"Ingrese costo de ventanas: "; std::cin>>costo;
    std::cout<<"Ingrese nombre de tienda: "; std::cin>>tienda;
    impuesto=0.18*costo;
}
CostoVentanas::CostoVentanas(float costo, std::string tienda){
    this->costo=costo;
    this->tienda=tienda;
    impuesto=0.18*costo;
}
void CostoVentanas::setCosto(float costo){
    this->costo = costo;
}
void CostoVentanas::setImpuesto(float impuesto){
    this->impuesto = impuesto;
}
void CostoVentanas::setTienda(std::string tienda){
    this->tienda = tienda;
}
float CostoVentanas::getCosto()const{
    return costo;
}
float CostoVentanas::getImpuesto()const{
    return impuesto;
}
std::string CostoVentanas::getTienda()const{
    return tienda;
}
CostoVentanas::~CostoVentanas(){
    std::cout<<"...Destruyendo CostoVentanas...\n";
}
#endif