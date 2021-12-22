//
// Created by orange on 12/18/2021.
//

#ifndef MAIN_CPP_CLIENT_H
#define MAIN_CPP_CLIENT_H


#include <string>
#include "abonament.h"
#include <iostream>

class client{
    std::string userName;
    int varsta;
    int parola;
    class abonament abonament;
    int nr_kilograme;

public:

    client(const std::string &userName, int varsta, int parola, const class abonament &abonament, int nrKilograme);

    int HashPassword(std::string const &Combine);

    friend std::ostream &operator<<(std::ostream &os, const client &client);

    const std::string &getName() const;

    class abonament &getAbonament();

    void schimba_abonament(class abonament &abonament_nou);

    void schimba_parola();


};


#endif //MAIN_CPP_CLIENT_H
