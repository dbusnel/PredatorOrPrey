//
// Created by David on 11/9/2023.
//

#ifndef PREDORPREY_CRITTER_H
#define PREDORPREY_CRITTER_H

#include <string>
#include "Board.h"

class Critter {
private:
public:
    virtual bool isEdible() = 0;
    int xPos, yPos;
    int timeAlive = 0, timeSinceLastMove = 0;
    virtual void move(Board*, int randSeed);
    virtual void doAction(Board* b, int randSeed) {
        if (this->timeSinceLastMove >= 5) {
            this->die(b);
            return;
        }
        this->move(b, randSeed);
    };
    virtual std::string toString() {return "?";};
    virtual bool canBreed() {return false;}
    virtual void die(Board* b) = 0;
};

#endif //PREDORPREY_CRITTER_H
