#include <iostream>
#include <string>
#include "gym.h"
#include "abonament.h"
#include "client.h"
#include "aplicatie.h"

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
    client marius{"Marius"s, 21, "123456"s, incepator};
    aplicatie AppGym{{worldclass},{marius},{incepator},"Work Smart","Nastase Marius",{{"student",10}}};
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
}
