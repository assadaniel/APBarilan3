#ifndef APBARILAN3_CONFUSIONMATRIX_H
#define APBARILAN3_CONFUSIONMATRIX_H


#include "Command.h"
#include "KSmallestRun.h"

class ConfusionMatrix : public Command {
public:
    ConfusionMatrix(Context& ctx, DefaultIO &dio);
    void execute() override;
};


#endif //APBARILAN3_CONFUSIONMATRIX_H
