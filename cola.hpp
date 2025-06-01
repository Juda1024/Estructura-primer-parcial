#pragma once

struct NodoCola {
    int value;
    NodoCola* next;
};

struct Cola {
    NodoCola* front;
    NodoCola* rear;
    Cola();
    ~Cola();
    void enqueue(int val);
    int dequeue();
    int getFront() const;
    bool isEmpty() const;
    void clear();
    void printRecursive(NodoCola* node) const;
};
