
#include <iostream>
#include <vector>
#include "ConfusionMatrix.h"
#include <unordered_map>
#include "../Iris/Iris.hpp"
#include <cmath>
#include <fstream>

#define N 3

ConfusionMatrix::ConfusionMatrix(Context &ctx, DefaultIO &dio) : Command(ctx, dio) {
    description = "display algorithm confusion matrix";
}

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
    std::string realClassName = context.getPathToTrain();
    if(realClassName.empty()) {
        defaultIo.write("Must upload train and test files beforehand.");
        return;
    }
    std::string predictedClassName = context.getClassifyName();
    if(predictedClassName.empty()) {
        defaultIo.write("Must classify data beforehand.");
        return;
    }
    std::fstream realClass(realClassName);
    std::string type;
    while (getline(realClass,type)) {
        realType.push_back(table[type]);
    }
    std::fstream predictedFstream(predictedClassName);
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
}
