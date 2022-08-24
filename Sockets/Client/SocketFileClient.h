//
// Created by User on 06/08/2022.
//

#ifndef APBARILAN2_SOCKETFILECLIENT_H
#define APBARILAN2_SOCKETFILECLIENT_H


#include "../SocketIO.h"


class SocketFileClient{
private:
    const char* ip_address;
    const int port_no;
    int client_sock;
public:
    SocketFileClient(const char* ip_address, int port_no);
    void close();

    int getClientSock() const;

    void setClientSock(int clientSock);

};


#endif //APBARILAN2_SOCKETFILECLIENT_H
