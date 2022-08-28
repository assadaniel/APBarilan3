//
// Created by User on 28/08/2022.
//

#include "ClientActions.h"

void ClientActions::read_and_send_file() {
    std::string input;
    getline(std::cin, input);
    std::fstream file_to_send(input);
    if(!file_to_send.is_open()) {
        std::cout << "Couldn't find file." << std::endl;
    }
    long file_size = SocketIO::getFileSize(input);
    socketIo.sendFile(file_to_send, file_size);
}

void ClientActions::receive_file(std::string file_name) {
    std::fstream fstream(file_name, std::ios::out);
    socketIo.receiveFile(fstream);
}

void ClientActions::read_and_send() {
    std::string input;
    getline(std::cin, input);
    socketIo.write(input);
}

void ClientActions::receive_and_print() {
    std::cout << socketIo.read() << std::endl;

}

void ClientActions::exit_client() {
    std::cout << "Exiting!" << std::endl;
    exit(0);
}

ClientActions::ClientActions(SocketIO &socketIo1) : socketIo(socketIo1) {

}

void ClientActions::get_name(){
    getline(std::cin,name);
}

void ClientActions::do_action(const std::string& option) {
    if (option == "RASF") {
        read_and_send_file();
    } else if (option == "RF") {
        receive_file(name);
    } else if (option == "RAS") {
        read_and_send();
    } else if (option == "RAP") {
        receive_and_print();
    } else if (option == "RASV") {
        get_name();
    }else {
        exit_client();
    }
}

