//
// Created by User on 20/08/2022.
//

#include <fstream>
#include "UploadUnclassified.h"

UploadUnclassified::UploadUnclassified(Context &ctx, DefaultIO &dio) : Command(ctx, dio) {
    description = "upload an unclassified csv data file";
}

void UploadUnclassified::execute() {
    DefaultIO* defaultIo = getDio();
    Context& context = getCtx();
    defaultIo->write("Please upload your local train CSV file.");
    context.setPathToTrain("trainCSVfile_server_receving");
    std::fstream train_f(context.getPathToTrain(), std::ios::out);
    defaultIo->receiveFile(train_f);
    defaultIo->write("Upload complete.");
    defaultIo->write("Please upload your local test CSV file.");
    context.setPathToTest("testCSVfile_server_receving");
    std::fstream test_f(context.getPathToTest(), std::ios::out);
    defaultIo->receiveFile(test_f);
    defaultIo->write("Upload complete.");
    train_f.close();
    test_f.close();
}
