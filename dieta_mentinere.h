//
// Created by orange on 12/22/2021.
//

#ifndef MAIN_CPP_DIETA_MENTINERE_H
#define MAIN_CPP_DIETA_MENTINERE_H


#include "dieta_deficit_caloric.h"

class dieta_mentinere final : public dieta_deficit_caloric{
public:
    dieta_mentinere(int necesarCaloric, tip_somatic tipSomatic, const std::string &tipDieta);

    void calc_necesar_caloric() final;

    ~dieta_mentinere() final;
};


#endif //MAIN_CPP_DIETA_MENTINERE_H
