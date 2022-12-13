cmake_minimum_required(VERSION 3.22)
project(CppCourse)

set(CMAKE_CXX_STANDARD 11)

add_executable(CppCourse Lab00/ex1.cpp Lab00/ex2.cpp Lab00/ex3.cpp Lab01/main.c Lab01/ADTStack.c lab02/main.cpp
        lab03/String.cpp lab03/String.h lab03/main.cpp HW01/DoubleVector.cpp HW01/DoubleVector.h HW01/main.cpp
HW01/Observation.cpp HW01/Observation.h HW01/ObservationVector.cpp HW01/ObservationVector.h lab04/SquareMat.cpp
lab04/SquareMat.h lab04/main.cpp lab05/Stack.cpp lab05/Stack.h lab05/main.cpp lab06/Stack.cpp lab06/Stack.h lab06/main.cpp
lab06/List.cpp HW02/main.cpp HW02/Board.cpp HW02/Board.h HW02/Cell.cpp HW02/Cell.h HW02/Player.cpp HW02/Player.h
lab07/Robot.cpp lab07/Robot.h lab07/Transformer.h lab07/Transformer.cpp)
