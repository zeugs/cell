#include "gameoflifeage.h"
#include <iostream>

GameOfLifeAge::GameOfLifeAge(sf::RenderWindow* window) {
    runCount = 0;
    golRenderer.window = window;
    golRenderer.matrix = &matrix;
}

void GameOfLifeAge::initialize(int initMethod) {
    if (initMethod == 0) {
        for (int x = 0; x < MATRIX_WIDTH; x++) {
            for (int y = 0; y < MATRIX_WIDTH; y++) {
                if (rand() % 5 == 0) {
                    matrix.fieldA[x][y] = rand()%80 + 1;
                }
            }
        }
    }

    if (initMethod == 1) {
        matrix.fieldA[80][40] = 40;
        matrix.fieldA[80][41] = 40;
        matrix.fieldA[80][42] = 40;

        matrix.fieldA[81][40] = 40;

        matrix.fieldA[82][40] = 40;
        matrix.fieldA[82][41] = 40;
        matrix.fieldA[82][42] = 40;

        matrix.fieldA[80][44] = 40;
        matrix.fieldA[80][45] = 40;
        matrix.fieldA[80][46] = 40;

        matrix.fieldA[81][46] = 40;

        matrix.fieldA[82][44] = 40;
        matrix.fieldA[82][45] = 40;
        matrix.fieldA[82][46] = 40;
    }

    if (initMethod == 2) {
        matrix.fieldA[90][50] = 40;
        matrix.fieldA[90][51] = 40;
        matrix.fieldA[90][52] = 40;

        matrix.fieldA[89][51] = 40;
        matrix.fieldA[91][50] = 40;
    }
};

void GameOfLifeAge::evaluate() {
    matrix.switchActiveField();

    runCount++;
    for (int x = 0; x < MATRIX_WIDTH; x++) {
        for (int y = 0; y < MATRIX_HEIGHT; y++) {
            bool lives = shouldLive(x, y);
            if (lives) {
                matrix.fieldB[x][y] = matrix.fieldA[x][y] < 83 ? matrix.fieldA[x][y] + 1: 0;
            } else {
                matrix.fieldB[x][y] = 0;
            }
        }
    }
};

void GameOfLifeAge::render() {
    golRenderer.renderMatrix();
}

bool GameOfLifeAge::shouldLive(int posX, int posY) {
    int neighbors[8];

    // 0 1 2
    // 7   3
    // 6 5 4
    int currentState = matrix.getState(posX, posY);

    neighbors[0] = matrix.getState(posX - 1, posY - 1);
    neighbors[1] = matrix.getState(posX, posY - 1);

    neighbors[2] = matrix.getState(posX + 1, posY - 1);
    neighbors[3] = matrix.getState(posX + 1, posY);
    neighbors[4] = matrix.getState(posX + 1, posY + 1);
    neighbors[5] = matrix.getState(posX, posY + 1);
    neighbors[6] = matrix.getState(posX - 1, posY + 1);
    neighbors[7] = matrix.getState(posX - 1, posY);

    int livingNeighbors = 0;
    for (int i = 0; i < 8; i++) {
        if (neighbors[i] > 0) {
            switch (neighbors[i]) {
            case 0 ... 6:
                livingNeighbors+=0;
                break;
            case 7 ... 14:
                livingNeighbors+=30;
                break;
            case 15 ... 26:
                livingNeighbors+=65;
                break;
            case 27 ... 65:
                livingNeighbors+=100;
                break;
            case 66 ... 82:
                livingNeighbors+=30;
                break;
            default:
                livingNeighbors+=0;
                break;
            }
        }
    }

    bool alive = false;
    if (currentState > 0) {
        float factor = 0;

        switch (currentState) {
            case 0 ... 6:
                factor=0.5;
                break;
            case 7 ... 14:
                factor=0.6;
                break;
            case 15 ... 26:
                factor=0.8;
                break;
            case 27 ... 65:
                factor=1.0;
                break;
            case 66 ... 82:
                factor=0.6;
                break;
            default:
                factor=0;
                break;
        }

        int neighborsResult = (int)(factor * livingNeighbors);

        // stasis
        if (neighborsResult >= 80 && neighborsResult < 336) {
            alive = true;
        }
    } else if (currentState == 0) {
        // reproduction
        if (livingNeighbors > 200) {
            alive = true;
        }
    }

    return alive;
}
