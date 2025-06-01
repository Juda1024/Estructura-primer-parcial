#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"
#include "VistaPila.hpp"

class Controller {
private:
    Pila pila;
    Cola cola;
    Lista lista;

    VistaPila* vistaPila;  // puntero para mejor control

public:
    Controller();
    ~Controller();

    void menuPrincipal();
    void menuPila();
    void menuCola();
    void menuLista();
};

#endif
