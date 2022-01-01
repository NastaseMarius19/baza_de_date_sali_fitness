//
// Created by orange on 12/20/2021.
//

#include "dieta_deficit_caloric.h"
#include "client.h"


void dieta_deficit_caloric::calc_necesar_caloric() {
    switch(getTipSomatic()){
        case tip_somatic::ECTOMORF:
            necesar_caloric = 1900;
            break;
        case tip_somatic::ENDOMORF:
            necesar_caloric = 1500;
            break;
        case tip_somatic::MEZOMORF:
            necesar_caloric = 1700;
            break;
    }
}


dieta_deficit_caloric::~dieta_deficit_caloric() {
    std::cout << "destr dieta deficit caloric\n";
}

float dieta_deficit_caloric::calc_necesar_proteic(class client& client) {
    necesar_proteic = static_cast<float >(0.8 * client.getNrKilograme());
    return necesar_proteic;
}

dieta_deficit_caloric::dieta_deficit_caloric(tip_somatic tipSomatic, int necesarCaloric,
                                             const std::string &tipDieta, float necesarProteic) : dieta_standard(
        tipSomatic, necesarCaloric, tipDieta, necesarProteic) {}

std::shared_ptr<dieta_standard> dieta_deficit_caloric::clone() const {
    return std::make_shared<dieta_deficit_caloric>(*this);
}

