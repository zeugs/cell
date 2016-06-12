#pragma once
#include "automaton.h"
#include "matrix.h"

class StarShips : public Automaton {

private:
    StarShipsRenderer dtRenderer;

public:
    Matrix matrix;

    StarShips(sf::RenderWindow* window);

    void initialize(int initMethod);
    void evaluate();
    void render();
    int shouldLive(int posX, int posY);
};

