//
// Created by noure on 23/05/2020.
//

#ifndef PROJECT3DS_F_H
#define PROJECT3DS_F_H


#include "KeyGen.h"
#include "S_fonction.h"

class F {

    private:
        KeyGen keyGen;
        S_fonction sFonction;
        int iteration = 0;

    public:
        F(SequenceD<64> key);
        Sequence operator()(Sequence sequence_entree);
};


#endif //PROJECT3DS_F_H
