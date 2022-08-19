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

class SocketFile {
private:
    int client_sock;
public:
    virtual ~SocketFile();
    virtual void receiveFile(std::fstream& file_s); // empty file stream
    virtual void sendFile(std::fstream& file_s, long file_size); //full file stream
    virtual void close() = 0;
    void setClientSock(int clientSock);
    static long getFileSize(const std::string &filename);
protected:
    int getClientSock() const;

};


#endif //APBARILAN2_SOCKETFILE_H
