//
// Created by orange on 1/1/2022.
//

#include "HashPassword.h"

unsigned int HashPassword(std::string const &Combine) {
    unsigned int hash = 0;

    const unsigned int VALUE = Combine.length();
    for (auto Letter : Combine)
    {
        srand(VALUE*Letter);
        hash += 33 + rand() % 92;
    }
    return hash;
}
