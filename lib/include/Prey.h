//
// Created by David on 11/9/2023.
//

#ifndef PREDORPREY_PREY_H
#define PREDORPREY_PREY_H


#include "Critter.h"

class Prey : public Critter {
public:
    bool isEdible() override {return true;};
    void doAction(Board* b, int randSeed) override {Critter::doAction(b, randSeed);}
    std::string toString() override {return Critter::toString();}
    void move(Board* b, int randSeed) override {Critter::move(b, randSeed);};
    void die(Board* b) override {
        b->layout[this->yPos][this->xPos] = nullptr;
        for (int index = 0; index < b->currentPrey.size(); index++) {
            if (b->currentPrey[index]->yPos == this->yPos
                && b->currentPrey[index]->xPos == this->xPos) {
                b->currentPrey.erase(b->currentPrey.begin() + index);
            }
        }
        delete this;
    };
};


#endif //PREDORPREY_PREY_H
