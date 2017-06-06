#pragma once

#include "allocation.h"
#include <cstdlib>

namespace LeakDetector {
	// Malloc method to use
	static fMalloc Malloc = ::malloc;

	// Free method to use
	static fFree Free = ::free;
}