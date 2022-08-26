#include "Sockets/Server/SocketFileServer.h"
#include "CLI.h"

//
// Created by User on 24/08/2022.
//
int main() {
    int port = 5557;
    SocketFileServer SFS(port);
    int client_sock = SFS.accept();
    SocketIO sIO(client_sock);
    CLI cli(sIO);
    cli.start();
}