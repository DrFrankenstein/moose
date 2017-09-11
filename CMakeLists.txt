cmake_minimum_required(VERSION 2.6)
project(moose)

set(warnings "-Wall -Wextra -pedantic")

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(warnings "-Wall -Wextra -pedantic")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(warnings "/W4")
endif()

if(NOT CONFIGURED_ONCE)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${warnings}")
endif()

include_directories(3rdparty/GSL/include)
add_subdirectory(src)

set(CONFIGURED_ONCE TRUE CACHE INTERNAL "Flag indicating that this project has
	been configured previously")
