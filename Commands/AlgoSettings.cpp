//
// Created by User on 19/08/2022.
//

#include <sstream>
#include "AlgoSettings.h"

AlgoSettings::AlgoSettings(Context &ctx, DefaultIO &dio) : Command(ctx, dio) {}

void AlgoSettings::execute() {
    std::string param = getDio()->read();
    std::stringstream ss(param);
    int k;
    std::string metric;
    ss >> k >> metric;
    getCtx().setK(k);
    getCtx().setDistanceMetric(metric);

}
