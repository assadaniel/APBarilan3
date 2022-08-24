//
// Created by User on 24/08/2022.
//

#include "Sockets/Client/SocketFileClient.h"
#include "Sockets/SocketIO.h"

int main() {
    SocketFileClient SFC("127.0.0.1", 7777);
    SocketIO sIO(SFC.getClientSock());
    std::string endString = sIO.getEndString();
    std::string from_server;
    while (!(from_server = sIO.read()).empty()) {
        std::cout << from_server << std::endl;
        int value = 0;
        std::cin >> value;
        sIO.write(std::to_string(value));
        switch (value) {
            case 1: {
                std::cout << sIO.read() << std::endl;
                std::string input;
                std::cin.ignore();
                getline(std::cin, input);
                std::cout << "INPUT IS " << input << std::endl;
                sIO.write(input); // won't work if input is empty
                from_server = sIO.read();
                std::cout << from_server << std::endl;
                if(from_server != "$") {
                    std::cout << from_server << std::endl;
                }
                break;
            }
            default: {
                sIO.write(std::to_string(value));
            }


        }
    }
}
