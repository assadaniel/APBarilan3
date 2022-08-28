
#include <iostream>
#include "DisplayResult.h"
#include <fstream>
DisplayResult::DisplayResult(Context &ctx, DefaultIO &dio) : Command(ctx, dio) {
    description = "display results";
}

void DisplayResult::execute() {
    Context& context = getCtx();
    DefaultIO& defaultIo = getDio();
    std::fstream readingFile(context.getClassifyName(), std::ios::in);
    int lineNumber = 1;
    std::string classify;
    while(getline(readingFile,classify)){
        std::string line = std::to_string(lineNumber) + " " + classify;
        defaultIo.write(line);
        lineNumber++;
    }
    defaultIo.write("Done.");
    readingFile.close();
    std::string param = defaultIo.read();
}
