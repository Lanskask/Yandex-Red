cmake_minimum_required(VERSION 3.15)
project(Yandex_Red)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libstdc++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ltbb")
#set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wno-long-long -pedantic")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -pedantic")

add_executable(Yandex_Red main.cpp)

add_subdirectory(W1_MACROSES)
add_subdirectory(W1_DEFS)
add_subdirectory(W1_CLASS_TEMPLATES)

add_subdirectory(W2_CODE_OPTIMISATION)
add_subdirectory(W2_OUT_STREAM_BUFFERISATION)

add_subdirectory(W3_ALGORITHM_COMPLEXITY)
add_subdirectory(W3_MEMORY_MODEL)

add_subdirectory(W4_EFFECTIVE_CONTAINER_USAGE)

add_subdirectory(W5_1_MOVING_OBJECTS)
add_subdirectory(W5_2_BASIC_MULTYTHREADING)
add_subdirectory(W5_1_MOVING_OBJECTS_2)
