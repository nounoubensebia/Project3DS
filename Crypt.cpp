//
// Created by noure on 23/05/2020.
//

#include "Crypt.h"
#include "DES.h"
#include "DESinv.h"

Crypt::Crypt(SequenceD<64> key1, SequenceD<64> key2) {
    this->key1 = key1;
    this->key2 = key2;
}

SequenceD<64> Crypt::cryptBinary(SequenceD<64> toCrypt) {
    DES des = DES(key1);
    SequenceD<64> result1 = des(toCrypt);
    DESinv deSinv = DESinv(key2);
    SequenceD<64> result2 = deSinv(result1);
    des = DES(key1);
    return des(result2);
}
