#pragma once
#include <SFML/Graphics.hpp>
#include "cola.hpp"

class ColaVisualizer {
public:
    ColaVisualizer();
    void drawCola(const Cola& cola);
    void animateEnqueue(const Cola& cola, int value);
    void animateDequeue(const Cola& cola, int value);
    void animateFront(const Cola& cola);
};
