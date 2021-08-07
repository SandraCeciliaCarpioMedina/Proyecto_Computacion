#ifndef _COSTOCEMENTO_H_
#define _COSTOCEMENTO_H_
#include <iostream>
class CostoCemento{
    private:
        float costo;
        std::string marca;
        std::string tienda;
        float impuesto;
    public:
        CostoCemento();
        CostoCemento(float&&,std::string&&,std::string&&);
        void setCosto(float&&);
        void setImpuesto(float&&);
        void setMarca(std::string&&);
        void setTienda(std::string&&);
        float getCosto()const;
        float getImpuesto()const;
        std::string getMarca()const;
        std::string getTienda()const;
        friend std::ostream& operator<<(std::ostream &o, const CostoCemento &c);
        ~CostoCemento();
};
std::ostream& operator<<(std::ostream &o, const CostoCemento &c){
    o << "Costo Cemento: " << c.getCosto() << "\n";
    o << "Marca Cemento: " << c.getMarca() << "\n";
    o << "Tienda Cemento: " << c.getTienda() << "\n";
    o << "Impuesto Cemento: " << c.getImpuesto() << "\n";
    return o;
}
CostoCemento::CostoCemento(){
    std::cout<<"Ingrese Costo Cemento: "; std::cin>>costo;
    std::cout<<"Ingrese marca de Cemento: "; std::cin>>marca;
    std::cout<<"Ingrese nombre de tienda donde se compro el cemento: "; std::cin>>tienda;
    impuesto=0.05*costo;
}
CostoCemento::CostoCemento(float &&costo, std::string &&marca, std::string &&tienda){
    this->costo=costo;
    this->marca=marca;
    this->tienda=tienda;
    impuesto=0.05*costo;
}
void CostoCemento::setCosto(float &&costo){
    this->costo = costo;
}
void CostoCemento::setImpuesto(float &&impuesto){
    this->impuesto = impuesto;
}
void CostoCemento::setMarca(std::string &&marca){
    this->marca=marca;
}
void CostoCemento::setTienda(std::string &&tienda){
    this->tienda = tienda;
}
float CostoCemento::getCosto()const{
    return costo;
}
float CostoCemento::getImpuesto()const{
    return impuesto;
}
std::string CostoCemento::getMarca()const{
    return marca;
}
std::string CostoCemento::getTienda()const{
    return tienda;
}
CostoCemento::~CostoCemento(){
}
#endif