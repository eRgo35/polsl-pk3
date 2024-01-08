cmake_minimum_required(VERSION 3.28)
project(listImpl
    VERSION 1.0.0
    DESCRIPTION "One-way linked list implementation"
    LANGUAGES CXX)

message(STATUS "Michał Czyż (c) 2024")
message(STATUS "GNU GPL 3")

add_library(
    linked_list
    include/list.hpp
    include/node.hpp
)

add_library(
    output_linter
    include/colors.hpp
)

add_executable(project src/main.cpp)

target_link_libraries(project PRIVATE linked_list)
set_target_properties(linked_list PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(project PRIVATE output_linter)
set_target_properties(output_linter PROPERTIES LINKER_LANGUAGE CXX)