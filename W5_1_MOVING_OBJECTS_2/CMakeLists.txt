project(simp_proj)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

add_executable(unique_ptr_from_func unique_ptr_from_func.cpp)
add_executable(references_and_pointer references_and_pointer.cpp)
add_executable(l_r_value l_r_value.cpp)
add_executable(un_ptr_vect_delete un_ptr_vect_delete.cpp)
