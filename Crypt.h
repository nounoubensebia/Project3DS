//
// Created by noure on 23/05/2020.
//

#ifndef PROJECT3DS_CRYPT_H
#define PROJECT3DS_CRYPT_H


#include "SequenceD.h"

class Crypt {
private:
    SequenceD<64> key1,key2;
    public:
        Crypt(SequenceD<64> key1,SequenceD<64> key2);
        SequenceD<64> cryptBinary(SequenceD<64> toCrypt);
        void operator() (string s1,string s2);
};


#endif //PROJECT3DS_CRYPT_H
