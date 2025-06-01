#include "cola_visualizer.hpp"
#include <sstream>
#include <SFML/System/Sleep.hpp>

ColaVisualizer::ColaVisualizer() {}

void ColaVisualizer::drawCola(const Cola& cola) {
    sf::RenderWindow window(sf::VideoMode({800, 200}, 32), "Visualizador de Cola");
    sf::Font font;
    if (!font.openFromFile("arial.ttf")) return;

    while (window.isOpen()) {
        while (auto eventOpt = window.pollEvent()) {
            if (eventOpt->is<sf::Event::Closed>()) window.close();
        }

        window.clear(sf::Color::White);

        NodoCola* current = cola.front;
        int x = 50;
        while (current) {
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

            x += 80;
            current = current->next;
        }

        window.display();
    }
}

void ColaVisualizer::animateEnqueue(const Cola& cola, int value) {
    sf::RenderWindow window(sf::VideoMode({800, 200}, 32), "Animación ENQUEUE");
    sf::Font font;
    if (!font.openFromFile("arial.ttf")) return;

    int startX = 10;
    int endX = 50 + 80 * colaLength(cola);
    int steps = 20;

    for (int i = 0; i <= steps && window.isOpen(); ++i) {
        while (auto eventOpt = window.pollEvent()) {
            if (eventOpt->is<sf::Event::Closed>()) window.close();
        }
        window.clear(sf::Color::White);


        NodoCola* current = cola.front;
        int x = 50;
        while (current) {
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
            x += 80;
            current = current->next;
        }


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
        sf::sleep(sf::milliseconds(20));
    }
}


void ColaVisualizer::animateDequeue(const Cola& cola, int value) {
    sf::RenderWindow window(sf::VideoMode({800, 200}, 32), "Animación DEQUEUE");
    sf::Font font;
    if (!font.openFromFile("arial.ttf")) return;

    int startX = 50;
    int endX = 800;
    int steps = 20;

    for (int i = 0; i <= steps && window.isOpen(); ++i) {
        while (auto eventOpt = window.pollEvent()) {
            if (eventOpt->is<sf::Event::Closed>()) window.close();
        }
        window.clear(sf::Color::White);


        NodoCola* current = cola.front ? cola.front->next : nullptr;
        int x = 130;
        while (current) {
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
            x += 80;
            current = current->next;
        }


        float animX = startX + (endX - startX) * i / float(steps);
        sf::RectangleShape animRect(sf::Vector2f(60, 60));
        animRect.setFillColor(sf::Color::Red);
        animRect.setOutlineColor(sf::Color::Black);
        animRect.setOutlineThickness(2);
        animRect.setPosition(sf::Vector2f(animX, 70));
        sf::Text animText(font, std::to_string(value), 24);
        animText.setFillColor(sf::Color::Black);
        animText.setPosition(sf::Vector2f(animX + 15, 90));
        window.draw(animRect);
        window.draw(animText);

        window.display();
        sf::sleep(sf::milliseconds(20));
    }
}


void ColaVisualizer::animateFront(const Cola& cola) {
    sf::RenderWindow window(sf::VideoMode({800, 200}, 32), "Animación FRONT");
    sf::Font font;
    if (!font.openFromFile("arial.ttf")) return;

    int highlightFrames = 30;
    for (int frame = 0; frame < highlightFrames && window.isOpen(); ++frame) {
        while (auto eventOpt = window.pollEvent()) {
            if (eventOpt->is<sf::Event::Closed>()) window.close();
        }
        window.clear(sf::Color::White);

        NodoCola* current = cola.front;
        int x = 50;
        bool first = true;
        while (current) {
            sf::RectangleShape rect(sf::Vector2f(60, 60));
            if (first && (frame / 5) % 2 == 0)
                rect.setFillColor(sf::Color::Yellow); // Resalta el frente
            else
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
            x += 80;
            current = current->next;
            first = false;
        }

        window.display();
        sf::sleep(sf::milliseconds(40));
    }
}



