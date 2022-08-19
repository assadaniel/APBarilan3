//
// Created by Daniel Assa on 19/07/2022.
//

#include "Iris.hpp"
#include <iostream>
#include <cmath>
#include <iostream>
#include <functional>


std::string enumArr[] = {"Iris-setosa","Iris-virginica", "Iris-versicolor","UNKNOWN"};

/**
 * @brief Construct a new classified Iris.
 * 
 * @param width A double representing the width of the Iris.
 * @param sepalLength A double representing the length of the sepal of the Iris.
 * @param sepalWidth A double representing the width of the sepal of the Iris
 * @param petalLength A double representing the length of the petal of the Iris
 * @param type An enum representing the type of the Iris.
 */
Iris::Iris(double width, double sepalLength, double sepalWidth, double petalLength, irisType type)
        : width(width), sepalLength(sepalLength), sepalWidth(sepalWidth), petalLength(petalLength), type(type) {}

Iris::Iris(const Iris &iris) {
    this->width = iris.width;
    this->sepalLength = iris.sepalLength;
    this->sepalWidth = iris.sepalWidth;
    this->petalLength = iris.sepalLength;
    this->type = iris.type;
}

/**
 * @brief Function calculating the euclidian distance (difference) between two flowers.
 * 
 * @param iris first Iris.
 * @param iris1 second Iris
 * @return double The distance (difference) between the flowers.
 */
double eucDistance(const Iris& iris, const Iris& iris1) {
    return sqrtf(pow((iris1.getWidth() - iris1.getWidth()), 2) +
                 pow((iris1.getSepalLength() - iris.getSepalLength()), 2) +
                 pow((iris1.getSepalWidth() - iris.getSepalWidth()), 2) +
                 pow((iris1.getPetalLength() - iris.getPetalLength()), 2));
}

/**
 * @brief Function calculating the chebyshev distance (difference) between two flowers.
 * 
 * @param iris The other iris we compare.
 * @return double The distance (difference) between the flowers.
 */
double chebDistance(const Iris& iris, const Iris& iris1) {
    double m1 = fmax(fabs(iris1.getWidth() - iris.getWidth()),
                     fabs(iris1.getSepalLength() - iris.getSepalLength()));
    double m2 = fmax(fabs(iris1.getSepalWidth() - iris.getSepalWidth()),
                     fabs(iris1.getPetalLength() - iris.getPetalLength()));
    return fmax(m1, m2);
}

/**
 * @brief Function calculating the manhattan distance (difference) between two flowers.
 * 
 * @param iris first Iris.
 * @param iris1 second Iris
 * @return double The distance (difference) between the flowers.
 */
double manDistance(const Iris& iris, const Iris& iris1) {
    return fabs(iris1.getWidth() - iris.getWidth()) + fabs(iris1.getSepalLength() - iris.getSepalLength()) +
           fabs(iris1.getSepalWidth() - iris.getSepalWidth())
           + fabs(iris1.getPetalLength() - iris.getPetalLength());
}

/**
 * @brief Width getter.
 * 
 * @return double The width of the iris.
 */
double Iris::getWidth() const {
    return width;
}

/**
 * @brief Sepal length getter.
 * 
 * @return double The sepal length of the iris.
 */
double Iris::getSepalLength() const {
    return sepalLength;
}

/**
 * @brief Sepal width getter.
 * 
 * @return double The sepal width of the iris.
 */

double Iris::getSepalWidth() const {
    return sepalWidth;
}

/**
 * @brief Petal length getter.
 * 
 * @return double The petal length of the iris.
 */

double Iris::getPetalLength() const {
    return petalLength;
}

/**
 * @brief Iris getter.
 * 
 * @return irisType The iris type (enum).
 */
irisType Iris::getType() const {
    return type;
}

/**
 * Make an Iris from a vector of the fields given in strings.
 * @param v The vector.
 */
void Iris::setFromVector(std::vector<std::string> v) {
    this->width = std::stod(v[0]);
    this->sepalLength = std::stod(v[1]);
    this->sepalWidth = std::stod(v[2]);
    this->petalLength = std::stod(v[3]);
    std::string t;
    try {
        t = v.at(4);
        if(t=="Iris-setosa") {
            this->type = setosa;
        } else if(t == "Iris-versicolor") {
            this->type = versicolor;
        } else {
            this->type = virginica;
        }
    } catch(const std::out_of_range& e) {
        this->type = UNKNOWN;
    }
}



/**
 * << operator for Iris.
 * @param os The out stream
 * @param iris Iris object
 * @return Out stream.
 */
std::ostream &operator<<(std::ostream &os, const Iris &iris) {
    return os << iris.getWidth() << "," << iris.getSepalLength() << ","
              << iris.getSepalWidth() << "," << iris.getPetalLength() << "," << enumArr[iris.getType()];
}
