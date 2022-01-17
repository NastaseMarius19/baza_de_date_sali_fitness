//
// Created by orange on 12/18/2021.
//

#include "client.h"

using namespace digestpp;
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
void client<T>::set_parola () {
    for(int i = 0; i < 3; i++) {
        std::string parola;
        std::string parola_verificare;
        std::cout << "Introduceti parola: ";
        std::cin >> parola;
        std::cout << "Introduceti din nou parola:";
        std::cin >> parola_verificare;
        if(parola == parola_verificare)
        {
            this->parola = blake2b(256).absorb(parola).hexdigest();
            std::cout << "Parola setata!\n";
            break;
        }

        else
            std::cout << "Parola noua nu este aceeasi in ambele campuri, incercati din nou(mai aveti "<<3-i<<" incercari)!\n"; }
}

template <typename T>
client<T>::client(std::string userName, int varsta, const class abonament &abonament, float nrKilograme)
        : userName(std::move(userName)), varsta(varsta), abonament(abonament), nr_kilograme(nrKilograme) {}

template <typename T>
float client<T>::getNrKilograme() const {
    return nr_kilograme;
}

template<typename T>
void client<T>::schimba_parola() {
    for(int i = 0; i < 3; i++) {
        std::string parola_noua;
        std::string parola_noua_verificare;
        std::cout << "Introduceti parola noua:";
        std::cin >> parola_noua;
        std::cout << "Introduceti din nou parola noua:";
        std::cin >> parola_noua_verificare;
        if(blake2b(256).absorb(parola_noua).hexdigest() == blake2b(256).absorb(parola_noua_verificare).hexdigest())
        {
            parola = blake2b(256).absorb(parola_noua).hexdigest();
            std::cout << "Parola noua setata!\n";
            break;
        }

        else
            std::cout << "Parola noua nu este aceeasi in ambele campuri, incercati din nou(mai aveti "<<3-i<<" incercari)!\n"; }
}

template class client<std::string>;