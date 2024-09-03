#include <iostream>
#include "Lista/Lista.h"
using namespace std;

/*Crear un programa que pida al usuario dar elementos a una Lista de números
 enteros. Luego cree una función que reciba una lista int L1 y devuelva
 otra lista int L2 conteniendo los elementos repetidos de L1. Por ejemplo,
 si L1 almacena los valores 5->2->7-> 2->5->5->1, debe construirse una lista L2
 con los valores 5->2. Si en L1 no hay elementos repetidos se debe indicar al
 usuario que no hay elementos repetidos en L1, de lo contrario imprimir ambas listas.*/

void repetidos(Lista<int> l1){
    Lista<int> l2;
    Lista<int> yaVistos;
    Lista<int> repetidos;

    for (int i = 0; i < l1.getTamanio(); i++) {
        int valor = l1.getDato(i);
        bool yaVisto = false;
        bool esRepetido = false;

        // Verificar si el valor ya ha sido visto
        for (int j = 0; j < yaVistos.getTamanio(); j++) {
            if (yaVistos.getDato(j) == valor) {
                yaVisto = true;
                break;
            }
        }

        // Si el valor ya ha sido visto, se marca como repetido
        if (yaVisto) {
            for (int j = 0; j < repetidos.getTamanio(); j++) {
                if (repetidos.getDato(j) == valor) {
                    esRepetido = true;
                    break;
                }
            }

            // Si es repetido y no está en L2, agregarlo a L2
            if (!esRepetido) {
                l2.insertarUltimo(valor);
                repetidos.insertarUltimo(valor);
            }
        } else {
            // Si el valor no ha sido visto antes, lo agregamos a la lista de vistos
            yaVistos.insertarUltimo(valor);
        }
    }

    if (l2.esVacia()) {
        cout << "No hay elementos repetidos en la lista." << endl;
    } else {
        cout << "\nLista con los numeros repetidos: " << endl;
        l2.print();
    }
}

int main(){
    Lista<int> l1;
    int t, l;

    cout << "\nIngrese la cantidad de elementos de la lista: " << endl;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cout << "Elemento [" << i + 1 << "]:" << endl;
        cin >> l;
        l1.insertarUltimo(l);
    }

    if (l1.esVacia()) {
        cout << "La lista esta vacia. No se pueden encontrar elementos repetidos." << endl;
        return 0;
    }

    cout << "\nLista original: " << endl;
    l1.print();

    repetidos(l1);

    return 0;
}