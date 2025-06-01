#ifndef NODOPILA_HPP
#define NODOPILA_HPP

struct NodoPila {
    int valor;
    NodoPila* siguiente;

    NodoPila(int val) : valor(val), siguiente(nullptr) {}
};

#endif
