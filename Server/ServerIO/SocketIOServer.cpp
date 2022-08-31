//
// Created by User on 28/08/2022.
//

#include "SocketIOServer.h"

/**
 * @brief Construct a new Socket IO Server:: Socket IO Server object.
 * 
 * @param client_sock The client socket.
 */
SocketIOServer::SocketIOServer(int client_sock): socketIo(client_sock) {}

/**
 * @brief Receiving a file.
 * 
 * @param file_s The fstream used.
 * @return true Checking if the file was received.
 * @return false Checking if the file was received.
 */
bool SocketIOServer::receiveFile(std::fstream &file_s) {
    socketIo.write("RASF"); // telling the client to read and send the file.
    return socketIo.receiveFile(file_s);
}

/**
 * @brief Sending a file.
 * 
 * @param file_s The fstream used.
 * @param file_size The file size.
 */
void SocketIOServer::sendFile(std::fstream &file_s, long file_size) {
    socketIo.write("RF"); // telling the client to receive the file.
    socketIo.sendFile(file_s,file_size);
}

/**
 * @brief Reading a file.
 * 
 * @return std::string The file needed to read.
 */
std::string SocketIOServer::read() {
    socketIo.write("RAS"); // telling the client to read and send.
    return socketIo.read();
}

/**
 * @brief Writing to the client.
 * 
 * @param str The string needed to write.
 */
void SocketIOServer::write(std::string str) {
    socketIo.write("RAP"); // telling the client to receive and print.
    socketIo.write(str);
}

/**
 * @brief Just writing.
 * 
 * @param str The string needed to write.
 */
void SocketIOServer::pure_write(std::string str){
    socketIo.write(str);
}

/**
 * @brief Closing the socket.
 * 
 */
void SocketIOServer::close() {
    active = false;
    socketIo.close();
}

/**
 * @brief Checking if the socket is active.
 * 
 */
bool SocketIOServer::is_active() const {
    return active;
}
