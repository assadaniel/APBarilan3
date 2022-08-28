#ifndef APBARILAN3_DOWNLOADRESULT_H
#define APBARILAN3_DOWNLOADRESULT_H


#include "Command.h"
#include "KSmallestRun.h"

class DownloadResult : public Command {
public:
    DownloadResult(Context& ctx, DefaultIO &dio);
    void execute() override;
};


#endif //APBARILAN3_DOWNLOADRESULT_H
