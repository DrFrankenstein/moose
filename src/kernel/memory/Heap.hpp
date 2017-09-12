#ifndef KERNEL_MEMORY_HEAP_INCLUDED
#define KERNEL_MEMORY_HEAP_INCLUDED

#include <cstdlib>
#include <memory>
#include <functional>
#include <gsl/gsl>

namespace Moose { namespace Kernel { namespace Memory {

class Heap
{
public:
	// the `unique_ptr`s we return have some memory overhead due to holding a reference to
	// the heap that created them, so that they get deleted correctly. use raw pointers if
	// memory usage is critical.
	template <typename T>
	std::unique_ptr<T> allocate(std::size_t size)
	{
		gsl::owner<T*> ptr = static_cast<T*>(this->allocateRaw(size));
		auto deleter = [this](T* ptr) { this->free(ptr); };
		return std::unique_ptr<T>(ptr, deleter);
	}

	template <typename T>
	std::unique_ptr<T> reallocate(std::unique_ptr<T> ptr, std::size_t newsize)
	{
		gsl::owner<T*> newptr = static_cast<T*>(this->reallocate(ptr.release(), newsize));
		auto deleter = [this](T* ptr) { this->free(ptr); };
		return std::unique_ptr<T>(newptr, deleter);
	}

	virtual gsl::owner<void*> allocateRaw(std::size_t size) = 0;
	virtual gsl::owner<void*> reallocate(gsl::owner<void*> ptr, std::size_t newsize) = 0;
	virtual void free(gsl::owner<void*> ptr) = 0;
	virtual ~Heap() = 0;
};

}}}

#endif

