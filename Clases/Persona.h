#ifndef _PERSONA_H_
#define _PERSONA_H_
#include <iostream>
#include "Sueldo.h"
class Persona{
    private:
        std::string nacionalidad;
        std::string nombre;
        std::string apellido;
        int edad;
        int dni;
        Sueldo sueldo;
    public:
        Persona();
        Persona(std::string, std::string, std::string, int, int);
        Persona(std::string, std::string, std::string, int, int, float, std::string, bool);
        std::string getNacionalidad()const;
        std::string getNombre()const;
        std::string getApellido()const;
        int getEdad()const;
        int getDni()const;
        float getSueldo()const;
        std::string getOcupacion()const;
        bool getCivil()const;
        void setNacionalidad(std::string);
        void setNombre(std::string);
        void setApellido(std::string);
        void setEdad(int);
        void setDni(int);
        void setSueldo(float);
        void setOcupacion(std::string);
        void setCivil(bool);
        ~Persona();
};
Persona::Persona(){
    std::cout<<"Ingrese nacionalidad: "; std::cin>>nacionalidad;
    std::cout<<"Ingrese nombre: "; std::cin>>nombre;
    std::cout<<"Ingrese apellido: "; std::cin>>apellido;
    std::cout<<"Ingrese edad: "; std::cin>>edad;
    std::cout<<"Ingrese dni: "; std::cin>>dni;
}
Persona::Persona(std::string nacionalidad, std::string nombre, std::string apellido, int edad, int dni){
    this->nacionalidad = nacionalidad;
    this->nombre = nombre;
    this->apellido = apellido;
    this->edad = edad;
    this->dni = dni;
}
Persona::Persona(std::string nacionalidad, std::string nombre, std::string apellido, int edad, int dni, float sueldo, std::string ocupacion, bool civil){
    this->nacionalidad = nacionalidad;
    this->nombre = nombre;
    this->apellido = apellido;
    this->edad = edad;
    this->dni = dni;
    this->sueldo.setSueldo(sueldo);
    this->sueldo.setOcupacion(ocupacion);
    this->sueldo.setCivil(civil);
}
std::string Persona::getNacionalidad()const{
    return nacionalidad;
}
std::string Persona::getNombre()const{
    return nombre;
}
std::string Persona::getApellido()const{
    return apellido;
}
int Persona::getEdad()const{
    return edad;
}
int Persona::getDni()const{
    return dni;
}
float Persona::getSueldo()const{
    return sueldo.getSueldo();
}
std::string Persona::getOcupacion()const{
    return sueldo.getOcupacion();
}
bool Persona::getCivil()const{
    return sueldo.getCivil();
}
void Persona::setNacionalidad(std::string nacionalidad){
    this->nacionalidad = nacionalidad;
}
void Persona::setNombre(std::string nombre){
    this->nombre = nombre;
}
void Persona::setApellido(std::string apellido){
    this->apellido = apellido;
}
void Persona::setEdad(int edad){
    this->edad = edad;
}
void Persona::setDni(int dni){
    this->dni = dni;
}
void Persona::setSueldo(float sueldo){
    this->sueldo.setSueldo(sueldo);
}
void Persona::setOcupacion(std::string ocupacion){
    this->sueldo.setOcupacion(ocupacion);
}
void Persona::setCivil(bool civil){
    this->sueldo.setCivil(civil);
}
Persona::~Persona(){
    std::cout<<"...Destruyendo Persona...\n";
}
#endif