//
// Created by David on 11/19/2023.
//

#include "FileReader.h"
#include <sstream>
#include <iostream>
#include <vector>

std::string readFromColon(std::string input) {
    std::string output = "";
    bool reading = false;
    for (int index = 0; index < input.length(); index++) {
        if (reading)
            output += input[index];
        if (input[index] == ':')
            reading = true;
    }
    return output.substr(1);
}

std::vector<std::string> FileReader::readFile(std::string dir) {
    std::vector<std::string> output;
    std::ifstream reader(dir);

    if(reader.is_open()) {
        std::string line;
        while(std::getline(reader, line)) {
            output.push_back(readFromColon(line));
        }
        reader.close();
        return output;
    } else {
        std::cout << "Could not read file.";
        return {};
    }
}

