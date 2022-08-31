//
// Created by User on 19/08/2022.
//

#include "Context.h"

/**
 * @brief Getter for k.
 * 
 * @return int The k used in KNN algorithm.
 */
int Context::getK() const {
    return k;
}

/**
 * @brief Setter for k.
 * 
 * @param k The k used in KNN algorithm.
 */
void Context::setK(int k) {
    Context::k = k;
}

/**
 * @brief Getter for the distance metric.
 * 
 * @return const std::string& The distance metric used in KNN algorithm.
 */
const std::string &Context::getDistanceMetric() const {
    return distance_metric;
}

/**
 * @brief Setter for the distance metric.
 * 
 * @param distanceMetric The distance metric used in knn algorithm.
 */
void Context::setDistanceMetric(const std::string &distanceMetric) {
    distance_metric = distanceMetric;
}

/**
 * @brief Getter for the path for the train file.
 * 
 * @return const std::string& The path to the train file.
 */
const std::string &Context::getPathToTrain() const {
    return path_to_train;
}

/**
 * @brief Setter for the path for the train file.
 * 
 * @param pathToTrain The path to the train file.
 */
void Context::setPathToTrain(const std::string &pathToTrain) {
    path_to_train = pathToTrain;
}

/**
 * @brief Getter for the path for the test file.
 * 
 * @return const std::string& The path to the test file.
 */
const std::string &Context::getPathToTest() const {
    return path_to_test;
}

/**
 * @brief Setter for the path for the test file.
 * 
 * @param pathToTest The path to the test file.
 */
void Context::setPathToTest(const std::string &pathToTest) {
    path_to_test = pathToTest;
}

/**
 * @brief Getter for the name of the classified file.
 * 
 * @return std::string& The name of the classified file.
 */
std::string &Context::getClassifyName() {
    return classify_file_name;
}

/**
 * @brief Setter for the name of the classified file.
 * 
 * @param classifiedName The name of the classified file.
 */
void Context::setClassifyName(std::string &classifiedName){
    classify_file_name = classifiedName;
}