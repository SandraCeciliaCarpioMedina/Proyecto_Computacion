#ifndef _FACTURA_H_
#define _FACTURA_H_
#include <iostream>
class Factura{
    private:
        float precio;
        float impuesto;
    public:
        Factura();
        Factura(float);
        float getPrecio()const;
        float getImpuesto()const;
        void setPrecio(float);
        ~Factura();
};
Factura::Factura(){
    std::cout<<"Ingrese precio de factura: "; std::cin>>precio;
    impuesto = 0.18*precio;
}
Factura::Factura(float precio){
    this->precio = precio;
    impuesto = 0.18*precio;
}
float Factura::getPrecio()const{
    return precio;
}
float Factura::getImpuesto()const{
    return impuesto;
}
void Factura::setPrecio(float precio){
    this->precio = precio;
    impuesto = 0.18*precio;
}
Factura::~Factura(){
}
#endif