
#include "Sockets/Server/SocketFileServer.h"
#include "KSmallestAlgo/KSmallestRun.h"

//
// Created by User on 10/08/2022.
//

/**
 * @brief The main function of the server.
 * 
 */
int main() {
    // Create socket
    int port_no = 5555;
    SocketFileServer SFS(port_no);

    //Create new classified fstream
    std::string name_uclsf = "servernewUnclassified.csv";
    std::string name_clsf = "servernewclassified.csv";
    std::fstream new_classified(name_clsf, std::ios::out | std::ios::in | std::ios::trunc); // write and read.
    std::fstream unclassified_received(name_uclsf, std::ios::out); // write only.
    SFS.receiveFile(unclassified_received);


    int k = 9; //decide k
    //Create Unclassified Iris vector
    unclassified_received.close();
    KSmallestRun::runKSmallest(k,new_classified,name_uclsf);
    new_classified.clear(); // clear eof
    new_classified.seekg(0, std::ios::beg); // go back to the start of the file.
    SFS.sendFile(new_classified, SocketFile::getFileSize(name_clsf));
    SFS.close();
    std::remove(name_uclsf.c_str());
    std::remove(name_clsf.c_str());
}