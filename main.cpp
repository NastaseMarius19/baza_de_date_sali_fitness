#include <iostream>
#include <string>
#include "gym.h"
#include "abonament.h"
#include "aplicatie.h"
#include "dieta_deficit_caloric.h"
#include "dieta_surplus_caloric.h"
#include "dieta_mentinere.h"
#include "erori_abonament.h"
using namespace std::string_literals;


int main () {

    try{
        abonament special(30,"special"s,{"4 sedinte cu antrenor"s,"10% reducere luna urmatoare"s});
    }catch (eroare_abonament& error)
    {
        std::cout << error.what() << "\n";
    }

    std::cout << "\n";
    gym_builder gym_build;
    gym worldclass = gym_build.name("WordlClass"s).location("Str.Soarelui Nr.25"s).program({{"Luni", "8:00-22:00"}, {"Marti", "8:00-22:00"}, {"Miercuri", "8:00-22:00"}, {"Joi", "8:00-22:00"},
                      {"Vineri", "8:00-22:00"}, {"Sambata", "10:00-16:00"}, {"Duminica", "INCHIS"}}).build();
    gym energymhealth_hub = gym_build.name("energymhealth_hub"s).location("Str.Mircea Bravo Nr.33"s).program({{"Luni", "8:00-22:00"}, {"Marti", "8:00-22:00"}, {"Miercuri", "8:00-22:00"},
                           {"Joi", "8:00-22:00"}, {"Vineri", "8:00-22:00"}, {"Sambata", "10:00-16:00"},
                          {"Duminica", "INCHIS"}}).build();
    gym anturaj_gym = gym_build.name("Anturaj_Gym"s).location("Str.Principala Bloc 8 Sc.A Et.4"s).program({{"Luni", "8:00-22:00"}, {"Marti", "8:00-22:00"}, {"Miercuri", "8:00-22:00"}, {"Joi", "8:00-22:00"},
                     {"Vineri", "8:00-22:00"}, {"Sambata", "INCHIS"}, {"Duminica", "INCHIS"}}).build();
    abonament incepator(140, "Incepator", {"Antrenamente online", "8 sedinte pe luna"s});
    abonament avansat(200, "Avansat", {"Antrenamente online"s, "O intrare pe zi la orice sala partenera"s,
                                       "4 sedinte cu antrenor personal"s});
    abonament VIP(300, "VIP",
                  {"Antrenamente online"s, "Intrare libera la orice sala partenera"s, "8 sedinte cu antrenor personal"s,
                   "diete personalizate"s});
    client marius{"marius"s, 21, HashPassword("marius"), incepator, 55};
    client viorel{"viorel"s, 19, HashPassword("mamaliga"), incepator, 50};

    auto AppGym = aplicatie::get_app();
    AppGym->aduaga_abonament(incepator);
    AppGym->aduaga_abonament(avansat);
    AppGym->aduaga_abonament(VIP);
    AppGym->adauga_client(marius);
    AppGym->adauga_client(viorel);
    AppGym->adauga_gym(worldclass);
    AppGym->adauga_gym(energymhealth_hub);
    AppGym->adauga_gym(anturaj_gym);
    AppGym->adauga_cupon("elev",15);
    AppGym->adauga_cupon("happy hour",10);


    AppGym->scbimba_abonament_client("Incepator","marius"s);

    std::cout<<AppGym->getNume()<<"\n";

    std::cout<<"Fondatorul aplicatiei este: "<<AppGym->getFondator()<<"\n";
    std::cout << *AppGym;
    marius.schimba_parola();
    marius.schimba_abonament(VIP);
    AppGym->reducere(marius,"student");
    AppGym->reducere(marius,"student");
    AppGym->reducere(marius,"tataie");
    std::cout << marius.getAbonament();

    dieta_deficit_caloric dieta2{ECTOMORF,0,"deficit _caloric -viorel"s,0};
    dieta2.calc_necesar_caloric();
    dieta_surplus_caloric dieta3{ECTOMORF,0,"surplus caloric - marius"s,0};
    dieta3.calc_necesar_caloric();
    dieta_mentinere dieta4{MEZOMORF,0,"mentinere - marius"s,0};
    dieta4.calc_necesar_caloric();

    AppGym->adauga_dieta(dieta2);
    AppGym->adauga_dieta(dieta3);
    AppGym->adauga_dieta(dieta4);
    AppGym->getDiete()[0]->calc_necesar_proteic(viorel);
    AppGym->getDiete()[1]->calc_necesar_proteic(marius);
    AppGym->getDiete()[2]->calc_necesar_proteic(marius);

    std::cout << *AppGym;
}
