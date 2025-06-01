#include "Lista.hpp"

Lista::Lista() {
    cabeza = nullptr;
}

Lista::~Lista() {
    while (cabeza != nullptr) {
        NodoLista* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}

void Lista::insertar(int valor) {
    NodoLista* nuevo = new NodoLista(valor);
    if (!cabeza) {
        cabeza = nuevo;
    } else {
        NodoLista* actual = cabeza;
        while (actual->siguiente) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
}

bool Lista::eliminar(int valor) {
    if (!cabeza) return false;

    if (cabeza->valor == valor) {
        NodoLista* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
        return true;
    }

    NodoLista* actual = cabeza;
    while (actual->siguiente && actual->siguiente->valor != valor) {
        actual = actual->siguiente;
    }

    if (actual->siguiente) {
        NodoLista* temp = actual->siguiente;
        actual->siguiente = temp->siguiente;
        delete temp;
        return true;
    }

    return false;
}

void Lista::mostrar() const {
    NodoLista* actual = cabeza;
    while (actual) {
        std::cout << actual->valor << " -> ";
        actual = actual->siguiente;
    }
    std::cout << "NULL\n";
}

NodoLista* Lista::obtenerCabeza() const {
    return cabeza;
}

// Función recursiva para mostrar la lista
void Lista::mostrarRecursivo() const {
    mostrarRecursivo(cabeza);
}

void Lista::mostrarRecursivo(NodoLista* nodo) const {
    if (!nodo) {
        std::cout << "NULL\n";
        return;
    }
    std::cout << nodo->valor << " -> ";
    mostrarRecursivo(nodo->siguiente);
}
