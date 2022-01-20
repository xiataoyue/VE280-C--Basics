cmake_minimum_required(VERSION 3.16)
project(Project_Three_Related_Files)

set(CMAKE_CXX_STANDARD 14)

add_executable(Blackjack blackjack.cpp deck.cpp hand.cpp player.cpp rand.cpp card.cpp)