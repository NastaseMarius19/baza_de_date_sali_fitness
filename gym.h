//
// Created by orange on 12/18/2021.
//

#ifndef MAIN_CPP_GYM_H
#define MAIN_CPP_GYM_H


#include <string>
#include <utility>
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

    friend std::ostream &operator<<(std::ostream &os, const gym &gym);

    const std::string &getName() const;

};

class gym_builder{
private:
    class gym gym;
public:
    gym_builder() = default;
    gym_builder& name(std::string name){
        gym.name = std::move(name);
        return *this;
    }
    gym_builder& location(std::string location){
        gym.location = std::move(location);
        return *this;
    }
    gym_builder& program(std::vector<std::pair<std::string, std::string>> program){
        gym.program = std::move(program);
        return *this;
    }
    class gym build(){
        return gym;
    }

};

#endif //MAIN_CPP_GYM_H
