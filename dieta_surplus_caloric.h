//
// Created by orange on 12/20/2021.
//

#ifndef MAIN_CPP_DIETA_SURPLUS_CALORIC_H
#define MAIN_CPP_DIETA_SURPLUS_CALORIC_H


#include "dieta_standard.h"
#include "dieta_deficit_caloric.h"

class dieta_surplus_caloric : public dieta_deficit_caloric{
public:
    dieta_surplus_caloric(int necesarCaloric, tip_somatic tipSomatic, const std::string &tipDieta);

    void calc_necesar_caloric() ;

    ~dieta_surplus_caloric() ;
};


#endif //MAIN_CPP_DIETA_SURPLUS_CALORIC_H
