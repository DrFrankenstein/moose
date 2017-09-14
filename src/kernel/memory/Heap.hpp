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
	struct Deleter
	{
		Heap& heap;
		void operator ()(gsl::owner<void*> ptr);
	};
	
	template <typename T>
	using Block = std::unique_ptr<T, Deleter>;

	template <typename T>
	Block<T> allocate(std::size_t count = 1)
	{
		gsl::owner<T*> ptr = static_cast<T*>(this->allocateRaw(count * sizeof(T)));
		Deleter deleter {*this};
		return Block<T>(ptr, deleter);
	}

	template <typename T>
	Block<T> reallocate(Block<T> ptr, std::size_t newcount)
	{
		gsl::owner<T*> newptr = static_cast<T*>(this->reallocate(ptr.release(), newcount * sizeof(T)));
		Deleter deleter {*this};
		return Block<T>(newptr, deleter);
	}

	virtual gsl::owner<void*> allocateRaw(std::size_t size) = 0;
	virtual gsl::owner<void*> reallocate(gsl::owner<void*> ptr, std::size_t newsize) = 0;
	virtual void free(gsl::owner<void*> ptr) = 0;
	//virtual ~Heap() = 0;
};

}}}

#endif
