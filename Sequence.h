//
// Created by noure on 08/05/2020.
//

#ifndef PROJECT3DS_SEQUENCE_H
#define PROJECT3DS_SEQUENCE_H
#include <deque>
#include <list>
#include <vector>

class Sequence {
private:
    std::deque<bool> bits;
    std::deque<bool> getRep (unsigned int n,int size);
public:
    Sequence(int size = 4);
    Sequence(std::list<Sequence> l);
    Sequence(std::deque<bool> bits);

    virtual bool& operator[](int i);

    virtual bool operator()(int i);
    void operator=(unsigned int i);

    virtual void decalage(int n);
    Sequence operator*(Sequence sequence);

    virtual int size();
    Sequence permutation (std::vector<int> vect);
    Sequence sous_sequence (int i,int j);
};




#endif //PROJECT3DS_SEQUENCE_H
