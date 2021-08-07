#ifndef _COSTOREPARACIONES_H_
#define _COSTOREPARACIONES_H_
#include <iostream>
class CostoReparaciones{
    private:
        float costo;
        std::string nombre;
        float impuesto;
    public:
        CostoReparaciones();
        CostoReparaciones(float&&,std::string&&);
        void setCosto(float&&);
        void setImpuesto(float&&);
        void setNombre(std::string&&);
        float getCosto()const;
        float getImpuesto()const;
        std::string getNombre()const;
        friend std::ostream& operator<<(std::ostream &o,const CostoReparaciones &c);
        ~CostoReparaciones();
};
std::ostream& operator<<(std::ostream &o,const CostoReparaciones &c){
    o << "Costo Reparacion: " << c.getCosto() << "\n";
    o << "Nombre Reparacion: " << c.getNombre() << "\n";
    o << "Impuesto Reparacion: " << c.getImpuesto() << "\n";
    return o;
}
CostoReparaciones::CostoReparaciones(){
    std::cout<<"Ingrese Costo de Reparacion: "; std::cin>>costo;
    std::cout<<"Ingrese nombre de reparacion: "; std::cin>>nombre;
    impuesto=0.18*costo;
}
CostoReparaciones::CostoReparaciones(float &&costo, std::string &&nombre){
    this->costo=costo;
    this->nombre=nombre;
    impuesto=0.18*costo;
}
void CostoReparaciones::setCosto(float &&costo){
    this->costo = costo;
}
void CostoReparaciones::setImpuesto(float &&impuesto){
    this->impuesto = impuesto;
}
void CostoReparaciones::setNombre(std::string &&nombre){
    this->nombre = nombre;
}
float CostoReparaciones::getCosto()const{
    return costo;
}
float CostoReparaciones::getImpuesto()const{
    return impuesto;
}
std::string CostoReparaciones::getNombre()const{
    return nombre;
}
CostoReparaciones::~CostoReparaciones(){
}
#endif