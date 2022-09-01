//
// Created by User on 24/08/2022.
//

#include <iostream>
#include "CLI.h"

/**
 * @brief Construct a new CLI::CLI object.
 * Adding all the commands to the command collection and setting the default context.
 * 
 * @param dio The defaultIO.
 */
CLI::CLI(DefaultIO& dio): ctx() ,dio(dio), commandCollection(dio,ctx) {
    ctx.setK(5);
    ctx.setDistanceMetric("EUC");
    commandCollection.addCommand("UploadUnclassified");
    commandCollection.addCommand("AlgoSettings");
    commandCollection.addCommand("ClassifyData");
    commandCollection.addCommand("DisplayResult");
    commandCollection.addCommand("DownloadResult");
    commandCollection.addCommand("ConfusionMatrix");
}

/**
 * @brief Running the menu and executing the commands and closing everything after the user want to exit.
 * 
 */
void CLI::start() {
    size_t exit = commandCollection.size() + 1;
    commandCollection.printMenu();
    int option = stoi(dio.read());
    while(option != exit) {
        commandCollection.executeAt(option-1);
        commandCollection.printMenu();
        option = stoi(dio.read());
    }
    dio.pure_write("EX");
    std::remove(ctx.getPathToTest().data());
    std::remove(ctx.getPathToTrain().data());
    std::remove(ctx.getClassifyName().data());
    dio.close();
    pthread_exit(0);
}
