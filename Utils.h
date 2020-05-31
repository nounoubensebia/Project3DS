//
// Created by noure on 22/05/2020.
//

#ifndef PROJECT3DS_UTILS_H
#define PROJECT3DS_UTILS_H


#include <vector>
#include "Sequence.h"


// Classe utilisée pour la génération des différantes tables de l'algorithme
// Cette classe contient aussi quelques fonctions utiles utilisés dans le programme
class Utils {
    public:
        static int binToDec(std::vector<bool> bits);
        static std::vector<std::vector<std::vector<int>>> getSboxes();
        static std::vector<int> getEPermutationTable();
        static std::vector<int> getPPermutationTable();
        static std::vector<int> getIPPermutationTable();
        static std::vector<int> getIPInverseTable();
        static unsigned  int getDecFromHexString(std::string hex, bool leftPart);
};


#endif //PROJECT3DS_UTILS_H
