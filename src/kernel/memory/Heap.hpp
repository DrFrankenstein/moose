#include <cstdlib>

namespace Moose { namespace Kernel { namespace Memory {

class Heap
{
	virtual void* allocate(std::size_t size, bool zero = false) = 0;
	virtual void* realloc(void* ptr, std::size_t newsize) = 0;
	virtual void free(void* ptr) = 0;
	virtual ~Heap() = 0;
};

}}}