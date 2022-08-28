//
// Created by User on 19/08/2022.
//

#ifndef APBARILAN3_CONTEXT_H
#define APBARILAN3_CONTEXT_H


#include <string>

class Context {
private:
    int k;
    std::string distance_metric;
    std::string path_to_train;
    std::string path_to_test;
    std::string classify_file_name;
public:
    int getK() const;

    void setK(int k);

    const std::string &getDistanceMetric() const;

    void setDistanceMetric(const std::string &distanceMetric);

    const std::string &getPathToTrain() const;

    void setPathToTrain(const std::string &pathToTrain);

    const std::string &getPathToTest() const;

    void setPathToTest(const std::string &pathToTest);

    std::string &getClassifyName();

    void setClassifyName(std::string &classifiedName);
};


#endif //APBARILAN3_CONTEXT_H
