//
// Created by Daniel Assa on 19/07/2022.
//

#ifndef T1_IRIS_HPP
#define T1_IRIS_HPP
#include <vector>
#include <string>
#include <functional>
enum irisType
{
    setosa,
    virginica,
    versicolor,
    UNKNOWN
};
extern std::string enumArr[];
class Iris{
private:
    double width;
    double sepalLength;
    double sepalWidth;
    double petalLength;
    irisType type;
public:
    Iris(double width = 0, double  sepalLength = 0, double sepalWidth = 0, double petalLength = 0,
         irisType type = UNKNOWN);
    Iris(const Iris& iris);
//    Iris& operator=(const Iris& iris);
//    Iris(const Iris&& iris);
//    Iris& operator=(Iris&& iris);
//    ~Iris();
//The class only has primitive types has fields therefore an implementation for the DCtor is not needed.

    double getWidth() const;

    double getSepalLength() const;

    double getSepalWidth() const;

    double getPetalLength() const;

    irisType getType() const;

    void setFromVector(std::vector<std::string> v);

};
double eucDistance(const Iris& iris, const Iris& iris1);
double chebDistance(const Iris& iris, const Iris& iris1);
double manDistance(const Iris& iris, const Iris& iris1);
std::ostream& operator<<(std::ostream& os, const Iris& iris);

#endif //T1_IRIS_HPP
