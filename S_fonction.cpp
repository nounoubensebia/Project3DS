//
// Created by noure on 22/05/2020.
//

#include <iostream>
#include "S_fonction.h"
#include "Sbox.h"

S_fonction::S_fonction(std::vector<std::vector<std::vector<int>>> sBoxes) {
    this->sBoxes = sBoxes;
}

S_fonction::~S_fonction() {
    for (int i=0;i<sBoxes.size();i++)
    {
        for (int j=0;j<sBoxes[i].size();j++)
        {
            sBoxes[i][j].clear();
            sBoxes[i][j].shrink_to_fit();
        }
        sBoxes[i].clear();
        sBoxes[i].shrink_to_fit();
    }
    sBoxes.clear();
    sBoxes.shrink_to_fit();
}

S_fonction::S_fonction(const S_fonction &s_fonction) {
    for (int i=0;i<s_fonction.sBoxes.size();i++)
    {
        std::vector<std::vector<int>> vectorI;
        for (int j=0;j<s_fonction.sBoxes[i].size();j++)
        {
            std::vector<int> vectorJ;
            for (int k=0;k<s_fonction.sBoxes[i][j].size();k++)
            {
                vectorJ.push_back(s_fonction.sBoxes[i][j][k]);
            }
            vectorI.push_back(vectorJ);
        }
        this->sBoxes.push_back(vectorI);
    }
}

S_fonction &S_fonction::operator=(const S_fonction &s_fonction) {
    for (int i=0;i<s_fonction.sBoxes.size();i++)
    {
        std::vector<std::vector<int>> vectorI;
        for (int j=0;j<s_fonction.sBoxes[i].size();j++)
        {
            std::vector<int> vectorJ;
            for (int k=0;k<s_fonction.sBoxes[i][j].size();k++)
            {
                vectorJ.push_back(s_fonction.sBoxes[i][j][k]);
            }
            vectorI.push_back(vectorJ);
        }
        this->sBoxes.push_back(vectorI);
    }
    return *this;
}

Sequence S_fonction::operator()(Sequence sequence) {
    Sequence sequenceSortie = Sequence(32);
    for (int i=0;i<8;i++)
    {
        Sbox sbox = Sbox(this->sBoxes[i]);
        Sequence subSequenceEntree = sequence.sous_sequence(i*6,i*6+5);
        Sequence subSequenceSortie = sbox(subSequenceEntree);
        //std::cout <<subSequenceSortie.size();
        for (int j=i*4;j<i*4+4;j++)
        {
            //std::cout <<subSequenceSortie.size();
            //std::cout<<j-i*4;
            //std::cout<<j;
            //std::cout<<std::endl;
            sequenceSortie[j] = subSequenceSortie[j-i*4];
        }
    }
    return sequenceSortie;
}
