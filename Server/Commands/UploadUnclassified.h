//
// Created by User on 20/08/2022.
//

#ifndef APBARILAN3_UPLOADUNCLASSIFIED_H
#define APBARILAN3_UPLOADUNCLASSIFIED_H


#include "Command.h"

class UploadUnclassified : public Command {
public:
    UploadUnclassified(Context& ctx, DefaultIO &dio);
    void execute() override;
    static bool is_empty(std::fstream& pFile);
};


#endif //APBARILAN3_UPLOADUNCLASSIFIED_H
