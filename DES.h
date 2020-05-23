//
// Created by noure on 23/05/2020.
//

#ifndef PROJECT3DS_DES_H
#define PROJECT3DS_DES_H


#include "SequenceD.h"

class DES {

    private:
        SequenceD<64> key;

    public:
        DES(SequenceD<64> sequenceD);
        SequenceD<64> operator()(SequenceD<64> sequence_entree);
};


#endif //PROJECT3DS_DES_H
