#ifndef LISTA_HPP
#define LISTA_HPP

#include "NodoLista.hpp"
#include <iostream>

class Lista {
private:
    NodoLista* cabeza;

public:
    Lista();
    ~Lista();

    void insertar(int valor);         // Inserta al final
    bool eliminar(int valor);         // Elimina el primer nodo con ese valor
    void mostrar() const;             // Muestra todos los nodos

    NodoLista* obtenerCabeza() const; // Para la vista (visualización)
    void mostrarRecursivo() const;    // Versión recursiva
    void mostrarRecursivo(NodoLista* nodo) const;
};

#endif

