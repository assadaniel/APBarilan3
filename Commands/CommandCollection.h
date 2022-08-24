//
// Created by User on 20/08/2022.
//

#ifndef APBARILAN3_COMMANDCOLLECTION_H
#define APBARILAN3_COMMANDCOLLECTION_H


#include <vector>
#include "Command.h"
#include "CommandFactory.h"

class CommandCollection {
private:
    std::vector<Command*> commands;
    DefaultIO &defaultIo;
    CommandFactory commandFactory;
    Context& ctx;
public:
    CommandCollection(DefaultIO& dio, Context& ctx);
    void addCommand(const std::string& string);
    void executeAt(int i);
    void printMenu();
    size_t size();

    ~CommandCollection();
};


#endif //APBARILAN3_COMMANDCOLLECTION_H
