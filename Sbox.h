//
// Created by noure on 22/05/2020.
//

#ifndef PROJECT3DS_SBOX_H
#define PROJECT3DS_SBOX_H


#include <vector>
#include "Sequence.h"

class Sbox {
    private:
        std::vector<std::vector<Sequence>> sequences;
    public:
        Sbox(std::vector<std::vector<Sequence>> sequences);
        ~Sbox();
        Sbox(const Sbox &sbox);
        Sbox &operator=(const Sbox &sbox);
        Sequence operator()(Sequence sequence_entree);
};


#endif //PROJECT3DS_SBOX_H
