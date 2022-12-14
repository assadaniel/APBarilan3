//
// Created by User on 24/08/2022.
//

#include <iostream>
#include "CommandFactory.h"
#include "AlgoSettings.h"
#include "UploadUnclassified.h"
#include "ClassifyData.h"
#include "DisplayResult.h"
#include "DownloadResult.h"
#include "ConfusionMatrix.h"

/**
 * @brief Construct a new Command Factory:: Command Factory object.
 * 
 * @param ctx The context.
 * @param dio The defaultIO.
 */
CommandFactory::CommandFactory(Context &ctx, DefaultIO &dio) : ctx(ctx), dio(dio) {

}

/**
 * @brief Creating a command using its name.
 * 
 * @param string The command name.
 * @return Command* The command created.
 */
Command *CommandFactory::createCommand(const std::string &string) const {
    if (string == "AlgoSettings") {
        return new AlgoSettings(ctx, dio);
    } else if (string == "UploadUnclassified") {
        return new UploadUnclassified(ctx, dio);
    } else if (string == "ClassifyData") {
        return new ClassifyData(ctx, dio);
    } else if (string == "DisplayResult") {
        return new DisplayResult(ctx, dio);
    } else if (string == "DownloadResult") {
        return new DownloadResult(ctx, dio);
    } else if (string == "ConfusionMatrix") {
        return new ConfusionMatrix(ctx, dio);
    } else {
        std::string s = "Command " + string + "not found.";
        perror(s.c_str());
    }
    return nullptr;
}
