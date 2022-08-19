//
// Created by User on 05/08/2022.
//
#define CHUNK_SIZE 512

#include <sys/stat.h>
#include "SocketFile.h"

/**
 * @brief Reciving a file in parts and writing it into the fstream file_s.
 * 
 * @param file_s The fstream we write to.
 */
void SocketFile::receiveFile(std::fstream &file_s) {
    char buffer[CHUNK_SIZE];
    size_t data;
    data = recv(client_sock, buffer, CHUNK_SIZE, 0);
    file_s.write(buffer, data);
    if (data < 0) {
        std::cout << "Server : Error receiving file." << std::endl;
    } else {
        std :: cout << "Received " << data << " bytes." << std::endl;
    }

}

/**
 * @brief Sending a file.
 * 
 * @param file_s The fstream we send from.
 * @param file_size The size of the file we want to send.
 */
void SocketFile::sendFile(std::fstream &file_s, long file_size) {
    size_t sent = 0;
    std::string line;
    char buffer[CHUNK_SIZE];
    file_s.read(buffer, file_size);
    sent = send(client_sock, buffer, file_size, 0);
    if (sent < 0) {
        std::cout << "Server : Error sending file." << std::endl;
    } else {
        std :: cout << "Sent " << sent << " bytes." << std::endl;
    }
}

/**
 * @brief Setting the client socket number.
 * 
 * @param clientSock The client socket number.
 */
void SocketFile::setClientSock(int clientSock) {
    client_sock = clientSock;
}

/**
 * @brief Destroy the Socket File:: Socket File object
 * 
 */
SocketFile::~SocketFile() = default;

/**
 * @brief Getting the client socket number.
 * 
 * @return The client socket number.
 */
int SocketFile::getClientSock() const {
    return client_sock;
}

//FROM STACK OVERFLOW: https://stackoverflow.com/questions/5840148/how-can-i-get-a-files-size-in-c?noredirect=1&lq=1
/**
 * @brief Getting the file size.
 * 
 * @param filename The name of the file we get the size of.
 * @return The size of the file.
 */
long SocketFile::getFileSize(const std::string &filename) {
    struct stat stat_buf{};
    int rc = stat(filename.c_str(), &stat_buf);
    return rc == 0 ? stat_buf.st_size : -1;
}
