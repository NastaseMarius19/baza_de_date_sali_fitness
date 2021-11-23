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
    gym(const std::string &name, const std::string &location,
        const std::vector<std::pair<std::string, std::string>> &program) : name(name), location(location),
                                                                             program(program) {}

    friend std::ostream &operator<<(std::ostream &os, const gym &gym) {
        os << "name: " << gym.name << "\nlocation: " << gym.location << "\nprogram: ";
        for(auto const & day : gym.program)
        {
            os << day.first << " : " << day.second << "\n";
        }
        return os;
    }

    void adauga(std::vector<std::pair<std::string, std::string>> &days)
    {
        for(auto const & day : days)
            program.push_back(day);

    }

    const std::string &getName() const {
        return name;
    }


};

class abonament{
    float pret;
    std::string nume;
    std::vector<std::string> bonusuri;
public:
    abonament(float pret, const std::string &nume, const std::vector<std::string> &bonusuri) : pret(pret), nume(nume),
                                                                                               bonusuri(bonusuri) {}

    friend std::ostream &operator<<(std::ostream &os, const abonament &abonament) {
        os << "pret: " << abonament.pret << "\nnume: " << abonament.nume << "\nbonusuri: ";
        for(const auto & bonus : abonament.bonusuri)
            os<<bonus<<" ";
        return os;
    }

    abonament& operator=(const abonament& copie) {
        this->nume = copie.nume;
        return *this;
    }

    abonament(const abonament& copie)
    {
        this->pret = copie.pret;
        this->nume = copie.nume;
        for(const auto& bonus:copie.bonusuri)
            this->bonusuri.push_back(bonus);
    }

    const std::string &getNume() const {
        return nume;
    }

};

class client{
    std::string userName;
    int varsta;
    std::string parola;
    abonament abonament;

public:
    client(const std::string &userName, int varsta, const std::string &parola, const class abonament &abonament) : userName(userName),
                                                                                                      varsta(varsta),
                                                                                                      parola(parola),
                                                                                                      abonament(
                                                                                                              abonament) {}

    friend std::ostream &operator<<(std::ostream &os, const client &client) {
        os << "name: " << client.userName << " varsta: " << client.varsta << " gen: " << client.parola << "\nabonament: " << client.abonament;
        return os;
    }

    const std::string &getName() const {
        return userName;
    }

    const std::string &getParola() const {
        return parola;
    }

};

class gym_parteners{
    std::vector<gym> gyms;
    std::vector<client> clienti;
    std::vector<abonament> abonamente;
    bool check;
public:

    gym_parteners(const std::vector<gym> &gyms, const std::vector<client> &clienti,
                  const std::vector<abonament> &abonamente) : gyms(gyms), clienti(clienti), abonamente(abonamente) {}


    void login(std::string nume)
    {
        for(const auto & client:clienti)
            if(client.getName().compare(nume)==0)
            {
                std::cout<<"Introduceti parola: ";
                std::string parola;
                std::cin>>parola;
                if(client.getParola().compare(parola)==0)
                {
                    std::cout<<"Bine ati venit! \n";
                    std::cout<<client;
                    check=0;
                    break;

                }

            } else
                check=1;

    }
    class client register_client()
    {
        std::string name;
        int varsta;
        std::string parola;
        std::string nume_abonament;
        std::cout<<"Introduceti username-ul dorit: ";
        std::cin>>name;
        std::cout<<"\n";
        for(int i = 0 ; i < clienti.size();i++)
            if(clienti[i].getName().compare(name)==0)
            {
                std::cout<<"Username-ul deja existent, va rog alegeti altul:";
                std::cin>>name;
                std::cout<<"\n";
                i=-1;

            }
        std::cout<<"Introduceti parola:";
        std::cin>>parola;
        std::cout<<"\n";
        std::cout<<"Introduceti varsta:";
        std::cin>>varsta;
        std::cout<<"\n";
        std::cout<<"Alegeti abonamentul dorit din lista urmatoare:\n";
        std::cout<<"incepator - 140 de lei\navansat - 200 de lei\nVIP - 400 de lei\nTip abonament:";
        std::cin>>nume_abonament;
        for(int i = 0 ; i < abonamente.size();i++)
            if(abonamente[i].getNume().compare(nume_abonament)==0)
            {
                class abonament aux = abonamente[i];
                class client client = {name,varsta,parola,aux};
                return client;
            }
    };

    void adauga_client(const class client& client)
    {
        clienti.push_back(client);
    }

    void adauga_gym(const class gym& gym)
    {
        gyms.push_back(gym);
    }

    bool isP() const {
        return check;
    }

    void afis()
    {
        std::cout<<"gyms: ";
        for(const auto & gym : gyms)
            std::cout<< gym.getName()<<" ";
        std::cout<<"\nclienti: ";
        for(const auto & client : clienti)
            std::cout<< client.getName()<< " ";
        std::cout<<"\nabonamente: ";
        for(const auto & abonament : abonamente)
            std::cout<<abonament.getNume()<<" ";

    }

    ~gym_parteners() {
        std::cout<<"\nDestructor";
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
    gym_parteners AppGym{{worldclass, energymhealth_hub, anturaj_gym},
                         {marius},
                         {incepator,  avansat,           VIP}};
    std::string nume;
    std::cin >> nume;
    AppGym.afis();
    AppGym.login(nume);
    if (AppGym.isP() == 1)
    {
        class client client = AppGym.register_client();
        std::cout<<client;
        AppGym.adauga_client(client);
    }
   AppGym.afis();
    bambam
}
