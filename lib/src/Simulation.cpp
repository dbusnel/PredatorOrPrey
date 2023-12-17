//
// Created by David on 11/16/2023.
//

#include <iostream>
#include <thread>
#include <chrono>
#include "Simulation.h"
#include "DoodleBug.h"
#include "QueenAnt.h"
#include "WorkerAnt.h"
#include "MatingAnt.h"

Simulation::Simulation(int gridSize, int numDoodleBugs, int numQueens, int numWorkers, int numMating, int randSeed) : board(Board(gridSize, gridSize)) {
    this->randomSeed = randSeed;
    srand(randSeed);

    for (int i = 0; i < numDoodleBugs; i++) {
        Predator* toPlace = new DoodleBug;
        this->board.placeCritterRandom(toPlace);
        this->board.currentPreds.push_back(toPlace);
    }
    Prey* toPlace;
    for (int i = 0; i < numQueens; i++) {
        toPlace = new QueenAnt;
        this->board.placeCritterRandom(toPlace);
        this->board.currentPrey.push_back(toPlace);
    } for (int i = 0; i < numWorkers; i++) {
        toPlace = new WorkerAnt;
        this->board.placeCritterRandom(toPlace);
        this->board.currentPrey.push_back(toPlace);
    } for (int i = 0; i < numMating; i++) {
        toPlace = new MatingAnt;
        this->board.placeCritterRandom(toPlace);
        this->board.currentPrey.push_back(toPlace);
    }

}

void Simulation::goForward() {
    this->time++;
    //std::cout << this->board.currentPreds.size();
    for (Predator* db : this->board.currentPreds) {
        //std::cout << db->toString() << ": success";
        db->doAction(&this->board, this->randomSeed);
    }

    for (Prey* ant : this->board.currentPrey) {
        ant->doAction(&this->board, this->randomSeed);
    }

    std::cout << this->board.toString() << std::endl;
}

void Simulation::runSimulation() {
    while (this->board.currentPrey.size() != 0 && this->board.currentPreds.size() != 0) {
        for (int newline = 0; newline < 50; newline++) {
            std::cout << std::endl;
        }

        this->goForward();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
