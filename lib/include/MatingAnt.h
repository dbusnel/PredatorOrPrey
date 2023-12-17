//
// Created by David on 11/9/2023.
//

#ifndef PREDORPREY_MATINGANT_H
#define PREDORPREY_MATINGANT_H

#include "Prey.h"

class MatingAnt : public Prey {
public:
    std::string toString() override {return "y";};
    bool canBreed() override {return true;}
    void move(Board* b, int randSeed) override {Prey::move(b, randSeed);}
    void doAction(Board* b, int randSeed) override {Critter::doAction(b, randSeed);}
    void die(Board* b) override {this->Prey::die(b);}
    bool isEdible() override {return Prey::isEdible();}
};


#endif //PREDORPREY_MATINGANT_H
