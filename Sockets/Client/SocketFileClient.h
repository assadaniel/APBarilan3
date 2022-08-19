//
// Created by User on 06/08/2022.
//

#ifndef APBARILAN2_SOCKETFILECLIENT_H
#define APBARILAN2_SOCKETFILECLIENT_H


#include "Sockets/SocketFile.h"

class SocketFileClient : public SocketFile {
private:
    const char* ip_address;
    const int port_no;
public:
    SocketFileClient(const char* ip_address, int port_no);
    void close() override;

};


#endif //APBARILAN2_SOCKETFILECLIENT_H
