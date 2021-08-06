#ifndef _COSTOMAQUINA_H_
#define _COSTOMAQUINA_H_
#include <iostream>
class CostoMaquina{
    private:
        float costo;
        std::string marca;
        std::string tienda;
        float impuesto;
        std::string nombre;
    public:
        CostoMaquina();
        CostoMaquina(float&&,std::string&&,std::string&&,std::string&&);
        void setCosto(float&&);
        void setImpuesto(float&&);
        void setMarca(std::string&&);
        void setTienda(std::string&&);
        void setNombre(std::string&&);
        float getCosto()const;
        float getImpuesto()const;
        std::string getMarca()const;
        std::string getTienda()const;
        std::string getNombre()const;
        friend std::ostream& operator<<(std::ostream &o, const CostoMaquina &m);
        ~CostoMaquina();
};
std::ostream& operator<<(std::ostream &o, const CostoMaquina &m){
    o << "Costo Maquina: " << m.getCosto() << "\n";
    o << "Marca Maquina: " << m.getMarca() << "\n";
    o << "Tienda Maquina: " << m.getTienda() << "\n";
    o << "Impuesto Maquina: " << m.getImpuesto() << "\n";
    o << "Nombre Maquina: " << m.getNombre() << "\n";
    return o;
}
CostoMaquina::CostoMaquina(){
    std::cout<<"Ingrese Costo de la maquina: "; std::cin>>costo;
    std::cout<<"Ingrese marca de la maquina: "; std::cin>>marca;
    std::cout<<"Ingrese tienda: "; std::cin>>tienda;
    std::cout<<"Ingrese Nombre de la maquina: "; std::cin>>nombre;
    impuesto=0.18*costo;
}
CostoMaquina::CostoMaquina(float &&costo, std::string &&marca, std::string &&tienda, std::string &&nombre){
    this->costo=costo;
    this->nombre=nombre;
    this->marca=marca;
    this->tienda=tienda;
    impuesto=0.18*costo;
}
void CostoMaquina::setCosto(float &&costo){
    this->costo = costo;
}
void CostoMaquina::setImpuesto(float &&impuesto){
    this->impuesto = impuesto;
}
void CostoMaquina::setMarca(std::string &&marca){
    this->marca=marca;
}
void CostoMaquina::setTienda(std::string &&tienda){
    this->tienda = tienda;
}
void CostoMaquina::setNombre(std::string &&nombre){
    this->nombre = nombre;
}
float CostoMaquina::getCosto()const{
    return costo;
}
float CostoMaquina::getImpuesto()const{
    return impuesto;
}
std::string CostoMaquina::getMarca()const{
    return marca;
}
std::string CostoMaquina::getTienda()const{
    return tienda;
}
std::string CostoMaquina::getNombre()const{
    return nombre;
}
CostoMaquina::~CostoMaquina(){
}
#endif