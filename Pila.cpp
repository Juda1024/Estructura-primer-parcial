#include "Pila.hpp"

Pila::Pila() {
    tope = nullptr;
}

Pila::~Pila() {
    while (!estaVacia()) {
        pop();
    }
}

void Pila::push(int valor) {
    NodoPila* nuevo = new NodoPila(valor);
    nuevo->siguiente = tope;
    tope = nuevo;
}

int Pila::pop() {
    if (estaVacia()) {
        std::cerr << "Error: Pila vacía\n";
        return -1; // O lanzar una excepción
    }

    NodoPila* temp = tope;
    int valor = temp->valor;
    tope = tope->siguiente;
    delete temp;
    return valor;
}

int Pila::top() const {
    if (estaVacia()) {
        std::cerr << "Error: Pila vacía\n";
        return -1;
    }
    return tope->valor;
}

bool Pila::estaVacia() const {
    return tope == nullptr;
}

void Pila::mostrar() const {
    NodoPila* actual = tope;
    while (actual != nullptr) {
        std::cout << actual->valor << " -> ";
        actual = actual->siguiente;
    }
    std::cout << "NULL\n";
}

NodoPila* Pila::obtenerTope() const {
    return tope;
}
