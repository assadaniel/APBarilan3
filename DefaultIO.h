//
// Created by User on 19/08/2022.
//

#ifndef APBARILAN3_DEFAULTIO_H
#define APBARILAN3_DEFAULTIO_H


#include <string>

class DefaultIO {
public:
    virtual std::string read() = 0;
    virtual void write(std::string str) = 0;
    virtual void receiveFile(std::fstream& file_s) = 0; // empty file stream
    virtual void sendFile(std::fstream& file_s, long file_size) = 0; //full file stream
    virtual ~DefaultIO();
};


#endif //APBARILAN3_DEFAULTIO_H
