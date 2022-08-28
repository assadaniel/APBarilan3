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
    Context& context = getCtx();
    DefaultIO& defaultIo = getDio();
    defaultIo.write(instruction);
    std::string param = defaultIo.read();
    if(param.empty()) {
        std::cout << "Empty" << std::endl;
        return;
    }
    std::stringstream ss(param);
    int k;
    std::string metric;
    ss >> k >> metric;
    if(k<1 || k>10) {
        defaultIo.write("Invalid k argument, k must be an integer between 1 and 10.");
        defaultIo.writeEndString();
        return;
    }
    if(metric!="EUC" && metric!="MAN" && metric!="CHE") {
        defaultIo.write("Invalid distance metric, the metric must be EUC, MAN or CHE.");
        return;
    }
    context.setK(k);
    context.setDistanceMetric(metric);
    refreshInstruction();

}

void AlgoSettings::refreshInstruction() {
    Context& ctx = getCtx();
    instruction = "The current KNN parameters are: K = "+ std::to_string(ctx.getK())
                  +", distance metric = "+ctx.getDistanceMetric();
}
