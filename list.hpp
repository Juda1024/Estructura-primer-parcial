#pragma once

struct NodoLista {
    int value;
    NodoLista* next;
};

struct Lista {
    NodoLista* head;
    Lista();
    ~Lista();
    void insertarInicio(int val);
    void insertarFinal(int val);
    bool eliminar(int val);
    NodoLista* buscar(int val) const;
    bool isEmpty() const;
    void clear();
    void printRecursive(NodoLista* node) const;

    // Sobrecarga de operador ==
    bool operator==(const Lista& otra) const;
};
