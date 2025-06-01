#include "list.hpp"
#include <iostream>
using namespace std;

Lista::Lista() : head(nullptr) {}

Lista::~Lista() { clear(); }

void Lista::insertarInicio(int val) {
    NodoLista* n = new NodoLista{val, head};
    head = n;
}

void Lista::insertarFinal(int val) {
    NodoLista* n = new NodoLista{val, nullptr};
    if (!head) {
        head = n;
    } else {
        NodoLista* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
    }
}

bool Lista::eliminar(int val) {
    NodoLista* curr = head;
    NodoLista* prev = nullptr;
    while (curr) {
        if (curr->value == val) {
            if (prev) prev->next = curr->next;
            else head = curr->next;
            delete curr;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
}

NodoLista* Lista::buscar(int val) const {
    NodoLista* temp = head;
    while (temp) {
        if (temp->value == val) return temp;
        temp = temp->next;
    }
    return nullptr;
}

bool Lista::isEmpty() const {
    return head == nullptr;
}

void Lista::clear() {
    while (head) {
        NodoLista* temp = head;
        head = head->next;
        delete temp;
    }
}

void Lista::printRecursive(NodoLista* node) const {
    if (!node) return;
    cout << "[" << node->value << "] ";
    printRecursive(node->next);
}

// Sobrecarga de operador ==
bool Lista::operator==(const Lista& otra) const {
    NodoLista* a = this->head;
    NodoLista* b = otra.head;
    while (a && b) {
        if (a->value != b->value)
            return false;
        a = a->next;
        b = b->next;
    }
    return a == nullptr && b == nullptr;
}
