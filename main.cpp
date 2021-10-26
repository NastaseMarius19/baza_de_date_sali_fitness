#include <iostream>
#include <vector>
#include <string>

using namespace std::string_literals;


class gym
{
    std::string name;
    std::string location;
    std::vector<std::string> day;
    std::vector<std::string> interval_orar;
public:
    gym(const std::string &name, const std::string &location, const std::vector<std::string> &day,
        const std::vector<std::string> &intervalOrar) : name(name), location(location), day(day),
                                                        interval_orar(intervalOrar) {}

    friend std::ostream &operator<<(std::ostream &os, const gym &gym) {
        os << "name: " << gym.name << "\n location: " << gym.location  << "\n program \n";
        for(int i=0;i<gym.day.size();i++)
            os<<gym.day[i]<<" "<<gym.interval_orar[i]<<"\n";
        return os;
    }
    void adauga_zi(std::string days){
        day.push_back(days);
    }
    void adauga_interval_orar(std::string interval){
        interval_orar.push_back(interval);
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



};

class gym_parteners{
    std::vector<gym> gyms;
};

int main ()
{
    std::vector<std::string> day;
    day = {"Luni","Marti","Miercuri","Joi","Vineri","Sambata","Duminica"};
    gym worlclass{"WorldClass"s,"Str.Aviatorilor nr.19"s,day,{"8:00-22:00","8:00-22:00","8:00-22:00","8:00-22:00","8:00-22:00","9:00-16:00","closed"}};
    gym energymhealth_pub{"energymhealt.pub"s,"Str.Dorobantilor bloc 8 sc B etaj 8"s,day,{"8:00-22:00","8:00-22:00","8:00-22:00","8:00-22:00","8:00-22:00","9:00-16:00","closed"}};
    //std::cout<<worlclass;
    //std::cout<<energymhealth_pub;
    abonament incepator(140,"Incepator",{"Antrenamente online","8 sedinte pe luna","Acces la orice sala partenera"});
    //std::cout<<incepator;
    client marius{"Marius"s,21,"m"s,incepator};
    std::cout << marius;
}