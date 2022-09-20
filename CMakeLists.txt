cmake_minimum_required(VERSION 3.23)
project(WH_spammer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -lcurl")
add_executable(WH_spammer main.cpp config.hpp)
target_link_libraries(WH_spammer curl)