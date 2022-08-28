#include <fstream>
#include <iostream>
#include "ClassifyData.h"

ClassifyData::ClassifyData(Context &ctx, DefaultIO &dio) : Command(ctx, dio) {
    description = "classify data";
}

void ClassifyData::execute() {
    Context& context = getCtx();
    DefaultIO& defaultIo = getDio();
    std::string classifyName = "Thread" + std::to_string(pthread_self()) +"newClassified.csv";
    context.setClassifyName(classifyName);
    std::string path_to_test = context.getPathToTest();
    if (path_to_test.empty()) {
        defaultIo.write("Must upload files beforehand.");
        return;
    }
    std::fstream new_classified(context.getClassifyName(), std::ios::out | std::ios::in | std::ios::trunc);
    std::function<double(const Iris, const Iris)> distanceFunction;
    std::string dm = context.getDistanceMetric();
    if (dm == "EUC") {
        distanceFunction = eucDistance;
    } else if (dm == "MAN") {
        distanceFunction = manDistance;
    } else {
        distanceFunction = chebDistance;
    }
    KSmallestRun::runKSmallest(context.getK() ,new_classified ,path_to_test, distanceFunction);
    defaultIo.write("Classified data successfully.");
    new_classified.close();
}

