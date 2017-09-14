#include "Heap.hpp"

namespace Moose { namespace Kernel { namespace Memory {

void Heap::Deleter::operator ()(gsl::owner<void*> ptr)
{
	this->heap.free(ptr);
}

}}}