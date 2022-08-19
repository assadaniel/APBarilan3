//
// Created by User on 07/08/2022.
//

#ifndef APBARILAN2_KSMALLESTRUN_H
#define APBARILAN2_KSMALLESTRUN_H
#include <fstream>
class KSmallestRun {
public:
    static void runKSmallest(int k, std::fstream& new_classified_stream, const std::string& unclassified_file_name);
};


#endif //APBARILAN2_KSMALLESTRUN_H
