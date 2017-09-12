#include "memory/DefaultHeap.hpp"

using Memory::DefaultHeap;

namespace Moose { namespace Kernel {

DefaultHeap kernelHeap;

void kmain()
{
	auto x = kernelHeap.allocate<int>(4);
}

}}
