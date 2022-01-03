//
// Created by orange on 12/22/2021.
//

#include "dieta_mentinere.h"
#include "client.h"

void dieta_mentinere::calc_necesar_caloric() {
    switch(getTipSomatic()){
        case tip_somatic::ECTOMORF:
            necesar_caloric = 2000;
            break;
        case tip_somatic::ENDOMORF:
            necesar_caloric = 2400;
            break;
        case tip_somatic::MEZOMORF:
            necesar_caloric = 2200;
            break;
    }
}

dieta_mentinere::~dieta_mentinere() {
    std::cout << "destr dieta mentinere \n";
}

float dieta_mentinere::calc_necesar_proteic(class client& client) {
    necesar_proteic = static_cast<float >(0.8 * client.getNrKilograme());
    return necesar_proteic;
}

dieta_mentinere::dieta_mentinere(tip_somatic tipSomatic, int necesarCaloric,
                                 const std::string &tipDieta, float necesarProteic) : dieta_standard(tipSomatic,
                                                                                                     necesarCaloric,
                                                                                                     tipDieta,
                                                                                                     necesarProteic) {}

std::shared_ptr<dieta_standard> dieta_mentinere::clone() const {
    try {
        return std::make_shared<dieta_mentinere>(*this);
    }catch (std::bad_alloc const&){
        std::cout << "Allocation failure - dieta mentinere clone";
        exit(EXIT_FAILURE);
    }
}
