
#include <iostream>
#include <vector>
#include "ConfusionMatrix.h"
#include "Iris/Iris.hpp"
#include <unordered_map>
#include "Iris/IrisReader.hpp"
#define N 3
ConfusionMatrix::ConfusionMatrix(Context &ctx, DefaultIO &dio) : Command(ctx, dio) {
    description = "display algorithm confusion matrix";
}

void ConfusionMatrix::execute() {
    Context& context = getCtx();
    DefaultIO& defaultIo = getDio();
    std::unordered_map<std::string,irisType> table = { {"Iris-setosa",irisType::setosa}, {"Iris-virginica",irisType::virginica}, {"Iris-versicolor",irisType::versicolor}};
    std::vector<std::vector<int>> matrix(N, std::vector<int>(N));
    std::vector<irisType> realType;
    std::vector<irisType> predictedType;
    std::vector<int> countTypes(N,0);
    std::string realClassName = context.getPathToTest();
    std::string predictedClassName = context.getClassifyName();
    IrisReader trueIrisReader(realClassName);
    Iris cIris;
    while (trueIrisReader.getNextIris(cIris)) {
        realType.push_back(cIris.getType());
    }
    IrisReader predictedIrisReader(realClassName);
    while (predictedIrisReader.getNextIris(cIris)) {
        predictedType.push_back(cIris.getType());
    }
    for (int i = 0; i < N; i++){
        matrix[realType[i]][predictedType[i]]++;
        countTypes[realType[i]]++;
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            matrix[i][j] = ((double)matrix[i][j]/(double)countTypes[i])*100 + 0.5;
        }
    }
    std::string confMatrix;
    for (int i = 0; i < N; i++){
        std::string row = enumArr[i];
        if (row.length() < 14){
            row += "\t";
        }
        row += "\t";
        for (int j = 0; j < N; j++){
            row += matrix[i][j];
            row += "\t";
        }
        confMatrix += row;
        confMatrix += "\n";
    }
    defaultIo.write(confMatrix);
}
