#include <iostream>
#include "Lista/Lista.h"
using namespace std;

/*Implementar una función que intercambie los elementos entre 2 listas de números enteros que
recibe como parámetros. Si los tamaños de las listas son distintos, igual debe cambiar los datos
y cambiarían los tamaños de cada lista. Ejemplo sea lista1= 15->1->8->35->40->25->12 y lista2=
3->4->912->45->66 al ejecutar la función quedarían lista1= 3->4->912->45->66 y lista2=15->1->8
>35->40->25->12.*/

void intercambio(Lista<int>& l1, Lista<int>& l2){
    Lista<int> temp1;
    Lista<int> temp2;

    for (int i = 0; i <l1.getTamanio(); ++i) {
        temp1.insertarUltimo(l1.getDato(i));
    }

    for (int i = 0; i <l2.getTamanio(); ++i) {
        temp2.insertarUltimo(l2.getDato(i));
    }

    l1.vaciar();
    l2.vaciar();

    for (int i = 0; i <temp1.getTamanio(); ++i) {
        l2.insertarUltimo(temp1.getDato(i));
    }

    for (int i = 0; i <temp2.getTamanio(); ++i) {
        l1.insertarUltimo(temp2.getDato(i));
    }
}

int main() {
    Lista<int> l1;
    Lista<int> l2;

    int d, t1, t2;

    cout << "\nIngrese el tamanio de la primer lista: " << endl;
    cin >> t1;

    for (int i = 0; i < t1; ++i) {
        cout << "--Ingrese el elemento de la posicion " << i + 1 << ":" << endl;
        cin >> d;
        l1.insertarUltimo(d);
    }

    cout << "\nIngrese el tamanio de la segunda lista: " << endl;
    cin >> t2;

    for (int i = 0; i < t2; ++i) {
        cout << "--Ingrese el elemento de la posicion " << i + 1 << ":" << endl;
        cin >> d;
        l2.insertarUltimo(d);
    }

    cout << "\nListas antes del intercambio: " << endl;
    cout << "Lista 1: " << endl;
    l1.print();
    cout << "\nLista 2: " << endl;
    l2.print();

    intercambio(l1, l2);

    cout << "\nListas despues del intercambio: " << endl;
    cout << "Lista 1: " << endl;
    l1.print();
    cout << "\nLista 2: " << endl;
    l2.print();

    return 0;
}
