//
// Created by User on 20/08/2022.
//

#include "CommandCollection.h"

#include <utility>
#include <iostream>

void CommandCollection::addCommand(const std::string& string) {
    commands.push_back(commandFactory.createCommand(string));
}

void CommandCollection::printMenu() {
    std::string menu = "Welcome to the KNN Classifier Server. Please choose an option:\n";
    for (int i = 0; i < commands.size(); i++) {
        menu += std::to_string(i + 1) + ". " + commands.at(i)->getDescription() + "\n";
    }
    menu += std::to_string(commands.size()+1) + ". exit";
    defaultIo.write(menu);
}

void CommandCollection::executeAt(int i) {
    commands.at(i)->execute();
}

CommandCollection::~CommandCollection() {
}


CommandCollection::CommandCollection(DefaultIO &dio, Context &ctx) :
        defaultIo(dio), ctx(ctx), commandFactory(ctx, dio) {

}

size_t CommandCollection::size() {
    return commands.size();
}
