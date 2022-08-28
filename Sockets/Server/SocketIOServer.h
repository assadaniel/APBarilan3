//
// Created by User on 28/08/2022.
//

#ifndef APBARILAN3_SOCKETIOSERVER_H
#define APBARILAN3_SOCKETIOSERVER_H

#include <Sockets/SocketIO.h>

class SocketIOServer: public DefaultIO {
private:
    SocketIO socketIo;
public:
    SocketIOServer(int client_sock);
    void receiveFile(std::fstream& file_s) override; // empty file stream
    void sendFile(std::fstream& file_s, long file_size) override; //full file stream
    std::string read() override;
    void write(std::string str) override;

};


#endif //APBARILAN3_SOCKETIOSERVER_H
