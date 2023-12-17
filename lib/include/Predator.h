//
// Created by David on 11/9/2023.
//

#ifndef PREDORPREY_PREDATOR_H
#define PREDORPREY_PREDATOR_H


#include "Critter.h"

class Predator : public Critter {
public:
    bool isEdible() override {return false;};

    void die(Board* b) override {
        b->layout[this->yPos][this->xPos] = nullptr;
        for (int index = 0; index < b->currentPreds.size(); index++) {
            if (b->currentPreds[index]->yPos == this->yPos
                && b->currentPreds[index]->xPos == this->xPos) {
                b->currentPreds.erase(b->currentPreds.begin() + index);
                delete this;
                return;
            }
        }
    };
};


#endif //PREDORPREY_PREDATOR_H
