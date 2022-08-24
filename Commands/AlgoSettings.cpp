//
// Created by User on 19/08/2022.
//

#include <sstream>
#include <iostream>
#include "AlgoSettings.h"

AlgoSettings::AlgoSettings(Context &ctx, DefaultIO &dio) : Command(ctx, dio) {
    instruction = "The current KNN parameters are: K = "+ std::to_string(ctx.getK())
                  +", distance metric = "+ctx.getDistanceMetric();
    description = "algorithm settings";
}

void AlgoSettings::execute() {
    std::cout << "1" << std::endl;
    Context& context = getCtx();
    std::cout << "2" << std::endl;
    DefaultIO& defaultIo = getDio();
    std::cout << "3" << std::endl;
    defaultIo.write(instruction);
    std::cout << "4" << std::endl;
    std::string param = defaultIo.read();
    std::cout << "param is " << param << std::endl;
    if(param.empty()) {
        std::cout << "is empty." << std::endl;
        return;
    }
    std::stringstream ss(param);
    int k;
    std::string metric;
    ss >> k >> metric;
    std::cout << k << metric << std::endl;
    if(k<1 || k>10) {
        defaultIo.write("Invalid k argument, k must be an integer between 1 and 10.");
        return;
    }
    if(metric!="EUC" && metric!="MAN" && metric!="CHE") {
        defaultIo.write("Invalid distance metric, the metric must be EUC, MAN or CHE.");
        return;
    }
    context.setK(k);
    context.setDistanceMetric(metric);
    std::cout << "Contents set." << std::endl;
    refreshInstruction();
    defaultIo.writeEndString();

}

void AlgoSettings::refreshInstruction() {
    Context& ctx = getCtx();
    instruction = "The current KNN parameters are: K = "+ std::to_string(ctx.getK())
                  +", distance metric = "+ctx.getDistanceMetric();
}
