#include <cstdlib>
#include <iostream>
#include "Critter.h"
#include "Board.h"

void Critter::move(Board* board, int randSeed) {
    int moveTo = rand() % 8; //represents position of 8 surrounding squares
    int vertFactor = 0, horizFactor = 0;

    //find vertical movement amount
    if (moveTo < 3) {
        vertFactor = -1;
    } else if (moveTo >= 5) {
        vertFactor = 1;
    }

    //find horizontal movement amount
    if (moveTo == 2 || moveTo == 4 || moveTo == 7) {
        horizFactor = 1;
    } else if (moveTo == 0 || moveTo == 3 || moveTo == 5) {
        horizFactor = -1;
    }

    int newX = this->xPos + horizFactor;
    int newY = this->yPos + vertFactor;
    //std::cout << newX << " " << newY;
    if (newX < 0 || newX >= board->width
     || newY < 0 || newY >= board->height) {
        //bounce back
        return;
    }

    if (board->layout[newY][newX] == nullptr) {
        board->layout[newY][newX] = this;
        board->layout[this->yPos][this->xPos] = nullptr;
        this->xPos = newX;
        this->yPos = newY;
        this->timeSinceLastMove = 0;
    }
}