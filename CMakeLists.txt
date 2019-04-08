cmake_minimum_required(VERSION 3.13)
project(GeneticRockets)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-g -Wall)

find_package(SFML 2.5 REQUIRED COMPONENT graphics window audio network system)

file(GLOB_RECURSE sources "src/*.cpp")

add_executable(GeneticRockets ${sources})
set_target_properties(GeneticRockets PROPERTIES OUTPUT_NAME "GeneticRockets.out")

target_link_libraries(GeneticRockets sfml-graphics sfml-window sfml-audio sfml-network sfml-system)
target_include_directories(GeneticRockets PUBLIC "include/")