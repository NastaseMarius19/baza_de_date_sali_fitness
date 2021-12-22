//
// Created by orange on 12/20/2021.
//

#include "dieta_surplus_caloric.h"

void dieta_surplus_caloric::calc_necesar_caloric() {
    switch(getTipSomatic()){
        case tip_somatic::ECTOMORF:
            setNecesarCaloric(3500);
            break;
        case tip_somatic::ENDOMORF:
            setNecesarCaloric(3000);
            break;
        case tip_somatic::MEZOMORF:
            setNecesarCaloric(3200);
            break;
    }
}



dieta_surplus_caloric::~dieta_surplus_caloric() {
    std::cout << "destructor surplus caloric\n";
}

dieta_surplus_caloric::dieta_surplus_caloric(int necesarCaloric, tip_somatic tipSomatic, const std::string &tipDieta)
        : dieta_deficit_caloric(necesarCaloric, tipSomatic, tipDieta) {}
