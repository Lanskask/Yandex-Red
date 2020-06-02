project(simp_proj)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")


add_executable(moving_objects moving_objects.cpp)
add_executable(move_function move_function.cpp)
add_executable(move_with_array move_with_array.cpp)
add_executable(copy_ctor copy_ctor.cpp)
add_executable(testing_copy testing_copy.cpp)
add_executable(move_constructor move_constructor.cpp)
add_executable(Person Person.cpp)
add_executable(VectorStream VectorStream.cpp)
add_executable(tricky_return tricky_return.cpp)
