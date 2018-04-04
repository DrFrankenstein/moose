#include <cstddef>
#include <new>

#include "KernelHeap.hpp"

using std::size_t;
using std::nothrow_t;
using std::nothrow;
using Moose::Kernel::Memory::kernelHeap;

void* operator new(size_t size)
{
	return operator new(size, nothrow);
}

void* operator new[](size_t size)
{
	return operator new[](size, nothrow);
}

void* operator new(size_t size, const nothrow_t&)
{
	return kernelHeap.allocate(size);
}

void* operator new[](size_t size, const nothrow_t&)
{
	return kernelHeap.allocate(size);
}

void operator delete(void* ptr)
{
	return kernelHeap.release(ptr);
}

void operator delete[](void* ptr)
{
	return kernelHeap.release(ptr);
}

void operator delete(void* ptr, size_t)
{
	return operator delete(ptr);
}

void operator delete[](void* ptr, size_t)
{
	return operator delete[](ptr);
}
