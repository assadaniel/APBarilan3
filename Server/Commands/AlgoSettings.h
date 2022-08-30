//
// Created by User on 19/08/2022.
//

#ifndef APBARILAN3_ALGOSETTINGS_H
#define APBARILAN3_ALGOSETTINGS_H


#include "Command.h"
#include "../GeneralServerResources/Context.h"
#include "../../Sockets/DefaultIO.h"

class AlgoSettings : public Command {
public:
    AlgoSettings(Context& ctx, DefaultIO &dio);
    void execute() override;
    void refreshInstruction();
};


#endif //APBARILAN3_ALGOSETTINGS_H
