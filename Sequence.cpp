//
// Created by noure on 08/05/2020.
//

#include "Sequence.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

Sequence::Sequence(int size)
{
    int i;
    bool b;

    for (i=0;i<size;i++)
    {
        if ((rand()%2)==0)
        {
            b = true;
        } else
        {
            b = false;
        }
        //std::cout <<b<<std::endl;
        bits.push_back(b);
    }
}

Sequence::Sequence(std::list<Sequence> l)
{
    int i,j;
    for (std::list<Sequence>::iterator it=l.begin();it != l.end();++it)
    {
        std::deque<bool> toAdd = (*it).bits;
        for (j=0;j<toAdd.size();j++)
        {
            bits.push_back(toAdd[j]);
        }
    }
}

int Sequence::size() {
    return bits.size();
}


bool& Sequence::operator[](int i) {
    return bits[i];
}

bool Sequence::operator()(int i) {
    return bits[i];
}

void Sequence::operator= (unsigned int n)
{
    bits = getRep(n,bits.size());
}

void Sequence::decalage(int n) {
    int oldSize = bits.size();
    for (int i=0;i<n;i++)
    {
            bool b = bits.front();
            bits.pop_front();
            bits.push_back(b);
    }
}

Sequence Sequence::operator*(Sequence sequence) {

    Sequence sequence1 = Sequence(sequence.size());
    for (int i=0;i<sequence.size();i++)
    {
        if (this->bits[i]!=sequence.bits[i])
        {
            sequence1[i] = true;
        } else
        {
            sequence1[i] = false;
        }
    }
    return sequence1;


    if (this->size()!=sequence.size())
    {
        return NULL;
    } else
    {

    }

}

Sequence::Sequence(std::deque<bool> bits)
{
    this->bits = bits;
}

std::deque<bool> Sequence::getRep(unsigned int n, int size) {
    std::deque<bool> dq;
    for (int i = 0;i<size;i++)
    {
        bool b = (n%2==0)?0:1;
        dq.push_front(b);
        n=n/2;
    }
    return dq;
}

Sequence Sequence::permutation (std::vector<int> vect) {
    //std::deque<bool> dq;
    Sequence sequence = Sequence(vect.size());
    for (int i=0;i<vect.size();i++)
    {
        sequence[i] = this->bits[vect[i]];
    }
    return sequence;
}

Sequence Sequence::sous_sequence(int i, int j) {

    Sequence sequence = Sequence(j-i+1);
    for (int k=i;k<=j;k++)
    {
        sequence[k-i] = this->bits[k];
    }
    return sequence;
}



