#ifndef KERNEL_MEMORY_STLALLOCATOR_INCLUDED
#define KERNEL_MEMORY_STLALLOCATOR_INCLUDED

#include "Heap.hpp"

namespace Kernel { namespace Memory {

template <typename T>
struct StlAllocator
{
	typedef T value_type;
	Heap& heap;

	StlAllocator(Heap& heap) : heap(heap)
	{ }
	template <typename U>
	StlAllocator(const StlAllocator<U>& other)
	{ }
};

}}

#endif