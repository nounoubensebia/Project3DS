//
// Created by noure on 21/05/2020.
//

#include "KeyGen.h"
#include "Permutation.h"


KeyGen::KeyGen(SequenceD<64> sequenceD) {
    key = sequenceD;
}

std::vector<int> KeyGen::getPc1() {
    std::vector<int> vect = {57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4};
    for (int i=0;i<vect.size();i++)
    {
        vect[i] = vect[i]-1;
    }
    return vect;
}

std::vector<int> KeyGen::getPc2()
{
    std::vector<int> vect = {14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,29,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32};
    for (int i=0;i<vect.size();i++)
    {
        vect[i] = vect[i]-1;
    }
    return vect;
}

SequenceD<48> KeyGen::next() {

    if (iteration == 0)
    {
        Permutation<64,56> permutation = Permutation<64,56>();
        CD = permutation(key,getPc1());

    }
    CD.decalage(getSchedule()[iteration]);
    Permutation<56,48> permutation1 = Permutation<56,48>();
    SequenceD<48> sequenceD = permutation1(CD,getPc2());
    iteration++;
    return sequenceD;
}

std::vector<int> KeyGen::getSchedule() {
    return {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
}
