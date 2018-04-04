#ifndef KERNEL_MEMORY_HEAP_INCLUDED
#define KERNEL_MEMORY_HEAP_INCLUDED

#include <cstdlib>
#include <memory>
#include <functional>
#include <gsl/gsl>

namespace Moose { namespace Kernel { namespace Memory {

class Heap
{
public:
	virtual gsl::owner<void*> allocate(std::size_t size = 1) = 0;
	virtual gsl::owner<void*> reallocate(gsl::owner<void*> ptr, std::size_t newsize) = 0;
	virtual void release(gsl::owner<void*> ptr) = 0;
	//virtual ~Heap() = 0;
};

}}}

#endif
