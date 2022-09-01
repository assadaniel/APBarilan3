//
// Created by User on 20/08/2022.
//

#include <fstream>
#include <iostream>
#include "UploadUnclassified.h"

/**
 * @brief Construct a new Upload Unclassified:: Upload Unclassified object
 * 
 * @param ctx Things the command needs to know in order to work.
 * @param dio DefaultIO used.
 */
UploadUnclassified::UploadUnclassified(Context &ctx, DefaultIO &dio) : Command(ctx, dio) {
    description = "upload an unclassified csv data file";
}

/**
 * @brief Executing the command.
 * 
 */
void UploadUnclassified::execute() {
    DefaultIO &defaultIo = getDio();
    Context &context = getCtx();
    bool valid;
    defaultIo.write("Please upload your local train CSV file.");
    context.setPathToTrain("Thread" + std::to_string(pthread_self()) + "trainCSVfile_server_receving.csv");
    std::fstream train_f(context.getPathToTrain(), std::ios::out);
    valid = defaultIo.receiveFile(train_f);
    if(!valid) {
        defaultIo.write("The file sent was invalid.\n"
                        "Try to provide a true path of a file in your working directory");
        context.setPathToTrain("");
        train_f.close();
        return;
    } else { defaultIo.write("Upload complete."); }
    defaultIo.write("Please upload your local test CSV file.");
    context.setPathToTest("Thread" + std::to_string(pthread_self()) + "testCSVfile_server_receving.csv");
    std::fstream test_f(context.getPathToTest(), std::ios::out);
    valid = defaultIo.receiveFile(test_f);
    if(!valid) {
        defaultIo.write("The file sent was invalid.\n"
                        "Try to provide a true path of a file in your working directory.");
        train_f.close();
        context.setPathToTest("");
        return;
    } else { defaultIo.write("Upload complete."); }
    train_f.close();
    test_f.close();
}

////From stack overflow: https://stackoverflow.com/questions/2390912/checking-for-an-empty-file-in-c
//bool UploadUnclassified::is_empty(std::fstream &pFile) {
//    return pFile.peek() == std::ifstream::traits_type::eof();
//}
