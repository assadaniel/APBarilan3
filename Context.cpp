//
// Created by User on 19/08/2022.
//

#include "Context.h"

int Context::getK() const {
    return k;
}

void Context::setK(int k) {
    Context::k = k;
}

const std::string &Context::getDistanceMetric() const {
    return distance_metric;
}

void Context::setDistanceMetric(const std::string &distanceMetric) {
    distance_metric = distanceMetric;
}
