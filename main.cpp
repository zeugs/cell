#include <SFML/Graphics.hpp>
#include <iostream>

#include "matrix.h"
#include "automaton.h"

int main()
{
    int refreshMs = 19;
    bool calcAndUpdate = true;

    sf::RenderWindow window(sf::VideoMode(FULL_WIDTH, FULL_HEIGHT), "Cell");
    GameOfLife automaton(&window);
    sf::Clock Clock;

    srand(time(NULL));

    automaton.initialize(2);

    sf::Time runSpan;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Time timeSpan = Clock.getElapsedTime();
        runSpan += timeSpan;

        if (!calcAndUpdate || (calcAndUpdate && timeSpan.asMilliseconds() > refreshMs)) {
            automaton.evaluate();
        }

        if (timeSpan.asMilliseconds() > refreshMs) {
            std::cout << "run " << automaton.runCount << " at " << runSpan.asSeconds() << " (refresh interval: " << refreshMs << ")" << std::endl;
            automaton.render();
            Clock.restart();
        }
    }

    return 0;
}
