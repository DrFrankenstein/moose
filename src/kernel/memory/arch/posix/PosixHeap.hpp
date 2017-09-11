#include <cstddef>
#include <gsl/gsl>

#include "../../Heap.hpp"

namespace Moose { namespace Kernel { namespace Memory {

class PosixHeap : public Heap
{
	virtual gsl::owner<void*> allocateRaw(std::size_t size);
	virtual gsl::owner<void*> reallocate(gsl::owner<void*> ptr, std::size_t newsize);
	virtual void free(gsl::owner<void*> ptr);
	virtual ~PosixHeap();
};

}}}