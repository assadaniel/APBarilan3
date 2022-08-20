//
// Created by User on 05/08/2022.
//

#ifndef APBARILAN2_SOCKETFILESERVER_H
#define APBARILAN2_SOCKETFILESERVER_H


#include "Sockets/SocketFile.h"


class SocketFileServer : public SocketFile {
private:
    const int port_no;
    int server_sock;
    struct sockaddr_in client_sin;
public:
    explicit SocketFileServer(int port_no);

    void setServerSock(int serverSock);
    void accept();
    void close() override;
};


#endif //APBARILAN2_SOCKETFILESERVER_H
