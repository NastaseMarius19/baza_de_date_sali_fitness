//
// Created by orange on 12/18/2021.
//

#include "client.h"


std::ostream &operator<<(std::ostream &os, const client &client) {
    os << "name: " << client.userName << " varsta: " << client.varsta << " gen: " << client.parola << "\nabonament: " << client.abonament << "\nnumar kilograme: " << client.nr_kilograme ;
    return os;
}

const std::string &client::getName() const {
    return userName;
}

class abonament &client::getAbonament() {
    return abonament;
}

void client::schimba_abonament(class abonament &abonament_nou){
    abonament = abonament_nou;
}

void client::schimba_parola() {
    for(int i = 0; i < 3; i++) {
        std::string parola_noua;
        std::string parola_noua_verificare;
        std::cout << "Introduceti parola noua:";
        std::cin >> parola_noua;
        std::cout << "Introduceti din nou parola noua:";
        std::cin >> parola_noua_verificare;
        if(parola_noua == parola_noua_verificare)
        {
            parola = HashPassword(parola_noua);
            std::cout << "Parola noua setata!\n";
            break;
        }

        else
            std::cout << "Parola noua nu este aceeasi in ambele campuri, incercati din nou(mai aveti "<<3-i<<" incercari)!\n"; }
}

client::client(std::string userName, int varsta,unsigned int parola, const class abonament &abonament, float nrKilograme)
        : userName(std::move(userName)), varsta(varsta), parola(parola), abonament(abonament), nr_kilograme(nrKilograme) {}

float client::getNrKilograme() const {
    return nr_kilograme;
}
