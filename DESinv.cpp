//
// Created by noure on 23/05/2020.
//

#include <iostream>
#include "DESinv.h"
#include "Permutation.h"
#include "Utils.h"
#include "Finv.h"

DESinv::DESinv(SequenceD<64> sequenceD) {
    key = sequenceD;
}

SequenceD<64> DESinv::operator()(SequenceD<64> sequence_entree) {
    Permutation<64,64> permutation = Permutation<64,64>();
    SequenceD<64> sequence_courante = permutation(sequence_entree,Utils::getIPPermutationTable());

    Finv f = Finv(key);
    for (int i=0;i<16;i++)
    {
       Sequence l = sequence_courante.right();
       Sequence r = sequence_courante.left() * f(sequence_courante.right());
       sequence_courante = SequenceD<64>(l,r);

    }
    sequence_courante = SequenceD<64> (sequence_courante.right(),sequence_courante.left());
    //std::cout<<sequence_courante.left().size();

    SequenceD<64> sequence_resultat = permutation(sequence_courante,Utils::getIPInverseTable());
    return sequence_resultat;
    //return SequenceD<64> ();
}
