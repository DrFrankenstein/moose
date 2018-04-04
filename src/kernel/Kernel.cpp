#include <string>

#include "memory/KernelHeap.hpp"

using std::string;
using Moose::Kernel::Memory::kernelHeap;

namespace Moose { namespace Kernel {

void kmain()
{
	auto x = kernelHeap.allocate();
	kernelHeap.release(x);

	auto y = new int;
	delete y;

	string foo ("Hello, World!");
}

}}
