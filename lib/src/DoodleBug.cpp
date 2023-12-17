//
// Created by David on 11/9/2023.
//

#include <iostream>
#include "DoodleBug.h"
#include "Board.h"

void DoodleBug::reproduce(Board* b) {

    int originX = this->xPos - 2;
    int originY = this->yPos - 2;
    bool success = false;

    bool** visited = new bool*[5];
    for (int row = 0; row < 5; row++) {
        visited[row] = new bool[5];
    }
    visited[2][2] = true;

    int eggsLaid = 0;

    while (eggsLaid < 2) {
        //std::cout << this->xPos << " " << this->yPos << std::endl;
        int xPos, yPos;

        bool stop = true;
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 5; x++) {
                if (!b->isValidCoord(originX + x, originY + y))
                    visited[y][x] = true;
                stop &= visited[y][x];
            }
        }
        if (stop)
            break;

        while(true) {
            xPos = rand() % 5;
            yPos = rand() % 5;
            if (!visited[yPos][xPos])
                break;
        }
        //std::cout << xPos << " " << yPos << std::endl;
        visited[yPos][xPos] = true;
        if (b->layout[originY + yPos][originX + xPos] == nullptr) {
            DoodleBug* baby = new DoodleBug();
            b->layout[originY + yPos][originX + xPos] = baby;
            baby->xPos = originX + xPos;
            baby->yPos = originY + yPos;
            b->currentPreds.push_back(baby);
            //std::cout << baby->xPos << baby->yPos << std::endl;
            eggsLaid++;
        }


    }
    for (int row = 0; row < 5; row++) {
        delete[] visited[row];
    }
    delete[] visited;
    this->hasReproduced = true;
}

void DoodleBug::eatBug(Board* b, Critter* other) {
    if (other->isEdible()) {
        this->hunger = 10;
        other->die(b);
    }
}

void DoodleBug::doodleMove(Board *b, int randSeed) {
    int originX = this->xPos - 1;
    int originY = this->yPos - 1;

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (b->isValidCoord(originX + col, originY + row)) {
                Critter* addr = b->layout[originY + row][originX + col];
                if (addr != nullptr) {
                    if (addr->isEdible()) {
                        this->eatBug(b, addr);
                        b->layout[originY + row][originX + col] = this;
                        b->layout[this->yPos][this->xPos] = nullptr;
                        this->yPos = originY + row;
                        this->xPos = originX + col;
                    }
                }
            }
        }
    }
}
