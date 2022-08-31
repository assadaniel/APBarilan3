
#include "GeneralServerResources/CLI.h"
#include "GeneralServerResources/ThreadCLI.h"
#include "GeneralServerResources/ServerTimer.h"
#include "ServerIO/SocketIOServer.h"
#include "ServerIO/SocketFileServer.h"
//
// Created by User on 24/08/2022.
//

/**
 * @brief Removing inactive sockets.
 * 
 * @param vSIO Vector of socketIOServer pointers.
 */
void remove_inactive_sockets(std::vector<SocketIOServer*>& vSIO) {
    for(int j = 0; j<vSIO.size();j++) {
        SocketIOServer* s = vSIO.at(j);
        if(!s->is_active()) {
            delete s;
            vSIO.erase(vSIO.begin()+j);
            j-=1;
        }
    }
}

/**
 * @brief Server main.
 * 
 */
int main() {
    int port = 7777;
    SocketFileServer SFS(port);
    bool listening = true;
    std::vector<ThreadCLI *> thread_vector;
    std::vector<SocketIOServer*> vSIO;
    bool resume_server = true;
    for (int i = 0; i < 4; i++) { //need to do server timeout.
        remove_inactive_sockets(vSIO);
        ServerTimer serverTimer(SFS);
        int client_sock;
        std::cout << "The size of the vector is " << vSIO.size() << std::endl;
        resume_server = serverTimer.start(client_sock);
        if (vSIO.empty() && !resume_server) {
            std::cout << "Server timeout : No clients for " << serverTimer.getSeconds() << " seconds." << std::endl;
            break;
        } else {
            while(!vSIO.empty() && !resume_server) {
                remove_inactive_sockets(vSIO);
                resume_server = serverTimer.start(client_sock);
            }
            if(client_sock<0) {
                std::cout << "Server timeout : No clients for " << serverTimer.getSeconds() << " seconds." << std::endl;
                break;
            }
        }
        SocketIOServer* socketIo = new SocketIOServer(client_sock);
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