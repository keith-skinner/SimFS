cmake_minimum_required(VERSION 3.15.6)
project(Volume)

add_library(SimfsVolume)

set_property(TARGET SimfsVolume PROPERTY C_STANDARD 11)
set_property(TARGET SimfsVolume PROPERTY C_STANDARD_REQUIRED ON)

target_compile_options(SimfsVolume PRIVATE "-Wall" "-Wextra" "-Wpedantic")

target_sources(SimfsVolume
    PRIVATE 
        volume.c
    PUBLIC  
        volume.h
        block/block.h
        block/descriptor.h
        block/content.h
)

target_link_libraries(SimfsVolume SimfsPartition)