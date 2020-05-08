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

void Sequence::operator= (int n)
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
    if (this->size()!=sequence.size())
    {
        return NULL;
    } else
    {
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
    }

}

std::deque<bool> Sequence::getRep(int n, int size) {
    std::deque<bool> dq;
    for (int i = 0;i<size;i++)
    {
        bool b = (n%2==0)?0:1;
        dq.push_front(b);
        n=n/2;
    }
    return dq;
}



