#include <iostream>
#include "Lista/Lista.h"
using namespace std;

/*Escribir un programa que pida al usuario una palabra o frase y la almacene en una Lista
separando letra por letra, luego pedirá al usuario una vocal que desee contar y, por último, se
debe imprimir por pantalla la lista y el número de veces que aparece la vocal en la palabra o
frase. Validar que la Lista no esté vacía y que la letra a contar que introduzca el usuario sea una
vocal.*/

bool EsVocal(char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int vocal(Lista<char>& l, char v){
    int contador = 0;
    for (int i = 0; i < l.getTamanio(); i++) {
        if (l.getDato(i) == v) {
            contador++;
        }
    }
    return contador;
}

int main(){
Lista<char> l;
string f;
char v;

    cout << "\nIngrese una palabra o frase: ";
    getline(cin, f);

    for (int i = 0; i < f.length(); ++i) {
        char c = f[i];
        l.insertarUltimo(c);
    }

    if (l.esVacia()) {
        cout << "\nLa lista esta vacia. No hay nada que contar." << endl;
        return 0;
    }

    cout << "\nIngrese una vocal para contar en la frase: ";
    cin >> v;

    if (!EsVocal(v)) {
        cout << "\nEl caracter ingresado no es una vocal." << endl;
        return 0;
    }

    cout << "\nLista: ";
    l.print();

    int cantidad = vocal(l, v);

    cout << "\nLa vocal '" << v << "' aparece " << cantidad << " veces en la lista" << endl;
    return 0;
}