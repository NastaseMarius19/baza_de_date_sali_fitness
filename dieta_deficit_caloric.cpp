//
// Created by orange on 12/20/2021.
//

#include "dieta_deficit_caloric.h"


void dieta_deficit_caloric::afis() {
    std::cout << "Necesarul caloric este: " << getNecesarCaloric() << std::endl;
    switch(getTipSomatic()){
        case tip_somatic::ECTOMORF:
            std::cout << "Tipul somatic este: ECTOMORF" << std::endl;
            break;
        case tip_somatic::ENDOMORF:
            std::cout << "Tipul somatic este: ENDOMORF" << std::endl;
            break;
        case tip_somatic::MEZOMORF:
            std::cout << "Tipul somatic este: MEZOMORF" << std::endl;
            break;
    }
    std::cout << "Tip dieta : " <<  tip_dieta << std::endl;
}

dieta_deficit_caloric::dieta_deficit_caloric(int necesarCaloric, tip_somatic tipSomatic, std::string tipDieta)
        : dieta_standard(necesarCaloric, tipSomatic), tip_dieta(std::move(tipDieta)) {}

void dieta_deficit_caloric::calc_necesar_caloric() {
    switch(getTipSomatic()){
        case tip_somatic::ECTOMORF:
            setNecesarCaloric(1900);
            break;
        case tip_somatic::ENDOMORF:
            setNecesarCaloric(1500);
            break;
        case tip_somatic::MEZOMORF:
            setNecesarCaloric(1700);
            break;
    }
}


dieta_deficit_caloric::~dieta_deficit_caloric() {
    std::cout << "destr dieta deficit caloric\n";
}

