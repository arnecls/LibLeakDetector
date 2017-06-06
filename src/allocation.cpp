#include "allocation_func.h"
#include "backtrace.h"
#include "spinlock.h"
#include <atomic>
#include <unordered_map>
#include <mutex>

namespace LeakDetector {
	// Allocation counter
	static std::atomic_int64_t ActiveAllocations = 0;

	// Type of AllocationMap
	using AllocationMap_t = std::unordered_map<void*, Stacktrace>;

	// Allocation to stacktrace mapping
	static AllocationMap_t AllocationMap = AllocationMap_t();

	// Lock for AllocationMap
	static Spinlock AllocationMapLock;

	// ---------------------------------------------------------------------------

	fMalloc SetMalloc(fMalloc afMalloc) {
		auto prev = Malloc;
		Malloc = afMalloc;
		return prev;
	}

	fFree SetFree(fFree afFree) {
		auto prev = Free;
		Free = afFree;
		return prev;
	}

	int64_t GetActiveAllocations() {
		return ActiveAllocations;
	}

	void AddAllocation(void* apData) {
		std::lock_guard<Spinlock> guard(AllocationMapLock);
		Backtrace(AllocationMap[apData], 2, 64);
	}

	void RemoveAllocation(void* apData) {
		std::lock_guard<Spinlock> guard(AllocationMapLock);
		AllocationMap.erase(apData);
	}

}