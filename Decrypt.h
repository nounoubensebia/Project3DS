//
// Created by noure on 23/05/2020.
//

#ifndef PROJECT3DS_DECRYPT_H
#define PROJECT3DS_DECRYPT_H

#include "SequenceD.h"

class Decrypt {
private:
    SequenceD<64> key1,key2;
public:
    Decrypt(SequenceD<64> key1,SequenceD<64> key2);
    SequenceD<64> decryptBinary(SequenceD<64> toDeCrypt);
};


#endif //PROJECT3DS_DECRYPT_H
