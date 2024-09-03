#include <iostream>
#include "Lista/Lista.h"
using namespace std;

/*Implementar una función que recibe una lista de números enteros y un número entero “n” y
que modifique la lista borrando todos los elementos de la lista que tengan el número “n”.
Imprimir la lista antes de hacer el llamado a la función y luego del llamado a la función para
mostrar que la lista original cambió. ej: lista: 1->2->3->4->5->3->7->8->3->10 con n=3 debe pasar
con la función a 1->2->4->5->7->8. */

void eliminar(Lista<int> &Lista, int n){
int i = 0;
    while (i < Lista.getTamanio()){
        if (Lista.getDato(i) == n){
            Lista.remover(i);
        }
        else {
            i++;
        }
    }
}

int main() {
Lista<int> lista;
int l, n, t;

    cout << "\nIngrese la cantidad de elementos de la lista: " << endl;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cout << "Elemento [" << i + 1 << "]:" << endl;
        cin >> l;
        lista.insertarUltimo(l);
    }

    cout << "Ingrese el numero que quiere eliminar de la lista: " << endl;
    cin >> n;

    cout << "\nLista antes: " << endl;
    lista.print();

    eliminar(lista, n);
    cout << "\nLista despues: " << endl;
    lista.print();

    return 0;
}
