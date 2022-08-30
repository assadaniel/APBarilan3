//
// Created by User on 24/08/2022.
//

#ifndef APBARILAN3_COMMANDFACTORY_H
#define APBARILAN3_COMMANDFACTORY_H



#include "Command.h"

class CommandFactory {
private:
    DefaultIO& dio;
    Context& ctx;
public:
    CommandFactory(Context & ctx,DefaultIO& dio);
    Command* createCommand(const std::string& string) const;
};


#endif //APBARILAN3_COMMANDFACTORY_H
