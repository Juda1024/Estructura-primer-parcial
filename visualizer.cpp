#include "visualizer.hpp"
#include <sstream>

Visualizer::Visualizer() {}

void Visualizer::drawStack(const Stack& stack) {
    sf::RenderWindow window(sf::VideoMode({400, 600}, 32), "Visualizador de Pila");
    sf::Font font;
    if (!font.openFromFile("arial.ttf")) {
        return;
    }

    while (window.isOpen()) {
        while (auto eventOpt = window.pollEvent()) {
            if (eventOpt->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::White);

        Node* current = stack.top;
        int y = 500;
        while (current) {
            sf::RectangleShape rect(sf::Vector2f(200, 40));
            rect.setFillColor(sf::Color::Cyan);
            rect.setOutlineColor(sf::Color::Black);
            rect.setOutlineThickness(2);
            rect.setPosition(sf::Vector2f(100, y));

            std::stringstream ss;
            ss << current->value;

            sf::Text text(font, ss.str(), 24);
            text.setFillColor(sf::Color::Black);
            text.setPosition(sf::Vector2f(190, y + 5));

            window.draw(rect);
            window.draw(text);

            y -= 50;
            current = current->next;
        }

        window.display();
    }
}

// Animación de PUSH
void Visualizer::animatePush(const Stack& stack, int value) {
    sf::RenderWindow window(sf::VideoMode({400, 600}, 32), "Animación PUSH");
    sf::Font font;
    if (!font.openFromFile("arial.ttf")) return;

    int startY = 0;
    int endY = 500 - (stack.isEmpty() ? 0 : 50 * stackLength(stack));
    int steps = 20;

    for (int i = 0; i <= steps && window.isOpen(); ++i) {
        while (auto eventOpt = window.pollEvent()) {
            if (eventOpt->is<sf::Event::Closed>()) window.close();
        }
        window.clear(sf::Color::White);

        // Dibuja la pila actual
        Node* current = stack.top;
        int y = 500;
        while (current) {
            sf::RectangleShape rect(sf::Vector2f(200, 40));
            rect.setFillColor(sf::Color::Cyan);
            rect.setOutlineColor(sf::Color::Black);
            rect.setOutlineThickness(2);
            rect.setPosition(sf::Vector2f(100, y));
            std::stringstream ss;
            ss << current->value;
            sf::Text text(font, ss.str(), 24);
            text.setFillColor(sf::Color::Black);
            text.setPosition(sf::Vector2f(190, y + 5));
            window.draw(rect);
            window.draw(text);
            y -= 50;
            current = current->next;
        }

        // Dibuja el nuevo bloque animado
        float animY = startY + (endY - startY) * i / float(steps);
        sf::RectangleShape animRect(sf::Vector2f(200, 40));
        animRect.setFillColor(sf::Color::Green);
        animRect.setOutlineColor(sf::Color::Black);
        animRect.setOutlineThickness(2);
        animRect.setPosition(sf::Vector2f(100, animY));
        sf::Text animText(font, std::to_string(value), 24);
        animText.setFillColor(sf::Color::Black);
        animText.setPosition(sf::Vector2f(190, animY + 5));
        window.draw(animRect);
        window.draw(animText);

        window.display();
        sf::sleep(sf::milliseconds(20));
    }
}

// Animación de POP
void Visualizer::animatePop(const Stack& stack, int value) {
    sf::RenderWindow window(sf::VideoMode({400, 600}, 32), "Animación POP");
    sf::Font font;
    if (!font.openFromFile("arial.ttf")) return;

    int startY = 500 - (stack.isEmpty() ? 0 : 50 * (stackLength(stack) - 1));
    int endY = 0;
    int steps = 20;

    for (int i = 0; i <= steps && window.isOpen(); ++i) {
        while (auto eventOpt = window.pollEvent()) {
            if (eventOpt->is<sf::Event::Closed>()) window.close();
        }
        window.clear(sf::Color::White);

        // Dibuja la pila sin el tope
        Node* current = stack.top ? stack.top->next : nullptr;
        int y = 500;
        while (current) {
            sf::RectangleShape rect(sf::Vector2f(200, 40));
            rect.setFillColor(sf::Color::Cyan);
            rect.setOutlineColor(sf::Color::Black);
            rect.setOutlineThickness(2);
            rect.setPosition(sf::Vector2f(100, y));
            std::stringstream ss;
            ss << current->value;
            sf::Text text(font, ss.str(), 24);
            text.setFillColor(sf::Color::Black);
            text.setPosition(sf::Vector2f(190, y + 5));
            window.draw(rect);
            window.draw(text);
            y -= 50;
            current = current->next;
        }

        // Dibuja el bloque animado saliendo
        float animY = startY + (endY - startY) * i / float(steps);
        sf::RectangleShape animRect(sf::Vector2f(200, 40));
        animRect.setFillColor(sf::Color::Red);
        animRect.setOutlineColor(sf::Color::Black);
        animRect.setOutlineThickness(2);
        animRect.setPosition(sf::Vector2f(100, animY));
        sf::Text animText(font, std::to_string(value), 24);
        animText.setFillColor(sf::Color::Black);
        animText.setPosition(sf::Vector2f(190, animY + 5));
        window.draw(animRect);
        window.draw(animText);

        window.display();
        sf::sleep(sf::milliseconds(20));
    }
}

// Animación de TOP (resalta el tope)
void Visualizer::animateTop(const Stack& stack) {
    sf::RenderWindow window(sf::VideoMode({400, 600}, 32), "Animación TOP");
    sf::Font font;
    if (!font.openFromFile("arial.ttf")) return;

    int highlightFrames = 30;
    for (int frame = 0; frame < highlightFrames && window.isOpen(); ++frame) {
        while (auto eventOpt = window.pollEvent()) {
            if (eventOpt->is<sf::Event::Closed>()) window.close();
        }
        window.clear(sf::Color::White);

        Node* current = stack.top;
        int y = 500;
        bool first = true;
        while (current) {
            sf::RectangleShape rect(sf::Vector2f(200, 40));
            if (first && (frame / 5) % 2 == 0)
                rect.setFillColor(sf::Color::Yellow); // Resalta el tope
            else
                rect.setFillColor(sf::Color::Cyan);
            rect.setOutlineColor(sf::Color::Black);
            rect.setOutlineThickness(2);
            rect.setPosition(sf::Vector2f(100, y));
            std::stringstream ss;
            ss << current->value;
            sf::Text text(font, ss.str(), 24);
            text.setFillColor(sf::Color::Black);
            text.setPosition(sf::Vector2f(190, y + 5));
            window.draw(rect);
            window.draw(text);
            y -= 50;
            current = current->next;
            first = false;
        }

        window.display();
        sf::sleep(sf::milliseconds(40));
    }
}


