//
// Created by noure on 20/05/2020.
//

#ifndef PROJECT3DS_SEQUENCED_H
#define PROJECT3DS_SEQUENCED_H


#include "Sequence.h"

template <int s> class SequenceD : private Sequence  {

    private:

    public:
        Sequence sequence;
        SequenceD();
        SequenceD(Sequence s1, Sequence s2);
        bool& operator[](int i) override ;
        bool operator()(int i) override ;
        SequenceD operator*(SequenceD sequenceD) ;
        int size() override ;
        void decalage(int s) override ;
        Sequence right();
        Sequence left();
};

template<int s>SequenceD<s>::SequenceD():Sequence(s/2) {
    //base(s/2);
    this->sequence = Sequence(s/2);
}

template<int s>
SequenceD<s>::SequenceD(Sequence s1, Sequence s2):Sequence(s1) {
    this->sequence = s2;
}

template<int s>
bool &SequenceD<s>::operator[](int i)  {
    if (i<s/2)
    {
        return Sequence::operator[](i);
    } else
    {
        return sequence[i-(s/2)];
    }
}

template<int s>
bool SequenceD<s>::operator()(int i) {
    if (i<s/2)
    {
        return Sequence::operator()(i);
    } else
    {
        return sequence[i-(s/2)];
    }
}

template<int s>
int SequenceD<s>::size() {
    return s;
}

template<int s>
void SequenceD<s>::decalage(int s) {

    Sequence::decalage(s);
    sequence.decalage(s);
}

template<int s>
SequenceD<s> SequenceD<s>::operator*(SequenceD sequenceD) {
    Sequence sequence1 = Sequence(s/2);
    Sequence sequence2 = Sequence(s/2);
    sequence1 = Sequence::operator*(sequenceD);
    sequence2 = sequence * sequenceD.sequence;

    return SequenceD(sequence1,sequence2);
}

template<int s>
Sequence SequenceD<s>::right() {
    return sequence;
}

template<int s>
Sequence SequenceD<s>::left() {
    return *this;
}



#endif //PROJECT3DS_SEQUENCED_H
