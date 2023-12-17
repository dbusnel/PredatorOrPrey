//
// Created by David on 11/9/2023.
//

#include <iostream>
#include "QueenAnt.h"
#include "Board.h"
#include "MatingAnt.h"
#include "WorkerAnt.h"

void QueenAnt::layEgg(Board* b, int xPos, int yPos) {
    Prey* toLay;
    int decision = rand() % 1000;
    //std::cout << decision;
    if (decision <= 5) {
        toLay = new QueenAnt();
        this->retired = true;
    } else if (decision <= 400) {
        toLay = new MatingAnt();
    } else {
        toLay = new WorkerAnt();
    }
    toLay->xPos = xPos;
    toLay->yPos = yPos;

    if (b->layout[yPos][xPos] == nullptr) {
        b->layout[yPos][xPos] = toLay;
        b->currentPrey.push_back(toLay);
    }
}

void QueenAnt::tryBreed(Board* b) {
    int originX = this->xPos - 2;
    int originY = this->yPos - 2;

    bool breedingPossible = false;
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            if (b->isValidCoord(originX + col, originY + row))
                breedingPossible |= b->layout[originY + row][originX + col] == nullptr;
        }
    }

    breedingPossible &= !onBreedingCooldown;

    if (!breedingPossible) {
        if (this->timeAlive >= 60)
            delete this;
    } else {
        bool success = false;

        bool** visited = new bool*[5];
        for (int row = 0; row < 5; row++) {
            visited[row] = new bool[5];
        }
        visited[2][2] = true;
        int eggsLaid = 0;
        while (eggsLaid < 10) {
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
                this->layEgg(b, originX + xPos, originY + yPos);
                eggsLaid++;
            }
            //std::cout << eggsLaid;

        }
        for (int row = 0; row < 5; row++) {
            delete[] visited[row];
        }
        delete[] visited;
        onBreedingCooldown = true;
        breedingCooldownTimer = 15;
    }
}

bool QueenAnt::hasAdjacentMatingAnt(Board* b) {
    int originX = this->xPos - 1;
    int originY = this->yPos - 1;
    for (int row = 0; row < 3; row++) {
        for(int col = 0; col < 3; col++) {
            Critter* littleGuy;
            if (b->isValidCoord(originX + col, originY + row))
                 littleGuy = b->layout[originY + row][originX + col];
            else
                continue;
            if (littleGuy != nullptr) {
                if (littleGuy->canBreed()) {
                    return true;
                }
            }
        }
    }
    return false;
}
