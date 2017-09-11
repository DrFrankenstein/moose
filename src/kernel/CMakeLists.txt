#add_subdirectory(memory)

set(kernel_SOURCES
    Kernel.cpp
    memory/arch/posix/PosixHeap.cpp
)

add_library(kernel ${kernel_SOURCES})
set_property(TARGET kernel PROPERTY CXX_STANDARD 14)
#target_link_libraries(kernel kernel_memory)