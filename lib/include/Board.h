//
// Created by David on 11/9/2023.
//

#ifndef PREDORPREY_BOARD_H
#define PREDORPREY_BOARD_H


#include <string>
#include <vector>
class Critter;
class Prey;
class Predator;


class Board {
public:
    int width, height;
    Critter*** layout;
    Board(int width, int height);
    ~Board();
    std::string toString();
    bool isValidCoord(int, int);
    std::vector<Predator*> currentPreds;
    std::vector<Prey*> currentPrey;
    void placeCritterRandom(Critter*);
};


#endif //PREDORPREY_BOARD_H
