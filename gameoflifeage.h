#pragma once
#include "automaton.h"
#include "matrix.h"

#ifndef GAMEOFLIFEAGE_HPP
#define GAMEOFLIFEAGE_HPP

class GameOfLifeAge : public Automaton {

private:
    GameOfLifeAgeRenderer golRenderer;

public:
    Matrix matrix;

    GameOfLifeAge(sf::RenderWindow* window);

    void initialize(int initMethod);
    void evaluate();
    void render();
    bool shouldLive(int posX, int posY);
};

#endif // GAMEOFLIFEAGE_HPP
