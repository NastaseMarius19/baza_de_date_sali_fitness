//
// Created by orange on 12/20/2021.
//

#include "dieta_surplus_caloric.h"

void dieta_surplus_caloric::calc_necesar_caloric() {
    switch(getTipSomatic()){
        case tip_somatic::ECTOMORF:
            necesar_caloric = 3500;
            break;
        case tip_somatic::ENDOMORF:
            necesar_caloric = 3000;
            break;
        case tip_somatic::MEZOMORF:
            necesar_caloric = 3200;
            break;
    }
}



dieta_surplus_caloric::~dieta_surplus_caloric() {
    std::cout << "destructor surplus caloric\n";
}


float dieta_surplus_caloric::calc_necesar_proteic(class client<unsigned int>& client) {
    necesar_proteic = static_cast<float >(0.8 * client.getNrKilograme());
    return necesar_proteic;
}

dieta_surplus_caloric::dieta_surplus_caloric(tip_somatic tipSomatic, int necesarCaloric,
                                             const std::string &tipDieta, float necesarProteic) : dieta_standard(
        tipSomatic, necesarCaloric, tipDieta, necesarProteic) {}

std::shared_ptr<dieta_standard> dieta_surplus_caloric::clone() const {
    try {
        return std::make_shared<dieta_surplus_caloric>(*this);
    }catch (std::bad_alloc const&){
        std::cout << "Allocation failure - dieta surplus caloric clone";
        exit(EXIT_FAILURE);
    }
}

