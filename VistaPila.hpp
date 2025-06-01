#ifndef VISTAPILA_HPP
#define VISTAPILA_HPP

#include <SFML/Graphics.hpp>
#include "Pila.hpp"

class VistaPila {
private:
    Pila* modelo;                      // puntero al modelo (no lo modifica)
    sf::RenderWindow window;           // ventana SFML
    sf::Font font;                     // fuente para el texto

    /* Dimensiones de cada bloque-nodo */
    const int blockWidth  = 80;
    const int blockHeight = 40;
    const int spacing     = 10;

    // ================== helpers ==================
    void drawEstructura();             // dibuja la pila completa (sin animar)
    void animarPush(int valor);        // bloque sube desde abajo
    void animarPop(int valor);         // bloque se desplaza hacia la derecha

public:
    explicit VistaPila(Pila* pila, int w = 400, int h = 600);
    /* M�todos que usar� el controlador */
    void mostrar();                    // solo dibuja estado actual
    void pushAnim(int valor);          // animaci�n despu�s de push
    void popAnim(int valor);           // animaci�n despu�s de pop
};

#endif
