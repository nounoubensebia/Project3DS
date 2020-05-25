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
    string data;
    string out;
    for (int i=0;i<seq.size();i++)
    {
        data += seq[i] ? "1" : "0";
    }
    stringstream sstream(data);
    char c;
    while(sstream.good())
    {
        bitset<8> bits;
        sstream >> bits;
        c = char(bits.to_ulong());
        //cout << c;
        out+=c;
    }
    out.pop_back();
    mycout << out;
}

inline void operator>>(istream &mycin, SequenceD<64> &seq) {
    string s;
    std::deque<bool> bitdq;
    bool b;
    string bits;
    mycin >> s;

    for (int i = 0; i < s.size(); i += 1) {
        //cout << bitset<8>(s[i]) << " ";
        bits = std::bitset<8>(s[i]).to_string();
        for(int j = 0; j < 8 ; j +=1 ){
            if (bits[j] == '1'){
                b = true;
            }else{
                b = false;
            }
            bitdq.push_back(b);
        }
    }
    for (int i = 0; i < bitdq.size(); i += 1) {
        seq[i]=bitdq[i];
        //cout << seq[i];
    }

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
    int i;
    cout << "la taille de l'objet est " << endl;
    cout << ob.size() << endl;
    cout << "Donner la position " << endl;
    cin >> i;
    cout << "le bit est " << endl;
    cout << ob(i) << endl;
}

template<typename t>
void affichage (t ob) {

}


#endif //PROJECT3DS_SEQUENCED_H
