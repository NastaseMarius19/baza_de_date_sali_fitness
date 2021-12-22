//
// Created by orange on 12/22/2021.
//

#include "dieta_mentinere.h"

dieta_mentinere::dieta_mentinere(int necesarCaloric, tip_somatic tipSomatic, const std::string &tipDieta)
        : dieta_deficit_caloric(necesarCaloric, tipSomatic, tipDieta) {}

void dieta_mentinere::calc_necesar_caloric() {
    switch(getTipSomatic()){
        case tip_somatic::ECTOMORF:
            setNecesarCaloric(2000);
            break;
        case tip_somatic::ENDOMORF:
            setNecesarCaloric(2400);
            break;
        case tip_somatic::MEZOMORF:
            setNecesarCaloric(2200);
            break;
    }
}

dieta_mentinere::~dieta_mentinere() {
    std::cout << "destr dieta mentinere \n";
}
