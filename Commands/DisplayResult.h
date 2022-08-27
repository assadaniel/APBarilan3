#ifndef APBARILAN3_DISPLAYRESULT_H
#define APBARILAN3_DISPLAYRESULT_H


#include "Command.h"
#include "KSmallestRun.h"

class DisplayResult : public Command {
public:
    DisplayResult(Context& ctx, DefaultIO &dio);
    void execute() override;
};


#endif //APBARILAN3_DISPLAYRESULT_H
