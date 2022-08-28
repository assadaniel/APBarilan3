#include <fstream>
#include <iostream>
#include "ClassifyData.h"

ClassifyData::ClassifyData(Context &ctx, DefaultIO &dio) : Command(ctx, dio) {
    description = "classify data";
}

void ClassifyData::execute() {
    Context& context = getCtx();
    DefaultIO& defaultIo = getDio();
    std::string classifyName = "newClassified.csv";
    context.setClassifyName(classifyName);
    std::fstream new_classified(context.getClassifyName(), std::ios::out | std::ios::in | std::ios::trunc);
    KSmallestRun::runKSmallest(context.getK() ,new_classified ,context.getPathToTest());
    defaultIo.writeEndString();

}

