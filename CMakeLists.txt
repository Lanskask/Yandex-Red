cmake_minimum_required(VERSION 3.15)
project(Yandex_Red)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libstdc++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ltbb")
#set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wno-long-long -pedantic")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -pedantic")

add_subdirectory(w1_macroses)
add_subdirectory(simp_proj_1)
add_subdirectory(BFS)
add_subdirectory(class_templates)
add_subdirectory(yandex_algorithms)

#Week 2
add_subdirectory(CODE_OPTIMISATION)
add_subdirectory(OUT_STREAM_BUFFERISATION)
add_subdirectory(ALGORITHM_COMPLEXITY)
add_subdirectory(MEMORY_MODEL)
add_subdirectory(EFFECTIVE_CONTAINER_USAGE)

# W 5
add_subdirectory(W5_1_MOVING_OBJECTS)
add_subdirectory(W5_2_BASIC_MULTYTHREADING)


add_subdirectory(0_LEET_CODE)

add_executable(Yandex_Red main.cpp)