//
// Created by User on 09/08/2022.


#include <fstream>
#include "Sockets/Client/SocketFileClient.h"

/**
 * @brief The main function of the client.
 * 
 * @param argv The path to the unclassified the client want to send and the path to where to save the classified file.
 */
int main(int argc, char **argv) {
    if(argc < 2) {
        std::cout << "Must provide paths for unclassified file and classified file." << std::endl;
    }
    std::fstream unclassified_file(argv[1], std::fstream::in); // read only

    std::fstream classified_file(argv[2], std::fstream::out); // write only
    SocketFileClient sfc("127.0.0.1", 5555);
    sfc.sendFile(unclassified_file, SocketFile::getFileSize(argv[1]));
    sfc.receiveFile(classified_file);
    sfc.close();
}
