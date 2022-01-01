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


const std::string &gym::getName() const {
    return name;
}
