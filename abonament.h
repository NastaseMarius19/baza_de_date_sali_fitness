//
// Created by orange on 12/18/2021.
//

#ifndef MAIN_CPP_ABONAMENT_H
#define MAIN_CPP_ABONAMENT_H


#include <string>
#include <vector>
#include <iostream>

class abonament{
    float pret;
    std::string nume;
    std::vector<std::string> bonusuri;
public:
    abonament(float pret, std::string nume, std::vector<std::string> bonusuri);

    friend std::ostream &operator<<(std::ostream &os, const abonament &abonament);

    abonament& operator=(const abonament &copie);

    abonament(const abonament &copie);

    const std::string &getNume() const;

    float getPret() const;

    void setPret(float pret);

};


#endif //MAIN_CPP_ABONAMENT_H
