//
// Created by User on 20/08/2022.
//

#ifndef APBARILAN3_COMMANDCOLLECTION_H
#define APBARILAN3_COMMANDCOLLECTION_H


#include <vector>
#include "Command.h"

class CommandCollection {
private:
    std::vector<Command*> commands;
    DefaultIO *defaultIo;
public:
    void addCommand(Command* command);
    void executeAt(int i);
    void printMenu();

    void setDefaultIo(DefaultIO *defaultIo);

    ~CommandCollection();
};


#endif //APBARILAN3_COMMANDCOLLECTION_H
