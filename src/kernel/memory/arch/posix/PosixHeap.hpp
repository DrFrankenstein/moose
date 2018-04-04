#ifndef KERNEL_MEMORY_ARCH_POSIX_POSIXHEAP_INCLUDED
#define KERNEL_MEMORY_ARCH_POSIX_POSIXHEAP_INCLUDED

#include <cstddef>
#include <gsl/gsl>

#include "../../Heap.hpp"

namespace Moose { namespace Kernel { namespace Memory {

class PosixHeap : public Heap
{
public:
	virtual gsl::owner<void*> allocate(std::size_t size = 1);
	virtual gsl::owner<void*> reallocate(gsl::owner<void*> ptr, std::size_t newsize);
	virtual void release(gsl::owner<void*> ptr);
	virtual ~PosixHeap();
};

}}}

#endif
