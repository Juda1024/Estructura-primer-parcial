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
