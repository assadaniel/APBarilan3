//
// Created by User on 07/08/2022.
//

#include "KSmallestRun.h"
#include "KSmallestElements.hpp"
#include "../Iris/IrisReader.hpp"

/**
 * @brief Running the K Smallest Elements function om multiple objects and using it to classifie the irises.
 * 
 * @param k The number of elements to find.
 * @param new_classified_stream The file of the classified irises.
 * @param unclassified_file_name The file name of the unclassified irises we want to classifie.
 */
void KSmallestRun::runKSmallest(int k, std::fstream& new_classified_stream, const std::string& unclassified_file_name,
                                const std::function<double(const Iris, const Iris)>& distanceFunction) {
    IrisReader classifiedIrisReader("classified.csv"); // name of classified file
    Iris cIris;
    std::vector<Iris> classifiedIrises;
    while (classifiedIrisReader.getNextIris(cIris)) { classifiedIrises.push_back(cIris); }
    //Create Unclassified Iris vector
    IrisReader unclassifiedIrisReader(unclassified_file_name);
    Iris uIris;
    std::vector<Iris> unclassifiedIrises;
    while (unclassifiedIrisReader.getNextIris(uIris)) { unclassifiedIrises.push_back(uIris); }
    //Create Streams
    for (const Iris& unclassifiedIris: unclassifiedIrises) {
        //Write the types to files.
        new_classified_stream <<
        enumArr[typeFromIrises(unclassifiedIris, classifiedIrises, k, distanceFunction)]
                << std::endl;
    }
}