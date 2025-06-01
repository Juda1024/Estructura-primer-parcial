#include "VistaPila.hpp"
#include <sstream>
#include <SFML/Graphics.hpp>

// -------- ctor --------
VistaPila::VistaPila(Pila* pilaModelo, int w, int h)
        : modelo(pilaModelo),
          window(sf::VideoMode(w, h), "Visualizador de Pila") {
    window.setFramerateLimit(60);

    /* Necesitas colocar alguna fuente (p. ej. arial.ttf) junto al ejecutable.
       Cambia el nombre si usas otra. */
    if (!font.loadFromFile("arial.ttf")) {
        // Fuente no encontrada: usar font por defecto de SFML (solo para depurar)
    }
}

/* ============== MÉTODOS PÚBLICOS ============== */
void VistaPila::mostrar() {
    if (!window.isOpen()) return;
    drawEstructura();
}

/* Se llama justo DESPUÉS de hacer push en el modelo  */
void VistaPila::pushAnim(int valor) {
    if (!window.isOpen()) return;

    const float cx = window.getSize().x / 2.f - blockWidth / 2.f;
    float yActual  = window.getSize().y - blockHeight - 10.f;      // arranca abajo
    float yDestino = 50.f;                                         // tope de la pila

    while (yActual > yDestino && window.isOpen()) {
        sf::Event ev{};
        while (window.pollEvent(ev))
            if (ev.type == sf::Event::Closed) window.close();

        window.clear(sf::Color::White);
        drawEstructura();

        sf::RectangleShape rect(sf::Vector2f(blockWidth, blockHeight));
        rect.setFillColor(sf::Color(100, 149, 237));   // CornflowerBlue
        rect.setPosition(cx, yActual);
        window.draw(rect);

        sf::Text txt;
        txt.setFont(font);
        txt.setCharacterSize(24);
        txt.setFillColor(sf::Color::White);
        txt.setString(std::to_string(valor));
        txt.setPosition(cx + blockWidth / 2.f - txt.getLocalBounds().width / 2.f,
                        yActual + blockHeight / 2.f - txt.getLocalBounds().height);
        window.draw(txt);

        window.display();
        yActual -= 8.f;           // velocidad
    }
    drawEstructura();
}

/* Se llama justo DESPUÉS de hacer pop en el modelo */
void VistaPila::popAnim(int valor) {
    if (!window.isOpen()) return;

    const float yTop   = 50.f;
    float       xActual = window.getSize().x / 2.f - blockWidth / 2.f;
    const float xDestino = window.getSize().x + blockWidth;        // fuera de pantalla

    while (xActual < xDestino && window.isOpen()) {
        sf::Event ev{};
        while (window.pollEvent(ev))
            if (ev.type == sf::Event::Closed) window.close();

        window.clear(sf::Color::White);
        drawEstructura();

        sf::RectangleShape rect(sf::Vector2f(blockWidth, blockHeight));
        rect.setFillColor(sf::Color(178, 34, 34));     // FireBrick
        rect.setPosition(xActual, yTop);
        window.draw(rect);

        sf::Text txt;
        txt.setFont(font);
        txt.setCharacterSize(24);
        txt.setFillColor(sf::Color::White);
        txt.setString(std::to_string(valor));
        txt.setPosition(xActual + blockWidth / 2.f - txt.getLocalBounds().width / 2.f,
                        yTop + blockHeight / 2.f - txt.getLocalBounds().height);
        window.draw(txt);

        window.display();
        xActual += 10.f;         // velocidad
    }
    drawEstructura();
}

/* ============== MÉTODOS PRIVADOS ============== */
void VistaPila::drawEstructura() {
    window.clear(sf::Color::White);

    NodoPila* nodo = modelo->obtenerTope();
    int nivel = 0;
    while (nodo) {
        float x = window.getSize().x / 2.f - blockWidth / 2.f;
        float y = 50.f + nivel * (blockHeight + spacing);

        sf::RectangleShape rect(sf::Vector2f(blockWidth, blockHeight));
        rect.setFillColor(sf::Color(30, 144, 255));      // DodgerBlue
        rect.setPosition(x, y);
        window.draw(rect);

        sf::Text txt;
        txt.setFont(font);
        txt.setCharacterSize(24);
        txt.setFillColor(sf::Color::White);
        txt.setString(std::to_string(nodo->valor));
        txt.setPosition(x + blockWidth / 2.f - txt.getLocalBounds().width / 2.f,
                        y + blockHeight / 2.f - txt.getLocalBounds().height);
        window.draw(txt);

        nodo = nodo->siguiente;
        ++nivel;
    }
    window.display();
}
