#ifndef _PERSONA_H_
#define _PERSONA_H_
#include <iostream>
class Persona{
    private:
        std::string nombre;
        int edad;
    public:
        Persona();
        Persona(std::string, int);
        std::string getNombre()const;
        int getEdad()const;
        void setNombre(std::string);
        void setEdad(int);
        friend std::ostream& operator<<(std::ostream&, const Persona&);
        ~Persona();
};
Persona::Persona(){
    std::cout<<"Ingrese Nombre:"; std::cin>>nombre;
    std::cout<<"Ingrese Edad:"; std::cin>>edad;
}
Persona::Persona(std::string nombre,int edad){
    this->nombre = nombre;
    this->edad = edad;
}
std::string Persona::getNombre()const{
    return nombre;
}
int Persona::getEdad()const{
    return edad;
}
void Persona::setNombre(std::string nombre){
    this->nombre = nombre;
}
void Persona::setEdad(int edad){
    this->edad = edad;
}
std::ostream& operator<<(std::ostream& o, const Persona& p){
    o << "Nombre: " << p.nombre <<" , Edad: " << p.edad << "\n";
    return o;
}
Persona::~Persona(){
    std::cout<<"...Destruyendo Persona...\n";
}
#endif