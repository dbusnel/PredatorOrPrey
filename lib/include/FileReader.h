//
// Created by David on 11/19/2023.
//

#ifndef PREDORPREY_FILEREADER_H
#define PREDORPREY_FILEREADER_H

#include <fstream>
#include <string>
#include <vector>

class FileReader {
public:
    std::vector<std::string> readFile(std::string dir);
};


#endif //PREDORPREY_FILEREADER_H
