//
// Created by noure on 23/05/2020.
//

#include "Decrypt.h"
#include "DESinv.h"
#include "DES.h"

#include <fstream>

Decrypt::Decrypt(SequenceD<64> key1, SequenceD<64> key2) {
    this->key1 = key1;
    this->key2 = key2;
}

SequenceD<64> Decrypt::decryptBinary(SequenceD<64> toDeCrypt) {
    DESinv des = DESinv(key1);
    SequenceD<64> result1 = des(toDeCrypt);
    DES deSinv = DES(key2);
    SequenceD<64> result2 = deSinv(result1);
    des = DESinv(key1);
    return des(result2);
}

void Decrypt::operator()(string s1, string s2) {
    ifstream in(s1,ios::in);
    SequenceD<64> toDecrypt;
    in >> toDecrypt;
    SequenceD<64> decrypted = decryptBinary(toDecrypt);
    ofstream out(s2,ios::out);
    decrypted << out;
}