//
// Created by User on 28/08/2022.
//

#include "ClientActions.h"

/**
 * @brief Reading a file and sending it.
 * 
 */
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

/**
 * @brief Reaciving a file.
 * 
 * @param file_name The file name recived.
 */
void ClientActions::receive_file(std::string file_name) {
    std::fstream fstream(file_name, std::ios::out);
    socketIo.receiveFile(fstream);
}

/**
 * @brief Reading an input and writing it.
 * 
 */
void ClientActions::read_and_send() {
    std::string input;
    getline(std::cin, input);
    socketIo.write(input);
}

/**
 * @brief Receving an input and printing on screen.
 * 
 */
void ClientActions::receive_and_print() {
    std::cout << socketIo.read() << std::endl;

}

/**
 * @brief Closing a client.
 * 
 */
void ClientActions::exit_client() {
    std::cout << "Exiting!" << std::endl;
    exit(0);
}

/**
 * @brief Construct a new Client Actions:: Client Actions object
 * 
 * @param socketIo1 
 */
ClientActions::ClientActions(SocketIO &socketIo1) : socketIo(socketIo1) {

}

/**
 * @brief Getting a name.
 * 
 */
void ClientActions::get_name(){
    getline(std::cin,name);
}

/**
 * @brief Accessing different actions.
 * 
 * @param option Short form of the action needed to use.
 */
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

