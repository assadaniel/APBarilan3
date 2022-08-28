//
// Created by User on 28/08/2022.
//

#include "Sockets/Client/SocketFileClient.h"
#include "Sockets/Client/ClientActions.h"

int main() {
    SocketFileClient SFC("127.0.0.1", 7777);
    SocketIO sIO(SFC.getClientSock());
    ClientActions clientActions(sIO);
    std::string option;
    while(true) {
        option = sIO.read();
        clientActions.do_action(option);
    }
}
