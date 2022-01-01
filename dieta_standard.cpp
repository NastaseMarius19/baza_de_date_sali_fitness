//
// Created by orange on 12/20/2021.
//

#include "dieta_standard.h"
#include "client.h"

tip_somatic dieta_standard::getTipSomatic() const {
    return tipSomatic;
}


dieta_standard::dieta_standard(tip_somatic tipSomatic, int necesarCaloric, std::string tipDieta,
                               float necesarProteic) : tipSomatic(tipSomatic),
                                                       necesar_caloric(necesarCaloric), tip_dieta(std::move(tipDieta)),
                                                       necesar_proteic(necesarProteic) {}

float dieta_standard::calc_necesar_proteic(class client& client) {
    necesar_proteic = static_cast<float> (0.8 * client.getNrKilograme());
    return necesar_proteic;
}

void dieta_standard::afis() {
    std::cout << "Necesarul caloric este: " << necesar_caloric << std::endl;
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

dieta_standard::~dieta_standard() {std::cout << "destr dieta_standard\n";}

std::shared_ptr<dieta_standard> dieta_standard::clone() const {
    return std::make_shared<dieta_standard>(*this);
}
