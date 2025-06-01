#ifndef COLA_HPP
#define COLA_HPP

#include "NodoCola.hpp"
#include <iostream>

class Cola {
private:
    NodoCola* frente;
    NodoCola* final;

public:
    Cola();
    ~Cola();

    void enqueue(int valor);
    int dequeue();
    int front() const;
    bool estaVacia() const;
    void mostrar() const;

    NodoCola* obtenerFrente() const;
};

#endif
