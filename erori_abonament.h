//
// Created by orange on 1/1/2022.
//

#ifndef MAIN_CPP_ERORI_ABONAMENT_H
#define MAIN_CPP_ERORI_ABONAMENT_H


#include <stdexcept>

class eroare_abonament : public std::runtime_error{
public:
    eroare_abonament(const std::string &arg);
};

class eroare_pret_abonament : public eroare_abonament{
public:
    eroare_pret_abonament();
};

class eroare_bonusuri_abonament : public eroare_abonament{
public:
    eroare_bonusuri_abonament();
};

#endif //MAIN_CPP_ERORI_ABONAMENT_H
