#include "stack.hpp"
#include <iostream>
using namespace std;

Stack::Stack() : top(nullptr) {}

Stack::~Stack() { clear(); }

void Stack::push(int val) {
    Node* n = new Node{val, top};
    top = n;
}

int Stack::pop() {
    if (!top) return -1;
    int val = top->value;
    Node* temp = top;
    top = top->next;
    delete temp;
    return val;
}

int Stack::peek() const {
    if (!top) return -1;
    return top->value;
}

bool Stack::isEmpty() const {
    return top == nullptr;
}

void Stack::clear() {
    while (top) pop();
}

void Stack::printRecursive(Node* node) const {
    if (!node) return;
    printRecursive(node->next);
    cout << "[" << node->value << "] ";
}
