cmake_minimum_required(VERSION 3.15.6)
project(Partition)

add_library(SimfsPartition)

set_property(TARGET SimfsPartition PROPERTY C_STANDARD 11)
set_property(TARGET SimfsPartition PROPERTY C_STANDARD_REQUIRED ON)

target_sources(SimfsPartition
    PRIVATE 
        partition.c
    PUBLIC  
        partition.h
        defines.h
        index.h
)

