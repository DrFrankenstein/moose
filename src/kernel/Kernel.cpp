#include "memory/DefaultHeap.hpp"

using Moose::Kernel::Memory::DefaultHeap;

namespace Moose { namespace Kernel {

DefaultHeap kernelHeap;

void kmain()
{
	auto x = kernelHeap.allocate<int>();
}

}}
