cmake_minimum_required(VERSION 3.20)
project(baza_de_date_sali_fitness)

set(CMAKE_CXX_STANDARD 14)

add_executable(baza_de_date_sali_fitness
        main.cpp gym.cpp gym.h abonament.cpp abonament.h client.cpp client.h aplicatie.cpp aplicatie.h dieta_standard.cpp dieta_standard.h dieta_deficit_caloric.cpp dieta_deficit_caloric.h dieta_surplus_caloric.cpp dieta_surplus_caloric.h dieta_mentinere.cpp dieta_mentinere.h HashPassword.cpp HashPassword.h erori_abonament.cpp erori_abonament.h)
