//
// Created by orange on 12/18/2021.
//

#include "gym.h"

std::ostream &operator<<(std::ostream &os, const gym &gym) {
    os << "name: " << gym.name << "\nlocation: " << gym.location << "\nprogram: ";
    for(auto const & day : gym.program) {
        os << day.first << " : " << day.second << "\n";
    }
    return os;
}

void gym::adauga(std::vector<std::pair<std::string, std::string>> &days) {
    for(auto const & day : days)
        program.push_back(day);

}

const std::string &gym::getName() const {
    return name;
}

const std::string &gym::getLocation() const {
    return location;
}

const std::vector<std::pair<std::string, std::string>> &gym::getProgram() const {
    return program;
}
