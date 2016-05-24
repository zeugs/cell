#pragma once
#include "automaton.h"
#include "matrix.h"

#ifndef AUTOMATON_HPP
#define AUTOMATON_HPP

class GameOfLife : Automaton {

private:
    GameOfLifeRenderer golRenderer;

public:
    Matrix matrix;
    long runCount;

    /*
    useRandom = 0;
    use54dead = 1;
    useRPentomino = 2;
    */

    GameOfLife(sf::RenderWindow* window);

    void initialize(int initMethod);
    void evaluate();
    void render();
    bool shouldLive(int posX, int posY);
};

#endif // AUTOMATON_HPP
