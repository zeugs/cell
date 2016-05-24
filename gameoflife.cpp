#include "automaton.h"

GameOfLife::GameOfLife(sf::RenderWindow* window) {
    runCount = 0;
    golRenderer.window = window;
    golRenderer.matrix = &matrix;
}

void GameOfLife::initialize(int initMethod) {
    if (initMethod == 0) {
        for (int x = 0; x < MATRIX_WIDTH; x++) {
            for (int y = 0; y < MATRIX_WIDTH; y++) {
                if (rand() % 10 == 0) {
                    matrix.fieldA[x][y] = 1;
                }
            }
        }
    }

    if (initMethod == 1) {
        matrix.fieldA[80][40] = 1;
        matrix.fieldA[80][41] = 1;
        matrix.fieldA[80][42] = 1;

        matrix.fieldA[81][40] = 1;

        matrix.fieldA[82][40] = 1;
        matrix.fieldA[82][41] = 1;
        matrix.fieldA[82][42] = 1;

        matrix.fieldA[80][44] = 1;
        matrix.fieldA[80][45] = 1;
        matrix.fieldA[80][46] = 1;

        matrix.fieldA[81][46] = 1;

        matrix.fieldA[82][44] = 1;
        matrix.fieldA[82][45] = 1;
        matrix.fieldA[82][46] = 1;
    }

    if (initMethod == 2) {
        matrix.fieldA[90][50] = 1;
        matrix.fieldA[90][51] = 1;
        matrix.fieldA[90][52] = 1;

        matrix.fieldA[89][51] = 1;
        matrix.fieldA[91][50] = 1;
    }
};

void GameOfLife::evaluate() {
    matrix.switchActiveField();

    runCount++;
    for (int x = 0; x < MATRIX_WIDTH; x++) {
        for (int y = 0; y < MATRIX_HEIGHT; y++) {
            bool lives = shouldLive(x, y);
            if (lives) {
                matrix.fieldB[x][y] = 1;
            } else {
                matrix.fieldB[x][y] = 0;
            }
        }
    }
};

void GameOfLife::render() {
    golRenderer.renderMatrix();
}

bool GameOfLife::shouldLive(int posX, int posY) {
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
            livingNeighbors++;
        }
    }

    /*
        - alive and 2 or 3 neighbors => stasis
        - alive and less than 2 or more than 3 => under-/overpopulation
        - dead and 3 neighbors => reproduction
    */
    bool alive = false;
    if (currentState == 1) {
        // stasis
        if (livingNeighbors == 2 || livingNeighbors == 3) {
            alive = true;
        }
    } else if (currentState == 0) {
        // reproduction
        if (livingNeighbors == 3) {
            alive = true;
        }
    }

    return alive;
}
