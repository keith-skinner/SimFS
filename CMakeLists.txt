cmake_minimum_required(VERSION 3.15.6)
project(simfs)

add_subdirectory(src)

add_executable(step1 step1.c)
target_link_libraries(step1 SimfsVolume)