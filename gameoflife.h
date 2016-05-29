#pragma once
#include "automaton.h"
#include "matrix.h"

#ifndef GAMEOFLIFE_HPP
#define GAMEOFLIFE_HPP

class GameOfLife : public Automaton {

private:
    GameOfLifeRenderer golRenderer;

public:
    Matrix matrix;

    /*
    useRandom = 0;
    use54dead = 1;
    useRPentomino = 2;
    */

    GameOfLife(sf::RenderWindow* window);

    void initialize(int initMethod);
    void evaluate();
    void render();
    int shouldLive(int posX, int posY);
};

#endif // GAMEOFLIFE_HPP
