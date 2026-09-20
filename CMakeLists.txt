cmake_minimum_required(VERSION 4.3)
project(01_Tic_tac_toe)

set(CMAKE_CXX_STANDARD 20)

add_executable(01_Tic_tac_toe main.cpp)

if(MSVC)
    add_compile_options(/WX)
else()
    add_compile_options(-Werror)
endif()