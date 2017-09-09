#include <cstdlib>

#include "../../Heap.hpp"

namespace Moose { namespace Kernel { namespace Memory {

class PosixHeap : public Heap
{
	virtual void* allocate(std::size_t size, bool zero = false);
	virtual void* realloc(void* ptr, std::size_t newsize);
	virtual void free(void* ptr);
	virtual ~Heap();
};

}}}