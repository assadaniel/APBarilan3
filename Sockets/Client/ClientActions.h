//
// Created by User on 28/08/2022.
//

#ifndef APBARILAN3CLIENT_CLIENTACTIONS_H
#define APBARILAN3CLIENT_CLIENTACTIONS_H


#include "Sockets/SocketIO.h"

class ClientActions {
private:
    SocketIO& socketIo;
public:
    ClientActions(SocketIO& socketIo1);
    void read_and_send_file();
    void receive_file(std::string file_name);
    void read_and_send();
    void receive_and_print();
    void exit_client();
    void do_action(const std::string& option);
};


#endif //APBARILAN3CLIENT_CLIENTACTIONS_H
