//
// Created by Daniel Assa on 20/07/2022.
//

#include "IrisReader.hpp"
#include <sstream>
#include <cstring>
/**
 * @brief Finding the file we read from and opening him.
 *
 * @param fileName The name of the file we want to read from.
 */
IrisReader ::IrisReader(const std::string& fileName) : fin(fileName){
    if(!fin.is_open()) {
        //Error Message
        std::cout<< "Could not open the file " << fileName << std::endl;
        std::cout<<"Error code: " << strerror(errno) << std::endl;
    }

}

/**
 * @brief Reading a line and initalizing an iris from the line.
 *
 * @param The iris we initaliize.
 * @return Returning true if there is another line to read from, and false otherwise.
 */
bool IrisReader ::getNextIris(Iris& iris) {
    row.clear(); // clear the vector
    std::string line, word;
    if (getline(fin, line)) {
        std::stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        iris.setFromVector(row);
        return true;
    }
    return false;
}


