cmake_minimum_required(VERSION 3.22)
project(untitled C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
include_directories(inc)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lncurses")
add_executable(untitled src/main.c src/editor.c
         src/gui.c
         src/init.c
         src/movement.c
        ../../Ten/Ten1.c)
find_package(Curses REQUIRED)
target_link_libraries(untitled ${CURSES_LIBRARIES})
