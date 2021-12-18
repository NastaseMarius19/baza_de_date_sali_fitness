//
// Created by orange on 12/18/2021.
//

#include "client.h"

client::client(std::string userName, int varsta, std::string parola, const class abonament &abonament) : userName(std::move(userName)),
                                                                                                   varsta(varsta),
                                                                                                   parola(std::move(parola)),
                                                                                                   abonament(
                                                                                                           abonament) {}

std::ostream &operator<<(std::ostream &os, const client &client) {
    os << "name: " << client.userName << " varsta: " << client.varsta << " gen: " << client.parola << "\nabonament: " << client.abonament;
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
            parola = parola_noua;
            std::cout << "Parola noua setata!\n";
            break;
        }

        else
            std::cout << "Parola noua nu este aceeasi in ambele campuri, incercati din nou(mai aveti "<<3-i<<" incercari)!\n"; }

}

const std::string &client::getParola() const {
    return parola;
}
