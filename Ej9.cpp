#include <iostream>
#include "Lista/ListaDoble.h"
using namespace std;

/*Gestión de Historial de Navegación en un Navegador
 Desarrolla un programa que simule el historial de páginas web visitadas en un navegador
 utilizando una lista doblemente enlazada. El programa debe permitir al usuario retroceder y
 avanzar entre las páginas visitadas, mostrando sus direcciones en pantalla.
 Requisitos:
 1.
 Estructura de Datos:
 ○ Usaelconcepto de una lista doblemente enlazada para mantener el historial de
 páginas web visitadas.
 ○ Cadanododelalista debe almacenar la URL de la página web visitada.
 2. Funciones del Programa:
 ○ AñadirPágina: Permite agregar una nueva URL al final del historial de
 navegación.
 ○ Mostrar Histórico: Muestra todas las URLs del historial desde la más antigua a la
 más reciente.
 ○ Retroceder: Permite al usuario retroceder a la página web visitada
 anteriormente, mostrando la URL en pantalla.
 ○ Avanzar: Permite al usuario avanzar a la siguiente página web en el historial,
 mostrando la URL en pantalla.
 3. Interfaz del Usuario:
 ○ Lainterfaz debe ser de línea de comandos y debe permitir al usuario ingresar
 URLs y navegar a través del historial usando comandos simples.
○ Implementa unmenúparaqueel usuario pueda elegir entre las opciones
 disponibles: añadir una página, mostrar el historial, retroceder, avanzar, y salir
 del programa*/

void mostrarPaginaActual(const ListaDoble<string>& historial, int posicionActual) {
    if (posicionActual >= 0 && posicionActual < historial.getTamanio()) {
        cout << "Pagina actual: " << historial.getDato(posicionActual) << endl;
    } else {
        cout << "No hay ninguna pagina actual." << endl;
    }
}

void retroceder(ListaDoble<string>& historial, int& posicionActual) {
    if (posicionActual > 0) {
        --posicionActual;
        mostrarPaginaActual(historial, posicionActual);
    } else {
        cout << "No hay paginas anteriores en el historial." << endl;
    }
}

void avanzar(ListaDoble<string>& historial, int& posicionActual) {
    if (posicionActual >= 0 && posicionActual < historial.getTamanio() - 1) {
        ++posicionActual;
        mostrarPaginaActual(historial, posicionActual);
    } else {
        cout << "No hay paginas siguientes en el historial." << endl;
    }
}

void mostrarHistorial(const ListaDoble<string>& historial) {
    historial.imprimir();
}

void anadirPagina(ListaDoble<string>& historial, int& posicionActual) {
    string url;
    cout << "Ingrese la URL de la pagina: ";
    getline(cin, url);
    historial.insertarUltimo(url);
    // Si es la primera página añadida, establecemos la posición actual en 0.
    if (historial.getTamanio() == 1) {
        posicionActual = 0;
    } else {
        // Actualiza la posición actual a la última página añadida
        if( posicionActual != (historial.getTamanio() - 2)){

        }else{
            posicionActual = historial.getTamanio() - 1;
        }

    }
}

void mostrarMenu() {
    cout << "\nMenu:" << endl;
    cout << "1. Anadir pagina" << endl;
    cout << "2. Mostrar historial" << endl;
    cout << "3. Retroceder" << endl;
    cout << "4. Avanzar" << endl;
    cout << "5. Salir" << endl;
}

int main() {
    ListaDoble<string> historial;
    int posicionActual = - 1;
    int opcion;

    do {
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                anadirPagina(historial, posicionActual);
                break;
            case 2:
                mostrarHistorial(historial);
                break;
            case 3:
                retroceder(historial, posicionActual);
                break;
            case 4:
                avanzar(historial, posicionActual);
                break;
            case 5:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 5);

    return 0;
}