//
// Created by Daniel Assa on 19/07/2022.
//

#include "IrisComp.hpp"

/**
 * @brief A constractor of IrisComp.
 *
 * @param iris The iris we want to convert to IrisComp.
 * @param dis The distance from the other iris (IrisComp is comparable to a different iris).
 */
IrisComp ::IrisComp(const Iris iris, double dis) : iris(iris), dis(dis){}

/**
    @brief The deafult constractor.
 */
IrisComp ::IrisComp() : dis(0) {}

/**
 * @brief The operators we want IrisComp to be able to get.
 * !=, <=, >=, ==, <, >.
 */
bool IrisComp ::operator!=(const IrisComp &irisComp) const {return this->dis != irisComp.dis;}
bool IrisComp ::operator<=(const IrisComp &irisComp) const {return this->dis <= irisComp.dis;}
bool IrisComp ::operator>=(const IrisComp &irisComp) const {return this->dis >= irisComp.dis;}
bool IrisComp ::operator==(const IrisComp &irisComp) const {return this->dis == irisComp.dis;}
bool IrisComp ::operator<(const IrisComp &irisComp) const {return this->dis < irisComp.dis;}
bool IrisComp ::operator>(const IrisComp &irisComp) const {return this->dis > irisComp.dis;}

/**
 * @brief Iris getter.
 *
 * @return The iris
 */
const Iris &IrisComp::getIris() const {
    return iris;
}

/**
 * @brief Distance getter.
 *
 * @return The distance.
 */
double IrisComp::getDis() const {
    return dis;
}


