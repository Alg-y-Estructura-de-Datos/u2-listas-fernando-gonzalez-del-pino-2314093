#include <iostream>
#include "Lista/Lista.h"
using namespace std;

/*Implementar una función llamada “printLista” que reciba una lista y una posición “p” e imprima
los elementos de esa lista a partir de la posición “p”. No debe modificarse la lista original. Ej:
listaOriginal: 1->2->3->4->5->6->7->8->9->10 con p=5 Por pantalla se verá: 5->6->7->8->9->10 */

void printLista(Lista<int> lista, int p){
    int t = lista.getTamanio();

    if (p >= t || p < 0) {
        cout << "La posicion " << p << " esta fuera de los limites de la lista." << endl;
        return;
    }

    for (int i = p; i < t; i++) {
        cout << lista.getDato(i) << "->";
    }

    cout << "NULL" << endl;
}

int main() {
    Lista<int> lista;
    int l, n, p;

    cout << "\nIngrese la cantidad de elementos de la lista: " << endl;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Elemento [" << i + 1 << "]:" << endl;
        cin >> l;
        lista.insertarUltimo(l);
    }

    cout << "Ingrese desde que numero quiere imprimir la lista: " << endl;
    cin >> p;

    cout << "\nLista: " << endl;
    printLista(lista, p);

    return 0;
}
