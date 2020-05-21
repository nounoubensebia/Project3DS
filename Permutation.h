//
// Created by noure on 21/05/2020.
//

#ifndef PROJECT3DS_PERMUTATION_H
#define PROJECT3DS_PERMUTATION_H


#include "Sequence.h"
#include "SequenceD.h"
#include <list>

template <int te,int ts> class Permutation {

    public:
        SequenceD<ts> operator()(SequenceD<te> sequenceD,std::vector<int> vect);

};

template<int te, int ts>
SequenceD<ts> Permutation<te, ts>::operator()(SequenceD<te> sequenceD, std::vector<int> vect) {
    std::list<Sequence> sequences;
    sequences.push_back(sequenceD.left());
    sequences.push_back(sequenceD.right());
    Sequence sequence = Sequence(sequences);
    Sequence permuted = sequence.permutation(vect);
    //std::cout<<permuted.size();
    Sequence permutedLeft = permuted.sous_sequence(0,ts/2-1);
    Sequence permutedRight = permuted.sous_sequence(ts/2,ts-1);
    return SequenceD<ts>(permutedLeft,permutedRight);
    //return  SequenceD<ts> ();
}


#endif //PROJECT3DS_PERMUTATION_H
