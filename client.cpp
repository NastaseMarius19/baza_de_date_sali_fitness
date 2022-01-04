//
// Created by orange on 12/18/2021.
//

#include "client.h"

template <typename T>
std::ostream &operator<<(std::ostream &os, const client<T> &client) {
    os << "name: " << client.userName << " varsta: " << client.varsta << " gen: " << client.parola << "\nabonament: " << client.abonament << "\nnumar kilograme: " << client.nr_kilograme ;
    return os;
}

template <typename T>
const std::string &client<T>::getName() const {
    return userName;
}

template <typename T>
class abonament &client<T>::getAbonament() {
    return abonament;
}

template <typename T>
void client<T>::schimba_abonament(class abonament &abonament_nou){
    abonament = abonament_nou;
}

template <typename T>
void client<T>::schimba_parola() {
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
template <typename T>
client<T>::client(std::string userName, int varsta,T parola, const class abonament &abonament, float nrKilograme)
        : userName(std::move(userName)), varsta(varsta), parola(parola), abonament(abonament), nr_kilograme(nrKilograme) {}

template <typename T>
float client<T>::getNrKilograme() const {
    return nr_kilograme;
}

template class client<unsigned int>;