#include <iostream>
#include <string>
#include "gym.h"
#include "abonament.h"
#include "aplicatie.h"
#include "dieta_deficit_caloric.h"
#include "dieta_surplus_caloric.h"
#include "dieta_mentinere.h"

using namespace std::string_literals;


int main () {
    gym worldclass{"WordlClass"s, "Str.Soarelui Nr.25"s,
                   {{"Luni", "8:00-22:00"}, {"Marti", "8:00-22:00"}, {"Miercuri", "8:00-22:00"}, {"Joi", "8:00-22:00"},
                    {"Vineri", "8:00-22:00"}, {"Sambata", "10:00-16:00"}, {"Duminica", "INCHIS"}}};
    gym energymhealth_hub{"energymhealth_hub"s, "Str.Mircea Bravo Nr.33"s,
                          {{"Luni", "8:00-22:00"}, {"Marti", "8:00-22:00"}, {"Miercuri", "8:00-22:00"},
                           {"Joi", "8:00-22:00"}, {"Vineri", "8:00-22:00"}, {"Sambata", "10:00-16:00"},
                           {"Duminica", "INCHIS"}}};
    gym anturaj_gym{"Anturaj_Gym"s, "Str.Principala Bloc 8 Sc.A Et.4"s,
                    {{"Luni", "8:00-22:00"}, {"Marti", "8:00-22:00"}, {"Miercuri", "8:00-22:00"}, {"Joi", "8:00-22:00"},
                     {"Vineri", "8:00-22:00"}, {"Sambata", "INCHIS"}, {"Duminica", "INCHIS"}}};
    abonament incepator(140, "Incepator", {"Antrenamente online", "8 sedinte pe luna"s});
    abonament avansat(200, "Avansat", {"Antrenamente online"s, "O intrare pe zi la orice sala partenera"s,
                                       "4 sedinte cu antrenor personal"s});
    abonament VIP(300, "VIP",
                  {"Antrenamente online"s, "Intrare libera la orice sala partenera"s, "8 sedinte cu antrenor personal"s,
                   "diete personalizate"s});
    client marius{"marius"s, 21, HashPassword("marius"), incepator, 55};
    client viorel{"viorel"s, 19, HashPassword("mamaliga"), incepator, 50};
    aplicatie AppGym{{worldclass},{marius},{incepator},"Work Smart","Nastase Marius",{{"student",10}}};
    AppGym.scbimba_abonament_client("VIP","marius"s);
    AppGym.adauga_client(viorel);
    AppGym.adauga_gym(energymhealth_hub);
    AppGym.adauga_gym(anturaj_gym);
    AppGym.aduaga_abonament(avansat);
    AppGym.aduaga_abonament(VIP);
    AppGym.adauga_cupon("elev",15);
    AppGym.adauga_cupon("happy hour",10);
    std::cout<<AppGym.getNume()<<"\n";
    std::cout<<"Fondatorul aplicatiei este: "<<AppGym.getFondator()<<"\n";
    std::cout<<AppGym;
    marius.schimba_parola();
    marius.schimba_abonament(VIP);
    AppGym.reducere(marius,"student");
    AppGym.reducere(marius,"student");
    AppGym.reducere(marius,"tataie");
    std::cout << marius.getAbonament();

    dieta_standard dieta1{ENDOMORF,0,"standard client - marius"s,0};
    dieta_deficit_caloric dieta2{ECTOMORF,0,"deficit _caloric -viorel"s,0};
    dieta2.calc_necesar_caloric();
    dieta_surplus_caloric dieta3{ECTOMORF,0,"surplus caloric - marius"s,0};
    dieta3.calc_necesar_caloric();
    dieta_mentinere dieta4{MEZOMORF,0,"mentinere - marius"s,0};
    dieta4.calc_necesar_caloric();

    AppGym.adauga_dieta(dieta2);
    AppGym.adauga_dieta(dieta3);
    AppGym.adauga_dieta(dieta4);
    AppGym.getDiete()[0]->calc_necesar_proteic(viorel);
    AppGym.getDiete()[1]->calc_necesar_proteic(marius);
    AppGym.getDiete()[2]->calc_necesar_proteic(marius);

    std::cout<<AppGym;
}
