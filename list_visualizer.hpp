#pragma once
#include <SFML/Graphics.hpp>
#include "list.hpp"

class ListVisualizer {
public:
    ListVisualizer();
    void drawList(const Lista& lista);
    void animateInsertFinal(const Lista& lista, int value);
    void animateInsertInicio(const Lista& lista, int value);
    void animateDelete(const Lista& lista, int value);
    void animateSearch(const Lista& lista, int value);

};
