//
// Created by orange on 12/20/2021.
//

#ifndef MAIN_CPP_DIETA_DEFICIT_CALORIC_H
#define MAIN_CPP_DIETA_DEFICIT_CALORIC_H


#include "dieta_standard.h"
#include <iostream>
#include <vector>

class dieta_deficit_caloric : public dieta_standard {
    std::string tip_dieta;
public:
    dieta_deficit_caloric(int necesarCaloric, tip_somatic tipSomatic, std::string tipDieta);

    virtual void calc_necesar_caloric();

    virtual void afis();

    ~dieta_deficit_caloric() ;

};


#endif //MAIN_CPP_DIETA_DEFICIT_CALORIC_H
