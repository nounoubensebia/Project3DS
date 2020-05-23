//
// Created by noure on 23/05/2020.
//

#include <iostream>
#include "DES.h"
#include "F.h"
#include "Permutation.h"
#include "Utils.h"

DES::DES(SequenceD<64> sequenceD) {

    key = sequenceD;

}

SequenceD<64> DES::operator()(SequenceD<64> sequence_entree) {
    Permutation<64,64> permutation = Permutation<64,64>();
    SequenceD<64> sequence_courante = permutation(sequence_entree,Utils::getIPPermutationTable());
    F f = F(key);
    for (int i=0;i<16;i++)
    {
        Sequence l = sequence_courante.right();
        Sequence r = sequence_courante.left() * f(sequence_courante.right());
        sequence_courante = SequenceD<64>(l,r);
    }
    sequence_courante = SequenceD<64> (sequence_courante.right(),sequence_courante.left());
    SequenceD<64> sequence_resultat = permutation(sequence_courante,Utils::getIPInverseTable());
    return sequence_resultat;
}
