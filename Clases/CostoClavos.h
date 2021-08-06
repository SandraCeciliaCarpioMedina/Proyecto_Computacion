#ifndef _COSTOCLAVOS_H_
#define _COSTOCLAVOS_H_
#include <iostream>
class CostoClavos{
    private:
        float costo;
        std::string tienda;
        float impuesto;
    public:
        CostoClavos();
        CostoClavos(float&&,std::string&&);
        void setCosto(float&&);
        void setImpuesto(float&&);
        void setTienda(std::string&&);
        float getCosto()const;
        float getImpuesto()const;
        std::string getTienda()const;
        friend std::ostream& operator<<(std::ostream &o, const CostoClavos &c);
        ~CostoClavos();
};
std::ostream& operator<<(std::ostream &o, const CostoClavos &c){
    o << "Costo Clavos: " << c.getCosto() << "\n";
    o << "Tienda Clavos: " << c.getTienda() << "\n";
    o << "Impuestos Clavos: " << c.getImpuesto() << "\n";
    return o;
}
CostoClavos::CostoClavos(){
    std::cout<<"Ingrese costo de clavos: "; std::cin>>costo;
    std::cout<<"Ingrese nombre de tienda: "; std::cin>>tienda;
    impuesto=0.18*costo;
}
CostoClavos::CostoClavos(float &&costo, std::string &&tienda){
    this->costo=costo;
    this->tienda=tienda;
    impuesto=0.18*costo;
}
void CostoClavos::setCosto(float &&costo){
    this->costo = costo;
}
void CostoClavos::setImpuesto(float &&impuesto){
    this->impuesto = impuesto;
}
void CostoClavos::setTienda(std::string &&tienda){
    this->tienda = tienda;
}
float CostoClavos::getCosto()const{
    return costo;
}
float CostoClavos::getImpuesto()const{
    return impuesto;
}
std::string CostoClavos::getTienda()const{
    return tienda;
}
CostoClavos::~CostoClavos(){
}
#endif