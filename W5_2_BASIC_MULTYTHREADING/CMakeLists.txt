project(simp_proj)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(basic_multythreading basic_multythreading.cpp)
add_executable(generate_sum_matrix generate_sum_matrix.cpp)
add_executable(BancAccount BancAccount.cpp)
add_executable(sum_matrix_2 sum_matrix_2.cpp)


