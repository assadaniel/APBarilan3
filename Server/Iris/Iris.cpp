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

Iris::Iris(const Iris &iris) {
    std::vector<double> qs = iris.getQualities();
    qualities = qs;
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
    double sum = 0;
    for(int i=0;i<iris.getQualitySize();i++) {
        sum+=pow((iris1.at(i) - iris.at(i)), 2);
    }
    return sqrtf(sum);
}

/**
 * @brief Function calculating the chebyshev distance (difference) between two flowers.
 *
 * @param iris The other iris we compare.
 * @return double The distance (difference) between the flowers.
 */
double chebDistance(const Iris& iris, const Iris& iris1) {
    double m;
    for(int i=0;i<iris.getQualitySize();i++) {
        m = fmax(m, fabs(iris.at(i)-iris1.at(i)));
    }
    return m;
}

/**
 * @brief Function calculating the manhattan distance (difference) between two flowers.
 *
 * @param iris first Iris.
 * @param iris1 second Iris
 * @return double The distance (difference) between the flowers.
 */
double manDistance(const Iris& iris, const Iris& iris1) {
    double sum = 0;
    for(int i=0;i<iris.getQualitySize();i++) {
        sum+= fabs(iris1.at(i) - iris.at(i));
    }
    return sum;
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
void Iris::setFromVector(std::vector<std::string>& v) {
    for(int i =0;i<v.size();i++) {
        if(i == v.size() -1) {
            std::string t;
            try {
                t = v.at(i);
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
        } else { qualities.push_back(std::stod(v.at(i))); }
    }

}

const std::vector<double> &Iris::getQualities() const {
    return qualities;
}

size_t Iris::getQualitySize() const {
    return qualities.size();
}

double Iris::at(int index) const {
    return qualities.at(index);
}

Iris::Iris(): type(UNKNOWN){

}

void Iris::clear() {
    qualities.clear();
}


///**
// * << operator for Iris.
// * @param os The out stream
// * @param iris Iris object
// * @return Out stream.
// */
//std::ostream &operator<<(std::ostream &os, const Iris &iris) {
//
//    return os << iris.getWidth() << "," << iris.getSepalLength() << ","
//              << iris.getSepalWidth() << "," << iris.getPetalLength() << "," << enumArr[iris.getType()];
//}
