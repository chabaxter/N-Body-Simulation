/*
    Charles Baxter
    Driver program for PS2b
    10/6/2021
*/

#include <iostream>
#include <string>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Universe.h"

int main(int argc, char* argv[]) {
    sf::Vector2u dim{ 800, 600 };
    sf::RenderWindow window(sf::VideoMode(dim.x, dim.y), "N-Body Simulation");

    sf::Font font;
    sf::Text text;
    font.loadFromFile("Comfortaa-Regular.ttf");
    text.setFont(font);

    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("2001.wav"))
        return EXIT_FAILURE;
    sf::Sound sound(buffer);
    sound.play();

    double T = std::stod(std::string{ argv[1] });
    double t = std::stod(std::string{ argv[2] });
    double elapsed{ 0 };

    int numParticles;
    double r;

    std::cin >> numParticles >> r;

    Universe universe(r, dim, numParticles);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        universe.step(t);
        elapsed += t;

        text.setString("Elapsed: " + std::to_string(int(elapsed)));

        window.clear();
        window.draw(universe);
        window.draw(text);
        window.display();
        
        if (elapsed > T)
            window.close();
    }

    std::cout << universe << std::endl;

    return EXIT_SUCCESS;
}