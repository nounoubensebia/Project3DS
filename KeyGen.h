//
// Created by noure on 21/05/2020.
//

#ifndef PROJECT3DS_KEYGEN_H
#define PROJECT3DS_KEYGEN_H


#include "SequenceD.h"

class KeyGen {
    private:
        SequenceD<64> key;
        SequenceD<56> CD;
        int iteration = 0;
        //std::vector<int> pc1 {57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4};

    public:
        KeyGen(SequenceD<64> sequenceD);
        SequenceD<48> next();
        static std::vector<int> getPc1();

    std::vector<int> getPc2();
};


#endif //PROJECT3DS_KEYGEN_H
