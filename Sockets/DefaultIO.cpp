//
// Created by User on 19/08/2022.
//

#include "DefaultIO.h"

/**
 * @brief Destroy the DefaultIO:: DefaultIO object
 * 
 */
DefaultIO::~DefaultIO() = default;

/**
 * @brief Writing the end string.
 * 
 */
void DefaultIO::writeEndString() {
    write(endString);
}

/**
 * @brief Just writing a string.
 * 
 * @param str The string needed to write.
 */
void DefaultIO::pure_write(std::string str){
    write(str);
}

/**
 * @brief Getter for the end string.
 * 
 * @return const std::string& The end string.
 */
const std::string &DefaultIO::getEndString() const {
    return endString;
}
