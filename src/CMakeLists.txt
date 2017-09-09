add_subdirectory(services)

add_executable(moose main.cpp)
set_property(TARGET moose PROPERTY CXX_STANDARD 14)
