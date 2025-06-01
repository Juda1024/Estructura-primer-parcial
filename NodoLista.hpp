#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP

struct NodoLista {
    int valor;
    NodoLista* siguiente;

    NodoLista(int val) : valor(val), siguiente(nullptr) {}
};

#endif
