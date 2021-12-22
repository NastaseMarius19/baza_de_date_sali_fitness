#include <iostream>
#include <string>
#include "gym.h"
#include "abonament.h"
#include "client.h"
#include "aplicatie.h"
#include "dieta_standard.h"
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
    client marius{"marius"s,21,marius.HashPassword("123456"),incepator,55};
    client viorel{"viorel"s,19,viorel.HashPassword("mamaliga"),incepator,50};
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

    dieta_standard dieta1{2000,ENDOMORF};
    dieta_deficit_caloric dieta2{0,ECTOMORF,"deficit caloric"};
    dieta2.calc_necesar_caloric();
    std::cout<<std::endl;
    dieta2.afis();
    dieta_surplus_caloric dieta3{0,ECTOMORF,"surplus caloric"s};
    dieta3.calc_necesar_caloric();
    std::cout<<std::endl;
    dieta3.afis();
    std::cout<<std::endl;
    dieta_mentinere dieta4{0,MEZOMORF,"dieta mentinere"};
    dieta4.calc_necesar_caloric();
    dieta4.afis();
    std::cout<<std::endl;
}
