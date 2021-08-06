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
    cout<<"Obras Construcciones\n";
    ObraConstruccion b;
    impC = b.getImpuestoTotal();
    cout<<"Obras Eventos:\n";
    ObraEvento c;
    impE = c.getImpuestoTotal();
    cout<<"Gestionando Impuestos:\n";
    Impuestos impuestos(std::move(impE),std::move(impR),std::move(impC));
    cout << impuestos << endl;
    impR = impuestos.getImpuestos();
    impC = a.getCostoTotal() + b.getCostoTotal() + c.getCostoTotal();
    cout << "El costo total generado de las obras del gobierno es: S/." << impC << endl;
    if (impR >= impC){
        cout << "El capital del gobierno es estable\n";
    } else{
        cout<< "El capital del gobierno es insuficiente, ALERTA DE CRISIS\n";
    }
    return 0;
}