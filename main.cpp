#include <iostream>
#include <vector>
#include <string>
#include <array>

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

    void adauga(std::vector<std::pair<std::string, std::string>> &b)
    {
        for(auto const & day : b)
            program.push_back(day);

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

    abonament(const abonament& copie)
    {
        this->pret = copie.pret;
        this->nume = copie.nume;
        for(const auto& bonus:copie.bonusuri)
            this->bonusuri.push_back(bonus);
    }

};

class client{
    std::string name;
    int varsta;
    std::string gen;
    abonament abonament;

public:
    client(const std::string &name, int varsta, const std::string &gen, const class abonament &abonament) : name(name),
                                                                                                      varsta(varsta),
                                                                                                      gen(gen),
                                                                                                      abonament(
                                                                                                              abonament) {}

    friend std::ostream &operator<<(std::ostream &os, const client &client) {
        os << "name: " << client.name << " varsta: " << client.varsta << " gen: " << client.gen << "\nabonament: " << client.abonament;
        return os;
    }

    void adauga(const class abonament tip)
    {
        abonament = tip;
    }

    const std::string &getName() const {
        return name;
    }

};

class gym_parteners{
    std::vector<gym> gyms;
    std::vector<client> clienti;

public:
    gym_parteners(const std::vector<gym> &gyms, const std::vector<client> &clienti) : gyms(gyms), clienti(clienti) {}

    void adauga(gym gym)
    {
        gyms.push_back(gym);
    }

    void cauta(std::string nume)
    {
        for(const auto & sala : clienti) // for(int i=0 ; i<client.size();i++)
            if(nume.compare(sala.getName())==0)
                std::cout<<"Este clientul nostru!";
            else
                std::cout<<"Nu este clientul nostru";

    }

    ~gym_parteners() {
        std::cout<<"\nDestructor";
    }
};

int main ()
{
    gym worldclass{"WordlClass"s,"Str.Soarelui Nr.25"s,{{"Luni","8:00-22:00"},{"Marti","8:00-22:00"},{"Miercuri","8:00-22:00"},{"Joi","8:00-22:00"},{"Vineri","8:00-22:00"},{"Sambata","10:00-16:00"},{"Duminica","INCHIS"}}};
    gym energymhealth_hub{"energymhealth_hub"s,"Str.Mircea Bravo Nr.33"s,{{"Luni","8:00-22:00"},{"Marti","8:00-22:00"},{"Miercuri","8:00-22:00"},{"Joi","8:00-22:00"},{"Vineri","8:00-22:00"},{"Sambata","10:00-16:00"},{"Duminica","INCHIS"}}};
    gym anturaj_gym{"Anturaj Gym"s,"Str.Principala Bloc 8 Sc.A Et.4"s,{{"Luni","8:00-22:00"},{"Marti","8:00-22:00"},{"Miercuri","8:00-22:00"},{"Joi","8:00-22:00"},{"Vineri","8:00-22:00"},{"Sambata","INCHIS"},{"Duminica","INCHIS"}}};
    abonament incepator(140,"Incepator",{"Antrenamente online","8 sedinte pe luna"s});
    abonament avansat(200,"Avansat",{"Antrenamente online"s,"O intrare pe zi la orice sala partenera"s,"4 sedinte cu antrenor personal"s});
    abonament VIP(300,"VIP",{"Antrenamente online"s,"Intrare libera la orice sala partenera"s,"8 sedinte cu antrenor personal"s,"diete personalizate"s});
    //std::cout<<incepator;
    client marius{"Marius"s,21,"m"s,incepator};
    //std::cout << marius;
    gym_parteners ESX{{worldclass},{marius}};
    ESX.cauta("Marius");

}
