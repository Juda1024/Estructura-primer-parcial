#include "cola.hpp"
#include <iostream>
using namespace std;

Cola::Cola() : front(nullptr), rear(nullptr) {}

Cola::~Cola() { clear(); }

void Cola::enqueue(int val) {
    NodoCola* n = new NodoCola{val, nullptr};
    if (rear) {
        rear->next = n;
        rear = n;
    } else {
        front = rear = n;
    }
}

int Cola::dequeue() {
    if (!front) return -1;
    int val = front->value;
    NodoCola* temp = front;
    front = front->next;
    if (!front) rear = nullptr;
    delete temp;
    return val;
}

int Cola::getFront() const {
    if (!front) return -1;
    return front->value;
}

bool Cola::isEmpty() const {
    return front == nullptr;
}

void Cola::clear() {
    while (front) dequeue();
}

void Cola::printRecursive(NodoCola* node) const {
    if (!node) return;
    cout << "[" << node->value << "] ";
    printRecursive(node->next);
}
