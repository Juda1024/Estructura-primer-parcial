#pragma once

struct Node {
    int value;
    Node* next;
};

struct Stack {
    Node* top;
    Stack();
    ~Stack();
    void push(int val);
    int pop();
    int peek() const;
    bool isEmpty() const;
    void clear();
    void printRecursive(Node* node) const;
};
