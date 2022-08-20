//
// Created by User on 20/08/2022.
//

#include "CommandCollection.h"

void CommandCollection::addCommand(Command *command) {
    commands.push_back(command);
}

void CommandCollection::printMenu() {
    std::string menu = "Welcome to the KNN Classifier Server. Please choose an option:\n";
    for (int i = 0; i < commands.size(); i++) {
        menu+=std::to_string(i+1)+". "+commands.at(i)->getDescription()+"\n";
    }
    menu+="8. exit\n";
    defaultIo->write(menu);
}

void CommandCollection::executeAt(int i) {
    commands.at(i)->execute();
}

CommandCollection::~CommandCollection() {
    for (Command *c: commands) {
        delete c;
    }
}

void CommandCollection::setDefaultIo(DefaultIO *defaultIo) {
    CommandCollection::defaultIo = defaultIo;
}
