//
// Created by User on 05/08/2022.
//
#define CHUNK_SIZE 512

#include <fstream>
#include "SocketFileServer.h"

/**
 * @brief Creating a new Socket in the port port_no.
 * binding the socket and listening in the port and accepting a client.
 * 
 * @param port_no The port number the server listen in.
 */
SocketFileServer::SocketFileServer( const int port_no) : port_no(port_no) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }
    setServerSock(sock);
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(port_no);
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }
    if (listen(sock, 5) < 0) {
        perror("error listening to a socket");
    }

}

void SocketFileServer::accept() {
    unsigned int addr_len = sizeof(client_sin);
    int cs = ::accept(server_sock, (struct sockaddr *) &client_sin, &addr_len);
    setClientSock(cs);

    if (cs < 0) {
        perror("error accepting client");
    }
}

/**
 * @brief Setting the server socket number.
 * 
 * @param serverSock The server socket number.
 */
void SocketFileServer::setServerSock(int serverSock) {
    server_sock = serverSock;
}

/**
 * @brief closing The server socket.
 * 
 */
void SocketFileServer::close() {
    ::close(server_sock);
}







