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
public:
    int getK() const;

    void setK(int k);

    const std::string &getDistanceMetric() const;

    void setDistanceMetric(const std::string &distanceMetric);

};


#endif //APBARILAN3_CONTEXT_H
