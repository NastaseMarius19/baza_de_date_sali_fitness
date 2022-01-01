//
// Created by orange on 12/22/2021.
//

#ifndef MAIN_CPP_DIETA_MENTINERE_H
#define MAIN_CPP_DIETA_MENTINERE_H


#include "dieta_standard.h"

class dieta_mentinere final : public dieta_standard{
public:
    dieta_mentinere(tip_somatic tipSomatic, int necesarCaloric, const std::string &tipDieta,
                    float necesarProteic);

    void calc_necesar_caloric() ;

    float calc_necesar_proteic(class client& client) override;

    std::shared_ptr<dieta_standard> clone() const override;

    ~dieta_mentinere() override;
};


#endif //MAIN_CPP_DIETA_MENTINERE_H
