cmake_minimum_required(VERSION 3.25)
project(prisoner_question)

include_directories(.)
add_library(lib Prison.cpp Boxes.cpp)
link_libraries(lib)
add_executable(main main.cpp)