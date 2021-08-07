#ifndef _SUELDO_H_
#define _SUELDO_H_
#include <iostream>
#include "Persona.h"
class Sueldo : public Persona{
    private:
        float sueldo;
        std::string ocupacion;
        bool civil;
    public:
        Sueldo();
        Sueldo(std::string&&,std::string&&,std::string&&,int&&,int&&,float&&,std::string&&,bool&&);
        void setSueldo(float&&);
        void setOcupacion(std::string&&);
        void setCivil(bool&&);
        float getSueldo()const;
        std::string getOcupacion()const;
        bool getCivil()const;
        Sueldo& operator=(Sueldo a){
            sueldo = a.sueldo;
            ocupacion = a.ocupacion;
            civil = a.civil;
            return *this;
        }
        friend std::ostream& operator<<(std::ostream &o, Sueldo &s);
        ~Sueldo();
};
std::ostream& operator<<(std::ostream &o,const Sueldo &s){
    bool civil = s.getCivil();
    o << "Nombre: " << s.getNombre() << "\n";
    o << "Apellido: " << s.getApellido() << "\n";
    o << "Ocupacion: " << s.getOcupacion() << "\n";
    o << "Edad: " << s.getEdad() << "\n";
    o << "DNI: " << s.getDni() << "\n";
    o << "Nacionalidad: " << s.getNacionalidad() << "\n";
    if (civil == false){
        o << "Civil: NO\n";
    }else{
        o << "Civil: SI\n";
    }
    o << "Sueldo: " << s.getSueldo() << "\n";
    return o;
}
Sueldo::Sueldo() : Persona(){
    int opc;
    std::cout<<"Ingrese sueldo: "; std::cin>>sueldo;
    std::cout<<"Ingrese ocupacion: "; std::cin>>ocupacion;
    std::cout<<"Si trabaja para el gobierno ingrese 0, caso contrario ingrese cualquier otro numero: ";
    std::cin>>opc;
    if(opc == 0){
        civil = false;
    } else{
        civil = true;
    }
}
Sueldo::Sueldo(std::string &&nacionalidad, std::string &&nombre, std::string &&apellido, int &&edad, int &&dni, float &&sueldo, std::string &&ocupacion, bool &&civil) : Persona(std::move(nacionalidad), std::move(nombre), std::move(apellido), std::move(edad), std::move(dni)){
    this->sueldo = sueldo;
    this->ocupacion = ocupacion;
    this->civil = civil;
}
void Sueldo::setSueldo(float &&sueldo){
    this->sueldo = sueldo;
}
void Sueldo::setOcupacion(std::string &&ocupacion){
    this->ocupacion = ocupacion;
}
void Sueldo::setCivil(bool &&civil){
    this->civil = civil;
}
float Sueldo::getSueldo()const{
    return sueldo;
}
std::string Sueldo::getOcupacion()const{
    return ocupacion;
}
bool Sueldo::getCivil()const{
    return civil;
}
Sueldo::~Sueldo(){
}
#endif