#pragma once

#include <cstdint>

namespace LeakDetector {

	// Signature of a ::malloc compatible function
	using fMalloc = void*(__cdecl*)(size_t);

	// Signature of a ::free compatible function
	using fFree = void(__cdecl*)(void*);

	// SetMalloc defines the malloc method used by the global new operators.
	// By default this is set to ::malloc.
	// @param afMalloc Pointer to ::malloc or a similar function.
	// @return Previous function set
	fMalloc SetMalloc(fMalloc afMalloc);

	// SetFree defines the free method used by the global delete operators.
	// By default this is set to ::free.
	// @param afFree Pointer to ::free or a similar function.
	// @return Previous function set
	fFree SetFree(fFree afFree);

	// GetActiveAllocations returns the number of allocations active at time
	// of call. This method can be used as a leak indicator.
	// @return Number of currently active allocations
	int64_t GetActiveAllocations();

	// AddAllocation adds a pointer to the list of allocations and stores the
	// current backtrace along with it.
	void AddAllocation(void* apData);

	// RemoveAllocation removes a pointer from the list of allocations.
	void RemoveAllocation(void* apData);
}