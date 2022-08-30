#ifndef APBARILAN3_CLASSIFYDATA_H
#define APBARILAN3_CLASSIFYDATA_H


#include "Command.h"
#include "../KSmallestAlgo/KSmallestRun.h"

class ClassifyData : public Command {
public:
    ClassifyData(Context& ctx, DefaultIO &dio);
    void execute() override;
};


#endif //APBARILAN3_CLASSIFYDATA_H
