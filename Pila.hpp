#ifndef PILA_HPP
#define PILA_HPP

#include "NodoPila.hpp"
#include <iostream>

class Pila {
private:
    NodoPila* tope;

public:
    Pila();
    ~Pila();

    void push(int valor);
    int pop();
    int top() const;
    bool estaVacia() const;
    void mostrar() const; // Para debug o consola

    // Para que la vista acceda a los nodos y los dibuje
    NodoPila* obtenerTope() const;
};

#endif
