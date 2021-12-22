//
// Created by orange on 12/20/2021.
//

#ifndef MAIN_CPP_DIETA_STANDARD_H
#define MAIN_CPP_DIETA_STANDARD_H


#include <iostream>

enum tip_somatic{
    ENDOMORF, MEZOMORF, ECTOMORF
}; // in functie de tipul somatic se va calcula necesarul caloric pentru diferite categorii de persoane

class dieta_standard {
    int necesar_caloric = 0;
    tip_somatic tipSomatic;

public:

    void setNecesarCaloric(int necesarCaloric);

    tip_somatic getTipSomatic() const;

    int getNecesarCaloric() const;

    dieta_standard(int necesarCaloric, tip_somatic tipSomatic);

    virtual ~dieta_standard();
};


#endif //MAIN_CPP_DIETA_STANDARD_H
