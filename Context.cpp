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

const std::string &Context::getPathToTrain() const {
    return path_to_train;
}

void Context::setPathToTrain(const std::string &pathToTrain) {
    path_to_train = pathToTrain;
}

const std::string &Context::getPathToTest() const {
    return path_to_test;
}

void Context::setPathToTest(const std::string &pathToTest) {
    path_to_test = pathToTest;
}
