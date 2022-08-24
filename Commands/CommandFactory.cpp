//
// Created by User on 24/08/2022.
//

#include <iostream>
#include "CommandFactory.h"
#include "AlgoSettings.h"
#include "UploadUnclassified.h"

CommandFactory::CommandFactory(Context &ctx, DefaultIO &dio): ctx(ctx), dio(dio) {

}

Command *CommandFactory::createCommand(const std::string& string) const {
    if (string == "AlgoSettings") {
        return new AlgoSettings(ctx, dio);
    } else if(string == "UploadUnclassified") {
        return new UploadUnclassified(ctx,dio);
    } else {
        std::string s = "Command " + string + "not found.";
        perror(s.c_str());
    }
}
