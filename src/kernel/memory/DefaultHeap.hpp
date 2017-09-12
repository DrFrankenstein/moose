#ifndef KERNEL_MEMORY_DEFAULT_HEAP_INCLUDED
#define KERNEL_MEMORY_DEFAULT_HEAP_INCLUDED

#include "Heap.hpp"
#include "arch/posix/PosixHeap.hpp"

namespace Moose { namespace Kernel { namespace Memory {

typedef PosixHeap DefaultHeap;

}}}

#endif
