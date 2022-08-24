//
// Created by User on 24/08/2022.
//

#ifndef APBARILAN3_CLI_H
#define APBARILAN3_CLI_H


#include "DefaultIO.h"
#include "Context.h"
#include "Commands/CommandCollection.h"

class CLI {
private:
    DefaultIO& dio;
    Context ctx;
    CommandCollection commandCollection;
public:
    CLI(DefaultIO& dio);
    void start();
};


#endif //APBARILAN3_CLI_H
