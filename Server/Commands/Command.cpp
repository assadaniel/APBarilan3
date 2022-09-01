//
// Created by User on 19/08/2022.
//

#include "Command.h"


/**
 * @brief Printing the description.
 * 
 */
void Command::printDesc() {
    dio.write(description);
}

/**
 * @brief Printing the instructions.
 * 
 */
void Command::printInst() {
    dio.write(instruction);
}

/**
 * @brief Construct a new Command:: Command object.
 * 
 * @param ctx Things the command needs to know in order to work.
 * @param dio DefaultIO used.
 */
Command::Command(Context& ctx, DefaultIO& dio): ctx(ctx), dio(dio) {}

/**
 * @brief Getter for the description.
 * 
 * @return const std::string& The description.
 */
const std::string &Command::getDescription() const {
    return description;
}

/**
 * @brief Getter for the instructions.
 * 
 * @return const std::string& The instructions.
 */
const std::string &Command::getInstruction() const {
    return instruction;
}

/**
 * @brief Getter for the context.
 * 
 * @return Context& The context.
 */
Context &Command::getCtx() {
    return ctx;
}

/**
 * @brief Getter for the defaultIO.
 * 
 * @return DefaultIO& The defaultIO.
 */
DefaultIO &Command::getDio() const {
    return dio;
}

/**
 * @brief Destroy the Command:: Command object.
 * 
 */
Command::~Command() = default;

