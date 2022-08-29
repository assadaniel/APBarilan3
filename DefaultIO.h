//
// Created by User on 19/08/2022.
//

#ifndef APBARILAN3_DEFAULTIO_H
#define APBARILAN3_DEFAULTIO_H


#include <string>

class DefaultIO {
private:
    std::string endString = "$";
public:
    virtual std::string read() = 0;
    virtual void write(std::string str) = 0;
    virtual bool receiveFile(std::fstream& file_s) = 0; // empty file stream
    virtual void sendFile(std::fstream& file_s, long file_size) = 0; //full file stream
    virtual void pure_write(std::string str);
    virtual void close() = 0;
    void writeEndString();
    virtual ~DefaultIO();

    const std::string &getEndString() const;
};


#endif //APBARILAN3_DEFAULTIO_H
