//
// Created by User on 19/08/2022.
//

#ifndef APBARILAN3_COMMAND_H
#define APBARILAN3_COMMAND_H


#include <string>
#include "../GeneralServerResources/Context.h"
#include "../../Sockets/DefaultIO.h"

class Command {
private:
    Context& ctx;
    DefaultIO& dio;
protected:
    std::string description; // description in the menu.
    std::string instruction; // the message shown after the command is chosen.
    Context &getCtx();

    DefaultIO &getDio() const;
public:
    Command(Context& ctx, DefaultIO &dio);
    virtual void execute() = 0;
    virtual ~Command();
    virtual void printDesc();
    virtual void printInst();

    const std::string &getDescription() const;

    const std::string &getInstruction() const;

};


#endif //APBARILAN3_COMMAND_H
