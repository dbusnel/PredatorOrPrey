//
// Created by David on 11/9/2023.
//

#include <sstream>
#include <iostream>
#include "Board.h"
#include "Critter.h"

Board::Board(int width, int height) : width(width), height(height) {
    this->layout = new Critter**[height];
    for (int row = 0; row < height; row++) {
        layout[row] = new Critter*[width];
        for (int col = 0; col < width; col++) {
            layout[row][col] = nullptr;
        }
    }
};
Board::~Board() {
    for (int row = 0; row < height; row++) {
        delete[] this->layout[row];
    }
    delete[] layout;
}

std::string Board::toString() {
    std::stringstream output;
    for (int curRow = 0; curRow < this->height; curRow++) {
        for(int curCol = 0; curCol < this->width; curCol++) {
            Critter* cur = this->layout[curRow][curCol];
            if (cur != nullptr)
                output << this->layout[curRow][curCol]->toString();
            else
                output << "-";
            output << " ";
        }
        output << std::endl;
    }
    return output.str();
}

bool Board::isValidCoord(int x, int y) {
    return x >= 0 && x < this->width
        && y >= 0 && y < this->height;
}

bool andmap(bool** toMap, int width, int height) {
    bool result = true;
    for(int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            result &= toMap[row][col];
        }
    }
    return result;
}

void Board::placeCritterRandom(Critter* toPlace) {
    bool** visited = new bool*[this->height];
    for (int row = 0; row < this->height; row++) {
        visited[row] = new bool[this->width];
    }

    while(!andmap(visited, this->width, this->height)) {
        int xPos = rand() % this->width;
        int yPos = rand() % this->height;
        visited[yPos][xPos] = true;
        if (this->layout[yPos][xPos] == nullptr) {
            toPlace->xPos = xPos;
            toPlace->yPos = yPos;
            this->layout[yPos][xPos] = toPlace;
            break;
        }
    }
}
