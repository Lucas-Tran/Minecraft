#include "FileReader.h"


#include <fstream>
#include <sstream>
#include <iostream>

std::string ReadFile(std::string path) {
    std::ifstream fileStream;
    fileStream.open("Resources/" + path);

    std::stringstream stringStream;
    stringStream << fileStream.rdbuf();
    fileStream.close();

    std::string contents = stringStream.str();

    return contents;
}