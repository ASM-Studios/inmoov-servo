cmake_minimum_required(VERSION 3.31.5)
include(pico_sdk_import.cmake)
project(embed)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

pico_sdk_init()

add_executable(embed
    src/main.cpp
)

target_link_libraries(embed
    pico_stdlib
    hardware_pwm hardware_gpio
)

pico_add_extra_outputs(embed)
