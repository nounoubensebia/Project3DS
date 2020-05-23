//
// Created by noure on 23/05/2020.
//

#ifndef PROJECT3DS_DESINV_H
#define PROJECT3DS_DESINV_H
#include "SequenceD.h"

class DESinv {
private:
    SequenceD<64> key;

public:
    DESinv(SequenceD<64> sequenceD);
    SequenceD<64> operator()(SequenceD<64> sequence_entree);
};


#endif //PROJECT3DS_DESINV_H
