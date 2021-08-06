#ifndef _OBRA_H_
#define _OBRA_H_
#include <iostream>
class Obra{
    protected:
        std::string nombre;
    public:
        Obra();
        Obra(std::string);
        std::string getNombreObra()const;
        ~Obra();
};
Obra::Obra(){
    std::cout<<"Nombre de Obra: ";
    std::cin>>nombre;
}
Obra::Obra(std::string nombre){
    this->nombre = nombre;
}
std::string Obra::getNombreObra()const{
    return nombre;
}
Obra::~Obra(){
    std::cout<<"...Destruyendo Obra...\n";
}
#endif