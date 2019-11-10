cmake_minimum_required(VERSION 3.14)
project(Go_Fish_)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Go_Fish_
    card.h
    deck.h
    driver.cpp
    player.h
    card.cpp
    deck.cpp
    player.cpp
        )
