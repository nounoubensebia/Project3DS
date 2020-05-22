//
// Created by noure on 22/05/2020.
//

#include "Sbox.h"
#include "Utils.h"

Sbox::Sbox(std::vector<std::vector<Sequence>> sequences) {
    this->sequences = sequences;
}

Sbox::~Sbox() {
    for (int i=0;i<sequences.size();i++)
    {
        sequences.at(i).clear();
    }
    this->sequences.clear();
    this->sequences.shrink_to_fit();
}

Sbox::Sbox(const Sbox &sbox) {
    for (int i=0;i<sbox.sequences.size();i++)
    {
        for (int j=0;j<sbox.sequences[i].size();j++)
        {
            this->sequences[i][j] = sbox.sequences[i][j];
        }
    }
}

Sbox &Sbox::operator=(const Sbox &sbox) {
    for (int i=0;i<sbox.sequences.size();i++)
    {
        for (int j=0;j<sbox.sequences[i].size();j++)
        {
            this->sequences[i][j] = sbox.sequences[i][j];
        }
    }
    return *this;
}

Sequence Sbox::operator()(Sequence sequence_entree) {
    std::vector<bool> extremes;
    extremes.push_back(sequence_entree[0]);
    extremes.push_back(sequence_entree[5]);
    std::vector<bool> middles;
    middles.push_back(sequence_entree[1]);
    middles.push_back(sequence_entree[2]);
    middles.push_back(sequence_entree[3]);
    middles.push_back(sequence_entree[4]);
    int i = Utils::binToDec(extremes);
    int j = Utils::binToDec(middles);
    return sequences[i][j];
}
