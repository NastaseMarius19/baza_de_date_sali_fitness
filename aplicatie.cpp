//
// Created by orange on 12/18/2021.
//

#include "aplicatie.h"

aplicatie::aplicatie(std::vector<gym> gyms, std::vector<client> clienti, std::vector<abonament> abonamente,
                     std::string nume, std::string fondator, std::vector<std::pair<std::string, int>> cupoane) : gyms(std::move(gyms)), clienti(std::move(clienti)),
                                                                                                                 abonamente(std::move(abonamente)), nume(std::move(nume)),
                                                                                                                 fondator(std::move(fondator)), cupoane(std::move(cupoane)) {}

void aplicatie::setCupoane(const std::vector<std::pair<std::string, int>> &cupoane) {
    aplicatie::cupoane = cupoane;
}

void aplicatie::adauga_cupon(const std::string &nume_cupon, int procent_reducere_cupon) {
    cupoane.emplace_back(nume_cupon, procent_reducere_cupon);
}

void aplicatie::adauga_client(const client &client) {
    clienti.push_back(client);
}

void aplicatie::adauga_gym(const gym &gym) {
    gyms.push_back(gym);
}

void aplicatie::aduaga_abonament(abonament &abonament) {
    abonamente.push_back(abonament);
}


std::ostream &operator<<(std::ostream &os, const aplicatie &aplicatie) {
    std::cout << "sali de sport partenere:\n";
    for(const auto &gym : aplicatie.gyms)
        std::cout << gym.getName() << "\n";
    std::cout << "\nclienti:\n";
    for(const auto &client : aplicatie.clienti)
        std::cout << client.getName() << "\n";
    std::cout << "\nabonamente dispinibile:\n";
    for(const auto &abonament : aplicatie.abonamente)
        std::cout << abonament.getNume() << "\n";
    return os;
}

void aplicatie::scbimba_abonament_client(const std::string &abonament_nou, const std::string &nume_client) {
    for(auto& client:clienti)
        if(client.getName() == nume_client) {
            for (auto &abonament : abonamente) {
                if (abonament.getNume() == abonament_nou)
                    client.schimba_abonament(abonament);
                break;
            }
        }
    std::cout << "Ati introdus un abonament invalid.";
}

void aplicatie::setNume(const std::string &nume) {
    aplicatie::nume = nume;
}

const std::string &aplicatie::getNume() const {
    return nume;
}

const std::string &aplicatie::getFondator() const {
    return fondator;
}

bool aplicatie::verifica_pret_abonament(struct client client) {
    for(auto & j : abonamente)
        if(client.getAbonament().getNume() == j.getNume() && client.getAbonament().getPret() < j.getPret())
            return true;
    return false;

}

void aplicatie::reducere(client &client, const std::string &nume_cupon) {

    for(int i = 0; i < cupoane.size(); i++)
        if(cupoane[i].first == nume_cupon)
        {
            if(verifica_pret_abonament(client))
            {
                std::cout << "Clientul dispune de o reducere! \n";
                break;
            }
            float pret_nou = client.getAbonament().getPret();
            pret_nou = pret_nou - (float)cupoane[i].second * pret_nou / 100;
            client.getAbonament().setPret(pret_nou);
            break;
        } else if (i == cupoane.size() - 1)
            std::cout << "Nu exista un astfel de cupon!\n";

}

aplicatie::~aplicatie() {
    std::cout << "\nDestructor";
}
