#include <iostream>
#include "stack.hpp"
#include "visualizer.hpp"
using namespace std;

void mostrarMenu() {
    cout << "\n--- MENU PRINCIPAL ---\n";
    cout << "1. Operaciones de pila\n";
    cout << "2. Salir\n";
    cout << "Seleccione una opcion: ";
}

void mostrarSubmenu() {
    cout << "\n--- OPERACIONES DE PILA ---\n";
    cout << "1. Push (apilar)\n";
    cout << "2. Pop (desapilar)\n";
    cout << "3. Top (ver tope)\n";
    cout << "4. Mostrar pila (recursivo)\n";
    cout << "5. Visualizar pila (SFML)\n";
    cout << "6. Volver al menu principal\n";
    cout << "Seleccione una opcion: ";
}

int main() {
    Stack pila;
    Visualizer visual;
    int opcion, subopcion, valor;

    do {
        mostrarMenu();
        cin >> opcion;
        switch (opcion) {
            case 1:
                do {
                    mostrarSubmenu();
                    cin >> subopcion;
                    switch (subopcion) {
                        case 1:
                            cout << "Ingrese valor a apilar: ";
                            cin >> valor;
                            visual.animatePush(pila, valor);
                            pila.push(valor);
                            cout << "Valor apilado.\n";
                            break;
                        case 2:
                            if (pila.isEmpty())
                                cout << "La pila esta vacia.\n";
                            else
                                int valor = pila.peek();
                                visual.animatePop(pila, valor);
                                pila.pop();
                                cout << "Valor desapilado: " << valor << "\n";
                            break;
                        case 3:
                            if (pila.isEmpty())
                                cout << "La pila esta vacia.\n";
                            else
                                visual.animateTop(pila);
                                cout << "Valor en el tope: " << pila.peek() << "\n";
                            break;
                        case 4:
                            cout << "Pila (de base a tope): ";
                            pila.printRecursive(pila.top);
                            cout << "\n";
                            break;
                        case 5:
                            visual.drawStack(pila);
                            break;
                        case 6:
                            cout << "Volviendo al menu principal...\n";
                            break;
                        default:
                            cout << "Opcion invalida.\n";
                    }
                } while (subopcion != 6);
                break;
            case 2:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 2);

    return 0;
}
