#include "list_visualizer.hpp"
#include <sstream>
#include <SFML/System/Sleep.hpp>

ListVisualizer::ListVisualizer() {}

void ListVisualizer::drawList(const Lista& lista) {
    sf::RenderWindow window(sf::VideoMode({900, 200}, 32), "Visualizador de Lista");
    sf::Font font;
    if (!font.openFromFile("arial.ttf")) return;

    while (window.isOpen()) {
        while (auto eventOpt = window.pollEvent()) {
            if (eventOpt->is<sf::Event::Closed>()) window.close();
        }

        window.clear(sf::Color::White);

        NodoLista* current = lista.head;
        int x = 50;
        while (current) {
            // Dibuja el nodo
            sf::RectangleShape rect(sf::Vector2f(60, 60));
            rect.setFillColor(sf::Color::Cyan);
            rect.setOutlineColor(sf::Color::Black);
            rect.setOutlineThickness(2);
            rect.setPosition(sf::Vector2f(x, 70));

            std::stringstream ss;
            ss << current->value;
            sf::Text text(font, ss.str(), 24);
            text.setFillColor(sf::Color::Black);
            text.setPosition(sf::Vector2f(x + 15, 90));

            window.draw(rect);
            window.draw(text);

            // Dibuja la flecha al siguiente nodo
            if (current->next) {
                sf::Vertex v1, v2;
                v1.position = sf::Vector2f(x + 60, 100);
                v1.color = sf::Color::Black;
                v2.position = sf::Vector2f(x + 80, 100);
                v2.color = sf::Color::Black;
                sf::Vertex line[] = { v1, v2 };
                window.draw(line, 2, sf::PrimitiveType::Lines);

                // Flecha (triángulo)
                sf::CircleShape arrow(5, 3);
                arrow.setFillColor(sf::Color::Black);
                arrow.setPosition(sf::Vector2f(x + 75, 95));
                arrow.setRotation(sf::degrees(90));
                window.draw(arrow);
            }

            x += 100;
            current = current->next;
        }

        window.display();
    }
}
void ListVisualizer::animateInsertFinal(const Lista& lista, int value) {
    sf::RenderWindow window(sf::VideoMode({900, 200}, 32), "Animación Insertar al Final");
    sf::Font font;
    if (!font.openFromFile("arial.ttf")) return;

    int steps = 20;
    int startX = 10;
    int endX = 50;
    NodoLista* current = lista.head;
    while (current) {
        endX += 100;
        current = current->next;
    }

    for (int i = 0; i <= steps && window.isOpen(); ++i) {
        while (auto eventOpt = window.pollEvent()) {
            if (eventOpt->is<sf::Event::Closed>()) window.close();
        }
        window.clear(sf::Color::White);

        // Dibuja la lista actual
        NodoLista* curr = lista.head;
        int x = 50;
        while (curr) {
            sf::RectangleShape rect(sf::Vector2f(60, 60));
            rect.setFillColor(sf::Color::Cyan);
            rect.setOutlineColor(sf::Color::Black);
            rect.setOutlineThickness(2);
            rect.setPosition(sf::Vector2f(x, 70));
            std::stringstream ss;
            ss << curr->value;
            sf::Text text(font, ss.str(), 24);
            text.setFillColor(sf::Color::Black);
            text.setPosition(sf::Vector2f(x + 15, 90));
            window.draw(rect);
            window.draw(text);

            if (curr->next) {
                sf::Vertex v1, v2;
                v1.position = sf::Vector2f(x + 60, 100);
                v1.color = sf::Color::Black;
                v2.position = sf::Vector2f(x + 80, 100);
                v2.color = sf::Color::Black;
                sf::Vertex line[] = { v1, v2 };
                window.draw(line, 2, sf::PrimitiveType::Lines);

                sf::CircleShape arrow(5, 3);
                arrow.setFillColor(sf::Color::Black);
                arrow.setPosition(sf::Vector2f(x + 75, 95));
                arrow.setRotation(sf::degrees(90));
                window.draw(arrow);
            }
            x += 100;
            curr = curr->next;
        }

        // Dibuja el nuevo nodo animado
        float animX = startX + (endX - startX) * i / float(steps);
        sf::RectangleShape animRect(sf::Vector2f(60, 60));
        animRect.setFillColor(sf::Color::Green);
        animRect.setOutlineColor(sf::Color::Black);
        animRect.setOutlineThickness(2);
        animRect.setPosition(sf::Vector2f(animX, 70));
        sf::Text animText(font, std::to_string(value), 24);
        animText.setFillColor(sf::Color::Black);
        animText.setPosition(sf::Vector2f(animX + 15, 90));
        window.draw(animRect);
        window.draw(animText);

        window.display();
        sf::sleep(sf::milliseconds(70));
    }
}

