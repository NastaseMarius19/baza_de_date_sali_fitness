//
// Created by orange on 12/18/2021.
//

#ifndef MAIN_CPP_GYM_H
#define MAIN_CPP_GYM_H


#include <string>
#include <vector>
#include <iostream>

class gym
{
    std::string name;
    std::string location;
    std::vector<std::pair<std::string, std::string>> program;
public:
    gym(std::string name, std::string location,
        std::vector<std::pair<std::string, std::string>> program) : name(std::move(name)), location(std::move(location)),
                                                                    program(std::move(program)) {}

    friend std::ostream &operator<<(std::ostream &os, const gym &gym);

    const std::string &getName() const;

};


#endif //MAIN_CPP_GYM_H
