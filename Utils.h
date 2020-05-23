//
// Created by noure on 22/05/2020.
//

#ifndef PROJECT3DS_UTILS_H
#define PROJECT3DS_UTILS_H


#include <vector>
#include "Sequence.h"

class Utils {
    public:
        static int binToDec(std::vector<bool> bits);
        static std::vector<std::vector<std::vector<int>>> getSboxes();
        static std::vector<int> getEPermutationTable();
        static std::vector<int> getPPermutationTable();
};


#endif //PROJECT3DS_UTILS_H
