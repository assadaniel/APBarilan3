
#include <iostream>
#include <vector>
#include "ConfusionMatrix.h"
#include <unordered_map>
#include "../Iris/Iris.hpp"
#include "../Iris/IrisReader.hpp"
#include "../KSmallestAlgo/KSmallestRun.h"
#include <cmath>
#include <fstream>

#define N 3

/**
 * @brief Construct a new Confusion Matrix:: Confusion Matrix object.
 * 
 * @param ctx Things the command needs to know in order to work.
 * @param dio DefaultIO used.
 */
ConfusionMatrix::ConfusionMatrix(Context &ctx, DefaultIO &dio) : Command(ctx, dio) {
    description = "display algorithm confusion matrix";
}

/**
 * @brief Executing the command.
 * 
 */
void ConfusionMatrix::execute() {
    Context &context = getCtx();
    DefaultIO &defaultIo = getDio();
    std::unordered_map<std::string, irisType> table = {{"Iris-setosa",     irisType::setosa},
                                                       {"Iris-virginica",  irisType::virginica},
                                                       {"Iris-versicolor", irisType::versicolor}};
    std::vector<std::vector<int>> matrix(N, std::vector<int>(N));
    std::vector<irisType> realType;
    std::vector<irisType> predictedType;
    std::vector<int> countTypes(N, 0);
    std::string train_name = context.getPathToTrain();
    std::string new_classified_predicted = "Thread" + std::to_string(pthread_self()) +"new_classified_train.csv";
    std::fstream new_classified_trained(new_classified_predicted,std::ios::out | std::ios::in | std::ios::trunc);
    std::function<double(const Iris, const Iris)> distanceFunction;
    std::string dm = context.getDistanceMetric();
    if (dm == "EUC") {
        distanceFunction = eucDistance;
    } else if (dm == "MAN") {
        distanceFunction = manDistance;
    } else {
        distanceFunction = chebDistance;
    }
    KSmallestRun::runKSmallest(train_name,context.getK(), new_classified_trained, train_name, distanceFunction);
    new_classified_trained.close();
    std::string realClassName = context.getPathToTrain();
    if(realClassName.empty()) {
        defaultIo.write("Must upload train and test files beforehand.");
        return;
    }

    IrisReader realClass(realClassName);
    Iris some_iris;
    while (realClass.getNextIris(some_iris)) {
        realType.push_back(some_iris.getType());
    }
    std::fstream predictedFstream(new_classified_predicted);
    std::string type;
    while (getline(predictedFstream,type)) {
        predictedType.push_back(table[type]);
    }
    realClass.close();
    predictedFstream.close();
    for (int i = 0; i < realType.size(); i++) {
        matrix[realType[i]][predictedType[i]]++;
        countTypes[realType[i]]++;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = lround(((double) matrix[i][j] / (double) countTypes[i]) * 100);
        }
    }
    std::string confMatrix;
    for (int i = 0; i < N; i++) {
        std::string row = enumArr[i];
        if (row.length() == 11) {
            row += "\t";
        }
        row += " ";
        for (int j = 0; j < N; j++) {
            std::string s = std::to_string(matrix[i][j]) + "%";
            row += s;
            //row += (s.length() < 4) ? "\t\t" : "\t";
            row+="\t";

        }
        confMatrix += row;
        confMatrix += "\n";
    }
    defaultIo.write(confMatrix);
    std::remove(new_classified_predicted.data());
}
