//
// Created by David on 11/16/2023.
//

#ifndef PREDORPREY_SIMULATION_H
#define PREDORPREY_SIMULATION_H


#include "Board.h"

class Simulation {
private:
    Board board;
public:
    int time = 0;
    int randomSeed;
    int width, height;
    Simulation(int, int, int);
    std::string getCurrentState() {return this->board.toString();};
    void goForward();
    Simulation(int, int, int, int, int, int);
    void runSimulation();
};


#endif //PREDORPREY_SIMULATION_H
