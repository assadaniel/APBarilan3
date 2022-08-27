//
// Created by User on 05/08/2022.
//
#define CHUNK_SIZE 512

#include <sys/stat.h>
#include "SocketIO.h"

/**
 * @brief Reciving a file in parts and writing it into the fstream file_s.
 * 
 * @param file_s The fstream we write to.
 */
void SocketIO::receiveFile(std::fstream &file_s) {
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

std::string SocketIO::read() {

    char buffer[CHUNK_SIZE];
    size_t data;
    int ret;
    receive_int(&ret);
    ret = ntohl(ret);
    if (ret == 0) {
        return "";
    }
    data = recv(client_sock, buffer, ret, 0);
    if (data < 0) {
        std::cout << "Server : Error reading." << std::endl;
    }
    if (data == 0) {
        return "";
    }
    std::string s(buffer, buffer+data);
    return s;
}

void SocketIO::write(std::string str) {
    send_int(str.size());
    int sent = send(client_sock, str.data(), str.size(), 0);
    if (sent < 0) {
        std::cout << "Server : Error sending message." << std::endl;
    }
}



/**
 * @brief Sending a file.
 * 
 * @param file_s The fstream we send from.
 * @param file_size The size of the file we want to send.
 */
void SocketIO::sendFile(std::fstream &file_s, long file_size) {
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
void SocketIO::setClientSock(int clientSock) {
    client_sock = clientSock;
}

/**
 * @brief Destroy the Socket File:: Socket File object
 * 
 */
SocketIO::~SocketIO() {
    close();
};

/**
 * @brief Getting the client socket number.
 * 
 * @return The client socket number.
 */
int SocketIO::getClientSock() const {
    return client_sock;
}

//FROM STACK OVERFLOW: https://stackoverflow.com/questions/5840148/how-can-i-get-a-files-size-in-c?noredirect=1&lq=1
/**
 * @brief Getting the file size.
 * 
 * @param filename The name of the file we get the size of.
 * @return The size of the file.
 */
long SocketIO::getFileSize(const std::string &filename) {
    struct stat stat_buf{};
    int rc = stat(filename.c_str(), &stat_buf);
    return rc == 0 ? stat_buf.st_size : -1;
}

SocketIO::SocketIO(int client_sock) : client_sock(client_sock) {

}



//FROM STACK OVERFLOW : https://stackoverflow.com/questions/9140409/transfer-integer-over-a-socket-in-c
int SocketIO::send_int(int num) const
{
    int32_t conv = htonl(num);
    char *data = (char*)&conv;
    int left = sizeof(conv);
    int rc;
    do {
        rc = send(client_sock, data, left, 0);
        if (rc < 0) {
            std::cout << "Error sending size." << std::endl;
            return -1;
        }
        else {
            data += rc;
            left -= rc;
        }
    }
    while (left > 0);
    return 0;
}

int SocketIO::receive_int(int *num) const
{
    int32_t ret;
    char *data = (char*)&ret;
    int left = sizeof(ret);
    int rc;
    do {
        rc = recv(client_sock, data, left, 0);
        if (rc <= 0) {
            std::cout << "Error reading size." << std::endl;
            return -1;
        }
        else {
            data += rc;
            left -= rc;
        }
    }
    while (left > 0);
    *num = ntohl(ret);
    return 0;
}

void SocketIO::close() {
    ::close(client_sock);
}
