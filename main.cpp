#include <iostream>
#include "stack.hpp"
#include "cola.hpp"
#include "list.hpp"
#include "visualizer.hpp"
#include "cola_visualizer.hpp"
#include "list_visualizer.hpp"
using namespace std;

void mostrarMenu() {
    cout << "\n--- MENU PRINCIPAL ---\n";
    cout << "1. Operaciones de pila\n";
    cout << "2. Operaciones de cola\n";
    cout << "3. Operaciones de lista\n";
    cout << "4. Salir\n";
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

void mostrarSubmenuCola() {
    cout << "\n--- OPERACIONES DE COLA ---\n";
    cout << "1. Enqueue (encolar)\n";
    cout << "2. Dequeue (desencolar)\n";
    cout << "3. Front (ver frente)\n";
    cout << "4. Mostrar cola (recursivo)\n";
    cout << "5. Visualizar cola (SFML)\n";
    cout << "6. Volver al menu principal\n";
    cout << "Seleccione una opcion: ";
}

void mostrarSubmenuLista() {
    cout << "\n--- OPERACIONES DE LISTA ---\n";
    cout << "1. Insertar al inicio\n";
    cout << "2. Insertar al final\n";
    cout << "3. Eliminar por valor\n";
    cout << "4. Buscar valor\n";
    cout << "5. Mostrar lista (recursivo)\n";
    cout << "6. Visualizar lista (SFML)\n";
    cout << "7. Volver al menu principal\n";
    cout << "Seleccione una opcion: ";
}


int main() {
    Stack pila;
    Cola cola;
    Lista lista;
    Visualizer visual;
    ColaVisualizer colaVisual;
    ListVisualizer listVisual;
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
                            else{
                                int valor = pila.peek();
                                visual.animatePop(pila, valor);
                                pila.pop();
                                cout << "Valor desapilado: " << valor << "\n";
                            }
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
                do {
                    mostrarSubmenuCola();
                    cin >> subopcion;
                    switch (subopcion) {
                        case 1:
                            cout << "Ingrese valor a encolar: ";
                            cin >> valor;
                            colaVisual.animateEnqueue(cola, valor);
                            cola.enqueue(valor);
                            cout << "Valor encolado.\n";
                            break;
                        case 2:
                            if (cola.isEmpty())
                                cout << "La cola esta vacia.\n";
                            else {
                                int valor = cola.getFront();
                                colaVisual.animateDequeue(cola, valor);
                                cola.dequeue();
                                cout << "Valor desencolado: " << valor << "\n";
                            }
                            break;
                        case 3:
                            if (cola.isEmpty())
                                cout << "La cola esta vacia.\n";
                            else
                                colaVisual.animateFront(cola);
                                cout << "Valor en el frente: " << cola.getFront() << "\n";
                            break;
                        case 4:
                            cout << "Cola (de frente a final): ";
                            cola.printRecursive(cola.front);
                            cout << "\n";
                            break;
                        case 5:
                            colaVisual.drawCola(cola);
                            break;
                        case 6:
                            cout << "Volviendo al menu principal...\n";
                            break;
                        default:
                            cout << "Opcion invalida.\n";
                    }
                } while (subopcion != 6);
                break;
            case 3:
                do {
                    mostrarSubmenuLista();
                    cin >> subopcion;
                    switch (subopcion) {
                        case 1:
                            cout << "Valor a insertar al inicio: ";
                            cin >> valor;
                            listVisual.animateInsertInicio(lista, valor);
                            lista.insertarInicio(valor);
                            cout << "Insertado al inicio.\n";
                            break;
                        case 2:
                            cout << "Valor a insertar al final: ";
                            cin >> valor;
                            listVisual.animateInsertFinal(lista, valor);
                            lista.insertarFinal(valor);
                            cout << "Insertado al final.\n";
                            break;
                        case 3:
                            cout << "Valor a eliminar: ";
                            cin >> valor;
                            listVisual.animateDelete(lista, valor);
                            if (lista.eliminar(valor))
                                cout << "Eliminado.\n";
                            else
                                cout << "No encontrado.\n";
                            break;
                        case 4:
                            cout << "Valor a buscar: ";
                            cin >> valor;
                            listVisual.animateSearch(lista, valor);
                            if (lista.buscar(valor))
                                cout << "Encontrado.\n";
                            else
                                cout << "No encontrado.\n";
                            break;
                        case 5:
                            cout << "Lista: ";
                            lista.printRecursive(lista.head);
                            cout << "\n";
                            break;
                        case 6:
                            listVisual.drawList(lista);
                            break;
                        case 7:
                            cout << "Volviendo al menu principal...\n";
                            break;
                        default:
                            cout << "Opcion invalida.\n";
                    }
                } while (subopcion != 7);
                break;
            case 4:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 4);

    return 0;
}
