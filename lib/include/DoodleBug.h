//
// Created by David on 11/9/2023.
//

#ifndef PREDORPREY_DOODLEBUG_H
#define PREDORPREY_DOODLEBUG_H

#include "Predator.h"
#include "Prey.h"

class DoodleBug : public Predator {
private:
    void reproduce(Board* b);
    void doodleMove(Board* b, int randSeed);
    bool hasReproduced = false;
public:
    bool edible = false;
    int hunger = 10;
    void eatBug(Board*, Critter*);
    std::string toString() override {return "D";};
    void move(Board* b, int randSeed) override { doodleMove(b, randSeed);}
    void doAction(Board* b, int randSeed) override {

        if (this->hunger <= 0) {
            this->die(b);
            return;
        }
        this->move(b, randSeed);
        if (this->timeAlive >= 10 && !this->hasReproduced) {
            this->reproduce(b);
        }
        this->timeAlive++;
        this->hunger--;
//        std::cout << this->xPos << " " << this->yPos << ": success";
    }
    void die(Board* b) override {this->Predator::die(b);}
};


#endif //PREDORPREY_DOODLEBUG_H
