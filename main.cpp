#include <SFML/Graphics.hpp>
#include <iostream>

#include "matrix.h"
#include "gameoflife.h"
#include "gameoflifeage.h"
#include "drugtest.h"

int main()
{
    int refreshMs = 50;
    bool calcAndUpdate = true;

    // 0 = GOL, 1 = GOL Age, 2 = Drug Test
    int usedAutomaton = 2;

    sf::RenderWindow window(sf::VideoMode(FULL_WIDTH, FULL_HEIGHT), "Cell");
    GameOfLife gameOfLife(&window);
    GameOfLifeAge gameOfLifeAge(&window);
    DrugTest drugTest(&window);

    Automaton* automaton;
    sf::Clock Clock;

    srand(time(NULL));

    if (usedAutomaton == 0) {
        automaton = &gameOfLife;
    } else if (usedAutomaton == 1) {
        automaton = &gameOfLifeAge;
    } else if (usedAutomaton == 2) {
        automaton = &drugTest;
    }

    automaton->initialize(0);

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
            automaton->evaluate();
        }

        if (timeSpan.asMilliseconds() > refreshMs) {
            std::cout << "run " << automaton->runCount << " at " << runSpan.asSeconds() << " (refresh interval: " << refreshMs << ")" << std::endl;
            automaton->render();
            Clock.restart();
        }
    }

    return 0;
}
