//
// Created by orange on 12/20/2021.
//

#ifndef MAIN_CPP_DIETA_DEFICIT_CALORIC_H
#define MAIN_CPP_DIETA_DEFICIT_CALORIC_H


#include "dieta_standard.h"
#include <iostream>
#include <vector>

class dieta_deficit_caloric : public dieta_standard {

public:

    dieta_deficit_caloric(tip_somatic tipSomatic, int necesarCaloric, const std::string &tipDieta,
                          float necesarProteic);

    void calc_necesar_caloric();

    float calc_necesar_proteic(class client<std::string>& client) override;

    std::shared_ptr<dieta_standard> clone() const override;

    ~dieta_deficit_caloric() override;

};


#endif //MAIN_CPP_DIETA_DEFICIT_CALORIC_H
