#include "new.h"
#include "allocation_func.h"
#include <atomic>

void* operator new(size_t aSizeByte) {
	void* pData = LeakDetector::Malloc(aSizeByte);
	if (pData == nullptr) {
		throw std::bad_alloc();
	}
	LeakDetector::AddAllocation(pData);
	return pData;
}

void* operator new[](size_t aSizeBytes) {
	void* pData = LeakDetector::Malloc(aSizeBytes);
	if (pData == nullptr) {
		throw std::bad_alloc();
	}
	LeakDetector::AddAllocation(pData);
	return pData;
}

void* operator new(size_t aSizeByte, std::nothrow_t) {
	void* pData = LeakDetector::Malloc(aSizeByte);
	if (pData != nullptr) {
		LeakDetector::AddAllocation(pData);
	}
	return pData;
}

void* operator new[](size_t aSizeBytes, std::nothrow_t) {
	void* pData = LeakDetector::Malloc(aSizeBytes);
	if (pData != nullptr) {
		LeakDetector::AddAllocation(pData);
	}
	return pData;
}

void operator delete(void* apData) {
	LeakDetector::Free(apData);
	LeakDetector::RemoveAllocation(apData);
}

void operator delete[](void* apData) {
	LeakDetector::Free(apData);
	LeakDetector::RemoveAllocation(apData);
}