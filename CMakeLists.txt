cmake_minimum_required(VERSION 3.23)
project(c5_3)

set(CMAKE_CXX_STANDARD 20)

include(fetchContent)

FetchContent_Declare(fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG master
        )
FetchContent_MakeAvailable(fmt)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.1 # or a later release
)


FetchContent_MakeAvailable(Catch2)

add_executable(c5_3 main.cpp list.hpp list_impl.hpp list_def.hpp node.hpp iterator.hpp iterator_impl.hpp assignment_unit_tests.cpp assignment.cpp assignment.hpp list_concepts.hpp)

#add_executable(ctt concept_tests.cpp)

target_link_libraries(c5_3 PRIVATE fmt::fmt Catch2::Catch2)

include(CTest)
include(Catch)
#catch_discover_tests(c5_3)