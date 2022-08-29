
#include <iostream>
#include <fstream>
#include "DownloadResult.h"
#include "Sockets/SocketIO.h"

DownloadResult::DownloadResult(Context &ctx, DefaultIO &dio) : Command(ctx, dio) {
    description = "download results";
}

void DownloadResult::execute() {
    Context &context = getCtx();
    DefaultIO &defaultIo = getDio();
    defaultIo.write("Enter path for results file: ");
    defaultIo.pure_write("RASV");
    std::string classified = context.getClassifyName();
    if(classified.empty()) {
        defaultIo.write("Must classify data beforehand.");
    }
    std::fstream readingFile(classified, std::ios::in);
    std::string results_path =  "Thread" + std::to_string(pthread_self()) + "results.txt";
    std::fstream writingFile(results_path,  std::ios::out | std::ios::in | std::ios::trunc);
    int lineNumber = 1;
    std::string classify;
    while (getline(readingFile, classify)) {
        std::string line = std::to_string(lineNumber) + " " + classify;
        writingFile << line << std::endl;
        lineNumber++;
    }
    writingFile.seekg(0, std::ios::beg);
    defaultIo.sendFile(writingFile, SocketIO::getFileSize(results_path));
    defaultIo.write("Upload Complete.");
    std::remove(results_path.data());
    std::string param = defaultIo.read();
}