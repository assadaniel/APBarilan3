//
// Created by User on 19/08/2022.
//

#include "DefaultIO.h"

DefaultIO::~DefaultIO() {

}

void DefaultIO::writeEndString() {
    write(endString);
}

void DefaultIO::pure_write(std::string str){
    write(str);
}

const std::string &DefaultIO::getEndString() const {
    return endString;
}
