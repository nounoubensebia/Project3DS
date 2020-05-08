//
// Created by noure on 08/05/2020.
//

#ifndef PROJECT3DS_SEQUENCE_H
#define PROJECT3DS_SEQUENCE_H
#include <deque>
#include <list>

class Sequence {
private:
    std::deque<bool> bits;
    std::deque<bool> getRep (int n,int size);
public:
    Sequence(int size = 4);
    Sequence(std::list<Sequence> l);
    bool& operator[](int i);
    bool operator()(int i);
    void operator=(int i);
    void decalage(int n);
    Sequence operator*(Sequence sequence);
    int size();
};




#endif //PROJECT3DS_SEQUENCE_H
