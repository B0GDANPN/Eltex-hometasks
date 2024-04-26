cmake_minimum_required(VERSION 3.26)
project(untitled C)
#Процессоп динамлибы виртуал фс
set(CMAKE_C_STANDARD 99)
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=leak")
add_executable( untitled
        #Part1/First/12.c
        #Part1/First/3.c
        #Part1/First/4.c
        #Part1/Second/1.c
        #Part1/Second/2.c
        #Part1/Second/3.c
        #Part1/Second/4.c
        #Part1/Third/1.c
        #Part1/Third/2.c
        #Part1/Part1/Third/3.c
        #Part1/Third/4.c
        #Part1/Fourth.c
        #Part1/Fifth.c
        #Part2/Six.c
        Part2/Eight/main.c
        Part2/Eight/add.c
        Part2/Eight/sub.c
        Part2/Eight/mul.c
        Part2/Eight/myDiv.c
)