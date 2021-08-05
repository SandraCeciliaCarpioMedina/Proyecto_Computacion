#ifndef _COSTOIMPLEMENTOS_H_
#define _COSTOIMPLEMENTOS_H_
#include <iostream>
class CostoImplementos{
    private:
        float costo;
        std::string marca;
        std::string tienda;
        float impuesto;
        std::string nombre;
    public:
        CostoImplementos();
        CostoImplementos(float,std::string,std::string,std::string);
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
        friend std::ostream& operator<<(std::ostream &o, const CostoImplementos &i);
        ~CostoImplementos();
};
std::ostream& operator<<(std::ostream &o, const CostoImplementos &i){
    o << "Costo Implemento: " << i.getCosto() << "\n";
    o << "Marca Implemento: " << i.getMarca() << "\n";
    o << "Tienda Implemento: " << i.getTienda() << "\n";
    o << "Impuesto Implemento: " << i.getImpuesto() << "\n";
    o << "Nombre Implemento: " << i.getNombre() << "\n";
    return o;
}
CostoImplementos::CostoImplementos(){
    std::cout<<"Ingrese Costo de implemento: "; std::cin>>costo;
    std::cout<<"Ingrese marca de implemento: "; std::cin>>marca;
    std::cout<<"Ingrese tienda: "; std::cin>>tienda;
    std::cout<<"Ingrese Nombre de implemento: "; std::cin>>nombre;
    impuesto=0.18*costo;
}
CostoImplementos::CostoImplementos(float costo, std::string marca, std::string tienda, std::string nombre){
    this->costo=costo;
    this->nombre=nombre;
    this->marca=marca;
    this->tienda=tienda;
    impuesto=0.18*costo;
}
void CostoImplementos::setCosto(float costo){
    this->costo = costo;
}
void CostoImplementos::setImpuesto(float impuesto){
    this->impuesto = impuesto;
}
void CostoImplementos::setMarca(std::string marca){
    this->marca=marca;
}
void CostoImplementos::setTienda(std::string tienda){
    this->tienda = tienda;
}
void CostoImplementos::setNombre(std::string nombre){
    this->nombre = nombre;
}
float CostoImplementos::getCosto()const{
    return costo;
}
float CostoImplementos::getImpuesto()const{
    return impuesto;
}
std::string CostoImplementos::getMarca()const{
    return marca;
}
std::string CostoImplementos::getTienda()const{
    return tienda;
}
std::string CostoImplementos::getNombre()const{
    return nombre;
}
CostoImplementos::~CostoImplementos(){
    std::cout<<"...Destruyendo CostoImplementos...\n";
}
#endif