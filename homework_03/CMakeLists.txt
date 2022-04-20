cmake_minimum_required(VERSION 3.8)

project(01.guessingGame)

add_executable(guessingGame 
    main.cpp
    guessingGame.cpp
    guessingGame.h
)

set_target_properties(guessingGame PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)