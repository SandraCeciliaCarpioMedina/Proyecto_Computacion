#ifndef _COSTOMUEBLE_H_
#define _COSTOMUEBLE_H_
#include <iostream>
class CostoMueble{
    private:
        float costo;
        std::string marca;
        std::string tienda;
        float impuesto;
        std::string nombre;
    public:
        CostoMueble();
        CostoMueble(float,std::string,std::string,std::string);
        void setCosto(float);
        void setImpuesto(float);
        void setMarca(std::string);
        void setTienda(std::string);
        void setNombre(std::string);
        float getCosto()const;
        float getImpuesto()const;
        std::string getMarca()const;
        std::string getTienda()const;
        std::string getNombre()const;
        friend std::ostream& operator<<(std::ostream &o, const CostoMueble &m);
        ~CostoMueble();
};
std::ostream& operator<<(std::ostream &o, const CostoMueble &m){
    o << "Costo de Mueble: " <<m.getCosto() << "\n";
    o << "Marca de Mueble: " <<m.getMarca() << "\n";
    o << "Tienda: " <<m.getTienda() << "\n";
    o << "Impuesto de Mueble: " <<m.getImpuesto() << "\n";
    o << "Nombre de Mueble: " <<m.getNombre() << "\n";
    return o;
}
CostoMueble::CostoMueble(){
    std::cout<<"Ingrese costo de mueble: "; std::cin>>costo;
    std::cout<<"Ingrese marca de mueble: "; std::cin>>marca;
    std::cout<<"Ingrese tienda: "; std::cin>>tienda;
    std::cout<<"Ingrese nombre de mueble: "; std::cin>>nombre;
    impuesto=0.18*costo;
}
CostoMueble::CostoMueble(float costo, std::string marca, std::string tienda, std::string nombre){
    this->costo=costo;
    this->nombre=nombre;
    this->marca=marca;
    this->tienda=tienda;
    impuesto=0.18*costo;
}
void CostoMueble::setCosto(float costo){
    this->costo = costo;
}
void CostoMueble::setImpuesto(float impuesto){
    this->impuesto = impuesto;
}
void CostoMueble::setMarca(std::string marca){
    this->marca=marca;
}
void CostoMueble::setTienda(std::string tienda){
    this->tienda = tienda;
}
void CostoMueble::setNombre(std::string nombre){
    this->nombre = nombre;
}
float CostoMueble::getCosto()const{
    return costo;
}
float CostoMueble::getImpuesto()const{
    return impuesto;
}
std::string CostoMueble::getMarca()const{
    return marca;
}
std::string CostoMueble::getTienda()const{
    return tienda;
}
std::string CostoMueble::getNombre()const{
    return nombre;
}
CostoMueble::~CostoMueble(){
}
#endif