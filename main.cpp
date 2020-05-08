#include <iostream>
#include "Sequence.h"


void f3()
{
    Sequence sequence1 = Sequence(5);
    Sequence sequence2 = Sequence(5);

    for (int i=0; i < sequence1.size(); i++)
    {
        std::cout << sequence1[i] ;
    }

    std::cout<<std::endl;

    for (int i=0; i < sequence2.size(); i++)
    {
        std::cout << sequence2[i] ;
    }

    std::cout<<std::endl;

    Sequence sequence = sequence1*sequence2;

    for (int i=0; i < sequence.size(); i++)
    {
        std::cout << sequence[i] ;
    }
}

void f2()
{

    Sequence sequence = Sequence(5);

    sequence = 1;

    sequence.decalage(2);

    for (int i=0; i < sequence.size(); i++)
    {
        std::cout << sequence[i] ;
    }

}


int main() {

    f3();

    return 0;
}



void f1()
{
    std::cout << "Hello, World!" << std::endl;
    Sequence sequence1 = Sequence(5);
    Sequence sequence2 = Sequence(4);
    for (int i=0; i < sequence1.size(); i++)
    {
        std::cout << sequence1[i] << std::endl;
    }

    for (int i=0; i < sequence2.size(); i++)
    {
        std::cout << sequence2[i] << std::endl;
    }
    std::list<Sequence> list;
    list.push_back(sequence1);
    list.push_back(sequence2);
    Sequence sequence3 = Sequence(list);

    std::cout <<"concat list" << std::endl;

    for (int i=0; i < sequence3.size(); i++)
    {
        std::cout << sequence3[i] << std::endl;
    }
}
