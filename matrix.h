#pragma once
#include <SFML/Graphics.hpp>

#ifndef MATRIX_HPP
#define MATRIX_HPP

const int FULL_WIDTH = 800;
const int FULL_HEIGHT = 600;
const int PIX_WIDTH = 5;
const int PIX_HEIGHT = 5;
const int MATRIX_WIDTH = FULL_WIDTH / PIX_WIDTH;
const int MATRIX_HEIGHT = FULL_HEIGHT / PIX_HEIGHT;

class Matrix {
private:
    int field1[MATRIX_WIDTH][MATRIX_HEIGHT];
    int field2[MATRIX_WIDTH][MATRIX_HEIGHT];
    bool useFirstMatrix;

public:
    int (*fieldA)[MATRIX_HEIGHT];
    int (*fieldB)[MATRIX_HEIGHT];

    Matrix();
    int getState(int posX, int posY);
    void switchActiveField();
};

class GameOfLifeRenderer {
private:
    sf::RectangleShape unitBox;

public:
    Matrix* matrix;
    sf::RenderWindow* window;

    GameOfLifeRenderer();
    void renderMatrix();
};

class GameOfLifeAgeRenderer {
private:
    sf::RectangleShape unitBox;

public:
    Matrix* matrix;
    sf::RenderWindow* window;

    GameOfLifeAgeRenderer();
    void renderMatrix();
};

class DrugTestRenderer {
private:
    sf::RectangleShape unitBox;

public:
    Matrix* matrix;
    sf::RenderWindow* window;

    DrugTestRenderer();
    void renderMatrix();
};

class StarShipsRenderer {
private:
    sf::RectangleShape unitBox;

public:
    Matrix* matrix;
    sf::RenderWindow* window;

    StarShipsRenderer();
    void renderMatrix();
};
#endif // MATRIX_HPP
