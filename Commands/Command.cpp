//
// Created by User on 19/08/2022.
//

#include "Command.h"



void Command::printDesc() {
    dio.write(description);
}

void Command::printInst() {
    dio.write(instruction);
}

Command::Command(Context& ctx, DefaultIO& dio): ctx(ctx), dio(dio) {}

const std::string &Command::getDescription() const {
    return description;
}

const std::string &Command::getInstruction() const {
    return instruction;
}

Context &Command::getCtx() {
    return ctx;
}

DefaultIO &Command::getDio() const {
    return dio;
}

Command::~Command() {

}

