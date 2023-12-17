//
// Created by David on 11/9/2023.
//

#ifndef PREDORPREY_QUEENANT_H
#define PREDORPREY_QUEENANT_H


#include "Prey.h"
#include "Board.h"

class QueenAnt : public Prey {
private:
    bool fertilized = false;
    bool retired = false;
    int pregnancyTimer = 0;
    bool onBreedingCooldown = false;
    int breedingCooldownTimer;
    void tryBreed(Board*);
    void layEgg(Board*, int, int);
public:
    bool hasMated = false;
    void move(Board* b, int randSeed) override {Prey::move(b, randSeed);}
    void doAction(Board* b, int randSeed) override {
        if (!retired) {
            if (!fertilized && timeAlive > 60) {
                this->die(b);
                return;
            }
            if (hasAdjacentMatingAnt(b) && !fertilized) {
                fertilized = true;
                pregnancyTimer = 30;
            }
            if (fertilized && pregnancyTimer == 0 && !onBreedingCooldown) {
                tryBreed(b);
            }

            //update lifetime timers
            if (onBreedingCooldown) {
                if (breedingCooldownTimer == 0) {
                    onBreedingCooldown = false;
                } else {
                    breedingCooldownTimer--;
                }
            }
            if (pregnancyTimer > 0)
                pregnancyTimer--;
        } else {
            Critter::doAction(b, randSeed);
        }
    }
    std::string toString() override {return "Q";};
    bool hasAdjacentMatingAnt(Board*);
    void die(Board* b) override {this->Prey::die(b);};
    bool isEdible() override {return Prey::isEdible();}
};


#endif //PREDORPREY_QUEENANT_H
