#include <iostream>
#include "Lista/CircList.h"
#include <thread>
#include <chrono>
using namespace std;

/* Sistema de Monitor Publicitario Circular
Desarrolla un programa para gestionar un monitor publicitario que debe mostrar frases de
 anuncios de manera circular. Para lograr esto, implementarás una solución utilizando una lista
 circular simplemente enlazada.
 Requisitos:
 1.
 Frases de Anuncios:
 ○ Cadafrase deanuncio será un texto simple que el monitor debe mostrar por
 vez.
 2. Mostrar Circularmente:
 ○ Lasfrases deben mostrarse en un formato circular, es decir, una vez que se ha
 mostrado la última frase, el monitor debe volver a mostrar la primera y así
 infinitamente.
 3. Implementación:
 ○ Utiliza una lista circular simplemente enlazada para gestionar el almacenamiento
 y la visualización de las frases. La lista circular debe permitir el recorrido
 continuo de los elementos.
 4. Operaciones Básicas:
 ○ Agregar Frases: Capacidad para añadir nuevas frases a la lista circular.
 ○ Eliminar Frases: Capacidad para eliminar frases específicas de la lista.
 ○ MostrarFrases: Implementa una función para mostrar las frases en el monitor
 de manera continua, recorriendo circularmente la lista e infinitamente*/

void mostrar(CircList<string> l){
    if (l.esVacia()) {
        cout << "\nLa lista esta vacia. No hay nada que contar." << endl;
        return;
    }
    int pos = 0;

    while(true) {
        cout << l.getDato(pos) << endl;
        pos = (pos + 1) % l.getTamanio();
        this_thread::sleep_for(chrono::seconds(3));
    }

}

int main(){
    CircList<string> l;
    string f;
    int t;

    cout << "\nIngrese el numero de frases: " << endl;
    cin >> t;
    cin.ignore();

    for (int i = 0; i < t; i++){
        cout << "\nIngrese una palabra o frase " << i + 1 << ":" << endl;
        getline(cin, f);
        l.insertarUltimo(f);
    }

    cout << endl;
    mostrar(l);

    return 0;
}