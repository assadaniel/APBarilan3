//
// Created by User on 06/08/2022.
//

#include "SocketFileClient.h"

/**
 * @brief Creating a new client socket and connecting to the server.
 * 
 * @param ip_address The ip address of the server the client connect to.
 * @param port_no The port number the server is in. 
 */
SocketFileClient::SocketFileClient(const char *ip_address, const int port_no) :
        ip_address(ip_address), port_no(port_no) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }
    setClientSock(sock);

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);

    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
    }


}

/**
 * @brief Closing the client socket.
 * 
 */
void SocketFileClient::close() {
    ::close(getClientSock());
}

int SocketFileClient::getClientSock() const {
    return client_sock;
}

void SocketFileClient::setClientSock(int clientSock) {
    client_sock = clientSock;
}
