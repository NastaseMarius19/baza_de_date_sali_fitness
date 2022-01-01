//
// Created by orange on 12/18/2021.
//

#ifndef MAIN_CPP_CLIENT_H
#define MAIN_CPP_CLIENT_H


#include <string>
#include "abonament.h"
#include <iostream>
#include "HashPassword.h"

class client{
    std::string userName;
    int varsta;
    unsigned int parola;
    class abonament abonament;
    float nr_kilograme;


public:

    client(std::string userName, int varsta,unsigned int parola, const class abonament &abonament, float nrKilograme);

    friend std::ostream &operator<<(std::ostream &os, const client &client);

    const std::string &getName() const;

    class abonament &getAbonament();

    float getNrKilograme() const;

    void schimba_abonament(class abonament &abonament_nou);

    void schimba_parola();

    friend unsigned int HashPassword(std::string const &Combine);

};


#endif //MAIN_CPP_CLIENT_H
