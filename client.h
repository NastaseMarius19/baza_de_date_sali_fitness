//
// Created by orange on 12/18/2021.
//

#ifndef MAIN_CPP_CLIENT_H
#define MAIN_CPP_CLIENT_H


#include <string>
#include "abonament.h"
#include <iostream>
#include "password_encryption/digestpp-master/digestpp.hpp"

template <typename T>
class client{
    std::string userName;
    int varsta;
    T parola;
    class abonament abonament;
    float nr_kilograme;


public:

    client(std::string userName, int varsta, const class abonament &abonament, float nrKilograme);

    friend std::ostream &operator<<(std::ostream &os, const client<unsigned int>& client);

    const std::string &getName() const;

    class abonament &getAbonament();

    float getNrKilograme() const;

    void schimba_abonament(class abonament &abonament_nou);

    void schimba_parola();

    void set_parola();

};


#endif //MAIN_CPP_CLIENT_H
