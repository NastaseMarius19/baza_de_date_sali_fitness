//
// Created by orange on 12/20/2021.
//

#ifndef MAIN_CPP_DIETA_STANDARD_H
#define MAIN_CPP_DIETA_STANDARD_H


#include <iostream>
#include <memory>
#include "client.h"

enum tip_somatic{
    ENDOMORF, MEZOMORF, ECTOMORF
}; // in functie de tipul somatic se va calcula necesarul caloric pentru diferite categorii de persoane

class dieta_standard {
    tip_somatic tipSomatic;

protected:
    int necesar_caloric = 0;
    std::string tip_dieta;
    float necesar_proteic = 0;

public:

    tip_somatic getTipSomatic() const;

    void afis();

    dieta_standard(tip_somatic tipSomatic, int necesarCaloric, std::string tipDieta,
                   float necesarProteic);

    virtual float calc_necesar_proteic(class client<unsigned int>& client)  = 0;

    virtual std::shared_ptr<dieta_standard> clone() const = 0;

    virtual ~dieta_standard()  = 0;
};


#endif //MAIN_CPP_DIETA_STANDARD_H
