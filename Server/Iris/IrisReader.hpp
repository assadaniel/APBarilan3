//
// Created by Daniel Assa on 20/07/2022.
//
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Iris.hpp"

#ifndef T1_IRISREADER_HPP
#define T1_IRISREADER_HPP
class IrisReader {
private:
    std::string fileName;
    std::ifstream fin;
    std::vector<std::string> row;
public:
    IrisReader(const std::string& fileName);
    bool getNextIris(Iris& iris);
};
#endif //T1_IRISREADER_HPP
