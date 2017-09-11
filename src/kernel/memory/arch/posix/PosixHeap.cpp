#include <cstdlib>
#include <memory>
#include <gsl/gsl>

#include "PosixHeap.hpp"

namespace Moose { namespace Kernel { namespace Memory {

gsl::owner<void*> PosixHeap::allocateRaw(std::size_t size)
{
	return std::malloc(size);
}


gsl::owner<void*> reallocate(gsl::owner<void*> ptr, std::size_t newsize)
{
	return std::realloc(ptr, newsize);
}

}}}