//
// Created by orange on 12/18/2021.
//

#include <memory>
#include "abonament.h"
#include "erori_abonament.h"

int abonament::nr_abonamente = 1;
abonament::abonament(float pret, std::string nume, std::vector<std::string> bonusuri) : pret(pret), nume(std::move(nume)),
                                                                                        bonusuri(std::move(bonusuri)) {
    nr_abonamente++;
    if(pret < 80)
        throw eroare_pret_abonament();
    if(bonusuri.size() == 1)
        throw eroare_bonusuri_abonament();
}

std::ostream &operator<<(std::ostream &os, const abonament &abonament) {
    os << "pret: " << abonament.pret << "\nnume: " << abonament.nume << "\nbonusuri:\n ";
    for(const auto & bonus : abonament.bonusuri)
        os<<bonus<<"\n";
    return os;
}

abonament &abonament::operator=(const abonament &copie) {
    if(this != &copie){
      this->nume = copie.nume;
      this->pret = copie.pret;
      for(const auto &bonus : copie.bonusuri)
      this->bonusuri.push_back(bonus);
    }
      return *this;
}

abonament::abonament(const abonament &copie) {
    this->pret = copie.pret;
    this->nume = copie.nume;
    for(const auto &bonus : copie.bonusuri)
        this->bonusuri.push_back(bonus);
}

const std::string &abonament::getNume() const {
    return nume;
}

float abonament::getPret() const {
    return pret;
}

void abonament::setPret(float pret_) {
    abonament::pret = pret_;
}

void abonament::verifica_abonament() {
    if(pret < 80)
        throw eroare_pret_abonament();
    if(bonusuri.size() == 1)
        throw eroare_bonusuri_abonament();
}

