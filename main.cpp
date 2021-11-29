#include <iostream>
#include <vector>
#include <string>

using namespace std::string_literals;


class gym
{
    std::string name;
    std::string location;
    std::vector<std::pair<std::string, std::string>> program;
public:
    gym(std::string name, std::string location,
        std::vector<std::pair<std::string, std::string>> program) : name(std::move(name)), location(std::move(location)),
                                                                             program(std::move(program)) {}

    friend std::ostream &operator<<(std::ostream &os, const gym &gym) {
        os << "name: " << gym.name << "\nlocation: " << gym.location << "\nprogram: ";
        for(auto const & day : gym.program) {
            os << day.first << " : " << day.second << "\n";
        }
        return os;
    }

    void adauga(std::vector<std::pair<std::string, std::string>> &days) {
        for(auto const & day : days)
            program.push_back(day);

    }

    const std::string &getName() const {
        return name;
    }

    const std::string &getLocation() const {
        return location;
    }

    const std::vector<std::pair<std::string, std::string>> &getProgram() const {
        return program;
    }

};

class abonament{
    float pret;
    std::string nume;
    std::vector<std::string> bonusuri;
public:
    abonament(float pret, std::string nume, std::vector<std::string> bonusuri) : pret(pret), nume(std::move(nume)),
                                                                                               bonusuri(std::move(bonusuri)) {}

    friend std::ostream &operator<<(std::ostream &os, const abonament &abonament) {
        os << "pret: " << abonament.pret << "\nnume: " << abonament.nume << "\nbonusuri:\n ";
        for(const auto & bonus : abonament.bonusuri)
            os<<bonus<<"\n";
        return os;
    }

    abonament& operator=(const abonament &copie) {
        this->nume = copie.nume;
        this->pret = copie.pret;
        for(const auto &bonus : copie.bonusuri)
            this->bonusuri.push_back(bonus);
        return *this;
    }

    abonament(const abonament &copie) {
        this->pret = copie.pret;
        this->nume = copie.nume;
        for(const auto &bonus : copie.bonusuri)
            this->bonusuri.push_back(bonus);
    }

    const std::string &getNume() const {
        return nume;
    }

    float getPret() const {
        return pret;
    }

    void setPret(float pret) {
        abonament::pret = pret;
    }

    void setNume(const std::string &nume) {
        abonament::nume = nume;
    }

    const std::vector<std::string> &getBonusuri() const {
        return bonusuri;
    }

    void setBonusuri(const std::vector<std::string> &bonusuri) {
        abonament::bonusuri = bonusuri;
    }
};

class client{
    std::string userName;
    int varsta;
    std::string parola;
    class abonament abonament;

public:
    client(std::string userName, int varsta, std::string parola, const class abonament &abonament) : userName(std::move(userName)),
                                                                                                      varsta(varsta),
                                                                                                      parola(std::move(parola)),
                                                                                                      abonament(
                                                                                                              abonament) {}

    friend std::ostream &operator<<(std::ostream &os, const client &client) {
        os << "name: " << client.userName << " varsta: " << client.varsta << " gen: " << client.parola << "\nabonament: " << client.abonament;
        return os;
    }

    const std::string &getName() const {
        return userName;
    }

    const class abonament &getAbonament() const {
        return abonament;
    }

    void schimba_abonament(class abonament &abonament_nou) {
        abonament = abonament_nou;
    }

    void schimba_parola() {
        for(int i = 0; i < 3; i++) {
        std::string parola_noua;
        std::string parola_noua_verificare;
        std::cout << "Introduceti parola noua:";
        std::cin >> parola_noua;
        std::cout << "Introduceti din nou parola noua:";
        std::cin >> parola_noua_verificare;
        if(parola_noua == parola_noua_verificare)
        {
            parola = parola_noua;
            std::cout << "Parola noua setata!\n";
            break;
        }

        else
            std::cout << "Parola noua nu este aceeasi in ambele campuri, incercati din nou(mai aveti "<<3-i<<" incercari)!\n"; }

    }
    void reducere(const int procent) {
        float pret_nou;
        pret_nou = abonament.getPret();
        pret_nou -= (pret_nou * procent) / 100;
        abonament.setPret(pret_nou);
    }

protected:
    const std::string &getParola() const {
        return parola;
    }

};

class aplicatie{
    std::vector<gym> gyms;
    std::vector<client> clienti;
    std::vector<abonament> abonamente;
    std::string nume;
    std::string fondator;


public:
    aplicatie(std::vector<gym> gyms, std::vector<client> clienti,
              std::vector<abonament> abonamente, std::string nume, std::string fondator) : gyms(std::move(
            gyms)), clienti(std::move(clienti)), abonamente(std::move(abonamente)), nume(std::move(nume)), fondator(std::move(fondator)) {}

    void adauga_client(const class client &client) {
        clienti.push_back(client);
    }

    void adauga_gym(const class gym &gym) {
        gyms.push_back(gym);
    }

    void aduaga_abonament(class abonament &abonament) {
        abonamente.push_back(abonament);
    }


    void afis()
    {
        std::cout << "sali de sport partenere:\n";
        for(const auto &gym : gyms)
            std::cout << gym.getName() << "\n";
        std::cout << "\nclienti:\n";
        for(const auto &client : clienti)
            std::cout << client.getName() << "\n";
        std::cout << "\nabonamente dispinibile:\n";
        for(const auto &abonament : abonamente)
            std::cout << abonament.getNume() << "\n";
    }
    void scbimba_abonament_client(const std::string& abonament_nou,const std::string& nume_client){
        for(auto& client:clienti)
            if(client.getName() == nume_client) {
                for (auto &abonament : abonamente) {
                    if (abonament.getNume() == abonament_nou)
                        client.schimba_abonament(abonament);
                    break;
                }
            }
        std::cout << "Ati introdus un abonament invalid.";
    }

    void setNume(const std::string &nume) {
        aplicatie::nume = nume;
    }

    const std::string &getNume() const {
        return nume;
    }

    const std::string &getFondator() const {
        return fondator;
    }

    ~aplicatie() {
        std::cout << "\nDestructor";
    }
};

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
    aplicatie AppGym{{worldclass},{marius},{incepator},"Work Smart","Nastase Marius"};
    AppGym.adauga_gym(energymhealth_hub);
    AppGym.adauga_gym(anturaj_gym);
    AppGym.aduaga_abonament(avansat);
    AppGym.aduaga_abonament(VIP);
    std::cout<<AppGym.getNume()<<"\n";
    std::cout<<"Fondatorul aplicatiei este: "<<AppGym.getFondator()<<"\n";
    AppGym.afis();
    marius.schimba_parola();
    marius.schimba_abonament(VIP);
    //marius.reducere(20);
    std::cout << marius.getAbonament();

}
