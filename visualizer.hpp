#pragma once
#include <SFML/Graphics.hpp>
#include "stack.hpp"

class Visualizer {
public:
    Visualizer();
    void drawStack(const Stack& stack);
};
