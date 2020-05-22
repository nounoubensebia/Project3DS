//
// Created by noure on 22/05/2020.
//

#include "Utils.h"
#include "Sequence.h"

int Utils::binToDec(std::vector<bool> bits) {
    int s = 0;
    for (int i=0;i<bits.size();i++)
    {
        if (bits[i]!=0)
        {
            s+= pow(2,(bits.size()-i-1));
        }
    }
    return s;
}

std::vector<std::vector<Sequence>> Utils::getSboxes(int indice) {
    std::vector<std::vector<int>> intVector
            {
                    {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
                    {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
                    {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
                    {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}
            };
    std::vector<std::vector<Sequence>> vector;
    for (int i=0;i<intVector.size();i++)
    {
        std::vector<Sequence> sequences;
        for (int j=0;j<intVector[i].size();j++)
        {
            Sequence sequence = Sequence(4);
            sequence = intVector[i][j];
            sequences.push_back(sequence);
        }
        vector.push_back(sequences);
    }
    return vector;
}
