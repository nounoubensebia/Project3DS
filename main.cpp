#include <iostream>
#include "Sequence.h"
#include "SequenceD.h"
#include "Permutation.h"
#include "KeyGen.h"


void f11()
{
    Sequence s1 = Sequence(32);
    Sequence s2 = Sequence(32);
    s1 = 322197369;
    s2 = 2612846577;
    SequenceD<64> sequenceD = SequenceD<64>(s1,s2);
    KeyGen keyGen = KeyGen(sequenceD);
    SequenceD<48> key = keyGen.next();
    for (int i=0;i<key.size();i++)
    {
        std::cout << key[i] ;
    }
}

void f10()
{
    Permutation<64,56> permutation = Permutation<64,56>();
    Sequence s1 = Sequence(32);
    Sequence s2 = Sequence(32);
    s1 = 322197369;
    s2 = 2612846577;
    SequenceD<64> sequenceD = SequenceD<64>(s1,s2);
    for (int i=0;i<sequenceD.size();i++)
    {
        std::cout << sequenceD[i] ;
    }
    std::cout << std::endl;
    SequenceD<56> sequenceD1;
    std::vector<int> vect = KeyGen::getPc1();
    sequenceD1 = permutation(sequenceD,vect);
    for (int i=0;i<sequenceD1.size();i++)
    {
        std::cout << sequenceD1[i] ;
    }
}

void f9()
{
    Sequence s1 = Sequence(4);
    Sequence s2 = Sequence(4);
    s1 = 5;
    s2 = 9;
    SequenceD<8> sequenceD = SequenceD<8>(s1,s2);
    std::cout<<sequenceD.right().size();
}

void f8()
{
    Sequence s1 = Sequence(4);
    Sequence s2 = Sequence(4);
    s1 = 5;
    s2 = 9;
    SequenceD<8> sequenceD1 = SequenceD<8>(s1,s2);
    for (int i=0;i<sequenceD1.size();i++)
    {
        std::cout << sequenceD1[i] ;
        //std::cout<<i;
    }
    std::cout<<std::endl;
    SequenceD<8> sequenceD2 = SequenceD<8>(s2,s1);
    for (int i=0;i<sequenceD2.size();i++)
    {
        std::cout << sequenceD2[i] ;
        //std::cout<<i;
    }
    SequenceD<8> sequenceD = sequenceD1*sequenceD2;
    //std::cout << sequenceD[1] ;
    std::cout<<std::endl;
    for (int i=0;i<sequenceD.size();i++)
    {
        std::cout << sequenceD[i] ;
        //std::cout<<i;
    }
}

void f7()
{
    Sequence s1 = Sequence(4);
    Sequence s2 = Sequence(4);
    s1 = 5;
    s2 = 9;
    SequenceD<8> sequenceD = SequenceD<8>(s1,s2);

    for (int i=0; i < sequenceD.sequence.size(); i++)
    {
        std::cout << sequenceD.sequence[i] ;
    }

    std::cout << std::endl;

    std::cout << sequenceD[7];
    sequenceD.decalage(2);
    std::cout << std::endl;
    for (int i=0; i < sequenceD.sequence.size(); i++)
    {
        std::cout << sequenceD.sequence[i] ;
    }
    //std::cout<<sequenceD.sequence.size();
}

void f6()
{
    SequenceD<12> sequenceD;
    sequenceD = SequenceD<12>();
    //std::cout<<sequenceD.size();
    //std::cout<<sequenceD.sequence.size();
}

void f5()
{
    Sequence sequence = Sequence(5);
    sequence = 18;
    Sequence sequence1 = sequence.sous_sequence(1,3);
    for (int i=0; i < sequence1.size(); i++)
    {
        std::cout << sequence1[i] ;
    }
}

void f4()
{
    Sequence sequence = Sequence(5);
    //std::cout << sequence.size();
    sequence = 18;

    for (int i=0; i < sequence.size(); i++)
    {
        std::cout << sequence[i] ;
    }

    std::cout << std::endl;

    std::vector<int> vector = std::vector<int>();
    vector.push_back(4);
    vector.push_back(2);
    vector.push_back(1);
    vector.push_back(0);
    vector.push_back(3);
    //std::cout << vector[1];
    //vector[1]=2;
    //vector[2]=0;

    Sequence sequence1 = sequence.permutation(vector);

    for (int i=0; i < sequence1.size(); i++)
    {
        std::cout << sequence1[i] ;
    }

}

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

    f11();

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
