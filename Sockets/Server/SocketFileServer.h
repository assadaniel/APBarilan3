//
// Created by User on 05/08/2022.
//

#ifndef APBARILAN2_SOCKETFILESERVER_H
#define APBARILAN2_SOCKETFILESERVER_H


#include "Sockets/SocketIO.h"


class SocketFileServer {
private:
    const int port_no;
    int server_sock;
    struct sockaddr_in client_sin;
public:
    explicit SocketFileServer(int port_no);

    void setServerSock(int serverSock);
    int accept();
    void close();
};


#endif //APBARILAN2_SOCKETFILESERVER_H
