#ifndef _COSTOTORNILLOS_H_
#define _COSTOTORNILLOS_H_
#include <iostream>
class CostoTornillos{
    private:
        float costo;
        std::string tienda;
        float impuesto;
    public:
        CostoTornillos();
        CostoTornillos(float,std::string);
        void setCosto(float);
        void setImpuesto(float);
        void setTienda(std::string);
        float getCosto()const;
        float getImpuesto()const;
        std::string getTienda()const;
        friend std::ostream& operator<<(std::ostream &o,const CostoTornillos &t);
        ~CostoTornillos();
};
std::ostream& operator<<(std::ostream &o,const CostoTornillos &t){
    o << "Costo Tornillos: " << t.getCosto() << "\n";
    o << "Tienda Tornillos: " << t.getTienda() << "\n";
    o << "Impuesto Tornillos: " << t.getImpuesto() << "\n";
    return o;
}
CostoTornillos::CostoTornillos(){
    std::cout<<"Ingrese costo de tornillos: "; std::cin>>costo;
    std::cout<<"Ingrese nombre de tienda "; std::cin>>tienda;
    impuesto=0.18*costo;
}
CostoTornillos::CostoTornillos(float costo, std::string tienda){
    this->costo=costo;
    this->tienda=tienda;
    impuesto=0.18*costo;
}
void CostoTornillos::setCosto(float costo){
    this->costo = costo;
}
void CostoTornillos::setImpuesto(float impuesto){
    this->impuesto = impuesto;
}
void CostoTornillos::setTienda(std::string tienda){
    this->tienda = tienda;
}
float CostoTornillos::getCosto()const{
    return costo;
}
float CostoTornillos::getImpuesto()const{
    return impuesto;
}
std::string CostoTornillos::getTienda()const{
    return tienda;
}
CostoTornillos::~CostoTornillos(){
}
#endif