void ListVisualizer::animateInsertInicio(const Lista& lista, int value) {
    sf::RenderWindow window(sf::VideoMode({900, 200}, 32), "Animación Insertar al Inicio");
    sf::Font font;
    if (!font.openFromFile("arial.ttf")) return;

    int steps = 20;
    int startX = 10;
    int endX = 50;

    for (int i = 0; i <= steps && window.isOpen(); ++i) {
        while (auto eventOpt = window.pollEvent()) {
            if (eventOpt->is<sf::Event::Closed>()) window.close();
        }
        window.clear(sf::Color::White);

        // Dibuja la lista actual
        NodoLista* curr = lista.head;
        int x = 50;
        while (curr) {
            sf::RectangleShape rect(sf::Vector2f(60, 60));
            rect.setFillColor(sf::Color::Cyan);
            rect.setOutlineColor(sf::Color::Black);
            rect.setOutlineThickness(2);
            rect.setPosition(sf::Vector2f(x, 70));
            std::stringstream ss;
            ss << curr->value;
            sf::Text text(font, ss.str(), 24);
            text.setFillColor(sf::Color::Black);
            text.setPosition(sf::Vector2f(x + 15, 90));
            window.draw(rect);
            window.draw(text);

            if (curr->next) {
                sf::Vertex v1, v2;
                v1.position = sf::Vector2f(x + 60, 100);
                v1.color = sf::Color::Black;
                v2.position = sf::Vector2f(x + 80, 100);
                v2.color = sf::Color::Black;
                sf::Vertex line[] = { v1, v2 };
                window.draw(line, 2, sf::PrimitiveType::Lines);

                sf::CircleShape arrow(5, 3);
                arrow.setFillColor(sf::Color::Black);
                arrow.setPosition(sf::Vector2f(x + 75, 95));
                arrow.setRotation(sf::degrees(90));
                window.draw(arrow);
            }
            x += 100;
            curr = curr->next;
        }

        // Dibuja el nuevo nodo animado
        float animX = startX + (endX - startX) * i / float(steps);
        sf::RectangleShape animRect(sf::Vector2f(60, 60));
        animRect.setFillColor(sf::Color::Green);
        animRect.setOutlineColor(sf::Color::Black);
        animRect.setOutlineThickness(2);
        animRect.setPosition(sf::Vector2f(animX, 70));
        sf::Text animText(font, std::to_string(value), 24);
        animText.setFillColor(sf::Color::Black);
        animText.setPosition(sf::Vector2f(animX + 15, 90));
        window.draw(animRect);
        window.draw(animText);

        window.display();
        sf::sleep(sf::milliseconds(70));
    }
}

