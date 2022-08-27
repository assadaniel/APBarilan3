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

class SocketIO : public DefaultIO {
private:
    int client_sock;
public:
    SocketIO(int client_sock);
    virtual ~SocketIO();
    void receiveFile(std::fstream& file_s) override; // empty file stream
    void sendFile(std::fstream& file_s, long file_size) override; //full file stream
    static long getFileSize(const std::string &filename);
    std::string read() override;
    void write(std::string str) override;
    int send_int(int num) const;
    int receive_int(int *num) const;
    void close();
protected:
    void setClientSock(int clientSock);
    int getClientSock() const;

};


#endif //APBARILAN2_SOCKETFILE_H
