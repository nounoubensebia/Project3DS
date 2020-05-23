//
// Created by noure on 23/05/2020.
//

#include <iostream>
#include "Finv.h"
#include "Utils.h"

Finv::Finv(SequenceD<64> key) {
    this->key = key;
    sFonction = S_fonction(Utils::getSboxes());
}

Sequence Finv::operator()(Sequence sequence_entree) {
    Sequence e = sequence_entree.permutation(Utils::getEPermutationTable());
    SequenceD<48> key_d = getCurrentKey();
    Sequence key1 = key_d.left();
    Sequence key2 = key_d.right();
    std::list<Sequence> key_list;
    key_list.push_back(key1);
    key_list.push_back(key2);
    Sequence keya = Sequence(key_list);
    Sequence xora = keya * e;
    Sequence s_boxed = sFonction(xora);
    Sequence result = s_boxed.permutation(Utils::getPPermutationTable());
    return result;
}

SequenceD<48> Finv::getCurrentKey() {
    int n = 16-iteration;
    //std::cout<<n;
    //std::cout<<std::endl;
    KeyGen keyGen = KeyGen(key);
    SequenceD<48> subKey;
    for (int i=0;i<n;i++)
    {
        subKey = keyGen.next();
    }
    //std::cout<<"entered\n";
    iteration++;
    return subKey;
}
