cmake_minimum_required(VERSION 3.22)
project(untitled C)
set(CMAKE_C_STANDARD 23)
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=leak")
add_library(calc SHARED add.c sub.c mul.c myDiv.c)
add_executable(untitled main.c)
target_link_libraries(untitled calc)