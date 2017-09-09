cmake_minimum_required(VERSION 2.6)
project(moose)

set(warnings "-Wall -Wextra -pedantic")

if(NOT CONFIGURED_ONCE)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${warnings}")
endif()

include_directories(3rdparty/GSL/include)
add_subdirectory(src)

set(CONFIGURED_ONCE TRUE CACHE INTERNAL "Flag indicating that this project has
	been configured previously")
