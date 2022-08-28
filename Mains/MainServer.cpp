#include "Sockets/Server/SocketFileServer.h"
#include "CLI.h"
#include "ThreadCLI.h"
#include "Sockets/Server/SocketIOServer.h"
//
// Created by User on 24/08/2022.
//


void* runner(void* param) {
    int client = *reinterpret_cast<int*>(param);
    SocketIO sIO(client);
    CLI cli(sIO);
    cli.start();
}
int main() {
    int port = 7777;
    SocketFileServer SFS(port);
    bool listening = true;
    std::vector<ThreadCLI *> thread_vector;
    std::vector<SocketIOServer*> vSIO;
    for (int i = 0; i < 4; i++) { //need to do server timeout.
        SocketIOServer* socketIo = new SocketIOServer(SFS.accept());
        vSIO.push_back(socketIo);
        ThreadCLI* t_CLI = new ThreadCLI(*socketIo);
        thread_vector.push_back(t_CLI);
        t_CLI->start_thread();
    }
    for (ThreadCLI *t: thread_vector) {
        delete t;
    }
    for(SocketIOServer* s: vSIO) {
        delete s;
    }
}