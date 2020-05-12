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
    std::deque<bool> getRep (int n,int size);
public:
    Sequence(int size = 4);
    Sequence(std::list<Sequence> l);
    Sequence(std::deque<bool> bits);
    bool& operator[](int i);
    bool operator()(int i);
    void operator=(int i);
    void decalage(int n);
    Sequence operator*(Sequence sequence);
    int size();
    Sequence permutation (std::vector<int> vect);
    Sequence sous_sequence (int i,int j);
};




#endif //PROJECT3DS_SEQUENCE_H
