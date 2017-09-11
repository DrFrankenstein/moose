set(moose_SOURCES main.cpp)

add_subdirectory(kernel)
add_subdirectory(services)

add_executable(moose ${moose_SOURCES})
set_property(TARGET moose PROPERTY CXX_STANDARD 14)
target_link_libraries(moose kernel)
