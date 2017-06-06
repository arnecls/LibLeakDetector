#pragma once

#include <new>

void* operator new(size_t aSizeByte);
void* operator new[](size_t aSizeBytes);

void* operator new(size_t aSizeByte, std::nothrow_t);
void* operator new[](size_t aSizeBytes, std::nothrow_t);

void operator delete(void* apData);
void operator delete[](void* apData);