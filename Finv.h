//
// Created by noure on 23/05/2020.
//

#ifndef PROJECT3DS_FINV_H
#define PROJECT3DS_FINV_H


#include "KeyGen.h"
#include "S_fonction.h"

class Finv {
    private:
        SequenceD<64> key;
        S_fonction sFonction;
        int iteration = 0;
        SequenceD<48> getCurrentKey();
    public:
        Finv(SequenceD<64> key);
        Sequence operator()(Sequence sequence_entree);
};


#endif //PROJECT3DS_FINV_H
