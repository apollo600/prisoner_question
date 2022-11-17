cmake_minimum_required(VERSION 3.25)
project(prisoner_question)

set(inc_dir "inc")

add_library(lib ${inc_dir}/Prison.cpp ${inc_dir}/Boxes.cpp)
link_libraries(lib)
add_executable(main main.cpp)