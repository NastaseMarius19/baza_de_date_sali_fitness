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
    friend class gym_builder;
public:
    gym() = default;
//    gym(std::string name, std::string location,
//        std::vector<std::pair<std::string, std::string>> program) : name(std::move(name)), location(std::move(location)),
//                                                                    program(std::move(program)) {}

    friend std::ostream &operator<<(std::ostream &os, const gym &gym);

    const std::string &getName() const;

};

class gym_builder{
private:
    gym gym;
public:
    gym_builder() = default;
    gym_builder& name(std::string name){
        gym.name = name;
        return *this;
    }
    gym_builder& location(std::string location){
        gym.location = location;
        return *this;
    }
    gym_builder& program(std::vector<std::pair<std::string, std::string>> program){
        gym.program = program;
        return *this;
    }
    class gym build(){
        return gym;
    }

};

#endif //MAIN_CPP_GYM_H
