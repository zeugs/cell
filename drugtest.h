#pragma once
#include "automaton.h"
#include "matrix.h"

class DrugTest : public Automaton {

private:
    DrugTestRenderer dtRenderer;

public:
    Matrix matrix;

    DrugTest(sf::RenderWindow* window);

    void initialize(int initMethod);
    void evaluate();
    void render();
    int shouldLive(int posX, int posY);
};
