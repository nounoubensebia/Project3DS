//
// Created by noure on 20/05/2020.
//

#ifndef PROJECT3DS_SEQUENCED_H
#define PROJECT3DS_SEQUENCED_H


#include <iostream>
using namespace std;
#include <bitset>
#include <sstream>
#include "Sequence.h"
#include "Utils.h"

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
        void decalage(int k) override ;
        Sequence right();
        Sequence left();
        friend void operator<<(SequenceD<64>& seq, ostream& mycout);
        friend void operator>>(istream& mycin, SequenceD<64>& seq);
        void write (SequenceD<64>& seq, ostream& mycout);
        void read (istream& mycin, SequenceD<64>& seq);
        template<typename t> void affichage (t ob);
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
void SequenceD<s>::decalage(int k) {

    Sequence::decalage(k);
    sequence.decalage(k);
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

inline void operator<<(SequenceD<64> &seq, ostream &mycout) {
    std::vector<bool> dqa;
    int j=1;
    for (int i=0;i<seq.size();i++)
    {
        dqa.push_back(seq[i]);
        if (j==8)
        {
            int c = Utils::binToDec(dqa);
            if (c>127)
            {
                c-=256;
            }
            char ch = (char)c;
            mycout.put(ch);
            j=1;
            dqa.clear();
        } else
        {
            j++;
        }
    }
}

inline void operator>>(istream &mycin, SequenceD<64> &seq) {
    std::list<Sequence> list;
    Sequence sequence1;
    Sequence sequence2;
    char ch;
    int i=0;
    while (mycin.get(ch))
        {
            Sequence sequence = Sequence(8);
            int c = (int)ch;
            if (c<0)
            {
                c+=256;
            }
            sequence = c;
            list.push_back(sequence);
            if (i==3)
            {
                sequence1 = Sequence(list);

                list.clear();
            }
            i++;
        }
    sequence2 = Sequence(list);
    seq = SequenceD<64>(sequence1,sequence2);
}

template<int s>
void SequenceD<s>::write(SequenceD<64> &seq, ostream &mycout) {
    mycout << "Les bits de la sequence sont \n";
    string data;
    for (int i=0;i<seq.size();i++)
    {
        data += seq[i] ? "1" : "0";
    }
    mycout << data;
}

template<int s>
void SequenceD<s>::read(istream &mycin, SequenceD<64> &seq) {
    string data;
    for (int i=0;i<seq.size();i++)
    {
        data += seq[i] ? "1" : "0";
    }
    mycin >> data;
}

template<int s>
template<typename t>
void SequenceD<s>::affichage(t ob) {
    cout << "la taille de l'objet est : ";
    cout <<ob.size();
    cout << std::endl;
    cout <<"elements de l'objet : ";
    cout << std::endl;
    for (int i=0;i<ob.size();i++)
    {
        std::cout<<ob(i);
    }
    cout << std::endl;
}



#endif //PROJECT3DS_SEQUENCED_H
