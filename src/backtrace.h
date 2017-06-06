#pragma once

#include <vector>

namespace LeakDetector {
	using Stacktrace = std::vector<void*>;

	// Backtrace will return an array of addresses denoting 0..n frames of the
	// callstack at the time of call. Backtrace itself is not included in the
	// array.
	// @param aFrames A vector holding the stack frames. This vector will not be
	//        resized but the length will be set to the number of frames received.
	// @param aSkip defines the number of frames to skip not including this function.
	// @param aNumFrames If not 0, aFrames will be resized to hold at least 
	//        the given number of frames.
	void Backtrace(Stacktrace& aFrames, size_t aSkip=1, size_t aNumFrames=0);
}