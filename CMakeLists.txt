cmake_minimum_required(VERSION 3.20)
project(PredOrPrey)

set(CMAKE_CXX_STANDARD 17)

# create the executable and use libimgLib created above
add_executable(${CMAKE_PROJECT_NAME}
        main.cpp
        lib/include/Critter.h
        lib/src/Prey.cpp
        lib/include/Prey.h
        lib/src/Predator.cpp
        lib/include/Predator.h
        lib/src/DoodleBug.cpp
        lib/include/DoodleBug.h
        lib/src/QueenAnt.cpp
        lib/include/QueenAnt.h
        lib/src/WorkerAnt.cpp
        lib/include/WorkerAnt.h
        lib/src/MatingAnt.cpp
        lib/include/MatingAnt.h
        lib/src/Board.cpp
        lib/include/Board.h
        lib/src/Critter.cpp
        lib/src/Simulation.cpp
        lib/include/Simulation.h
        lib/src/FileReader.cpp
        lib/include/FileReader.h
)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE lib/include)
