#ifndef _PERSONA_H_
#define _PERSONA_H_
#include <iostream>
class Persona{
    private:
        std::string nacionalidad;
        std::string nombre;
        std::string apellido;
        int edad;
        int dni;
    public:
        Persona();
        Persona(std::string, std::string, std::string, int, int);
        std::string getNacionalidad()const;
        std::string getNombre()const;
        std::string getApellido()const;
        int getEdad()const;
        int getDni()const;
        void setNacionalidad(std::string);
        void setNombre(std::string);
        void setApellido(std::string);
        void setEdad(int);
        void setDni(int);
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
Persona::~Persona(){
}
#endif