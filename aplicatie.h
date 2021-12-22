//
// Created by orange on 12/18/2021.
//

#ifndef MAIN_CPP_APLICATIE_H
#define MAIN_CPP_APLICATIE_H


#include <vector>
#include <ostream>
#include "gym.h"
#include "client.h"

class aplicatie{
    std::vector<gym> gyms;
    std::vector<client> clienti;
    std::vector<abonament> abonamente;
    std::string nume;
    std::string fondator;
    std::vector<std::pair<std::string, int >> cupoane;


public:
    aplicatie(std::vector<gym> gyms, std::vector<client> clienti,
              std::vector<abonament> abonamente, std::string nume, std::string fondator,
              std::vector<std::pair<std::string, int>> cupoane);

    void adauga_cupon(const std::string& nume_cupon, int procent_reducere_cupon);

    void adauga_client(const class client &client);

    void adauga_gym(const class gym &gym);

    void aduaga_abonament(class abonament &abonament);

    friend std::ostream &operator<<(std::ostream &os, const aplicatie &aplicatie);

    void scbimba_abonament_client(const std::string& abonament_nou,const std::string& nume_client);

    const std::string &getNume() const;

    const std::string &getFondator() const;

    bool verifica_pret_abonament(class client client);

    void reducere(class client &client, const std::string& nume_cupon);

    ~aplicatie();
};

#endif //MAIN_CPP_APLICATIE_H
