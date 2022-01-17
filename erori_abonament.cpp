//
// Created by orange on 1/1/2022.
//

#include "erori_abonament.h"

eroare_abonament::eroare_abonament(const std::string &arg) : runtime_error("Eroare abonament:" + arg) {}

eroare_pret_abonament::eroare_pret_abonament() : eroare_abonament("Pretul este prea mic") {}

eroare_bonusuri_abonament::eroare_bonusuri_abonament() : eroare_abonament("Un abonament trebuie sa aiba cel putin 2 bonusuri(ati adaugat doar 1 bonus)") {}