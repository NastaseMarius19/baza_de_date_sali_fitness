//
// Created by orange on 12/18/2021.
//

#ifndef MAIN_CPP_APLICATIE_H
#define MAIN_CPP_APLICATIE_H


#include <vector>
#include <ostream>
#include <memory>
#include "gym.h"
#include "client.h"
#include "dieta_standard.h"

class aplicatie{
    std::vector<gym> gyms;
    std::vector<client> clienti;
    std::vector<abonament> abonamente;
    std::string nume;
    std::string fondator;
    std::vector<std::pair<std::string, int >> cupoane;
    std::vector<std::shared_ptr<dieta_standard>> diete;

private:
    aplicatie(std::vector<gym> gyms, std::vector<client> clienti,
              std::vector<abonament> abonamente, std::string nume, std::string fondator,
              std::vector<std::pair<std::string, int>> cupoane);

    explicit aplicatie(std::vector<std::shared_ptr<dieta_standard>> diete);

    static aplicatie* app;


public:
    aplicatie(const aplicatie&) = delete;
    aplicatie& operator=(const aplicatie&) = delete;
    static aplicatie* get_app(){
        if(app == nullptr) { app = new aplicatie{{},{},{},"Work smart","Nastase Marius",{}};}
        return app;
    }

    void adauga_dieta(const dieta_standard& dietaStandard);

    void adauga_cupon(const std::string& nume_cupon, int procent_reducere_cupon);

    void adauga_client(const class client &client);

    const std::vector<std::shared_ptr<dieta_standard>> &getDiete() const;

    void adauga_gym(const class gym &gym);

    void aduaga_abonament(class abonament &abonament);

    friend std::ostream &operator<<(std::ostream &os, const aplicatie &aplicatie);

    void scbimba_abonament_client(const std::string& abonament_nou,const std::string& nume_client);

    const std::string &getNume() const;

    const std::string &getFondator() const;

    bool verifica_pret_abonament(const class client client);

    void reducere(class client &client, const std::string& nume_cupon); //cuponul este de fapt o reducere pentru diferite cazuri(student,elev,etc)
                                                                         //pentru un client se poate facem maxim o reducere, cu ajutorul functiei anterioare
                                                                         // care verifica daca pretul abonamentului unui client este egal sau mai mic cu pretul standard de la respectivul abonament

    ~aplicatie();
};

#endif //MAIN_CPP_APLICATIE_H
