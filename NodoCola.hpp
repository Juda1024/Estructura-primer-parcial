#ifndef NODOCOLA_HPP
#define NODOCOLA_HPP

struct NodoCola {
    int valor;
    NodoCola* siguiente;

    NodoCola(int val) : valor(val), siguiente(nullptr) {}
};

#endif
