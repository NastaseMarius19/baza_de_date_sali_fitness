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


int client::HashPassword(const std::string &Combine) {
    unsigned int hash = 0;

    const unsigned int VALUE = Combine.length();
    for (auto Letter : Combine)
    {
        srand(VALUE*Letter);
        hash += 33 + rand() % 92;
    }
    parola = hash;
    return hash;
}

client::client(const std::string &userName, int varsta, int parola, const class abonament &abonament, int nrKilograme)
        : userName(userName), varsta(varsta), parola(parola), abonament(abonament), nr_kilograme(nrKilograme) {}
