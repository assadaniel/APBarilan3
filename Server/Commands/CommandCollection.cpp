//
// Created by User on 20/08/2022.
//

#include "CommandCollection.h"

#include <utility>
#include <iostream>

/**
 * @brief Adding a command using its name.
 * 
 * @param string The command name.
 */
void CommandCollection::addCommand(const std::string& string) {
    commands.push_back(commandFactory.createCommand(string));
}

/**
 * @brief Printing the menu of the commands.
 * 
 */
void CommandCollection::printMenu() {
    std::string menu = "Welcome to the KNN Classifier Server. Please choose an option:\n";
    for (int i = 0; i < commands.size(); i++) {
        menu += std::to_string(i + 1) + ". " + commands.at(i)->getDescription() + "\n";
    }
    menu += std::to_string(commands.size()+1) + ". exit";
    defaultIo.write(menu);
}

/**
 * @brief Executing a specific command using its number.
 * 
 * @param i The command number.
 */
void CommandCollection::executeAt(int i) {
    commands.at(i)->execute();
}

/**
 * @brief Destroy the Command Collection:: Command Collection object.
 * 
 */
CommandCollection::~CommandCollection() {
    for(Command* c : commands) {
        delete c;
    }
}

/**
 * @brief Construct a new Command Collection:: Command Collection object.
 * 
 * @param dio The defaultIO.
 * @param ctx The context.
 */
CommandCollection::CommandCollection(DefaultIO &dio, Context &ctx) :
        defaultIo(dio), ctx(ctx), commandFactory(ctx, dio) {

}

/**
 * @brief Getting the command collection size.
 * 
 * @return size_t The size of the command collection.
 */
size_t CommandCollection::size() {
    return commands.size();
}
