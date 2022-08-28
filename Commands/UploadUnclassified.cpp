//
// Created by User on 20/08/2022.
//

#include <fstream>
#include <iostream>
#include "UploadUnclassified.h"

UploadUnclassified::UploadUnclassified(Context &ctx, DefaultIO &dio) : Command(ctx, dio) {
    description = "upload an unclassified csv data file";
}

void UploadUnclassified::execute() {
    DefaultIO &defaultIo = getDio();
    Context &context = getCtx();
    defaultIo.write("Please upload your local train CSV file.");
    context.setPathToTrain("Thread" + std::to_string(pthread_self()) +"trainCSVfile_server_receving.csv");
    std::fstream train_f(context.getPathToTrain(), std::ios::out);
    defaultIo.receiveFile(train_f);
    defaultIo.write("Upload complete.");
    defaultIo.write("Please upload your local test CSV file.");
    context.setPathToTest("Thread" + std::to_string(pthread_self()) +"testCSVfile_server_receving.csv");
    std::fstream test_f(context.getPathToTest(), std::ios::out);
    defaultIo.receiveFile(test_f);
    defaultIo.write("Upload complete.");
    train_f.close();
    test_f.close();
}
