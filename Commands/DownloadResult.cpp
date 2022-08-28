
#include <iostream>
#include <fstream>
#include "DownloadResult.h"
#include "Sockets/SocketIO.h"
DownloadResult::DownloadResult(Context &ctx, DefaultIO &dio) : Command(ctx, dio) {
    description = "download results";
}

void DownloadResult::execute() {
    Context& context = getCtx();
    DefaultIO& defaultIo = getDio();
    defaultIo.write("Enter path for results file: ");
    defaultIo.pure_write("RASV");
    std::fstream readingFile(context.getClassifyName(), std::ios::out | std::ios::in | std::ios::trunc);
    std::fstream WritingFile("results.txt", std::ios::out | std::ios::in | std::ios::trunc);
    int lineNumber = 1;
    while(!readingFile.eof()){
        std::string classify;
        getline(readingFile,classify);
        std::string line = std::to_string(lineNumber) + " " + classify;
        WritingFile << line << '\n';
        lineNumber++;
    }
    WritingFile << "Done.\n";
    WritingFile.seekg(0,std::ios::beg);
    defaultIo.sendFile(WritingFile,SocketIO::getFileSize("results.txt"));
    std::string param = defaultIo.read();
}