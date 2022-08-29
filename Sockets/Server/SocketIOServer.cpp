//
// Created by User on 28/08/2022.
//

#include "SocketIOServer.h"

SocketIOServer::SocketIOServer(int client_sock): socketIo(client_sock) {}

void SocketIOServer::receiveFile(std::fstream &file_s) {
    socketIo.write("RASF"); // telling the client to read and send the file.
    socketIo.receiveFile(file_s);
}

void SocketIOServer::sendFile(std::fstream &file_s, long file_size) {
    socketIo.write("RF"); // telling the client to receive the file.
    socketIo.sendFile(file_s,file_size);
}

std::string SocketIOServer::read() {
    socketIo.write("RAS"); // telling the client to read and send.
    return socketIo.read();
}

void SocketIOServer::write(std::string str) {
    socketIo.write("RAP"); // telling the client to receive and print.
    socketIo.write(str);
}

void SocketIOServer::pure_write(std::string str){
    socketIo.write(str);
}

void SocketIOServer::close() {
    active = false;
    socketIo.close();
}

bool SocketIOServer::is_active() const {
    return active;
}
