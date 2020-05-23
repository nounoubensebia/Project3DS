//
// Created by noure on 23/05/2020.
//

#include <iostream>
#include "F.h"
#include "Utils.h"

F::F(SequenceD<64> key) {
    sFonction = S_fonction(Utils::getSboxes());
    keyGen = KeyGen(key);
}

Sequence F::operator()(Sequence sequence_entree) {
    Sequence e = sequence_entree.permutation(Utils::getEPermutationTable());
    SequenceD<48> key_d = keyGen.next();
    Sequence key1 = key_d.left();
    Sequence key2 = key_d.right();
    std::list<Sequence> key_list;
    key_list.push_back(key1);
    key_list.push_back(key2);
    Sequence key = Sequence(key_list);
    Sequence xora = key * e;
    Sequence s_boxed = sFonction(xora);
    Sequence result = s_boxed.permutation(Utils::getPPermutationTable());
    return result;
    //return Sequence(32);
}
