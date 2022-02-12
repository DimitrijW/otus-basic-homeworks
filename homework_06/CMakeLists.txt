cmake_minimum_required(VERSION 3.8)

project(06.container)

add_executable(container 
    container.cpp
)

set_target_properties(container PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)