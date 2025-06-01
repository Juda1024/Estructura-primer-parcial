#include "Controller.hpp"
#include <iostream>

using namespace std;

Controller::Controller() : vistaPila(&pila) {}

void Controller::menuPrincipal() {
    int opcion;

    do {
        cout << "\n=== MENU PRINCIPAL ===\n";
        cout << "1. Gestion de Pila\n";
        cout << "2. Gestion de Cola\n";
        cout << "3. Gestion de Lista\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: menuPila(); break;
            case 2: menuCola(); break;
            case 3: menuLista(); break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida\n";
        }

    } while (opcion != 0);
}

// ================= PILA ===================

void Controller::menuPila() {
    int opcion, valor;

    do {
        cout << "\n--- Gestion de Pila ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Mostrar\n";
        cout << "0. Volver\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Valor a insertar: ";
                cin >> valor;
                pila.push(valor);
                vistaPila.pushAnim(valor);
                break;
            case 2:
                valor = pila.pop();
                if (valor != -1) {
                    cout << "Valor eliminado: " << valor << endl;
                    vistaPila.popAnim(valor);
                } else {
                    cout << "Pila vacia, nada que eliminar\n";
                }
                break;
            case 3:
                cout << "Tope: " << pila.top() << endl;
                vistaPila.mostrar();
                break;
            case 4:
                pila.mostrar();
                vistaPila.mostrar();
                break;
            case 0:
                break;
            default:
                cout << "Opcion invalida\n";
        }
    } while (opcion != 0);
}

// ================= COLA ===================

void Controller::menuCola() {
    int opcion, valor;

    do {
        cout << "\n--- Gestion de Cola ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        cout << "4. Mostrar\n";
        cout << "0. Volver\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Valor a insertar: ";
                cin >> valor;
                cola.enqueue(valor);
                break;
            case 2:
                valor = cola.dequeue();
                if (valor != -1)
                    cout << "Valor eliminado: " << valor << endl;
                else
                    cout << "Cola vacia, nada que eliminar\n";
                break;
            case 3:
                cout << "Frente: " << cola.front() << endl;
                break;
            case 4:
                cola.mostrar();
                break;
            case 0:
                break;
            default:
                cout << "Opcion invalida\n";
        }
    } while (opcion != 0);
}

// ================= LISTA ===================

void Controller::menuLista() {
    int opcion, valor;

    do {
        cout << "\n--- Gestion de Lista ---\n";
        cout << "1. Insertar\n";
        cout << "2. Eliminar\n";
        cout << "3. Mostrar\n";
        cout << "4. Mostrar (Recursivo)\n";
        cout << "0. Volver\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Valor a insertar: ";
                cin >> valor;
                lista.insertar(valor);
                break;
            case 2:
                cout << "Valor a eliminar: ";
                cin >> valor;
                if (lista.eliminar(valor)) {
                    cout << "Valor eliminado correctamente\n";
                } else {
                    cout << "Valor no encontrado\n";
                }
                break;
            case 3:
                lista.mostrar();
                break;
            case 4:
                lista.mostrarRecursivo();
                break;
            case 0:
                break;
            default:
                cout << "Opcion invalida\n";
        }
    } while (opcion != 0);
}
