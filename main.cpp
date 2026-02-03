#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
    unsigned int wWidth = 800;
    unsigned int wHeight= 600;

    sf::RenderWindow window(sf::VideoMode({ wWidth, wHeight }), "Example window");

    window.setFramerateLimit(60);

    sf::CircleShape circle;
    circle.setRadius(15);
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(sf::Vector2f(100, 100));

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::Black);

        window.draw(circle);

        window.display();
    }
}