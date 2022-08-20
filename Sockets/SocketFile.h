//
// Created by User on 05/08/2022.
//

#ifndef APBARILAN2_SOCKETFILE_H
#define APBARILAN2_SOCKETFILE_H

#include <iostream>
#include <sys/socket.h>
#include <cstdio>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <fstream>
#include "DefaultIO.h"

class SocketFile : DefaultIO {
private:
    int client_sock;
public:
    virtual ~SocketFile();
    void receiveFile(std::fstream& file_s) override; // empty file stream
    void sendFile(std::fstream& file_s, long file_size) override; //full file stream
    virtual void close() = 0;
    static long getFileSize(const std::string &filename);
    std::string read();
    void write(std::string str);
protected:
    void setClientSock(int clientSock);
    int getClientSock() const;

};


#endif //APBARILAN2_SOCKETFILE_H