void ListVisualizer::animateDelete(const Lista& lista, int value) {
    sf::RenderWindow window(sf::VideoMode({900, 200}, 32), "Animación Eliminar");
    sf::Font font;
    if (!font.openFromFile("arial.ttf")) return;

    int highlightFrames = 30;
    for (int frame = 0; frame < highlightFrames && window.isOpen(); ++frame) {
        while (auto eventOpt = window.pollEvent()) {
            if (eventOpt->is<sf::Event::Closed>()) window.close();
        }
        window.clear(sf::Color::White);

        NodoLista* curr = lista.head;
        int x = 50;
        while (curr) {
            sf::RectangleShape rect(sf::Vector2f(60, 60));
            if (curr->value == value && (frame / 5) % 2 == 0)
                rect.setFillColor(sf::Color::Red); // Resalta el nodo a eliminar
            else
                rect.setFillColor(sf::Color::Cyan);
            rect.setOutlineColor(sf::Color::Black);
            rect.setOutlineThickness(2);
            rect.setPosition(sf::Vector2f(x, 70));
            std::stringstream ss;
            ss << curr->value;
            sf::Text text(font, ss.str(), 24);
            text.setFillColor(sf::Color::Black);
            text.setPosition(sf::Vector2f(x + 15, 90));
            window.draw(rect);
            window.draw(text);

            if (curr->next) {
                sf::Vertex v1, v2;
                v1.position = sf::Vector2f(x + 60, 100);
                v1.color = sf::Color::Black;
                v2.position = sf::Vector2f(x + 80, 100);
                v2.color = sf::Color::Black;
                sf::Vertex line[] = { v1, v2 };
                window.draw(line, 2, sf::PrimitiveType::Lines);

                sf::CircleShape arrow(5, 3);
                arrow.setFillColor(sf::Color::Black);
                arrow.setPosition(sf::Vector2f(x + 75, 95));
                arrow.setRotation(sf::degrees(90));
                window.draw(arrow);
            }
            x += 100;
            curr = curr->next;
        }

        window.display();
        sf::sleep(sf::milliseconds(70));
    }
}

void ListVisualizer::animateSearch(const Lista& lista, int value) {
    sf::RenderWindow window(sf::VideoMode({900, 200}, 32), "Animación Buscar");
    sf::Font font;
    if (!font.openFromFile("arial.ttf")) return;

    int highlightFrames = 30;
    for (int frame = 0; frame < highlightFrames && window.isOpen(); ++frame) {
        while (auto eventOpt = window.pollEvent()) {
            if (eventOpt->is<sf::Event::Closed>()) window.close();
        }
        window.clear(sf::Color::White);

        NodoLista* curr = lista.head;
        int x = 50;
        while (curr) {
            sf::RectangleShape rect(sf::Vector2f(60, 60));
            if (curr->value == value && (frame / 5) % 2 == 0)
                rect.setFillColor(sf::Color::Yellow);
            else
                rect.setFillColor(sf::Color::Cyan);
            rect.setOutlineColor(sf::Color::Black);
            rect.setOutlineThickness(2);
            rect.setPosition(sf::Vector2f(x, 70));
            std::stringstream ss;
            ss << curr->value;
            sf::Text text(font, ss.str(), 24);
            text.setFillColor(sf::Color::Black);
            text.setPosition(sf::Vector2f(x + 15, 90));
            window.draw(rect);
            window.draw(text);

            if (curr->next) {
                sf::Vertex v1, v2;
                v1.position = sf::Vector2f(x + 60, 100);
                v1.color = sf::Color::Black;
                v2.position = sf::Vector2f(x + 80, 100);
                v2.color = sf::Color::Black;
                sf::Vertex line[] = { v1, v2 };
                window.draw(line, 2, sf::PrimitiveType::Lines);

                sf::CircleShape arrow(5, 3);
                arrow.setFillColor(sf::Color::Black);
                arrow.setPosition(sf::Vector2f(x + 75, 95));
                arrow.setRotation(sf::degrees(90));
                window.draw(arrow);
            }
            x += 100;
            curr = curr->next;
        }

        window.display();
        sf::sleep(sf::milliseconds(70));
    }
}
