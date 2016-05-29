#include "matrix.h"
#include <iostream>

Matrix::Matrix() {
    useFirstMatrix = true;
    fieldA = field1;
    fieldB = field2;
}

int Matrix::getState(int posX, int posY)
{
    if (posX < 0) {
        posX = MATRIX_WIDTH - 1;
    } else if (posX >= MATRIX_WIDTH) {
        posX = 0;
    }

    if (posY < 0) {
        posY = MATRIX_HEIGHT - 1;
    } else if (posY >= MATRIX_HEIGHT) {
        posY = 0;
    }

    return fieldA[posX][posY];
}

void Matrix::switchActiveField() {
    if (useFirstMatrix) {
        fieldA = field1;
        fieldB = field2;
    } else {
        fieldA = field2;
        fieldB = field1;
    }

    useFirstMatrix = !useFirstMatrix;
}

GameOfLifeRenderer::GameOfLifeRenderer() {
    unitBox.setSize(sf::Vector2f(PIX_WIDTH, PIX_HEIGHT));
};

void GameOfLifeRenderer::renderMatrix() {
    window->clear();
    for (int x = 0; x < MATRIX_WIDTH; x++) {
        for (int y = 0; y < MATRIX_HEIGHT; y++) {
            unitBox.setPosition(x * PIX_WIDTH, y * PIX_HEIGHT);
            bool lives = matrix->fieldB[x][y] == 1;
            if (lives) {
                unitBox.setFillColor(sf::Color::White);
            } else {
                unitBox.setFillColor(sf::Color::Black);
            }
            window->draw(unitBox);
        }
    }
    window->display();
};

GameOfLifeAgeRenderer::GameOfLifeAgeRenderer() {
    unitBox.setSize(sf::Vector2f(PIX_WIDTH, PIX_HEIGHT));
};

void GameOfLifeAgeRenderer::renderMatrix() {
    window->clear();
    for (int x = 0; x < MATRIX_WIDTH; x++) {
        for (int y = 0; y < MATRIX_HEIGHT; y++) {
            unitBox.setPosition(x * PIX_WIDTH, y * PIX_HEIGHT);
            bool lives = matrix->fieldB[x][y] > 0;
            sf::Color col;
            if (lives) {
                unitBox.setFillColor(sf::Color::White);
                //std::cout << matrix->fieldB[x][y] << " ";
                switch (matrix->fieldB[x][y]) {
                case 0 ... 6:
                    col = sf::Color::White;
                    break;
                case 7 ... 14:
                    col = sf::Color::Yellow;
                    break;
                case 15 ... 26:
                    col = sf::Color::Blue;
                    break;
                case 27 ... 65:
                    col = sf::Color::Green;
                    break;
                case 66 ... 82:
                    col = sf::Color::Magenta;
                    break;
                }
                unitBox.setFillColor(col);
            } else {
                unitBox.setFillColor(sf::Color::Black);
            }
            window->draw(unitBox);
        }
    }
    window->display();
    //std::cout << std::endl;
};

DrugTestRenderer::DrugTestRenderer() {
    unitBox.setSize(sf::Vector2f(PIX_WIDTH, PIX_HEIGHT));
};

void DrugTestRenderer::renderMatrix() {
    window->clear();
    for (int x = 0; x < MATRIX_WIDTH; x++) {
        for (int y = 0; y < MATRIX_HEIGHT; y++) {
            int color = matrix->fieldB[x][y];
            unsigned char red = (color & 0xFF000000) >> 24;
            unsigned char green = (color & 0x00FF0000) >> 16;
            unsigned char blue = (color & 0x0000FF00) >> 8;

            unitBox.setPosition(x * PIX_WIDTH, y * PIX_HEIGHT);
            unitBox.setFillColor(sf::Color(red, green, blue));
            window->draw(unitBox);
        }
    }
    window->display();
};
