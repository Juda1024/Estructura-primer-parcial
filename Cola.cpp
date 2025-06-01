#include "Cola.hpp"

Cola::Cola() {
    frente = nullptr;
    final = nullptr;
}

Cola::~Cola() {
    while (!estaVacia()) {
        dequeue();
    }
}

void Cola::enqueue(int valor) {
    NodoCola* nuevo = new NodoCola(valor);
    if (estaVacia()) {
        frente = final = nuevo;
    } else {
        final->siguiente = nuevo;
        final = nuevo;
    }
}

int Cola::dequeue() {
    if (estaVacia()) {
        std::cerr << "Error: Cola vacía\n";
        return -1;
    }

    NodoCola* temp = frente;
    int valor = temp->valor;
    frente = frente->siguiente;
    if (frente == nullptr) {
        final = nullptr;
    }
    delete temp;
    return valor;
}

int Cola::front() const {
    if (estaVacia()) {
        std::cerr << "Error: Cola vacía\n";
        return -1;
    }
    return frente->valor;
}

bool Cola::estaVacia() const {
    return frente == nullptr;
}

void Cola::mostrar() const {
    NodoCola* actual = frente;
    while (actual != nullptr) {
        std::cout << actual->valor << " -> ";
        actual = actual->siguiente;
    }
    std::cout << "NULL\n";
}

NodoCola* Cola::obtenerFrente() const {
    return frente;
}
