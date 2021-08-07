#include <iostream>
#include "LinkedList.h"
#include <string>

using namespace std;

int main()
{
    LinkedList<string> l;

    l.pushBack("gato");    //insertamos los nodos
    l.pushBack("perro");
    l.pushBack("raton");
    l.pushFront("hamster");

    l.print();

    //l.pop(2);   //removemos indicando la posicion
    l.popFront();
    l.popBack();

    l.print();

    return 0;
}
