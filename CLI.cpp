//
// Created by User on 24/08/2022.
//

#include <iostream>
#include "CLI.h"
#include "Commands/CommandCollection.h"
#include "Commands/AlgoSettings.h"
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
    pthread_exit(0);
}
