#include <iostream>
#include "Board.h"
#include "QueenAnt.h"
#include "Simulation.h"
#include "FileReader.h"
#include <string>


int main(int argc, char** argv) {
    if (argc == 1) {
        return 1;
    }
    std::string inputPath = argv[1];
    int size, numDoodle, numQueens, numWorker, numMating, randSeed;
    FileReader reader;
    std::vector<std::string> input = reader.readFile(inputPath);
    if (input.size() == 6) {
        size = std::stoi(input[0]);
        numDoodle = std::stoi(input[1]);
        numQueens = std::stoi(input[2]);
        numWorker = std::stoi(input[3]);
        numMating = std::stoi(input[4]);
        randSeed = std::stoi(input[5]);
    } else {
        std::cerr << "Invalid input.";
    }
    Simulation simulation(size, numDoodle, numQueens, numWorker, numMating, randSeed);
    simulation.runSimulation();
}