project(simp_proj)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -pedantic")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")


add_executable(effective_container_usage effective_container_usage.cpp)
add_executable(StringSet StringSet.cpp)
add_executable(vector_to_deque vector_to_deque.cpp)
add_executable(iterator_invalidation iterator_invalidation.cpp)
add_executable(list_tries list_tries.cpp)
add_executable(array_exprs array_exprs.cpp)
add_executable(split_string split_string.cpp)
