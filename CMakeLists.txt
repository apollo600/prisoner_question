cmake_minimum_required(VERSION 3.22)
project(prisoner_question)

set(inc_dir "include")
set(src_dir "src")

include_directories(${inc_dir})
add_library(lib ${src_dir}/Prison.cpp ${src_dir}/Boxes.cpp)
link_libraries(lib)
add_executable(main ${src_dir}/main.cpp)