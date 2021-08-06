#include <iostream>
#include "Persona.h"
#include "ObraConstruccion.h"
#include "ObraEvento.h"
#include "ObraReparacion.h"
#include "Impuestos.h"
using namespace std;
int main(){
    float impR, impC, impE;
    cout<<"Obras Reparaciones\n";
    ObraReparacion a;
    impR = a.getImpuestoTotal();
    cout<<"Obras Construcciones";
    ObraConstruccion b;
    impC = b.getImpuestoTotal();
    cout<<"Obras Eventos:\n";
    ObraEvento c;
    impE = c.getImpuestoTotal();
    cout<<"Gestionando Impuestos:\n";
    Impuestos impuestos(std::move(impE),std::move(impR),std::move(impC));
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << impuestos << endl;
    return 0;
}