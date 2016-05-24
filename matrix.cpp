#include "matrix.h"

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
