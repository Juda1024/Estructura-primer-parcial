#pragma once
#include <SFML/Graphics.hpp>
#include "stack.hpp"

class Visualizer {
public:
    Visualizer();
    void drawStack(const Stack& stack);
    void animatePush(const Stack& stack, int value);
    void animatePop(const Stack& stack, int value);
    void animateTop(const Stack& stack);
};
