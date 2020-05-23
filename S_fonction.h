//
// Created by noure on 22/05/2020.
//

#ifndef PROJECT3DS_S_FONCTION_H
#define PROJECT3DS_S_FONCTION_H


#include <vector>
#include "Sequence.h"

class S_fonction {
    private:
        std::vector<std::vector<std::vector<int>>> sBoxes;

    public:
        S_fonction(std::vector<std::vector<std::vector<int>>> sBoxes);
        ~S_fonction();
        S_fonction(const S_fonction &s_fonction);

    S_fonction();

    S_fonction &operator=(const S_fonction &s_fonction);
        Sequence operator()(Sequence sequence);
};


#endif //PROJECT3DS_S_FONCTION_H
