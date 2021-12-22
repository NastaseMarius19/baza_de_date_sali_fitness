//
// Created by orange on 12/20/2021.
//

#include "dieta_standard.h"

dieta_standard::dieta_standard( int necesarCaloric, tip_somatic tipSomatic) : necesar_caloric(necesarCaloric), tipSomatic(tipSomatic) {}

dieta_standard::~dieta_standard() {std::cout << "destr dieta_standard\n";}


tip_somatic dieta_standard::getTipSomatic() const {
    return tipSomatic;
}

int dieta_standard::getNecesarCaloric() const {
    return necesar_caloric;
}

void dieta_standard::setNecesarCaloric(int necesarCaloric) {
    necesar_caloric = necesarCaloric;
}


