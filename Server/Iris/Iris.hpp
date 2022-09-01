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
    std::vector<double> qualities;
    irisType type;
public:
    Iris();
    Iris(const Iris& iris);
    irisType getType() const;
    double at(int index) const;
    const std::vector<double> &getQualities() const;
    size_t getQualitySize() const;
    void setFromVector(std::vector<std::string>& v);
    void clear();
};
double eucDistance(const Iris& iris, const Iris& iris1);
double chebDistance(const Iris& iris, const Iris& iris1);
double manDistance(const Iris& iris, const Iris& iris1);
//std::ostream& operator<<(std::ostream& os, const Iris& iris);

#endif //T1_IRIS_HPP

